#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"
int Date::GetMonthDay(int year, int month)
{
	//if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	//{
	//	if (month == 4 || month == 6 || month == 9 || month == 11)
	//		return 30;
	//	else if (month == 2)
	//		return 29;
	//	else
	//		return 31;
	//}
	//else
	//{
	//	if (month == 4 || month == 6 || month == 9 || month == 11)
	//		return 30;
	//	else if (month == 2)
	//		return 28;
	//	else
	//		return 31;
	//}

	//这个GetMonthDay函数需要频繁调用,设置为静态的数组,节省效率
	static int daysArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = daysArr[month];

	//先决条件是month==2,也是为了提高效率
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}
	return day;
}
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
	if (!(year >= 0 && month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month)))
	{
		cout << "日期非法" << endl;
	}
}
void Date::PrintD()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
Date::~Date()
{
	cout << "~Date()" << endl;
}

Date& Date::operator+=(const int& day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}