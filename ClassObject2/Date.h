#pragma once
#include <iostream>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month);
	void PrintD();
	//ȫȱʡ�������캯��--->�ڸ�������
	Date(int year = 1900, int month = 1, int day = 1);
	//�������캯��--->�ڸ���û��--->���Բ�д,ʹ��Ĭ�ϵ�
	Date(const Date& d);
	//��ֵ���������--->�ڸ���û��--->���Բ�д,ʹ��Ĭ�ϵ�
	Date& operator=(const Date& d);
	//��������--->�ڸ���û��--->���Բ�д,ʹ��Ĭ�ϵ�
	~Date();

	//����+=����
	Date& operator+=(const int& day);
	//����+����
	//Date& operator+(const int& day);
	//����-����

	//����-=����

	//ǰ��++

	//����++

	//ǰ��--

	//����--

	// > ���������

	// == ���������

	// >= ���������

	// < ���������

	// <= ���������

	// != ���������

	//����-���� ��������

private:
	int _year;
	int _month;
	int _day;
};
