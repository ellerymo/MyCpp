#include"BigData.h"
using namespace std;
void testOSADD()
{
	BigData big1("123");
	cout << big1 << endl;
	BigData big2("9999999999999999999999999999999999999999999999999");
	cout << big2 << endl;
	BigData big3("1111111111111111111111111111111111");
	cout << big3 << endl;
	BigData big4(123456789);
	cout << big4 << endl;
	cout << (big1 + big3) << endl;
	cout << (big1 + big4) << endl;
}


int main()
{
	testOSADD();
	getchar();
	return 0;
}