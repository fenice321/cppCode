#pragma once
class Date
{
public:
	void PrintD();
	int GetMonthDay(int year, int month);
	Date(int year = 1900, int month = 1, int day = 1);//全缺省构造函数
	//~Date();//析构函数
	//Date(const Date& d);//拷贝构造
	Date& operator=(const Date& d);//赋值运算符重载

	//任何表达式是有值的

	//天数+日期,重载+
	//注意:重载+时的几个问题
	//1.对象j = i + 2有一个返回值,j得到返回值,但是加完后i不变,
	//2.对象j = i + -2易错,成为bug
	Date operator+(const int& day);
	//日期+=天数,重载+=
	Date& operator+=(const int& day);
	//日期-天数,重载-
	Date operator-(const int& day);
	//日期-=天数,重载-=
	Date& operator-=(const int& day);
	//重载前置++
	Date& operator++();
	//重载后置++,
	//C++中默认的重载前置++,没有参数,后置++为了和它区分,人为的加了一个参数,这里的参数无用,构成函数重载
	//传参可以认为是operator++(&d, 0);
	//也可以是operator++(&d, 10000);
	Date operator++(int);
	//重载前置--
	Date& operator--();
	//重载后置--
	Date operator--(int);
	//重载>
	bool operator>(const Date& d);
	//重载<
	bool operator<(const Date& d);
	//重载==
	bool operator==(const Date& d);
	//重载!=
	bool operator!=(const Date& d);
	//重载>=
	bool operator>=(const Date& d);
	//重载<=
	bool operator<=(const Date& d);
	//日期-日期 返回天数
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};