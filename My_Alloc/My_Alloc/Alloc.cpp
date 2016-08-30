#include<iostream>
#include<cstdarg>
using namespace std;

//���ڵ��Ե���Ϣ��ӡ����
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

	// ������ú�������Ϣ
	fprintf(stdout, "��%s:%d�� %s", GetFileName(filename).c_str(), line, function);
	// ����û����trace��Ϣ
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
}
#define __TRACE_DEBUG(...) \
	__trace_debug(__FUNCTION__, __FILE__, __LINE__, __VA_ARGS__);
////////////////////////////////////////һ���ռ�������//////////////////////////////////
void(*Malloc_Alloc_Oom_Handler)() = 0;
template <int inst>
class Malloc_Alloc_Template {
private:
	static void *Oom_Malloc(size_t);
	static void(*Malloc_Alloc_Oom_Handler)();
public:
	//�����ڴ�
	static void *Allocate(size_t n)
	{
		__TRACE_DEBUG("(n:%u)\n", n);
		void *ret = malloc(n);
		//ʧ������Oom_Malloc����
		if (0 == ret)
			ret = Oom_Malloc(n);
		return ret;
	}

	//�ͷ��ڴ�
	static void Deallocate(void *p, size_t)
	{
		__TRACE_DEBUG("(n:%u)\n", n);
		free(p);
	}

	//�ı䴦���ڴ治��ĺ������ؾɵ�
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
//���ڴ治��ʱ����
void *Malloc_Alloc_Template<inst>::Oom_Malloc(size_t n)
{
	void(*My_Malloc_Handler)();
	void *ret;
	while (1)
	{
		My_Malloc_Handler = Malloc_Alloc_Oom_Handler;
		//û�����ô�����ʱֱ�ӽ�������
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
///////////////////////////�����ռ�������//////////////////////////
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
		//ָ����һ���ڴ���ָ��
		union Obj * Free_List_Link;
		char Client_Data[1];
	};
	static volatile Obj* Free_List[_NFREELISTS];	/*��������*/
	static char *_Start;							/*ˮλ��*/
	static char *_End;								/*�ڴ�ص�*/
	static size_t Heap_Size;						/*��ϵͳ�ѷ�����ܴ�С*/

	//����������ڴ��������������ĸ�λ��
	static size_t FreeList_Index(size_t bytes)
	{
		return (((bytes)+_ALIGN - 1) / _ALIGN - 1);
	}
	//����Ӧ�÷�������ڴ棬���뵽ĳһ���ڴ��
	static size_t ROUND_UP(size_t n)
	{
		return (n + (_ALIGN)-1) & ~(_ALIGN - 1);
	}
public:
	//�ڴ����
	static void * Allocate(size_t n)
	{
		Obj*  result;
		if (n > 128)
		{
			return Malloc_Alloc::Allocate(n);
		}

		int index = FreeList_Index(n);
		result = (Obj*)Free_List[index];

		//��λ������������û���ڴ��
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
		//��������ڴ��ֱ��ʹ�õ�һ���ռ�������
		if (n > (size_t)_MAX_BYTES)
		{
			Malloc_Alloc::Deallocate(p, n);
			return;
		}
		//���黹���ڴ�һ���������
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
		//ȥ�ڴ���з��ڴ�
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
		1.�ڴ��㹻
		2.�ڴ�ֻ�ܹ����ٷ���һ���ڴ���С
		3.�ڴ治���Է���һ���ڴ��
		*/

		//1
		size_t Need = size *nobjs;
		size_t LeftBytes = _End - _Start;
		char* Ret = NULL;
		if (Need <= LeftBytes)
		{
			__TRACE_DEBUG("�ڴ�����ڴ��㹻����%d������\n", nobjs);
			Ret = _Start;
			_Start += Need;
			return Ret;
		}
		else if (Need >= size)
		{
			__TRACE_DEBUG("�ڴ�����ڴ治������%d������ ֻ�ܷ���%d������\n", nobjs, LeftBytes / size);
			nobjs = LeftBytes / size;
			Need = size *nobjs;
			Ret = _Start;
			_Start += Need;
		}
		else
		{
			//������Ҫ��ϵͳ��������ڴ�
			size_t Bytes_to_Get = 2 * Need + ROUND_UP(Heap_Size >> 4);
			if (LeftBytes > 0)
			{
				int Index = FreeList_Index(LeftBytes);
				((Obj*)_Start)->Free_List_Link = (Obj*)Free_List[Index];
				Free_List[Index] =(Obj*) _Start;
				__TRACE_DEBUG("���ڴ����ʣ��Ŀռ䣬 �����freeList[%d]\n", Index);
			}
			_Start = (char *)malloc(Bytes_to_Get);
			//ϵͳҲ�Ѿ����䲻���ڴ�
			__TRACE_DEBUG("�ڴ�ؿռ䲻�㣬 ϵͳ�Ӷѷ���%u bytes�ڴ�\n", Bytes_to_Get);
			if (0 == _Start)
			{
				//ȥ�Լ��������������Ҹ����
				for (int i = size; i < _MAX_BYTES; i += _ALIGN)
				{

					int Index = FreeList_Index(i);
					if (Free_List[Index] != 0)
					{
						_Start = (char *)Free_List[Index];
						_End = _Start + i;
						Free_List[Index] = Free_List[Index]->Free_List_Link;
						__TRACE_DEBUG("ϵͳ�ڴ治����ϵͳ��freeList[%d]���ڴ���ó�\n", Index);
						return Chunk_Alloc(size, nobjs);
					}
				}
				//��֮���׳��쳣���ᵼ��Ұָ������
				_End = 0;
				__TRACE_DEBUG("ϵͳ�Ѻ��������������ڴ�\n");
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