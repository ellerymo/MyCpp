//#include<iostream>
//#include<vector>
//#include<string>
//#include<fstream>
//using namespace std;
//#if 0
//
//int main()
//{
//	unsigned u = 10, u2 = 42;
//	int i = 10, i2 = 42;
//	cout << u2 - u << endl;
//	cout << u - u2 << endl;//4294967264
//	cout << i2 - i << endl;
//	cout << i - i2 << endl;
//	cout << u - i << endl;
//	cout << i - u << endl;
//	getchar();
//	return 0;
//}
//#endif
//
//#if 0
//int main()
//{
//	
//	int a = 1;
//	int *ptr = (int *)&a;
//	int *ptr2 = ptr;
//	ptr2++;
//	cout << ptr2 - ptr << endl;
//	getchar();
//	return 0;
//}
//#endif
//#if 0
////利用vector 给文件加上行号
//int main()
//{
//	ifstream in("read.txt");
//	vector<string> vec;
//	string line;
//	while (getline(in, line))
//	{
//		vec.push_back(line);
//	}
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << i + 1 << " "<<vec[i] << endl;
//	}
//	getchar();
//	return 0;
//}
//#endif
//#if 0
////将一个类指针赋空再调用 
////结构仍然输出show 函数内容但不可以输出display函数
////...因为display 函数使用了this 指针（动态绑定&静态绑定）
//class cal
//{
//public:
//	cal() :a(10)
//	{}
//	void show()
//	{
//		cout << "cal::Show()" << endl;
//	}
//	void display()
//	{
//		cout << a << endl;
//	}
//private:
//	int a;
//};
//int main()
//{
//	cal *pcal = NULL;
//	pcal->show();
//	pcal->display();
//	getchar();
//	return 0;
//}
//#endif
//
//#if 0
////使用using实现typedef的用法
//using ee = int;
//#define P(EX) cout<<#EX<<endl 
//int main()
//{
//	ee a = 0;
//	cout <<a << endl;
//	P(aaa);
//	getchar();
//	return 0;
//}
//#endif
//
//#if 0
////插入运行时调试标记
//bool debug = false;
//int main(int argc,char *argv[])
//{
//	for (int i = 0; i < argc; i++)
//	{
//		if (string(argv[i]) == "--debug = on")
//			debug = true;
//	}
//	bool go = true;
//	while (go)
//	{
//		if (debug)
//		{
//			cout << "Debugger is now on!" << endl;
//		}
//		else
//		{
//			cout << "Debugger is now off" << endl;
//		}
//		string reply;
//		cin >> reply;
//		if (reply == ":q")
//			break;
//	}
//}
//#endif
//
//#if 0
////方便我们查看谁被调用
//#define DF(N) void N(){\
//	cout << "函数"#N"被调用..." << endl; }
//DF(a); DF(b); DF(c); DF(d); DF(e); DF(f); DF(g);
//void(*func_table[])() = { a, b, c, d, e,f,g };
//int main()
//{
//	while (1)
//	{
//		cout << "press a key from 'a' to 'g'，or 'q'" << endl;
//		char c;
//		cin.get(c);
//		if (c == 'q')
//			break;
//		if (c >= 'a'&& c <= 'g')
//			(func_table[c - 'a'])();
//		else
//			continue;
//	}
//	return 0;
//}
//#endif
//#if 0
////关键字volatile
//class Comm
//{
//	const volatile unsigned char byte;
//	volatile unsigned char flag;
//	enum{ bufsize = 100 };
//	unsigned char buf[bufsize];
//	int index;
//
//public:
//	Comm();
//	void isr() volatile;
//	char read(int index) const;
//};
//#endif
//#if 1
////模板实现容器配接
//template<class T, class Container = vector<T> >
//class Test
//{
//private :
//	Container con;
//public:
//	void  _push(const T& data)
//	{
//		con.push_back(data);
//	}
//	void show()
//	{
//		cout << con[0] << endl;
//	}
//};
//
//int main()
//{
//	Test< string > te;
//	te._push("This");
//	te.show();
//	getchar();
//	return 0;
//}
//#endif
#include"标头.h"
void main()
{
	Test();
}