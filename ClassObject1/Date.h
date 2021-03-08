#pragma once
#include <iostream>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month);
	Date(int year = 1900, int month = 1, int day = 1);
	void PrintD();
private:
	int _year;
	int _month;
	int _day;
};