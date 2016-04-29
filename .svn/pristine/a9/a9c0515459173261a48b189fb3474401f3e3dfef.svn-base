#include<iostream>
using namespace std;
#define MAX 2501
#define N 51
struct Node
{
	int x;
	int y;
	int father;//父亲编号（便于计算路径）
	int s;//步数
};
int main()
{
	Node Que[MAX];
	int a[N][N] = { 0 };
	int book[N][N] = { 0 };
	int next[][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	int head, tail;
	int i, j, k, n, m, startx, starty, p, q, nextx, nexty, flag;

	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> startx >> starty >> p >> q;

	head = 1;
	tail = 1;
	Que[tail].x = startx;
	Que[tail].y = starty;
	Que[tail].father = 0;
	Que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	flag = 0;//记录到达终点与否
	while (head < tail)
	{
		for (k = 0; k < 4; k++)
		{
			nextx = Que[head].x + next[k][0];
			nexty = Que[head].y + next[k][1];
			
			//判断下一个坐标点否越界
			if (nextx<1 || nexty>n || nexty<1 || nextx>n)
				continue;
			
			//判断下一步的点是不是障碍物，查看队列中是否已有这个点
			if (a[nextx][nexty] == 0 && book[nextx][nexty] == 0)
			{
				book[nextx][nexty] = 1;
				Que[tail].x = nextx;
				Que[tail].y = nexty;
				Que[tail].father = head;
				Que[tail].s = Que[head].s+1;
				tail++;
			}

			//判断是否已经到了终点
			if (nextx == p && nexty == q)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;
	}
	//打印队列中末尾最后一个点所走的步数（达到目标点的步数）
	cout << Que[tail-1].s << endl;
	getchar();
	getchar();
	return 0;
}