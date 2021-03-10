#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "DateClass.h"
using namespace std;
void Date::PrintD()
{
	cout << _year << "-" << _month << "-" << _day ;
	if (!(_year > 0 && _month > 0 && _month < 13 && _day > 0
		&& _day <= GetMonthDay(_year, _month)))
	{
		cout << "日期非法!";
	}
	cout << endl;
}
int Date::GetMonthDay(int year, int month)
{
	static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = daysArray[month];
	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
		day = 29;
	return day;
}
Date::Date(int year, int month, int day)//全缺省构造函数
{
	_year = year;
	_month = month;
	_day = day;
}
//Date::~Date()//析构函数
//{
//	cout << "~Date()" << endl;
//}
//Date::Date(const Date& d)//拷贝构造
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}
Date& Date::operator=(const Date& d)//赋值运算符重载
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
Date& Date::operator+=(const int& day)
{
	if (day < 0)
	{
		*this -= -day;
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(const int& day)
{
	//Date res(*this);
	//if (day >= 0)
	//{
	//	res._day += day;
	//	while (res._day > GetMonthDay(res._year, res._month))
	//	{
	//		res._day -= GetMonthDay(res._year, res._month);
	//		++res._month;
	//		if (13 == res._month)
	//		{
	//			res._month = 1;
	//			++res._year;
	//		}
	//	}
	//}
	//else
	//{
	//	res._day -= -day;
	//	while (res._day <= 0)
	//	{
	//		res._month--;
	//		if (res._month == 0)
	//		{
	//			res._month = 12;
	//			res._year--;
	//		}
	//		res._day += GetMonthDay(res._year, res._month);
	//	}
	//}
	//return res;

	Date res(*this);
	res += day;
	return res;
}
Date Date::operator-(const int& day)
{
	Date res(*this);
	res -= day;
	return res;
}
Date& Date::operator-=(const int& day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;//先--,后借位
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator++(int)
{
	Date res(*this);
	*this += 1;
	return res;
}
Date Date::operator--(int)
{
	Date res(*this);
	*this -= 1;
	return res;
}
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	else
		return false;
}
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator!=(const Date& d)
{
	return !((*this) == d);
}
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}
bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	Date dt;
	int flag = 1;
	int n = 0;
	if (max < min)
	{
		dt = max;
		max = min;
		min = dt;
		flag = -1;
	}
	while (max != min)
	{
		min++;
		n++;
	}
	return n * flag;
}