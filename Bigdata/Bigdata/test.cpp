#include"BigData.h"
using namespace std;


void testOSADD()
{
	BigData big1("-123");
	BigData big3(-9223372036854775807);
	cout << (big1 + big3) << endl;
}
void testSUB()
{
	BigData big(9223372036854775807);
	BigData sma("447899");
	cout << big - sma << endl;

}
void testMUL()
{
	BigData big("99999999999999999999999999999999");
	BigData sma("11");
	cout << big * sma << endl;
}

void testDIV()
{
	BigData big("22222222222222222222222222222222");
	BigData sma("33");
	cout << big / sma << endl;
}
void testString()
{
	string s1("123");
	cout << s1 << endl;
}
int main()
{
//	testOSADD();
//	testSUB();
//	testMUL();
//	testDIV();
	testString();
	getchar();
	return 0;
}