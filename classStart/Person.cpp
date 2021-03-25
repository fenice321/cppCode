#define _CRT_SECURE_NO_WARNINGS 1
#include "Person.h"
#include <iostream>
#include <cstring>
using namespace std;
//注意成员函数如果放在类外进行定义,成员函数名之前必须加  类名:: , 表明该函数是哪个类中的成员函数
//如果没有加,就相当于在全局作用域中定义了一个函数
void Person::InitPerson(const char* name, const char* gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
void Person::Eat()
{
	cout << "biajibiaji" << endl;
}
void Person::Sleep()
{
	cout << "ZZZ~~~~~~hhh~~~~~" << endl;
}
void Person::PrintPersonInfo()
{
	cout << _name << "-" << _gender << "-" << _age << endl;
}
