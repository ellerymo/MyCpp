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
	hash.push("Zhao", "��ӱ��");
	hash.push("Ji", "������");
	hash.push("Zhang", "����ΰ");
	hash.push("Xu", "�쾸��");
	hash.push("Wang", "������");
	hash.display();
	hash.find("Zhao");
}
int main()
{

	testString();
	getchar();
	return 0;
}