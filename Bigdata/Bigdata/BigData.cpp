#include"BigData.h"
using namespace std;
#define MAX "9223372036854775807"
#define MAX_INT64 9223372036854775807
#define MIN_INT64 9223372036854775808



BigData::BigData(const INT64 data) :_value(data)
{
	INT64 tmp = _value;
	int VCount = 0;
	
	/*
		������ֵ��λ���Ա����ڴ���
	*/
	while (tmp)
	{
		tmp = tmp / 10;
		VCount++;
	}

	//����
	tmp = _value;
	int Index = 1;
	
	//��ֹ��λ��ɵĿռ䲻��Ԥ�ȶ����һλ
	_StrData.resize(VCount + 1);

	//ȷ��string�����ֵ�ķ���λ
	_StrData[0] = '+';
	if (_value < 0)
	{
		_StrData[0] = '-';
	}
	for (int i = VCount - 1; i >= 0; i--)
	{
		_StrData[i + 1] = tmp % 10 +'0';
		tmp = tmp / 10;
	}
}

BigData::BigData(const char * str) : _value(INIT)
{
	const char *cur = str;
	/*
		�жϴ��εķ���λ������
		��ʱ�����⼸�ִ��η�ʽ :
		"+123456789" "-123456789" "123456789"
	*/
	char symbol = '+';
	if (cur[0] == '-' || cur[0] == '+')
	{
		if (cur[0] == '-')
			symbol = '-';
		cur++;
	}


	/*
		������Ч������ǰ��0 ������ִ��Σ�
		"000000111223456789" 
	*/
	while (cur == 0)
		cur++;
	
	/*
		��������Ҫ�洢���ݵ�string����ռ�
		**�����һλΪ���Ǳ�������
	*/
	_StrData.resize(strlen(cur) + 1);
	_StrData[0] = symbol;

	int index = 1;
	while (*cur != '\0')
	{
		if (*cur > '9' || *cur < '0')
			break;
		_StrData[index++] = *cur++;
	}
	if (*cur != '\0')
		_StrData.resize(0);
	
	//��curָ���������λ���������ţ�
	cur = (char *)&_StrData[1];
	
	/*
	�ж��Ƿ��ܽ������long long���ʹ洢
	*/
	if (!INTisOverFlow(cur))
	{
		_value = 0;
		while (*cur != '\0')
		{
			_value = _value * 10 + *cur - '0';
			cur++;
		}
	}
}

/*�ж�long long �Ƿ����*/
bool BigData::INTisOverFlow(const char * str)
{
	/* �ж��Ƿ���������� */
	if (strlen(str) < strlen(MAX))
		return false;
	else
		return true;
}

BigData BigData:: operator+ (const BigData& big)
{
	/*
		 �����ͬ����ţ����������������������Ƿ������
	*/
	BigData sum;

	//�������ݾ������ �ҷ�����ͬ
	if (_StrData[0] == big._StrData[0])
	{

		//�������ݾ������
		if (_StrData.size() == 0 && big._StrData.size() == 0)
		{
			if (_StrData[0] == '+')
			{
				if (MAX_INT64 - _value >= big._value)
				{
					sum._value = _value + big._value;
					sum._StrData.resize(0);
				}
				else
				{
					sum._StrData = _ADD(big);
				}
			}
			else
			{
				if (MIN_INT64 - (-1)*_value >= (-1)*big._value)
				{
					sum._value = _value + big._value;
					sum._StrData.resize(0);
				}
				else
				{
					sum._StrData = _ADD(big);
					sum._value = INIT;
				}
			}
		}
		//���
		sum._StrData = _ADD(big);
		sum._value = INIT;
	}
	
	return sum;
}

/*���üӷ��㷨*/
string BigData::_ADD(const BigData& big)
{
	/*
		
	*/
	string sum;
	int Index = _StrData.size()-1;
	int Step = 0;
	int Short = big._StrData.size()-1;
	int flag = 1;
	if (_StrData.size() < big._StrData.size())
	{
		swap(Index, Short);
		flag = 2;

	}
	sum.resize(Index + 2); 
	sum[0] = _StrData[0];
	int tmp = 0;
	while (Index)
	{
		if (flag == 1)
		{
			if (Short != 0)
				tmp = (_StrData[Index] - '0') + (big._StrData[Short--] - '0') + Step;
			else
				tmp = _StrData[Index] - '0' + Step;
		}
		else
		{
			if (Short != 0)
				tmp = (big._StrData[Index] - '0') + (_StrData[Short--] - '0') + Step;
			else
				tmp = big._StrData[Index] - '0' + Step;
		}
		Step = tmp / 10;
		sum[Index + 1] = tmp % 10 + '0';
		Index--;
	}
	sum[1] = Step+'0';
	return sum;
}

ostream& operator<<(std::ostream& os, const BigData big)
{
	if (big._value != INIT)
		os << big._value;
	else
	{
		if (big._StrData[0] == '+')
		{
			size_t i = 1;
			while (big._StrData[i] == '0')
				i++;
			for (i; i < big._StrData.size(); i++)
			{
				os << big._StrData[i];
			}
		}
		else
			os << big._StrData;
	}
	if (big._value == INIT && big._StrData.size() == 0)
		os << "error!";
	return os;
}
