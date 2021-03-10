#pragma once
class Date
{
public:
	void PrintD();
	int GetMonthDay(int year, int month);
	Date(int year = 1900, int month = 1, int day = 1);//ȫȱʡ���캯��
	//~Date();//��������
	//Date(const Date& d);//��������
	Date& operator=(const Date& d);//��ֵ���������

	//�κα��ʽ����ֵ��

	//����+����,����+
	//ע��:����+ʱ�ļ�������
	//1.����j = i + 2��һ������ֵ,j�õ�����ֵ,���Ǽ����i����,
	//2.����j = i + -2�״�,��Ϊbug
	Date operator+(const int& day);
	//����+=����,����+=
	Date& operator+=(const int& day);
	//����-����,����-
	Date operator-(const int& day);
	//����-=����,����-=
	Date& operator-=(const int& day);
	//����ǰ��++
	Date& operator++();
	//���غ���++,
	//C++��Ĭ�ϵ�����ǰ��++,û�в���,����++Ϊ�˺�������,��Ϊ�ļ���һ������,����Ĳ�������,���ɺ�������
	//���ο�����Ϊ��operator++(&d, 0);
	//Ҳ������operator++(&d, 10000);
	Date operator++(int);
	//����ǰ��--
	Date& operator--();
	//���غ���--
	Date operator--(int);
	//����>
	bool operator>(const Date& d);
	//����<
	bool operator<(const Date& d);
	//����==
	bool operator==(const Date& d);
	//����!=
	bool operator!=(const Date& d);
	//����>=
	bool operator>=(const Date& d);
	//����<=
	bool operator<=(const Date& d);
	//����-���� ��������
	int operator-(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};