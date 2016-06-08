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
		fOut = fopen(filename, "r");
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
		//生成Huffman编码
		GetHuffmanCode(tree._root, "");
		//保存Huffman编码
		FILE *write = fopen("file.huff", "w");
		assert(write);
		char cha = 0;
		//重新从文件里读code并且保存
		fseek(fOut, 0, SEEK_SET);
		cha = fgetc(fOut);
		char value = 0;
		int size = 0;
		while (cha != EOF)
		{
			string &code = _infos[cha]._code;
			for (int i = 0; i < code.size(); ++i)
			{
				if (code[i] == '1')
					value |= 1;
				if (size < 7)
					value <<= 1;
				++size;
				if (size == 8)
				{
					fputc(value, write);
					value = 0;
					size = 0;
				}
			}
			cha = fgetc(fOut);
		}
		if (size > 0)
		{
			value <<= (8 - size - 1);
			fputc(value, write);
		}

		//写配置文件
		FILE *conf = fopen("config.txt","w");
		for (int i = 0; i < 256; i++)
		{
			if (_infos[i]._count != 0)
			{
				fputc(_infos[i]._ch, conf);
				fputc(',',conf);
				fputc(_infos[i]._count+'0', conf);
				fputc('\n',conf);
			}
		}
		fclose(fOut);
		fclose(write);
		fclose(conf);
	}

protected:
	//生成huffman编码算法
	void GetHuffmanCode(HuffmanTreeNode<CharInfo>* root, string code)
	{
		if (root == NULL)
			return;
		GetHuffmanCode(root->_left, code + '0');
		GetHuffmanCode(root->_right, code + '1');
		_infos[(root->_weight)._ch]._code = code;
		(root->_weight)._code = code;
	}
	CharInfo _infos[256];
};