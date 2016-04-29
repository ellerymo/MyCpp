#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<cassert>
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
struct Pos
{
	size_t _x;
	size_t _y;
	Pos(size_t x, size_t y) :_x(x), _y(y)
	{}
};
stack<Pos> min;
bool IsValid(int *a, Pos cur, size_t R, size_t C)
{
	if ((a[cur._x*C + cur._y] == 0) && (cur._x < R) && (cur._y < C))
		return true;
	else
		return false;
}
void PrintMap(int *Map, size_t m, size_t n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << Map[i*n + j] << " ";
		}
		std::cout << std::endl;
	}
}
void GetMaze(int *a,size_t Row,size_t Col,std::ifstream& fout)
{
	size_t ch = 0;

	for (size_t i = 0; i < Row; i++)
	{
		for (size_t j = 0; j < Col;)
		{
			ch = fout.get()-'0';
			if (ch == 0 || ch == 1)
			{
				a[i*Col + j] = ch;
				j++;
			}
			else
				continue;
		}
	}
	PrintMap(a, Row, Col);
}
bool Check(int *a,Pos entry,int R,int C)
{
	Pos Up = entry;
	Pos Down = entry;
	Pos Left = entry;
	Pos Right = entry;

	Down._x++;
	Right._y++;
	Up._x--;
	Left._y--;
	if (IsValid(a, Down, R, C) || IsValid(a, Up, R, C) || 
		IsValid(a, Left, R, C) || IsValid(a, Right, R, C))
		return true;
	else
		return false;
}
bool GamePlay(int *a, Pos entry, size_t R, size_t C)
{
	assert(a);
	stack<Pos> s1;
	Pos man = entry;
	Pos next = man;
	Pos cur = entry;
	while ( 1 )
	{
		if (!Check(a, man, R, C))
		{
			cout << "最佳路径长度:";
			cout << min.size() << endl;
			return true;
		}
		s1.push(man);
		while (!s1.empty())
		{
			a[man._x*C + man._y] = 2;
			if (man._x == (R - 1) || man._y == (C - 1))
			{
				cout << "Find&end" << endl;
				if ((s1.size() < min.size()) || min.size() == 0)
					min = s1;
				while (!s1.empty())
				{
					cur = s1.top();
					s1.pop();
					if (Check(a, cur, R, C))
					{
						man = cur;
						break;
					}
				}
				if (s1.empty())
				{
					cout << "最佳路径长度:";
					cout << min.size() << endl;
					return true;
				}
			}
			
			//********************************************下
			next = man;
			next._x++;
			if (IsValid(a, next, R, C))
			{
				s1.push(man);
				man = next;
				continue;
			}
			//********************************************右
			next = man;
			next._y++;
			if (IsValid(a, next, R, C))
			{
				s1.push(man);
				man = next;
				continue;
			}
			//********************************************左
			next = man;
			next._y--;
			if (IsValid(a, next, R, C))
			{
				s1.push(man);
				man = next;
				continue;
			}
			//********************************************上
			next._x--;
			if (IsValid(a, next, R, C))
			{
				s1.push(man);
				man = next;
				continue;
			}
			else
			{
				man = s1.top();
				s1.pop();
			}
		}
		man = entry;
	}
}
void GameTest()
{
	//**********************从文件读入迷宫大小**********************
	ifstream fout("Maze.txt");
	stack<int> s1;
	int Row = 0;
	int Col = 0;
	char ch = fout.get();
	while (ch != ' ')
	{
		int tmp = ch - '0';
		s1.push(tmp);
		ch = fout.get();
	}
	int c = 0;
	while (!s1.empty())
	{
		Row += s1.top()*(int)pow(10, c);
		s1.pop();
		c++;
	}
	ch = fout.get();
	while (ch != ' '&&ch != '\n')
	{
		int tmp = ch - '0';
		s1.push(tmp);
		ch = fout.get();
	}
	c = 0;
	while (!s1.empty())
	{
		Col += (int)s1.top()*(int)pow(10, c);
		s1.pop();
		c++;
	}
	int *a = new int[Row*Col];
	//********************************************************

	Pos entry(0, 1);
	cout << endl << "***********    Map    **********" << endl;
	GetMaze(a, Row, Col, fout);
	GamePlay(a, entry, Row, Col);
	cout << endl << "***********    Map    **********" << endl;
	PrintMap(a, Row, Col);
	fout.close();
}
