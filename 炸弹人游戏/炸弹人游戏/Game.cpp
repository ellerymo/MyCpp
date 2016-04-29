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
	/*������ͼÿ����*/
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			//�ж���һ���ǲ��ǿ��Է���ը����
			if (Map[i][j] == '.')
			{
				sum = 0;//��¼�ܹ������ڴ˵�ը���ĵ�������
				x = i;
				y = j;
				while (Map[x][y] != '#')
				{
					if (Map[x][y] == 'G')
						sum++;
					x--;//����ͳ��
				}
				x = i;
				y = j;
				while (Map[x][y] != '#')
				{
					if (Map[x][y] == 'G')
						sum++;
					x++;//����ͳ��
				}
				x = i;
				y = j;
				while (Map[x][y] != '#')
				{
					if (Map[x][y] == 'G')
						sum++;
					y++;//����ͳ��
				}
				x = i;
				y = j;
				while (Map[x][y] != '#')
				{
					if (Map[x][y] == 'G')
						sum++;
					y--;//����ͳ��
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
	cout << "�����������˵�λ���ǣ�" << "[" << x << "," << y << "]" << endl;
	cout << "������ĵ�������:" << map << endl;
}
int main()
{
	PrintMap();
	FindMaxMap();
	getchar();
	return 0;
}