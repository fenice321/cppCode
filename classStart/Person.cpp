#define _CRT_SECURE_NO_WARNINGS 1
#include "Person.h"
#include <iostream>
#include <cstring>
using namespace std;
//ע���Ա�����������������ж���,��Ա������֮ǰ�����  ����:: , �����ú������ĸ����еĳ�Ա����
//���û�м�,���൱����ȫ���������ж�����һ������
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
