#define _CRT_SECURE_NO_WARNINGS 1
#include"Huffman.h"
#include<string>
#include<stdio.h>
typedef unsigned long Long;
struct CharInfo
{
	unsigned char _ch;
	Long _count;
	string _code;
	CharInfo(Long count = 0) :_count(count)
	{}
	bool operator== (const CharInfo ch) const
	{
		return ch._count == _count ;
	}
	CharInfo operator+(const CharInfo ch)
	{
		return CharInfo(_count + ch._count);
	}
	bool operator<(const CharInfo ch) const
	{
		return _count < ch._count;
	}
};
class FileCompress
{
public:
	FileCompress()
	{
		//��ʼ������ÿ���ַ�������Ϣ������
		for (int i = 0; i < 256; i++)
		{
			_infos[i]._ch = i;
			_infos[i]._count = 0;
		}
	}
	void Compree(const char *filename)
	{
		FILE *fOut = NULL;
		fOut =fopen(filename, "r");
		assert(fOut);
		//ͳ���ַ����ֵĴ���
		char ch = fgetc(fOut);
		while (ch != EOF)
		{
			_infos[ch]._count++;
			ch = fgetc(fOut);
		}

		//����Huffman��
		CharInfo invalid;
		HuffmanTree<CharInfo> tree(_infos, 256, invalid);

	}
protected:
	CharInfo _infos[256];
};