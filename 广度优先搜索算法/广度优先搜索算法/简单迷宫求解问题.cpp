#include<iostream>
using namespace std;
#define MAX 2501
#define N 51
struct Node
{
	int x;
	int y;
	int father;//���ױ�ţ����ڼ���·����
	int s;//����
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
	flag = 0;//��¼�����յ����
	while (head < tail)
	{
		for (k = 0; k < 4; k++)
		{
			nextx = Que[head].x + next[k][0];
			nexty = Que[head].y + next[k][1];
			
			//�ж���һ��������Խ��
			if (nextx<1 || nexty>n || nexty<1 || nextx>n)
				continue;
			
			//�ж���һ���ĵ��ǲ����ϰ���鿴�������Ƿ����������
			if (a[nextx][nexty] == 0 && book[nextx][nexty] == 0)
			{
				book[nextx][nexty] = 1;
				Que[tail].x = nextx;
				Que[tail].y = nexty;
				Que[tail].father = head;
				Que[tail].s = Que[head].s+1;
				tail++;
			}

			//�ж��Ƿ��Ѿ������յ�
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
	//��ӡ������ĩβ���һ�������ߵĲ������ﵽĿ���Ĳ�����
	cout << Que[tail-1].s << endl;
	getchar();
	getchar();
	return 0;
}