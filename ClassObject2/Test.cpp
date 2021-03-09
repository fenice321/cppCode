#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
//int main()
//{
//	Date d1;
//	d1.PrintD();
//	Date d2(2021, 2, 29);//日期非法
//	d2.PrintD();
//	Date d3(2021, 13, 0);//日期非法
//	d3.PrintD();
//
//	Date d4(2021, 2, 2);//日期合法
//	d3.Add(100);//加一百天
//	d3.PrintD();
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//拷贝构造函数,也称复制构造函数,是一种特殊的构造函数,是构造函数的重载
//	//拷贝构造函数只有一个形参,一般是const修饰的类类型对象的引用形如"const className& 对象名",eg. const Date& d
//	//在用已存在的类类型创建新的对象时由编译器完成
//
//	//特性:
//	//1.拷贝构造函数是一种特殊的构造函数,是构造函数的函数重载
//	//2.拷贝构造函数的参数只有一个且必须使用引用传参,使用传值传参方式会引发无限递归调用
//	//3.若未显示定义拷贝构造函数,系统自动生成默认拷贝构造函数,默认拷贝构造函数对象内存按内存存储字节序完成拷贝,这种拷贝我们叫做浅拷贝或者值拷贝
//	//4.那么编译器生成的默认拷贝构造函数已经可以完成字节序的值拷贝了,我们还要自己实现吗?
//	//当然像日期类这样的类是没有必要的,只需值拷贝即可,
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	void PrintD()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void f(Date d)
//{
//	d.PrintD();
//}
//int main()
//{
//	//Date d1;//调用构造函数
//	//d1.PrintD();
//	//Date d2(d1);//调用拷贝构造函数
//	//d2.PrintD();
//
//	Date d1(2021, 3, 10);
//	d1.PrintD();
//	//d2的值想跟d1一样
//	//Date d2(2021, 3, 9);//方法一:复制d1的初始值
//	Date d2(d1);//方法二:调用拷贝构造函数复制对象d1给d2,且Date d2(d1)等价Date d2 = d1;都是拷贝构造
//	//Date d2 = d1;
//	d2.PrintD();
//	f(d1);//f函数调用传参是一个自定义类型的对象,运行时先调用拷贝构造函数Date(const Date& d),拷贝构造调用完毕再进入f函数体内运行
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	void PrintD();
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Date::PrintD()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main()
//{
//	Date d1(2021, 3, 10);
//	d1.PrintD();
//
//	//这里调用默认拷贝构造函数
//	Date d2(d1);
//	d2.PrintD();
//	//默认拷贝构造函数复制成功,说明像日期类这样的类是不需要写拷贝构造的,默认生成的拷贝构造函数就可以完成拷贝
//
//	//这里调用默认拷贝构造函数
//	Date d3 = d2;
//	d3.PrintD();
//	return 0;
//}

//#define DEFAULT_STACK_CAPACITY 4
//class Stack
//{
//public:
//	Stack(int capacity = DEFAULT_STACK_CAPACITY)
//	{
//		_a = (int*)malloc(capacity * sizeof(int));
//		if (nullptr == _a)
//		{
//			puts(strerror(errno));
//			exit(-1);
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	Stack(const Stack& st)
//	{
//		_size = st._size;
//		_capacity = st._capacity;
//		_a = (int*)malloc(st._capacity * sizeof(int));
//		if (nullptr == _a)
//		{
//			puts(strerror(errno));
//			exit(-1);
//		}
//	}
//	~Stack()
//	{
//		if (nullptr != _a)
//		{
//			free(_a);
//			_a = nullptr;
//			_size = 0;
//			_capacity = 0;
//		}
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//int main()
//{
//	//有时候系统默认生成的拷贝构造函数可以使用,有时候不行,我们得自己写
//	//拷贝构造默认完成这种值拷贝行为叫做浅拷贝,像日期类这样的类用浅拷贝就可以了,像栈这样的类浅拷贝不行,程序会崩溃
//
//	//程序崩溃原因分析:
//	//自己没写拷贝构造函数,系统默认生成自己的拷贝构造函数,而系统默认生成的拷贝构造是单纯的值拷贝(浅拷贝)--->只针对一些类似日期类
//	//这样的只需要值的有用,对于数据结构的类拷贝需要自己写拷贝构造函数,以Stack类为例
//	//Stack类中有申请资源,第一步调用构造函数初始化st1,第二步调用系统默认拷贝构造函数(值拷贝),将st1对象的值拷到st2中,指针值也是如此
//	//第三步调用系统默认拷贝构造函数(值拷贝),将对象st1的值拷贝到st3中,指针值也是如此
//	//上面三步导致一段堆区有三个指针指向它,然后第四步,三个对象生命周期结束,出作用域,调用类中的析构函数,调用顺序是后实例化的对象先调用析构
//	//导致一段堆区的内存资源被释放了3次,系统崩溃
//	//解决方法:自己写拷贝构造函数,不用默认的拷贝构造函数
//	Stack st1;
//	Stack st2(st1);//系统默认生成的拷贝构造函数是值拷贝
//	Stack st3 = st1;
//	//有3个对象被实例化出来,出作用域后,析构函数被调用,后实例化的对象先调用析构函数,即调用析构函数的对象的顺序是st3 st2 st1
//	return 0;
//}

//class String
//{
//public:
//	String(const char* str = "Jack")
//	{
//		_str = (char*)malloc(strlen(str + 1) * sizeof(char));
//		if (nullptr == _str)
//		{
//			puts(strerror(errno));
//			exit(-1);
//		}
//		strcpy(_str, str);
//	}
//	String(const String& s)
//	{
//		_str = (char*)malloc(strlen(s._str + 1) * sizeof(char));
//		if (nullptr == _str)
//		{
//			puts(strerror(errno));
//			exit(-1);
//		}
//		strcpy(_str, s._str);
//	}
//	~String()
//	{
//		free(_str);
//		_str = nullptr;
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	String s1("Fenice");
//	String s2(s1);
//	return 0;
//}

//函数重载:函数名相同,参数不同
//运算符重载:使自定义类型也能进行运算符操作就像内置类型一样(注意的是自定义类型默认是不能进行运算符操作的,要有运算符操作必须进行重载)

//C++为了增强代码的可读性引入了运算符操作,运算符重载是有特殊的函数名的函数,也具有其返回值类型,函数名字以及参数列表,其返回值参数列表和普通函数类似
//总的说运算符重载是一个特殊的函数,函数名是operator+操作符,形如operator+,operator==,函数返回值和函数参数列表与普通函数类似
//形如:bool operator==(arg1, arg2,....)--->returnType operator操作符(arg1, arg2,...)

//注意:
//1.不能通过连接其他符号来创建新的操作符,比如operator@就是非法的
//2.sizeof, .* , ., ?:, ::这5个操作符不能重载
//3.运算符重载写成成员函数以后参数会少一个,因为作为类的成员函数的重载函数时,
//其形参有一个隐藏的className* const this指针,预定了第一个位置,所以形参看起来比操作数数目少一个


//赋值运算符重载
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	//~Date()
//	//{
//	//	cout << "~Date()" << endl;
//	//}
//	void PrintD()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//int GetYear()
//	//{
//	//	return _year;
//	//}
//	//int GetMonth()
//	//{
//	//	return _month;
//	//}
//	//int GetDay()
//	//{
//	//	return _day;
//	//}
//
//	//bool operator==(const Date& d1, const Date& d2)//成员函数中运算符重载,参数太多,error
//	//{
//	//	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//	//}
//
//	//bool operator==(Date* const this, const Date& d2)
//	//这里要注意的是,左操作数是this指针,指向的是调用函数的对象,而这个指针是隐藏的,所以只需一个参数就可以了
//	bool operator==(const Date& d2)//注意有一个隐藏的this指针Date* const this,这个this指针预定了第一个位置,且必须在第一个位置
//	{
//		return _year == d2._year && _month == d2._month && _day == d2._day;
//	}
//private://全局的operator==需要成员变量变成公有的,封装性保证不了
//	int _year;
//	int _month;
//	int _day;
//};
////全局的operator==需要成员变量变成公有的,封装性保证不了
////这里可以用友元函数解决,或者干脆重载成成员函数
////bool operator==(const Date& d1, const Date& d2)
////{
////	//return d1.GetYear() == d2.GetYear() && d1.GetMonth() == d2.GetMonth() && d1.GetDay == d2.GetDay;
////	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
////}
////bool operatorFunc(const Date& d1, const Date& d2)//重载类似的函数,但是不能进行方便的运算符调用
////{
////	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
////}
//int main()
//{
//	Date d1(2021, 2, 4);
//	Date d2(d1);
//	//d1 == d2;//自定义类型默认不能进行运算符操作
//
//	cout << d1.operator==(d2) << endl;//可以直接作为函数调用,编译器就是这样调用的
//	cout << (d1 == d2) << endl;//方便使用,直接用运算符
//	//cout << operatorFunc(d1, d2) << endl;
//
//	//等价于调用d1.operator==(&d1, d2);--->但是不能写出来
//	d1.operator==(d2);
//	//等价于调用
//	cout << (d1 == d2) << endl;//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//~Date()
//	//{
//	//	cout << "~Date()" << endl;
//	//}
//	bool operator==(const Date& d)
//	{
//		return _year == d._year && _month == d._month && _day == d._day;
//	}
//	//int GetYear()
//	//{
//	//	return _year;
//	//}
//	//int GetMonth()
//	//{
//	//	return _month;
//	//}
//	//int GetDay()
//	//{
//	//	return _day;
//	//}
//
//	//operator>
//	//d1 > d2;
//	//d1.operator>(d2);
//	//d1.operator>(&d1, d2);
//	bool operator>(const Date& d)
//	{
//		if (_year > d._year)
//			return true;
//		else if (_year == d._year && _month > d._month)
//			return true;
//		else  if (_year == d._year && _month == d._month && _day > d._day)
//			return true;
//		else
//			return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////全局中重载,封装性遭到了破坏,后面的友元函数可以解决这个问题,但是还是破坏了封装,类中运算符重载比较好
////bool operator==(const Date& d1, const Date& d2)
////{
////	return d1._day == d2._day && d1._month == d2._month && d1._year == d2._year;
////	//return d1._day == d2._day && d1._month == d2._month && d1._year == d2._year;
////}
////bool operatorFunc(const Date& d1, const Date& d2)
////{
////	return d1._day == d2._day && d1._month == d2._month && d1._year == d2._year;
////	//return d1._day == d2._day && d1._month == d2._month && d1._year == d2._year;
////}
//int main()
//{
//	Date d1(2021, 3, 9);
//	Date d2(d1);
//	//cout << operatorFunc(d1, d2) << endl;//重载类似的函数实现
//	//cout << operator==(d1, d2) << endl;//编译器就是这样的
//	////等价	函数名为operator==,入参为d1, d2,返回值为bool
//	//cout << (d1 == d2) << endl;
//
//	//cout << d1.operator==(&d1, d2) << endl;--->不能写出来
//	//等价于
//	//cout << d1.operator==(d2) << endl;
//	////等价于
//	//cout << (d1 == d2) << endl;
//
//	cout << (d1 > d2) << endl;
//	//等价于
//	cout << d1.operator>(d2) << endl;
//	//等价于cout << d1.operator>(&d1, d2) << endl;--->不能写出来 
//	return 0;
//}

//类中有六大默认成员函数
//其中四个很重要
//1.构造函数
//2.析构函数
//3.拷贝构造函数
//4.赋值运算符重载

//赋值运算符重载
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//赋值运算符重载函数
//	//d2 = d3
//	//void operator=(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}//不够,要能支持连续赋值,有返回值,一般返回赋值号左边的值类型
//
//	//这个引用,和			这个引用能减少两次拷贝构造
//	//Date& operator=(const Date& d)
//	//{
//	//	if (this != &d)
//	//	{
//	//		_year = d._year;
//	//		_month = d._month;
//	//		_day = d._day;
//	//	}
//	//	return *this;//*this就是d2,d2是main中的局部对象,生命周期等于进程,所以d2出了这个赋值运算符重载函数还在,能传引用出来
//	//}
//	//operator>
//	//bool operator>(const Date& d)
//	//{
//	//	if (_year > d._year)
//	//		return true;
//	//	else if (_year == d._year && _month > d._month)
//	//		return true;
//	//	else if (_year == d._year && _month == d._month && _day == d._day)
//	//		return true;
//	//	else
//	//		return false;
//	//}
//	//operator==
//	//bool operator==(const Date& d)
//	//{
//	//	return _year == d._year && _month == d._month && _day == d._day;
//	//}
//
//	//~Date()
//	//{
//	//	cout << "~Date()" << endl;
//	//}
//	//Date(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//
//	void PrintD()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////operator=跟拷贝构造类似,我们不实现,编译器也会默认生成一份,operator=,他会完成按字节的值拷贝(浅拷贝),对于Date类,默认生成
////的拷贝构造函数和operator=都是可以用的,其实不需要去实现,但是
////像Stack这样的类,默认生成拷贝构造和operator=都是值拷贝(浅拷贝),都不能使用,都会崩溃,需要自己实现深拷贝
//int main()
//{
//	Date d1(2021, 2, 4);
//	Date d2 = d1;//初始化,走的是构造器
//	Date d3(2021, 3, 1);
//	d1 = d2 = d3;//两个对象创建出来了,赋值运算符重载
//
//	d2 = d2;//自己给自己赋值的时候,需要特殊处理一下,以节省效率
//	d1.PrintD();
//	return 0;
//}

//class String
//{
//public:
//	String(const char* str = "")
//	{
//		_str = (char*)malloc((strlen(str) + 1) * sizeof(char));
//		if (nullptr == _str)
//		{
//			puts(strerror(errno));
//			exit(-1);
//		}
//		strcpy(_str, str);
//	}
//	//自己实现的赋值运算符重载深拷贝
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			_str = (char*)malloc((strlen(s._str) + 1) * sizeof(char));
//			if (nullptr == _str)
//			{
//				puts(strerror(errno));
//				exit(-1);
//			}
//			strcpy(_str, s._str);
//		}
//		return *this;
//	}
//	//浅拷贝的赋值运算符重载,写了和没写的崩溃错误是一样的,都是崩溃在了析构函数中,一段堆空间释放了两次导致系统崩溃
//	//String& operator=(const String& s)
//	//{
//	//	if (this != &s)
//	//	{
//	//		_str = s._str;
//	//	}
//	//	return *this;
//	//}
//	~String()
//	{
//		if (_str != nullptr)
//		{
//			free(_str);
//			_str = nullptr;
//		}
//	}
//private:
//	char* _str;
//};
//int main()
//{
//	String s1("hello");
//	String s2("world");
//	s1 = s2;
//	return 0;
//}

int main()
{
	Date d1(2021, 2, 3);
	d1 += 100;
	d1.PrintD();
	//Date d2(2021, 2, 29);//非法
	//d2.PrintD();

	//Date d3(2021, 13, 0);//非法
	//d3.PrintD();

	//Date d4(2020, 2, 29);//合法
	//d4.PrintD();


	return 0;
}