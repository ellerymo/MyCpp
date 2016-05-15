#include"BigData.h"
using namespace std;
#define MAX "9223372036854775807"
#define MAX_INT64 9223372036854775807
#define MIN_INT64 9223372036854775808



BigData::BigData(const long long data) :_value(data)
{
	INT64 tmp = _value;
	int VCount = 0;
	
	/*
		计算数值的位数以保存在串里
	*/
	while (tmp)
	{
		tmp = tmp / 10;
		VCount++;
	}

	//保存
	tmp = _value;
	int Index = 1;
	
	//防止进位造成的空间不足预先多分配一位
	_StrData.resize(VCount + 1);

	//确定string里的数值的符号位
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

BigData::BigData(const char* str) : _value(INIT)
{
	const char *cur = str;
	/*
		判断传参的符号位并跳过
		此时假设这几种传参方式 :
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
		忽略有效参数的前的0 例如此种传参：
		"000000111223456789" 
	*/
	while (cur == 0)
		cur++;
	
	/*
		给我们需要存储数据的string分配空间
		**多分配一位为我们保留符号
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
	
	//让cur指向大数的首位（不带符号）
	cur = (char *)&_StrData[1];
	
	/*
	判断是否能将其放入long long类型存储
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
BigData::BigData(const string str) :_StrData(str)
{}
/*判断long long 是否溢出*/
bool BigData::INTisOverFlow(const char * str)
{
	/* 判断是否溢出有歧义 */
	if (strlen(str) < strlen(MAX))
		return false;
	else
		return true;
}

BigData BigData:: operator+ (const BigData& big)
{
	/*
		 运算分同号异号，并且区分两个运算数据是否有溢出
	*/
	BigData sum;

	//两个数据均不溢出 且符号相同
	if (_StrData[0] == big._StrData[0])
	{

		//两个数据均不溢出
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
		//溢出
		sum._StrData = _ADD(big);
		sum._value = INIT;
	}
	else
	{
		//异号直接减法

	}
	
	return sum;
}

BigData BigData:: operator- (const BigData& big)
{
	//没有溢出
	if (_value != INIT && big._value != INIT)
	{
		//同号
		if (_StrData[0] == big._StrData[0])
		{
			if (_StrData[0] == '+' && MIN_INT64 + big._value <= _value)
				return BigData(_value - big._value);
			else if (_StrData[0] == '-' && MAX_INT64 + big._value >= _value)
				return BigData(_value - big._value);
			else
				return BigData(_SUB(big));
		}
		//异号
		else
		{
			if (_StrData[0] == '+' && MIN_INT64 + big._value >= _value)
				return BigData(_value - big._value);
			else if (_StrData[0] == '-' && MAX_INT64 + big._value <= _value)
				return BigData(_value - big._value);
			else
				return BigData(_SUB(big));
		}
	}

	//有溢出
	return BigData(_SUB(big));
}

/*内置加法算法*/
string BigData::_ADD(const BigData& big)
{
	
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

string BigData::_SUB(const BigData& big)
{
	string ret;
	int Step = 0;
	bool Th = true;
	//找最长的作为循环因子
	int left = _StrData.size();
	int right = big._StrData.size();
	if (right > left)
	{
		swap(left, right);
		Th = false;
	}
	
	ret.resize(left);
	ret[0] = _StrData[0];
	int Sub = 0;
	int Index1 = left - 1;
	int Index2 = right - 1;
	//异号
	if (_StrData[0] != big._StrData[0])
		ret = _ADD(big);
	//同号
	else
	{
		//都为正
		if (_StrData[0] == '+')
		{
			if (Th)
			{
				while (Index1 != 0)
				{
					if (Index2 > 0)
						Sub = (_StrData[Index1] - '0') - (big._StrData[Index2] - '0') + Step;
					else
						Sub = (_StrData[Index1] - '0')+ Step;
					if (Sub < 0)
					{
						Sub = (_StrData[Index1] - '0') + 10 - (big._StrData[Index2] - '0') + Step;
						Step = -1;
					}
					else
						Step = 0;
					ret[Index1] = Sub + '0';
					Index1--;
					Index2--;
				}
			}
			else
			{
				while (Index1 != 0)
				{
					if (Index2 > 0)
						Sub = (_StrData[Index2] - '0') - (big._StrData[Index1] - '0') + Step;
					else
						Sub = (_StrData[Index1] - '0') + Step;
					if (Sub < 0)
					{
						Sub = (_StrData[Index2] - '0') + 10 - (big._StrData[Index1] - '0') + Step;
						Step = -1;
					}
					else
						Step = 0;
					ret[Index1] = Sub + '0';
					Index1--;
					Index2--;
				}
			}
		}
		//都为负
		else
		{
			if (Th)
			{
				while (Index1 != 0)
				{
					if (Index2 > 0)
						Sub = (big._StrData[Index2] - '0') - (_StrData[Index1] - '0') + Step;
					else
						Sub = (_StrData[Index1] - '0') + Step;
					if (Sub < 0)
					{
						Sub = (big._StrData[Index2] - '0') + 10 - (_StrData[Index1] - '0') + Step;
						Step = -1;
					}
					else
						Step = 0;
					ret[Index1] = Sub + '0';
					Index1--;
					Index2--;
				}
			}
			else
			{
				while (Index1 != 0)
				{
					if (Index2 > 0)
						Sub = (big._StrData[Index1] - '0') - (_StrData[Index2] - '0') + Step;
					else
						Sub = (_StrData[Index1] - '0') + Step;
					if (Sub < 0)
					{
						Sub = (big._StrData[Index1] - '0') + 10 - (_StrData[Index2] - '0') + Step;
						Step = -1;
					}
					else
						Step = 0;
					ret[Index1] = Sub + '0';
					Index1--;
					Index2--;
				}
			}
		}

	}
	return ret;
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
