#pragma once
#include <iostream>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month);
	void PrintD();
	//全缺省参数构造函数--->在该类有用
	Date(int year = 1900, int month = 1, int day = 1);
	//拷贝构造函数--->在该类没用--->可以不写,使用默认的
	Date(const Date& d);
	//赋值运算符重载--->在该类没用--->可以不写,使用默认的
	Date& operator=(const Date& d);
	//析构函数--->在该类没用--->可以不写,使用默认的
	~Date();

	//日期+=天数
	Date& operator+=(const int& day);
	//日期+天数
	//Date& operator+(const int& day);
	//日期-天数

	//日期-=天数

	//前置++

	//后置++

	//前置--

	//后置--

	// > 运算符重载

	// == 运算符重载

	// >= 运算符重载

	// < 运算符重载

	// <= 运算符重载

	// != 运算符重载

	//日期-日期 返回天数

private:
	int _year;
	int _month;
	int _day;
};
