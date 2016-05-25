#include"Hash.h"
void testPush()
{
	Hash<int, int> hash;
	for (int i = 0; i < 53;i++)
		hash.push(i, i);
	hash.push(53, 53);
	hash.push(97, 97);
	hash.display();
	hash.find(52);
	hash.Remove(52);
	hash.display();
}

void testString()
{
	Hash<string, string> hash;
	hash.push("Zhao", "赵颖娜");
	hash.push("Ji", "纪立新");
	hash.push("Zhang", "张鹏伟");
	hash.push("Xu", "徐靖杭");
	hash.push("Wang", "王海斌");
	hash.display();
	hash.find("Zhao");
}
int main()
{

	testString();
	getchar();
	return 0;
}