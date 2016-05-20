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
	BigData big("0");
}
void testSUB()
{
	BigData big("1234567890234567");
	BigData sma("-233333452213");
	cout << big - sma << endl;

}
void testMUL()
{
	BigData big("123");
	BigData sma("2345");
	cout << big * sma << endl;
}

void testDIV()
{
	BigData big("12345");
	BigData sma("-1");
	cout << big / sma << endl;
}
void testString()
{
	string s1("123");
	cout << s1 << endl;
}
int main()
{
	testDIV();
	getchar();
	return 0;
}