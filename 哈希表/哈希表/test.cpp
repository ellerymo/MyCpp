#include"Hash.h"
void testInsert()
{
	HashTable<int,float> hash;
	hash.push(1, 1.5);
	hash.push(11, 1.5);
	hash.push(21, 1.5);
	hash.push(12, 2.5);
	hash.push(13, 3.5);
	hash.Display();
}
void testString()
{
	HashTable<string, string> hash;
	hash.push("Peter", "����ΰ");
	hash.push("Yang", "���");
	hash.push("Wang", "������");
	hash.push("Xu", "�쾸��");
	hash.Display();
	cout << "Wang��ѯ���:" << hash.find("Wang")->_value << endl;
}
void testCopy()
{
	HashTable<string, string> hash;
	hash.push("Peter", "����ΰ");
	hash.push("Yang", "���");
	hash.push("Wang", "������");
	hash.push("Xu", "�쾸��");
	HashTable<string, string> hash2(hash);
	hash2.Display();
	HashTable<string, string> hash3;
	hash3.push("Jilixin", "������");
	hash3.push("ZhaoYingna", "��ӱ��");
	hash3.Display();
	hash3 = hash;
	hash3.Display();
}

int main()
{
	testInsert();
	testString();
	testCopy();
	getchar();
	return 0;
}