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
//	Date d2(2021, 2, 29);//���ڷǷ�
//	d2.PrintD();
//	Date d3(2021, 13, 0);//���ڷǷ�
//	d3.PrintD();
//
//	Date d4(2021, 2, 2);//���ںϷ�
//	d3.Add(100);//��һ����
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
//	//�������캯��,Ҳ�Ƹ��ƹ��캯��,��һ������Ĺ��캯��,�ǹ��캯��������
//	//�������캯��ֻ��һ���β�,һ����const���ε������Ͷ������������"const className& ������",eg. const Date& d
//	//�����Ѵ��ڵ������ʹ����µĶ���ʱ�ɱ��������
//
//	//����:
//	//1.�������캯����һ������Ĺ��캯��,�ǹ��캯���ĺ�������
//	//2.�������캯���Ĳ���ֻ��һ���ұ���ʹ�����ô���,ʹ�ô�ֵ���η�ʽ���������޵ݹ����
//	//3.��δ��ʾ���忽�����캯��,ϵͳ�Զ�����Ĭ�Ͽ������캯��,Ĭ�Ͽ������캯�������ڴ水�ڴ�洢�ֽ�����ɿ���,���ֿ������ǽ���ǳ��������ֵ����
//	//4.��ô���������ɵ�Ĭ�Ͽ������캯���Ѿ���������ֽ����ֵ������,���ǻ�Ҫ�Լ�ʵ����?
//	//��Ȼ������������������û�б�Ҫ��,ֻ��ֵ��������,
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
//	//Date d1;//���ù��캯��
//	//d1.PrintD();
//	//Date d2(d1);//���ÿ������캯��
//	//d2.PrintD();
//
//	Date d1(2021, 3, 10);
//	d1.PrintD();
//	//d2��ֵ���d1һ��
//	//Date d2(2021, 3, 9);//����һ:����d1�ĳ�ʼֵ
//	Date d2(d1);//������:���ÿ������캯�����ƶ���d1��d2,��Date d2(d1)�ȼ�Date d2 = d1;���ǿ�������
//	//Date d2 = d1;
//	d2.PrintD();
//	f(d1);//f�������ô�����һ���Զ������͵Ķ���,����ʱ�ȵ��ÿ������캯��Date(const Date& d),���������������ٽ���f������������
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
//	//�������Ĭ�Ͽ������캯��
//	Date d2(d1);
//	d2.PrintD();
//	//Ĭ�Ͽ������캯�����Ƴɹ�,˵�������������������ǲ���Ҫд���������,Ĭ�����ɵĿ������캯���Ϳ�����ɿ���
//
//	//�������Ĭ�Ͽ������캯��
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
//	//��ʱ��ϵͳĬ�����ɵĿ������캯������ʹ��,��ʱ����,���ǵ��Լ�д
//	//��������Ĭ���������ֵ������Ϊ����ǳ����,������������������ǳ�����Ϳ�����,��ջ��������ǳ��������,��������
//
//	//�������ԭ�����:
//	//�Լ�ûд�������캯��,ϵͳĬ�������Լ��Ŀ������캯��,��ϵͳĬ�����ɵĿ��������ǵ�����ֵ����(ǳ����)--->ֻ���һЩ����������
//	//������ֻ��Ҫֵ������,�������ݽṹ���࿽����Ҫ�Լ�д�������캯��,��Stack��Ϊ��
//	//Stack������������Դ,��һ�����ù��캯����ʼ��st1,�ڶ�������ϵͳĬ�Ͽ������캯��(ֵ����),��st1�����ֵ����st2��,ָ��ֵҲ�����
//	//����������ϵͳĬ�Ͽ������캯��(ֵ����),������st1��ֵ������st3��,ָ��ֵҲ�����
//	//������������һ�ζ���������ָ��ָ����,Ȼ����Ĳ�,���������������ڽ���,��������,�������е���������,����˳���Ǻ�ʵ�����Ķ����ȵ�������
//	//����һ�ζ������ڴ���Դ���ͷ���3��,ϵͳ����
//	//�������:�Լ�д�������캯��,����Ĭ�ϵĿ������캯��
//	Stack st1;
//	Stack st2(st1);//ϵͳĬ�����ɵĿ������캯����ֵ����
//	Stack st3 = st1;
//	//��3������ʵ��������,���������,��������������,��ʵ�����Ķ����ȵ�����������,���������������Ķ����˳����st3 st2 st1
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

//��������:��������ͬ,������ͬ
//���������:ʹ�Զ�������Ҳ�ܽ������������������������һ��(ע������Զ�������Ĭ���ǲ��ܽ��������������,Ҫ����������������������)

//C++Ϊ����ǿ����Ŀɶ������������������,�����������������ĺ������ĺ���,Ҳ�����䷵��ֵ����,���������Լ������б�,�䷵��ֵ�����б����ͨ��������
//�ܵ�˵�����������һ������ĺ���,��������operator+������,����operator+,operator==,��������ֵ�ͺ��������б�����ͨ��������
//����:bool operator==(arg1, arg2,....)--->returnType operator������(arg1, arg2,...)

//ע��:
//1.����ͨ���������������������µĲ�����,����operator@���ǷǷ���
//2.sizeof, .* , ., ?:, ::��5����������������
//3.���������д�ɳ�Ա�����Ժ��������һ��,��Ϊ��Ϊ��ĳ�Ա���������غ���ʱ,
//���β���һ�����ص�className* const thisָ��,Ԥ���˵�һ��λ��,�����βο������Ȳ�������Ŀ��һ��


//��ֵ���������
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
//	//bool operator==(const Date& d1, const Date& d2)//��Ա���������������,����̫��,error
//	//{
//	//	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//	//}
//
//	//bool operator==(Date* const this, const Date& d2)
//	//����Ҫע�����,���������thisָ��,ָ����ǵ��ú����Ķ���,�����ָ�������ص�,����ֻ��һ�������Ϳ�����
//	bool operator==(const Date& d2)//ע����һ�����ص�thisָ��Date* const this,���thisָ��Ԥ���˵�һ��λ��,�ұ����ڵ�һ��λ��
//	{
//		return _year == d2._year && _month == d2._month && _day == d2._day;
//	}
//private://ȫ�ֵ�operator==��Ҫ��Ա������ɹ��е�,��װ�Ա�֤����
//	int _year;
//	int _month;
//	int _day;
//};
////ȫ�ֵ�operator==��Ҫ��Ա������ɹ��е�,��װ�Ա�֤����
////�����������Ԫ�������,���߸ɴ����سɳ�Ա����
////bool operator==(const Date& d1, const Date& d2)
////{
////	//return d1.GetYear() == d2.GetYear() && d1.GetMonth() == d2.GetMonth() && d1.GetDay == d2.GetDay;
////	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
////}
////bool operatorFunc(const Date& d1, const Date& d2)//�������Ƶĺ���,���ǲ��ܽ��з�������������
////{
////	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
////}
//int main()
//{
//	Date d1(2021, 2, 4);
//	Date d2(d1);
//	//d1 == d2;//�Զ�������Ĭ�ϲ��ܽ������������
//
//	cout << d1.operator==(d2) << endl;//����ֱ����Ϊ��������,�����������������õ�
//	cout << (d1 == d2) << endl;//����ʹ��,ֱ���������
//	//cout << operatorFunc(d1, d2) << endl;
//
//	//�ȼ��ڵ���d1.operator==(&d1, d2);--->���ǲ���д����
//	d1.operator==(d2);
//	//�ȼ��ڵ���
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
////ȫ��������,��װ���⵽���ƻ�,�������Ԫ�������Խ���������,���ǻ����ƻ��˷�װ,������������رȽϺ�
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
//	//cout << operatorFunc(d1, d2) << endl;//�������Ƶĺ���ʵ��
//	//cout << operator==(d1, d2) << endl;//����������������
//	////�ȼ�	������Ϊoperator==,���Ϊd1, d2,����ֵΪbool
//	//cout << (d1 == d2) << endl;
//
//	//cout << d1.operator==(&d1, d2) << endl;--->����д����
//	//�ȼ���
//	//cout << d1.operator==(d2) << endl;
//	////�ȼ���
//	//cout << (d1 == d2) << endl;
//
//	cout << (d1 > d2) << endl;
//	//�ȼ���
//	cout << d1.operator>(d2) << endl;
//	//�ȼ���cout << d1.operator>(&d1, d2) << endl;--->����д���� 
//	return 0;
//}

//����������Ĭ�ϳ�Ա����
//�����ĸ�����Ҫ
//1.���캯��
//2.��������
//3.�������캯��
//4.��ֵ���������

//��ֵ���������
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
//	//��ֵ��������غ���
//	//d2 = d3
//	//void operator=(const Date& d)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}//����,Ҫ��֧��������ֵ,�з���ֵ,һ�㷵�ظ�ֵ����ߵ�ֵ����
//
//	//�������,��			��������ܼ������ο�������
//	//Date& operator=(const Date& d)
//	//{
//	//	if (this != &d)
//	//	{
//	//		_year = d._year;
//	//		_month = d._month;
//	//		_day = d._day;
//	//	}
//	//	return *this;//*this����d2,d2��main�еľֲ�����,�������ڵ��ڽ���,����d2���������ֵ��������غ�������,�ܴ����ó���
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
////operator=��������������,���ǲ�ʵ��,������Ҳ��Ĭ������һ��,operator=,������ɰ��ֽڵ�ֵ����(ǳ����),����Date��,Ĭ������
////�Ŀ������캯����operator=���ǿ����õ�,��ʵ����Ҫȥʵ��,����
////��Stack��������,Ĭ�����ɿ��������operator=����ֵ����(ǳ����),������ʹ��,�������,��Ҫ�Լ�ʵ�����
//int main()
//{
//	Date d1(2021, 2, 4);
//	Date d2 = d1;//��ʼ��,�ߵ��ǹ�����
//	Date d3(2021, 3, 1);
//	d1 = d2 = d3;//�������󴴽�������,��ֵ���������
//
//	d2 = d2;//�Լ����Լ���ֵ��ʱ��,��Ҫ���⴦��һ��,�Խ�ʡЧ��
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
//	//�Լ�ʵ�ֵĸ�ֵ������������
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
//	//ǳ�����ĸ�ֵ���������,д�˺�ûд�ı���������һ����,���Ǳ�����������������,һ�ζѿռ��ͷ������ε���ϵͳ����
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
	//Date d2(2021, 2, 29);//�Ƿ�
	//d2.PrintD();

	//Date d3(2021, 13, 0);//�Ƿ�
	//d3.PrintD();

	//Date d4(2020, 2, 29);//�Ϸ�
	//d4.PrintD();


	return 0;
}