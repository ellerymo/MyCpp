#pragma once
#include<iostream>
#include<cassert>
#include<string>

#define  INIT 0xCCCCCCCCCCCCCCCC

using INT64 = long long;
class BigData
{
	friend std::ostream& operator << (std::ostream& os, const BigData big);
private:
	//用于存放没有溢出的数据
	INT64 _value;

	std::string _StrData;

public:
	BigData(const long long data);
	BigData(const char* str = "");
	BigData(const std::string str);
	BigData operator+ (const BigData& big);
	BigData operator- (const BigData& big);
	

private:
	bool INTisOverFlow(const char * str);
	std::string _ADD(const BigData& big);
	std::string _SUB(const BigData& big);

};