#define _CRT_SECURE_NO_WARNINGS 1
#include "DateClass.h"
#include <iostream>
using namespace std;
void TestDateClass()
{
	Date d1(2021, 2, 3);
	d1.PrintD();

	Date ret = d1 + 100;
	ret.PrintD();
	
	d1 += 100;
	d1.PrintD();

	ret = d1 + -100;
	ret.PrintD();
	d1++;
	++d1;
	//Date d2(2021, 2, 29);
	//d2.PrintD();

	Date d3(2021, 2, 3);
	Date d4(2021, 8, 1);
	cout << d3.operator-(d4) << endl;
	cout << d3 - d4 << endl;
	cout << d4 - d3 << endl;
}
void TestIOstream()
{
	int i = 0;
	//cin/cout是两个类类型对象,对应的类名分别是istream/ostream,是在std命名空间中定义的全局对象
	cout << i;
	//等价于
	cout.operator<<(i);
	//等价于cout.operator<<(ostream& this, int i);
	cout << "I love China";
	//等价于cout.operator<<(ostream& this, const void* str);
	cout.operator<<("I love China");
	//为什么能自动识别对象的类型?--->在运算符重载的基础上,进行了函数重载

	//缺省参数的好处---->让一些函数更好用,尤其是类似构造函数这样的初始化函数
	//eg.	Date(int year = 1900, int month = 1, int day = 1);

	//函数重载(考试重点)
	//a.是什么函数重载
	//b.为什么C语言不支持函数重载,而C++支持--->C++底层用了命名倾轧技术,将相同函数名但参数不同的函数的函数名处理成不同的函数名
	//而C语言没有用这个技术,不能重载
	//extern的作用:extern "C",使用C方法处理函数名,不使用命名倾轧
	//应用场景:C中用到C++中的库函数接口,将接口函数extern "C"修饰即可

	//5.引用(重点)
	//a.引用的基本使用语法
	//b.引用做参数和返回值
	//c.引用和指针的区别
	//1.引用+1,指针+1
	//2.sizeof(引用),sizeof(指针)
	//3.NULL指针,没NULL引用
	//4.引用是给一个变量取别名,指针是保存一个变量的首字节地址
	//5.指针指向一个变量后可以更改指向另一个变量,引用去了一个变量的别名,不能再去另一个变量的别名
	//6.指针可以不初始化,引用必须初始化
	//7.可以有多级指针,没有多级引用
	//8.引用是对指针的包装,比指针更好用,更安全
	//9.指针需要解引用访问指向的变量,引用直接可以访问取别名的变量
	//C++中,自定义类型对象传参,尽量不要使用传值传参,尽量使用引用传参,这样可以减少一次拷贝构造,提高效率
}
int main()
{
	TestDateClass();
	//TestIOstream();
	return 0;
}