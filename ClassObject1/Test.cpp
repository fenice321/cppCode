#define _CRT_SECURE_NO_WARNINGS 1
#include "Person.h"
#include "Date.h"
#include <iostream>
#include <cstring>
#include <assert.h>
#include <cerrno>
#include <cstdio>
using namespace std;
//C�����нṹ����ֻ�ܶ������,���ҽṹ�������ܰ���struct����ʹ��,Ҫ��Ȼ��ʹ��typedefȡ����,����
//struct Student1
//{
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
////C++�����ȼ���C���Խṹ����÷�,�����ڴ˻����ϰ�struct����������,�ص�:
////C++�ṹ���в����ܶ������,���ܶ��庯��,���ҽṹ�������԰���struct����ʹ��,Ҳ����typedefȡ����ʹ��,�ǳ�����,����
//struct Student
//{
//	char _name[20];
//	char _gender[3];
//	int _age;
//
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//};
////�����ṹ��Ķ���,��C++�и�ϲ����class�����
//struct A
//{
//
//};
//class B
//{
//
//};
//int  main()
//{
//	//cout << sizeof(A) << endl;//1--->C++֧�ֿսṹ��,�սṹ���С��1,����C���Բ�֧�ֿսṹ��
//	//cout << sizeof(B) << endl;//1--->�����СҲ��1
//	//cout << sizeof(Student) << endl;//28
//	//cout << sizeof(Student1) << endl;//28
//
//	Student s = { "Peter", "��", 19 };
//	s.PrintStudentInfo();//Peter �� 19
//	s.SetStudentInfo("Fenice", "��", 22);
//	cout << s._name << " " << s._gender << " " << s._age << endl;//Fenice �� 22
//	s.PrintStudentInfo();//Fenice �� 22
//	return 0;
//}

//��Ķ���:
//class className
//{
//	//����,���涨�庯���ͱ���---���ɳ�Ա�����ͳ�Ա�������
//};//��struct�ṹ�嶨������,ĩβ��Ҫ©���ֺ�

//����:Person����,�����Ͷ���ŵ���һ��,��Ҫע�����:��Ա������������ж���,���������ܻὫ�䴦�����������
//Ϊʲô�ǿ�����?
//��:����֪��inline���κ������Ա���׶�ֱ��չ�����ٺ������õĿ���,��������������������Ͷ���ֿ���.h�ļ���
//.cpp�ļ���,�ᱨ��,.h�ļ�һ��ź���,��������,��������������������һ��ֱ�ӷ���.h�ļ���,ͬ��,���г�Ա����
//��������������������ᵼ�¾�����������,ֻ����Ҫ����Ա�����������,�������������򱻱���������,�����������
//������Ϊ��������,�����ǿ���,һ�㹤��������д���ʱ��,������г�Ա�����������,���Խ������Ͷ��嶼��������,
//����,��Ա����������������,�������.cpp�ļ���,����
//void Person::showinfo()
//{
//	cout << _name << " " << _sex << " " << _age << endl;
//}

//class Person
//{
//public:
//	//��ʾ������Ϣ
//	void showinfo()
//	{
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//public:
//	char* _name;
//	char* _sex;
//	int _age;
//};
//int main()
//{
//
//	return 0;
//}

//�������������������:��װ��,�̳���,��̬��
//��Ͷ���׶�����ֻ̽�����еķ�װ��
//��ķ����޶�������װ
//public,protected,private
//��װ:
//1.���ݺͷ��������л���Ϸŵ�����
//2.ͨ�������޶��������������ܷ����
//class A
//{
//public:
//	void Init(int a1, int a2)
//	{
//		_a1 = a1;
//		_a2 = a2;
//	}
//	void Print()
//	{
//		cout << _a1 << endl;
//		cout << _a2 << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//protected:
//	int _a3;
//};
//ע��:�����޶���������������ʱҪ���ܲ��ܷ���,�����治������
//һ�����:��Ա��������˽�е�,��Ա����ͨ���ǹ��е�
//int main()
//{
//	A aa;
//	aa.Print();//���ֵ,���ֵ
//	aa.Init(1, 2);
//	//aa._a1;//error,�޷�����private��Ա
//	//aa._a3;//error,�޷�����protected��Ա
//	aa.Print();//1 2
//	return 0;
//}
//class��û���޶���Ĭ����˽�е�
//structҲ��������������,��class����,ҲΪ�˼���C����û�и��޶���ʱ�ǹ��е�
//class B
//{
//public:
//	void Init(int a1, int a2)
//	{
//		_a1 = a2;
//		_a2 = a1;
//	}
//	void Print()
//	{
//		cout << _a1 << endl;
//		cout << _a2 << endl;
//	}
//private:
//	int _a1;
//	int _a2;
//protected:
//	int _a3;
//};
//int main()
//{
//	B bb;
//	bb.Print();//���ֵ
//	bb.Init(1, 2);
//	bb.Print();//2 1
//	return 0;
//}

//���������
//�ඨ����һ���µ�������,������г�Ա���������������,�����ⶨ���Ա(һ��ָ����),��Ҫʹ��::�������޶���ָ����Ա���������ĸ�����
//class Person
//{
//public:
//	void PrintPersonInfo();
//	//void Init(const char* name, const char* sex, int age);
//
//
//private:
//	char _name[20];
//	char _sex[3];
//	int _age;
//};
////void Person::Init(const char* name, const char* sex, int age)
////{
////
////	strcpy(_name, name);
////	strcpy(_sex, sex);
////	_age = age;
////
////}
//void Person::PrintPersonInfo()
//{
//	cout << _name << "-" << _sex << "-" << _age << endl;
//}
//int main()
//{
//	Person p;
//	//p.Init("�ܺ�", "��", 22);
//	p.PrintPersonInfo();
//	return 0;
//}

//class Person
//{
//public:
//	//��ʾ������Ϣ
//	void showInfo();
//public:
//	const char* _name;
//	const char* _sex;
//	int _age;
//};
//void Person::showInfo()
//{
//	cout << _age << endl;
//	cout << _name << endl;
//	cout << _sex << endl;
//}
//void TestPerson()
//{
//	Person man;
//	//man._name = (char*)malloc(101 * sizeof(char));
//	//man._sex = (char*)malloc(10 * sizeof(char));
//	//assert(man._name != NULL);
//	//assert(man._sex != NULL);
//	//strcpy(man._name, "Fenice");
//	//strcpy(man._sex, "f");
//
//	man._name = "Fenice";
//	man._sex = "f";
//	man._age = 22;
//	man.showInfo();
//}
//class B
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Init(int a)
//	{
//		_a = a;
//	}
//private:
//	char _a;
//};
//void TestB()
//{
//	B b;
//	b.Init(48);
//	b.PrintA();
//}
//int main()
//{
//	cout << "===============" << endl;
//	TestPerson();
//	TestB();
//	return 0;
//}

////���м��г�Ա����,���г�Ա����
//class A1
//{
//public:
//	void f1() {};
//private:
//	int _a;
//};
////���н��г�Ա����
//class A2
//{
//public:
//	void f2() {};
//};
////����ʲôҲû��
//class A3
//{
//};
////���н��г�Ա����
//class A4
//{
//public:
//	int _a;
//};
//int main()
//{
//	cout << sizeof(A1) << endl;//4
//	cout << sizeof(A2) << endl;//1
//	cout << sizeof(A3) << endl;//1
//	cout << sizeof(A4) << endl;//4
//	return 0;
//}

//#define DEFAULT_STACK_CAPACITY 4
////��Ӧ�ö�����Stack.h
//class Stack
//{
//public:
//	void Init(int capacity = DEFAULT_STACK_CAPACITY);
//	void Push(int item);
//	void Pop();
//	void Destroy();
//	int Top();
//	void Size();
//	int Empty();
//
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
////��Ӧ�ĳ�Ա����Ӧ�ö�����Stack.cpp
//void Stack::Init(int capacity)
//{
//	_capacity = capacity;
//	//_capacity = DEFAULT_STACK_CAPACITY;
//	_a = (int*)malloc(_capacity * sizeof(int));
//	assert(_a != NULL);
//	_size = 0;
//}
//void Stack::Push(int item)
//{
//
//}
//int main()
//{
//	Stack st;
//	//st._size;//error,������˽�еĳ�Ա�������´���
//	//st.Init();
//	st.Init(100);
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	st.Destroy();
//	return 0;
//}

//class A
//{
//public:
//	void PrintA() {}
////public:
//	char _a;
//};
//class A2
//{
//public:
//	void f2() {}
//};
//class A3
//{
//};
//int main()
//{
//	A a;
//	cout << sizeof(a) << endl;
//	cout << sizeof(A) << endl;
//	A a1;
//	A a2;
//	A a3;
//	A a4;
//	//��Ա��������ÿ�������Ƕ�����,��Ա��������ÿ�������ǹ�����,��������洢��Ա�������˷ѿռ�
//	//������С,ֻ�����Ա������С֮�Ϳ����ڴ���뼴��
//	a1._a = 3;
//	a2._a = 4;
//	a3.PrintA();
//	a4.PrintA();
//
//	A2 aa2;
//	A2 aaa2;
//	//���������0�ֽ�,��һ:����0�ֽڿռ䲻����,�ڶ�:����ʵ�������������ֽڶ���0,������������ȡ��ַû������
//	//�����1���ֽ���Ϊ��ռλ,��ʾʵ�������Ķ������,����Ϊ�˴洢����,����Ƚ�����,���������˿���һ���ֽ���Ψһ��ʶ�����
//	cout << sizeof(A2) << endl;//1
//	cout << sizeof(A3) << endl;//1
//	cout << &aa2 << endl;
//	cout << &aaa2 << endl;
//	return 0;
//}

////�������ջ�ṹ
//class Date
//{
//	//��Ա����һ���ǹ��е�
//public:
//	//void Init(Date* this, int year, int month, int day)//�ֶ����thisָ���βα������
//	void Init(int year, int month, int day)
//	{
//		cout << "this -> " << this << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//
//		//������thisָ��ֻ��д�ڳ�Ա�����ڲ�,�����ֶ���ӵ���������ʵ���б�ͳ�Ա�����β��б���
//		//������ĵĵȼ�
//		//this->_year = year;
//		//this->_month = month;
//		//this->_day = day;
//	}
//	void Print();
//	//���ݳ�Ա����һ�㶼��˽�е�--->��������,Ϊ�˰�ȫ�Ƕ�
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Date::Print()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main()
//{
//	Date d1;
//	d1.Init(2021, 2, 2);//call Init(0x00234334),��Ա���������ڹ���������ʹ��ʱcallһ�¾Ϳ��Ե�����
//	cout << "&d1 -> " << &d1 << endl;
//	d1.Print();
//	//��ӡ���d1����ĵ�ַ&d1�Ͷ�Ӧ���÷����е�thisָ���ַһ��
//	//��ӡ���d2����ĵ�ַ&d2�Ͷ�Ӧ���÷����е�thisָ���ַһ��
//	Date d2;
//	d2.Init(2021, 2, 3);//call Init(0x00234334)
//	cout << "&d2 -> " << &d2 << endl;
//	d2.Print();
//	//d2.Init(&d2);//�ֶ���Ӷ����ַʵ�α������
//
//
//	//�и�����,��������ô���ֶ���d1,d2���õķ����ֱ���ʲô
//	//��:������Ϊ�Ǿ�̬��Ա����������һ�����ص�thisָ��,ָ��������className* const this
//	//��ָ��ָ��ǰ����,�ڳ�Ա�����������г�Ա�����Ĳ�����ͨ����ָ��ȥ����,ֻ�������в������û���͸����,�����û�����,�������Զ����
//	
//	//thisָ������:
//	//1.thisָ��������:������* const this��ָ��,����Demo��thisָ����Date* const��
//	//2.thisָ��ֻ���ڳ�Ա�����ڲ�ʹ��
//	//3.thisָ�뱾������ʵ��һ����Ա�������β�,�Ƕ�����ó�Ա����ʱ�������ַ��Ϊʵ�δ��ݸ�this�β�,���Զ����в�����thisָ��
//	//4.thisָ���ǳ�Ա������һ�����ص�ָ���β�,һ������ɱ�����ͨ��ecx�Ĵ����Զ�����,����Ҫ�û�����
//	//5.thisָ����������,ʵ�κ��βε�λ�����ǲ����ֶ�ȥ��,�����ڳ�Ա�����ڲ�����ʹ��thisָ��
//	return 0;
//}
//������:
//1.thisָ���������?--->���������ָ���ǽ��̿ռ��е�����
//	A.����	B.ջ��	C.������		D.��̬��		E.������
//A����,��Ϊthisָ����һ�����ص�������*const��ָ����Ϊָ���β�,���ڶ�������
//B��,��A������֪,�βκ;ֲ�������ջ֡��,thisָ����ջ��
//C����,���ڳ��������²����޸�ָ��Ķ���
//D����,��ABC������֪���ھ�̬��
//E����,�������С,�����С,��̬����ʱû�м���thisָ��

//2.thisָ�����Ϊ����?
//��:����

//��������ܱ���ͨ����?--->��
//�������������?���������--->459�б���
//class A
//{
//public:
//	void PrintA();
//	void Show();
//private:
//	int _a;
//};
//void A::PrintA()
//{
//	cout << "_a = " << _a << endl;
//	puts(strerror(errno));
//}
//void A::Show()
//{
//	cout << "Show()" << endl;
//	puts(strerror(errno));
//}
//int main()
//{
//	A* p = nullptr;
//	p->Show();
//	p->PrintA();
//}

//class Date
//{
//public:
//	//�Լ�����Ĺ��캯��
//	//���캯��������--->����ĳ�Ա����
//	//1.���캯����������������ͬ,���캯��������Ĭ�ϵĳ�Ա����֮һ,�ҹ��캯���Լ�д�͵����Լ���
//	//2.���캯��û�з���ֵ,�ҷ���ֵû��Ҳ����дvoid,���캯���вε��ú���ͨ������ͬ,������ + ������(ʵ���б�)
//	//���캯���޲ε���ʱ��������+������,�����ڶ����������(),�������žͳ��˺���������,��ͨ�����Ǻ�����+(ʵ���б�)
//	//3.����ʵ����ʱ�������Զ����ù��캯��
//	//4.���캯�����Ժ�������,����������캯��,�������ֳ�ʼ����ʽ
//	//5.���캯��Ҳ�����ص�thisָ��
//	Date(int year, int month, int day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//�޲ι��캯��
//	Date() 
//	{
//		cout << "Date()" << endl;
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	void Init(int year, int month, int day);
//	void Print();
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Date::Init(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
//void Date::Print()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main()
//{
//	//����ûд���캯��,�������Ѿ�Ĭ�������˹��캯��,�����Ѿ�����
//
//	//Date d1;//�Լ�ûд���캯��ʱ,�Ѿ����˹��캯��,����d1�����ֵ�������ֵ,˵��Ĭ�ϵĳ�Ա����---���캯�������ﲻ��,���ǵ��Լ�д
//
//	Date d1(2021, 2, 3);//���캯�����ú���ͨ�������ò�һ��,��ͨ�����������ں���������,���캯���������ڶ������
//	//d1._year = 20;//error, _year��˽�е�,���б�����һ����ʼ����Ա����
//
//	//δ��ʼ��,���ǳ�ʼ��,�������,Ӱ��ܴ�,��Ҫ������(����)�����ͳ�ʼ����
//
//	//C++���ṩ��Ĭ�ϳ�Ա����---���캯��--->��ʼ����������Ķ���
//	d1.Print();
//	//d1.Init(2021, 2, 2);
//	//d1.Print();
//	
//	Date d2;
//	d2.Print();
//
//	//Date d2;
//	//d2.Init(2021, 2, 3);
//	//d2.Print();
//	return 0;
//}

//Сdemo,дһ��ջ�Ĺ��캯��
//#define DEFAULT_STACK_CAPACITY 4
//class Stack
//{
//public:
//	//Stack(int capacity = DEFAULT_STACK_CAPACITY)
//	//{
//	//	_a = (int*)malloc(capacity * sizeof(int));
//	//	if (_a == NULL)
//	//	{
//	//		puts(strerror(errno));
//	//		exit(-1);
//	//	}
//	//	_size = 0;
//	//	_capacity = capacity;
//	//}
//
//	Stack()
//	{
//		_capacity = 4;
//		int* _a = (int*)calloc(_capacity, sizeof(int));
//		if (_a == NULL)
//		{
//			puts(strerror(errno));
//			exit(-1);
//		}
//		_size = 0;
//	}
//	Stack(int capacity)
//	{
//		_capacity = capacity;
//		int* _a = (int*)calloc(_capacity, sizeof(int));
//		if (_a == NULL)
//		{
//			puts(strerror(errno));
//			exit(-1);
//		}
//		_size = 0;
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//int main()
//{
//	//Stack st;
//
//	Stack st1;
//	Stack st2(100);
//	return 0;
//}

//class Date
//{
//	//���������ĳ���,����ֱ�ӿ��Ը���һ��ȫȱʡ�����Ĺ��캯��,�ȿ��������޲ι��캯��������,Ҳ�����������ι��캯��������
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		cout << "Date(int year = 1900, int month = 1, int day = 1)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Date()//����޲ι��캯���������ȫȱʡ���캯����������,����������,��һ������,������ù��캯��ʱֱ��Date d;�Ǳ�������֪�������ĸ�
//	//{		//����:��Date�������Ĭ�Ϲ��캯��,��Ĭ�Ϲ��캯����Ȼ������,����ֻ�ܳ���һ��
//	//	cout << "Date()" << endl;
//	//	_year = 1999;
//	//	_month = 10;
//	//	_day = 23;
//	//}
//	void Print();
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Date::Print()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//int main()
//{
//	Date d1;//�޲ι���
//	d1.Print();
//	Date d2(2021);//���ι���
//	d2.Print();
//	Date d3(2021, 3);//
//	d3.Print();
//	Date d4(2021, 3, 8);
//	d4.Print();
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 10)
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	//��������(��������)
//	int _year;
//	int _month;
//	int _day;
//	//�Զ�������
//	Time _t;
//public:
//	void PrintD();
//};
//void Date::PrintD()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
////ͨ�������,дһ��ȫȱʡ�Ĺ��캯���͹�����
//int main()
//{
//	Date d;
//	//d.PrintD();
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year)
//	{
//		//�Լ������Լ�,�����β�,��Ա����û�г�ʼ��,�ܽ�Ӳ
//		year = year;
//	}
//private:
//	int year;
//};
//class Date1
//{
//public :
//	Date1(int year = 1900)
//	{
//		_year = year;
//	}
//private:
//	int _year;
//};
//class Date2
//{
//public:
//	Date2(int year = 2021)
//	{
//		m_year = year;
//	}
//private:
//	int m_year;
//};

//��������
//1.������������������ǰ�����ַ�~
//2.���������޲��޷���ֵ
//3.����������֧�ֺ�������(�޲�),����ֻ��һ����������,��δ��ʾ������������,��������Զ�����Ĭ�ϵ���������
//4.һ�������������ڽ����Ժ�,C++������ϵͳ���Զ�������������
//typedef int DataType;
//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity * sizeof(DataType));
//		if (_pData == nullptr)
//		{
//			puts(strerror(errno));
//			exit(-1);;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	~SeqList()
//	{
//		if (_pData)
//		{
//			free(_pData);
//			_pData = nullptr;
//			_size = 0;
//			_capacity = 0;
//		}
//	}
//private:
//	int* _pData;
//	size_t _size;
//	size_t _capacity;
//};

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		cout << "Date(int year = 1900, int month = 1, int day = 1)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//~Date()
//	//{
//	//	//������û����Ҫ����Ĺ���,����������дҲ����
//	//	//�����ϸ���˵Date�಻��Ҫд��������,��Ϊ���ǲ�д,������Ĭ�����ɾͿ�����
//
//	//	cout << "~Date" << endl;//��ӡ֤����������������
//	//}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//class Stack
//{
//public:
//	Stack(int capacity = 10)
//	{
//		cout << "Stack(int capacity = 10)" << endl;
//		_a = (int*)malloc(capacity * sizeof(int));
//		if (_a == nullptr)
//		{
//			puts(strerror(errno));
//			exit(-1);
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	//��������û����Դ��Ҫ����,���Բ���Ҫ�Լ�ʵ����������,�������Զ����ɵ�Ĭ�����������Ϳ���
//	//��ջ���жѿռ���Ҫ�����ͷ���Դ,����һ��Ҫ�Լ�ʵ����������
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		if (_a)
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
//	Date d;
//	Stack st;
//	return 0;
//}
//class String
//{
//public:
//	String(const char* str = "Jack")
//	{
//		cout << "String(const char* str = \"Jack\")" << endl;
//		_str = (char*)malloc((strlen(str) + 1) * sizeof(char*));
//		if (nullptr == _str)
//		{
//			puts(strerror(errno));
//			exit(-1);
//		}
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		if (_str)
//		{
//			free(_str);
//			_str = nullptr;
//		}
//		cout << "~String()" << endl;
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	//Ĭ����������,����������Ͳ�����
//	//Ĭ����������,����Զ�������Ҫ�����,����������������
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	return 0;
//}

int main()
{
	Date d1;
	d1.PrintD();
	Date d2(2021, 2, 29);//2021��2��û��29��,�Ƿ����ڹ��������
	d2.PrintD();
	Date d3(2021, 3, 32);//2021��3��û��31��,�Ƿ����ڹ��������
	d3.PrintD();
	return 0;
}