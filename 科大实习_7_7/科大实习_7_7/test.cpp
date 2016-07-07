#include<iostream>
using namespace std;
//1.统计一个整形的二进制形式里的1的个数
int count_one( int n )
{
	int count = 0;
	while (n)
	{
		n &= n - 1;
		count++;
	}
	return count;
}
//2.两个int型整数里的二进制表达里面有多少位不同
int diff_in_two_num(int m,int n)
{
	int num = m^n;
	int ret = 0;
	while (num)
	{
		num &= num - 1;
		ret++;
	}
	return ret;
}
//3.判断一个数是不是2的N次方
bool check_2N(int n)
{
	if (!(n&(n - 1)))
		return true;
	else
		return false;
}
//4.写一个宏定义实现奇偶位互换
#define SWAP(X) (((X&0x55555555)<<1)|((X&0xaaaaaaaa)>>1))
//5.将一个数的二进制序列逆序
int reverse_bin_in_num(int num)
{
	int ret = 0;
	for (int i = 31; i >= 0; i--)
	{
		ret |= num << i;
		num = num >> 1;
	}
	return ret;
}
//6.编写一个函数将指定位置1或者置0
int set_pos_bit(int num,int pos,int flag)
{
	if (flag == 1)
		num |= 1 << (pos - 1);
	else
		num &= ~(1 << (pos - 1));
	return num;
}
//7.找出唯一一个只出现一次的数字，其他数字成对出现
int find_only_in_arr(int *arr, int size)
{
	int tmp = 0;
	for (int i = 0; i < size; i++)
	{
		tmp = tmp^arr[i];
	}
	return tmp;
}
//8.找出数组里唯一出现的两个数字，其他数字均只出现一次
void find_only_two_in_arr(int arr[], int size, int *p1, int *p2)
{
	int tmp = 0;
	for (int i = 0; i < size; i++)
	{
		tmp ^= arr[i];
	}
	int pos = 0;
	int ret = tmp;
	while (tmp)
	{
		if (tmp & 1 == 1)
			break;
		tmp >>= 1;
		pos++;
	}
	for (int j = 0; j < size; j++)
	{
		if ((arr[j] & (1 << pos)) == 1)
			(*p1) ^= arr[j];
	}
	(*p2) = ret ^ (*p1);
}
int main()
{
	//cout << count_one(15) << endl;
	//cout << diff_in_two_num(1999, 2299) << endl;
	//cout << "2的N次方？ " << check_2N(5) << endl;
	//cout << SWAP(10) << endl;
	//cout << reverse_bin_in_num(10) << endl;
	//cout << set_pos_bit(10, 1, 1) << endl;
	//cout << set_pos_bit(10, 2, 0) << endl;
	//int arr[] = { 1, 2, 2, 1, 4, 6, 4 };
	//cout << find_only_in_arr(arr, sizeof(arr) / sizeof(arr[0])) << endl;
	int arr[] = { 1, 2, 2, 1, 4, 5, 6, 5, 4, 6, 8, 3 };
	int ret1 = 0;
	int ret2 = 0;
	find_only_two_in_arr(arr, sizeof(arr) / sizeof(arr[0]), &ret1, &ret2);
	cout << ret1 << " " << ret2 << endl;
	getchar();
}