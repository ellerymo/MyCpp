#include<iostream>
#include<cstdarg>
using namespace std;

//用于调试的信息打印函数
static string GetFileName(const string& path)
{
	char ch = '/';
#ifdef _WIN32
	ch = '\\';
#endif
	size_t pos = path.rfind(ch);
	if (pos == string::npos)
		return path;
	else
		return path.substr(pos + 1);
}

inline static void __trace_debug(const char* function,
	const char * filename, int line, char* format, ...)
{

	// 输出调用函数的信息
	fprintf(stdout, "【%s:%d】 %s", GetFileName(filename).c_str(), line, function);
	// 输出用户打的trace信息
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
}
#define __TRACE_DEBUG(...) \
	__trace_debug(__FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);
////////////////////////////////////////一级空间配置器//////////////////////////////////
void(*Malloc_Alloc_Oom_Handler)() = 0;
template <int inst>
class Malloc_Alloc_Template {
private:
	static void *Oom_Malloc(size_t);
	static void(*Malloc_Alloc_Oom_Handler)();
public:
	//分配内存
	static void *Allocate(size_t n)
	{
		__TRACE_DEBUG("(n:%u)\n", n);
		void *ret = malloc(n);
		//失败则交由Oom_Malloc处理
		if (0 == ret)
			ret = Oom_Malloc(n);
		return ret;
	}

	//释放内存
	static void Deallocate(void *p, size_t)
	{
		__TRACE_DEBUG("(n:%u)\n", n);
		free(p);
	}

	//改变处里内存不足的函数返回旧的
	static void(*Set_Malloc_Handler(void(*Fun)()))()
	{
		void(*Old_Func)() = Malloc_Alloc_Oom_Handler();
		Malloc_Alloc_Oom_Handler = Fun;
		return Old_Func;
	}
};

template <int inst>
void(*Malloc_Alloc_Template<inst>::Malloc_Alloc_Oom_Handler)() = 0;

template <int inst>
//当内存不足时调用
void *Malloc_Alloc_Template<inst>::Oom_Malloc(size_t n)
{
	void(*My_Malloc_Handler)();
	void *ret;
	while (1)
	{
		My_Malloc_Handler = Malloc_Alloc_Oom_Handler;
		//没有设置处理函数时直接结束程序
		if (My_Malloc_Handler == 0)
		{
			throw  bad_alloc();
		}
		//(*My_Malloc_Handler)();
		My_Malloc_Handler();
		ret = malloc(n);
		if (NULL != ret)
			return ret;
	}
}
typedef Malloc_Alloc_Template<0> Malloc_Alloc;
///////////////////////////二级空间配置器//////////////////////////
template <bool threads, int inst>
class _Default_Alloc_Template
{
public:
	enum { _ALIGN = 8 };
	enum { _MAX_BYTES = 128 };
	enum { _NFREELISTS = _MAX_BYTES / _ALIGN };
private:
	union Obj
	{
		//指向下一个内存块的指针
		union Obj * Free_List_Link;
		char Client_Data[1];
	};
	static volatile Obj* Free_List[_NFREELISTS];	/*自由链表*/
	static char *_Start;							/*水位线*/
	static char *_End;								/*内存池底*/
	static size_t Heap_Size;						/*从系统堆分配的总大小*/

	//计算申请的内存块在自由链表的哪个位置
	static size_t FreeList_Index(size_t bytes)
	{
		return (((bytes)+_ALIGN - 1) / _ALIGN - 1);
	}
	//计算应该分配多少内存，对齐到某一个内存块
	static size_t ROUND_UP(size_t n)
	{
		return (n + (_ALIGN)-1) & ~(_ALIGN - 1);
	}
public:
	//内存分配
	static void * Allocate(size_t n)
	{
		Obj*  result;
		if (n > 128)
		{
			return Malloc_Alloc::Allocate(n);
		}

		int index = FreeList_Index(n);
		result = (Obj*)Free_List[index];

		//该位置自由链表下没有内存块
		if (result == 0) {
			void *ret = Refill(ROUND_UP(n));
			return ret;
		}
		Free_List[index] = result->Free_List_Link;
		return (result);
	};
	static void Deallocate(void *p, size_t n)
	{
		Obj *q = (Obj *)p;
		//大于最大内存块直接使用第一级空间配置器
		if (n > (size_t)_MAX_BYTES)
		{
			Malloc_Alloc::Deallocate(p, n);
			return;
		}
		//将归还的内存挂回自由链表
		else
		{
			int Index = FreeList_Index(n);
			q->Free_List_Link = Free_List[Index];
			Free_List[Index] = q;
		}
	}

	static void* Refill(size_t n)
	{
		int nobjs = 20;
		//去内存池切分内存
		char* chunk = Chunk_Alloc(n, nobjs);
		Obj * result;
		Obj * cur, *next;
		if (1 == nobjs)
			return(chunk);
		int Index = FreeList_Index(n);
		cur = Free_List[Index]->Free_List_Link;
		for (int i = 1; i < nobjs - 1; i++)
		{
			next = (Obj *)((char *)cur + n);
			cur->Free_List_Link = next;
			next = cur;
		}
		cur->Free_List_Link = 0;
		result = (Obj*)chunk;
		return(result);
	}
	static char *Chunk_Alloc(size_t size, int& nobjs)
	{
		/*
		1.内存足够
		2.内存只能够至少分配一个内存块大小
		3.内存不足以分配一个内存块
		*/

		//1
		size_t Need = size *nobjs;
		size_t LeftBytes = _End - _Start;
		char* Ret = NULL;
		if (Need <= LeftBytes)
		{
			__TRACE_DEBUG("内存池中内存足够分配%d个对象\n", nobjs);
			Ret = _Start;
			_Start += Need;
			return Ret;
		}
		else if (Need >= size)
		{
			__TRACE_DEBUG("内存池中内存不够分配%d个对象， 只能分配%d个对象\n", nobjs, LeftBytes / size);
			nobjs = LeftBytes / size;
			Need = size *nobjs;
			Ret = _Start;
			_Start += Need;
		}
		else
		{
			//定义需要从系统分配多少内存
			size_t Bytes_to_Get = 2 * Need + ROUND_UP(Heap_Size >> 4);
			if (LeftBytes > 0)
			{
				int Index = FreeList_Index(LeftBytes);
				((Obj*)_Start)->Free_List_Link = (Obj*)Free_List[Index];
				Free_List[Index] =(Obj*) _Start;
				__TRACE_DEBUG("将内存池中剩余的空间， 分配给freeList[%d]\n", Index);
			}
			_Start = (char *)malloc(Bytes_to_Get);
			//系统也已经分配不出内存
			__TRACE_DEBUG("内存池空间不足， 系统从堆分配%u bytes内存\n", Bytes_to_Get);
			if (0 == _Start)
			{
				//去自己的自由链表里找更大的
				for (int i = size; i < _MAX_BYTES; i += _ALIGN)
				{

					int Index = FreeList_Index(i);
					if (Free_List[Index] != 0)
					{
						_Start = (char *)Free_List[Index];
						_End = _Start + i;
						Free_List[Index] = Free_List[Index]->Free_List_Link;
						__TRACE_DEBUG("系统内存不够，系统将freeList[%d]的内存块拿出\n", Index);
						return Chunk_Alloc(size, nobjs);
					}
				}
				//若之后抛出异常不会导致野指针问题
				_End = 0;
				__TRACE_DEBUG("系统堆和自由链表都已无内存\n");
				_Start = (char *)Malloc_Alloc::Allocate(Bytes_to_Get);
			}

			Heap_Size += Bytes_to_Get;
			_End = _Start + Bytes_to_Get;
			return Chunk_Alloc(size, nobjs);
		}
	}
};
template <bool threads, int inst>
char *_Default_Alloc_Template<threads, inst>::_Start = 0;

template <bool threads, int inst>
char *_Default_Alloc_Template<threads, inst>::_End = 0;

template <bool threads, int inst>
size_t _Default_Alloc_Template<threads, inst>::Heap_Size = 0;

template <bool threads, int inst>
typename  _Default_Alloc_Template<threads, inst>::Obj* volatile \
_Default_Alloc_Template<threads, inst>:: \
Free_List[_Default_Alloc_Template<threads, inst>::_NFREELISTS] = { 0 };


template<class T, class Alloc = _Default_Alloc_Template<0, 0> >
class Simple_Alloc {

public:
	static T *Allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::Allocate(n * sizeof (T));
	}
	static T *Allocate(void)
	{
		return (T*)Alloc::Allocate(sizeof (T));
	}
	static void Deallocate(T *p, size_t n)
	{
		if (0 != n) Alloc::Deallocate(p, n * sizeof (T));
	}
	static void Deallocate(T *p)
	{
		Alloc::Deallocate(p, sizeof (T));
	}
};
int main()
{
	char * p = Simple_Alloc<char>::Allocate(5);
	char * p2 = Simple_Alloc<char>::Allocate(128);
	char * p3 = Simple_Alloc<char>::Allocate(129);
	char * p4 = Simple_Alloc<char>::Allocate(128);
	getchar();
	return 0;
}