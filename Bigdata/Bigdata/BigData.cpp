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
	
	int Index = 1;
	
	//防止进位造成的空间不足预先多分配一位
	_StrData.resize(VCount + 1);

	//确定string里的数值的符号位
	_StrData[0] = '+';
	if (_value < 0)
	{
		_StrData[0] = '-';
		_value = _value*(-1);
	}
	tmp = _value;
	for (int i = VCount; i > 0; i--)
	{
		_StrData[i] = tmp % 10 +'0';
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

BigData::BigData(const string str) :_StrData(str), _value(INIT)
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
	///*
	//	 运算分同号异号，并且区分两个运算数据是否有溢出
	//*/
	//BigData sum;

	////两个数据均不溢出 且符号相同
	//if (_StrData[0] == big._StrData[0])
	//{

	//	//两个数据均不溢出
	//	if (_StrData.size() == 0 && big._StrData.size() == 0)
	//	{
	//		if (_StrData[0] == '+')
	//		{
	//			if (MAX_INT64 - _value >= big._value)
	//			{
	//				sum._value = _value + big._value;
	//				sum._StrData.resize(0);
	//			}
	//			else
	//			{
	//				sum._StrData = _ADD(_StrData,big._StrData);
	//			}
	//		}
	//		else
	//		{
	//			if (MIN_INT64 - (-1)*_value >= (-1)*big._value)
	//			{
	//				sum._value = _value + big._value;
	//				sum._StrData.resize(0);
	//			}
	//			else
	//			{
	//				sum._StrData = _ADD(_StrData, big._StrData);
	//				sum._value = INIT;
	//			}
	//		}
	//	}
	//	//溢出
	//	sum._StrData = _ADD(_StrData, big._StrData);
	//	sum._value = INIT;
	//}
	//else
	//{
	//	//异号直接减法
	//	if (_StrData[0] == '+')
	//		return _SUB(_StrData, big._StrData);
	//	else
	//		return _SUB(big._StrData, _StrData);
	//}
	string ret = _ADD(big._StrData, _StrData);
	return ret;
}

BigData BigData:: operator- (const BigData& big)
{

	return BigData(_SUB(_StrData, big._StrData));
}

BigData BigData:: operator* (const BigData& big)
{
	if (_value == 0 || big._value == 0)
		return BigData("0");
	return BigData(_MUL(_StrData, big._StrData));
}

BigData BigData:: operator/ (const BigData& big)
{
	return BigData(_DIV(_StrData,big._StrData));
}

/*内置加法算法*/
string BigData::_ADD(string s1, string s2)
{
	string sum;
	int Index = s1.size()-1;
	int Step = 0;
	int Short = s2.size()-1;
	int flag = 1;
	if (s1[0] != s2[0])
	{
		if (s1[0] == '-')
		{
			s1[0] = '+';
			return _SUB(s2, s1);
		}
		else
		{
			s2[0] = '+';
			return _SUB(s1, s2);
		}
	}
	if (s1.size() < s2.size())
	{
		swap(Index, Short);
		flag = 2;
	}
	sum.resize(Index + 2); 
	sum[0] = s1[0];
	int tmp = 0;
	while (Index)
	{
		if (flag == 1)
		{
			if (Short != 0)
				tmp = (s1[Index] - '0') + (s2[Short--] - '0') + Step;
			else
				tmp = s1[Index] - '0' + Step;
		}
		else
		{
			if (Short != 0)
				tmp = (s2[Index] - '0') + (s1[Short--] - '0') + Step;
			else
				tmp = s2[Index] - '0' + Step;
		}
		Step = tmp / 10;
		sum[Index + 1] = tmp % 10 + '0';
		Index--;
	}
	sum[1] = Step+'0';
	CleanZero(sum);
	return sum;
}

string BigData::_SUB(string s1, string s2)
{
	string ret;
	ret.resize(1);
	if (s1[0] != s2[0])
	{
		if (s1[0] == '-')
		{
			s1[0] = '+'; 
			ret=_ADD(s1, s2);
			ret[0] = '-';
		}
		else if (s2[0] == '-')
		{
			s2[0] = '+';
			ret = _ADD(s1, s2);
			ret[0] = '+';
		}
		return ret;
	}
	//同号相减
		if (s1.size() < s2.size())
		{
			swap(s1, s2);
			if (s1[0] == '+')
				ret[0] = '-';
			else
				ret[0] = s1[0];
		}
		else if (s1.size() == s2.size())
		{
			//调换减数及被减数
			if (strcmp((char*)s1.c_str() + 1, (char*)s2.c_str() + 1) == 0)
				return "+0";
			else if (strcmp((char*)s1.c_str() + 1, (char*)s2.c_str() + 1) < 0)
			{
				swap(s1, s2);
				if (s1[0] == '+')
					ret[0] = '-';
				else
					ret[0] = s1[0];
			}
			else
				ret[0] = s1[0];
		}
		else
			ret[0] = s1[0];
		
		ret.resize(s1.size());
		int j = s2.size() - 1;
		int sub = 0;
		int step = 0;
		for (int i = s1.size() - 1; i>0; i--)
		{
			if (j > 0)
			{
				sub = (s1[i] - '0') - (s2[j] - '0') + step;
			}
			else
				sub = s1[i]-'0'+step;
			if (sub < 0)
			{
				step = -1;
				sub = sub + 10;
			}
			else
				step = 0;
			ret[i] = sub + '0';
			j--;
		}
		
	return ret;
}

string BigData::_MUL(string s1, string s2)
{	
	int dis = 0;
	int left = s1.size()-1;
	int right = s2.size()-1;
	bool th = true;
	int mul = 0;
	int step = 0;
	if (left > right)
	{
		swap(left, right);
		th = false;
	}

	string ret;
	ret.resize(s1.size() + s2.size() - 1);
	int index = left + right;
	if (s1[0] == s2[0])
		ret[0] = '+';
	else
		ret[0] = '-';

	for (int i = left; i > 0; --i)
	{
		for (int j = right; j > 0; --j)
		{
			if (th)
			{
				mul = (s1[i] - '0')*(s2[j] - '0') + step;
			}
			else
			{
				mul = (s2[i] - '0')*(s1[j] - '0') + step;
			}
			if (dis != 0 && ret[index -dis] != '\0')
			{
				mul += ret[index - dis]-'0';
			}
			if (mul >= 10)
			{
				step = mul / 10;
				mul = mul % 10;
			}
			else
				step = 0;
			ret[index - dis] = mul + '0';
			index--;
		}
		ret[index - dis] += step + '0';
		dis++;
		index = left + right;
		step = 0;
	}

	CleanZero(ret);
	return ret;
}

int BigData::Bigger(string s1, string s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	if (len1 > len2)
		return 1;
	if (len1 == len2)
	{
		//s1大于s2
		if (s1.compare(s2) > 0)
			return 1;
		//等于
		else if (s1.compare(s2) == 0)
			return 0;
		//小于
		else
			return -1;
	}
	else
		return -1;
}

string BigData::_DIV(string s1,string s2)
{
	string result = "+0";
	int left = s1.size()-1;
	int right = s2.size()-1;
	
	if (left == right)
	{
		if (strcmp((char*)s1.c_str() + 1, (char*)s2.c_str() + 1) == 0)
			return "1";
		if (strcmp((char*)s1.c_str() + 1, (char*)s2.c_str() + 1) < 0)
			return "0";
	}

	if (s2 == "+0")
	{	
		cout << "error,We will end the prog!" << endl;
		getchar();
		exit(EXIT_FAILURE);
	}
	
	int index = 0;

	string onenumber = "+0";

	string  subtrahend="+";
	if (s1[0] == s2[0])
		result[0] = '+';
	else
		result[0] = '-';
	
	subtrahend[0] = '+';

	//初始化余数值
	for (int i = 1; i <= right; i++)
	{
		subtrahend.push_back(s1[i]);
	}
	
	index = left - right;
	bool chag1 = false;
	bool chag2 = false;
	if (s1[0] == '-')
	{
		s1[0] = '+';
		chag1 = true;
	}
	if (s2[0] == '-')
	{
		s2[0] = '+';
		chag2 = true;
	}
	for (int j = right; j <= left; j++)
	{	
		if (Bigger(subtrahend, s2) == -1)
		{
			string tmp = "+0";
			tmp[1] = s1[j];
			
			//余数
			subtrahend = _ADD(_MUL(subtrahend, "+10"), tmp);
			tmp = "0";
		}

		while (Bigger(subtrahend, s2) >= 0)
		{
			subtrahend = _SUB(subtrahend, s2);
			onenumber = _ADD(onenumber ,"+1");
			CleanZero(onenumber);
			CleanZero(subtrahend);
		} 
		result = _ADD(_MUL(result,"+10"), onenumber);
		onenumber = "+0";
	}
	if (chag1)
		s1[0] = '-';
	if (chag2)
		s2[0] = '-';
	if (s2[0] != s1[0])
		result[0] = '-';
	return result;
}


void BigData::CleanZero(string& st)
{
	if ((st[1] == '0' || st[1] == '\0') && st.size() != 2)
	{
		int Index = 1;
		while (st[Index] == '0' || st[Index] == '\0')
		{
			Index++;
			if (Index == st.size())
			{
				st = "+0";
				st.resize(2);
				return;
			}
		}
		int Slow = 1;
		while (st[Index] != '\0' )
		{
			st[Slow++] = st[Index++];
		}
		st.resize(Slow);

	}
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
			while (big._StrData[i] == '0' || big._StrData[i] == 0)
			{
				if (i == big._StrData.size()-1)
				{
					os << "0";
					return os;
				}
				i++;
			
			}
				

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

