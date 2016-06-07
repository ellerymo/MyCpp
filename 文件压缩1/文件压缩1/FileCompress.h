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
		//初始化保存每个字符出现信息的数组
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
		//统计字符出现的次数
		char ch = fgetc(fOut);
		while (ch != EOF)
		{
			_infos[ch]._count++;
			ch = fgetc(fOut);
		}

		//构建Huffman树
		CharInfo invalid;
		HuffmanTree<CharInfo> tree(_infos, 256, invalid);

	}
protected:
	CharInfo _infos[256];
};