#include"Map.h"
using namespace std;
void PrintMap()
{
	char(*p)[M] = Map;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout <<*(p[i]+j);
		}
		cout << endl;
	}
}
void FindMaxMap()
{
	int map = 0;
	int x = 0;
	int y = 0;
	int sum = 0;
	int max_x = 0;
	int max_y = 0;
	/*遍历地图每个点*/
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			//判断这一点是不是可以放置炸弹处
			if (Map[i][j] == '.')
			{
				sum = 0;//记录总共可以在此点炸掉的敌人总数
				x = i;
				y = j;
				while (Map[x][y] != '#')
				{
					if (Map[x][y] == 'G')
						sum++;
					x--;//向上统计
				}
				x = i;
				y = j;
				while (Map[x][y] != '#')
				{
					if (Map[x][y] == 'G')
						sum++;
					x++;//向下统计
				}
				x = i;
				y = j;
				while (Map[x][y] != '#')
				{
					if (Map[x][y] == 'G')
						sum++;
					y++;//向右统计
				}
				x = i;
				y = j;
				while (Map[x][y] != '#')
				{
					if (Map[x][y] == 'G')
						sum++;
					y--;//向左统计
				}
				x = i;
				y = j;
				if (sum > map)
				{
					map = sum;
					max_x = x;
					max_y = y;
				}
			}
		}
	}
	cout << "能消灭最多敌人的位置是：" << "[" << x << "," << y << "]" << endl;
	cout << "消灭掉的敌人数量:" << map << endl;
}
int main()
{
	PrintMap();
	FindMaxMap();
	getchar();
	return 0;
}