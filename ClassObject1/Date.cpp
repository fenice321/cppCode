#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "Date.h"
using namespace std;
Date::Date(int year, int month, int day)
{
	cout << "Date(int year, int month, int day)" << endl;
	//if (year >= 0 && month > 0 && month < 13 && day > 0 && day < 32)//不好用
	if (year >= 0 && month > 0 && month < 13 && day > 0 && day < this->GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法" << endl;
	}
}
void Date::PrintD()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}