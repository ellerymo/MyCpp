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
			_infos[(unsigned char)i]._ch = i;
			_infos[(unsigned char)i]._count = 0;
		}
	}
	//ѹ���ļ�
	void Compree(string filename)
	{
		FILE *fOut = NULL;
		fOut = fopen((filename+".PNG").c_str(), "rb");
		assert(fOut);
		//ͳ���ַ����ֵĴ���
		char ch = fgetc(fOut);
		while (ch != EOF)
		{
			_infos[(unsigned char)ch]._count++;
			ch = fgetc(fOut);
		}

		//����Huffman��
		CharInfo invalid;
		HuffmanTree<CharInfo> tree(_infos, 256, invalid);
		//����Huffman����
		GetHuffmanCode(tree._root, "");
		//����Huffman����
		FILE *write = fopen((filename + ".huffman").c_str(), "wb");
		assert(write);
		char cha = 0;
		//���´��ļ����code���ұ���
		fseek(fOut, 0, SEEK_SET);
		cha = fgetc(fOut);
		unsigned char value = 0;
		int size = 0;
		while (cha != EOF)
		{
			string &code = _infos[(unsigned char)cha]._code;
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

		//д�����ļ�
		FILE *conf = fopen("config.txt","wb");
		for (int i = 0; i < 256; i++)
		{
			if (_infos[i]._count != 0)
			{
				char buf[128] = { '\0' };
   				fputc(_infos[i]._ch, conf);
				fputc(',',conf);
				_itoa(_infos[i]._count, buf, 10);
				fputs(buf, conf);
				fputc('\n',conf);
			}
		}
		fclose(fOut);
		fclose(write);
		fclose(conf);
	}
	//��ѹ��
	void UnCompress(string filename)
	{
		//�������ļ������������
		FILE *fIn = fopen("config.txt", "rb");
		assert(fIn);
		string line;
		int Count = 0;
		while (ReadLine(fIn, line) != EOF)
		{
			if (line.empty())
			{
				line += '\n';
			}
			else
			{
				_infos[(unsigned char)line[0]]._count = atoi(line.substr(2).c_str());
				line.clear();
			}
		}
		for (int i = 0; i < 256; i++)
		{
			if (_infos[i]._count != 0)
				Count += _infos[i]._count;
		}
		CharInfo invalid;
		HuffmanTree<CharInfo> tree(_infos, 256, invalid);
		//��������������ѹ���ļ�
		HuffmanTreeNode<CharInfo> *root = tree.GetRoot();
		GetHuffmanCode(tree._root, "");
		int pos = 7;
		FILE *fOut = fopen((filename +".huffman").c_str(), "rb");
		FILE*UnCom = fopen((filename + ".uncompress").c_str(), "wb");
		char fo = fgetc(fOut);
		HuffmanTreeNode<CharInfo> *cur = root;
		while (fo != EOF || Count != 0)
		{
			if (fo& (1 << pos))
				cur = cur->_right;
			else
				cur = cur->_left;
			if (!cur->_right &&!cur->_right)
			{
				if (Count-- == 0)
					break;
			fputc(cur->_weight._ch, UnCom);
				cur = root;
			}
			if (pos-- == 0)
			{
				fo = fgetc(fOut);
				pos = 7;
			}
		}
		fclose(fOut);
		fclose(fIn);
		fclose(UnCom);
	}
	//����ÿ�δ������ļ���ȡһ������
	char  ReadLine(FILE *file,string& line)
	{
		char ch = fgetc(file);
		while (ch != '\n' && ch != EOF)
		{
			line += ch;
			ch = fgetc(file);
		}
		return ch;
	}

protected:
	//����huffman�����㷨
	void GetHuffmanCode(HuffmanTreeNode<CharInfo>* root, string code)
	{
		if (root == NULL)
			return;
		GetHuffmanCode(root->_left, code + '0');
		GetHuffmanCode(root->_right, code + '1');
		if (!root->_left && !root->_right)
		{
			_infos[(root->_weight)._ch]._code = code;
			(root->_weight)._code = code;
		}
	}
	CharInfo _infos[256];
};