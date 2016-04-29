#include"SmartPtr.h"
void testAuto()
{
	
	AutoPtr<int> ap1(new int (5));
	cout << "ap1:" << ap1 << endl;
	cout << "*ap1:" << *ap1 << endl;

	AutoPtr<int> ap2(ap1);
	cout << "ap2:" << ap2 << endl;
	cout << "*ap2:" << *ap2 << endl;

	AutoPtr<int> ap3(new int(1));
	cout << "ap3:" << ap3 << endl;
	cout << "*ap3:" << *ap3 << endl;

	ap3 = ap2;
	cout << "ap3:" << ap3 << endl;
	cout << "*ap3:" << *ap3 << endl;

}
void testScopedPtr()
{

	ScopedPtr<int> sp1(new int(5));
	ScopedPtr<int> sp2(new int(5));
	cout << "*sp2:" << *sp2<<endl;
	cout << "*sp1:" << *sp1 << endl;
}
void testSharedPtr()
{
	SharedPtr<int> sp1(new int(10));
	cout << "sp1:" << *sp1<< endl;
	cout << "sp1Conut:" <<sp1.GetCount() << endl;

	SharedPtr<int> sp2(new int(5));
	cout << "sp2:" << *sp2 << endl;
	cout << "sp2Count:" << sp2.GetCount()<< endl;

	sp2 = sp1;
	cout << "sp1:" << *sp1 << endl;
	cout << "sp1Count:" << sp1.GetCount() << endl;

}
int main()
{
	cout <<"------------------------------------"<< endl;
	testAuto();
	cout <<"------------------------------------" << endl;
	testScopedPtr();
	cout << "------------------------------------" << endl;
	testSharedPtr();
	getchar();
	return 0;
}