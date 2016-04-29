#include<iostream>
using namespace std;

struct TrueType
{
	bool Get()
	{
		return true;
	}
};
struct FalseType
{
	bool Get()
	{
		return false;
	}
};

template <class T>
struct Traits
{
	typedef FalseType IsPODType;
};

template <>
struct Traits<int>
{
	typedef TrueType IsPODType;
};
template <>
struct Traits<char>
{
	typedef TrueType IsPODType;
};
template <>
struct Traits<float>
{
	typedef TrueType IsPODType;
};
template <>
struct Traits<unsigned>
{
	typedef TrueType IsPODType;
};
template <>
struct Traits<long>
{
	typedef TrueType IsPODType;
};
template <>
struct Traits<double>
{
	typedef TrueType IsPODType;
};
