#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stddef.h>
using namespace std;
#if 0
//C������������̵�,��ע���ǹ���--->����
//C++�ǻ�����������(���Ǵ���������������,�����������,�����������,��ΪC++Ҫ����C����),��ע���Ƕ���--->��

//������̺����������һ�ű������,����һ�ֽ�������˼·/˼��
//����:ϴ�·�
//��ĸ��:1.ȡ���·�	2.��һ��ˮ��	3.��ϴ�·�	4.�����·��ŵ�ˮ����	5.�����е�ˮ	6.���ִ�һ��	7.����ˮ����	8.�������е�ˮ
//9.��ϴ�·�	10.�����ִ�һ��/��һ��	11.����ˮ����	12.�ٵ�ˮ,���·�Ū�ɾ�	13.���·�š��	14���·�
//������ĸ��ϴ�·����̾����������,����Щ����/�������Ĳ��谴���Ͱ�Ľ�����ȥ,�����������˳��,ÿ��������Է�װ��һ������,��Щ��������һ���Ĵ��������е���,�����������

//��һ��:1.���·�		2.��		3.ϴ�»�      4ϴ��Һ		5.ˮ
//���������·��ŵ�ϴ�»���,����ϴ��Һ,����ϴ�»���Ӧ�İ�ť,��ˮ,ϴ�»����Լ���ϴ�·���,�˲��ù��ĵ�������ôϴ���·�,����һ���������������ķ�ʽ
//��,���·�,ϴ�»�,ϴ��Һ,ˮ�����Կ����Ƕ���,ϴ�·���������ͨ����������֮����໥Э����ɵ�

//���翪��:
//�������:
//1.�򿪳��� 2.�ϳ� 3.����ϵ�ϰ�ȫ�� 4.��� 5.�ҵ� 6.����ɲ 7.������ 8.����� 9.������

//�������:
//1.��	2.��
//�˺ͳ���ʵʵ���ڴ��ڵ�ʵ��,��C++�а���ʵ�п���������(����Ҳ�п�������)��Ϊ����
//�˺ͳ��Ľ���,�Ϳ�����ɿ����Ķ���
//�Զ���ʻ--->�Ƽ��ǳ�������
//��--->����ǰһ��--->�����Զ���
//����������,����:�ؼ�--->�����˵���

//��Ҫ���������--->��C++��ʵ���������ı��˼��Ļ�,class��������Ƿǳ��ؼ���һ��

//��C������,����ʹ��struct���Զ���һ���µ�����,����:C������struct�п��Էź�����?��:����
struct Student
{
	//�ṹ���еı���
	char _name[20];
	char _gender[3];
	int _age;
	//�ṹ���еĺ���
	void InitStudent(const char name[], const char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
	void SetAge(int age)//��C������,����ʧ����--->˵��:C�����еĽṹ���ڲ��ǲ��ܷź�����
	{					//��C++��,����ɹ�--->˵��:C++�����нṹ���ڲ��ܷź���
		_age = age;
	}
};//��C++��struct������������;Ϳ��Կ�����һ������
  //C�����еĽṹ��,��C++��ҡ��һ��,���--->������һ����
  //ֻ����C++��,���Ҫ������,���Ǹ�ϲ��ʹ��class�Ĺؼ���
int main()
{
	//C�����еķ�ʽ
	struct Student s1;
	s1._age = 10;
	//C++�еķ�ʽ
	Student s2;//C++�нṹ�������԰���struct����ʹ�����������
	s2.InitStudent("Peter", "��", 18);
	s2.SetAge(10);
	return 0;
}
#endif
#if 0
//ֻ����C++��,���Ҫ������,���Ǹ�ϲ��ʹ��class�Ĺؼ���

//C�����нṹ����ֻ�ܷ�һЩ����,C++�����ڳ��˿��Է����ݻ����Էź���,ΪʲôҪ���������������:��Ϊ�����˶��������֪
class Student//����Ƕ�ʵ�����������--->ʵ�������(��ĳ�Ա����),ʵ��Ĺ���(��ĳ�Ա����/����)
{
	//һ�����ݸ��ķ����޶�����˽�е�
private:
	char _name[20];
	char _gender[3];
protected:
	int _age;
	//һ�㷽�����ķ����޶����ǹ��е�
public:
	void SetAge(int age)
	{
		_age = age;
	}
	void PrintStudent()//ע��:��Ա������������ڲ����ж���,��Ա�������ܻᱻ���������������������Դ�
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
	void InitStudent(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
};//���������������:��װ,�̳�,��̬,��Ͷ���ģ����Ҫ�Ǵ����װ���Ե�

//�ඨ������ַ�ʽ:
//1.�����Ͷ���ȫ����������
//2.����.h��ͷ�ļ��н�������,��.cpp��Դ�ļ��н��ж���,����һ�������,���Ƕ�ʹ�÷�ʽ2,��ϰ����ʱʹ�÷�ʽ1

//���ǶԶ���(ʵ��)������������,�����಻�Ƕ���(ʵ��)
//ѧ����𲻵���ĳ�������ѧ��,��Ҳ���Կ������¶�����һ����������
//��			�ඨ��Ķ���(ʵ��)
//int		��int��������ı���
int main()
{
	//Student������,���Խ��俴��ѧ����һ��Ⱥ�� 

	//s����Student�ඨ������Ķ���
	//s��һ��������ڵ�ѧ��,���ǲſ��Խ�����,�Ա�,����ŵ������ѧ��������
	Student s;
	//���뱨��:��ΪStudent����һ�������ѧ��,���ǲ��ܽ�����,�Ա�,����ŵ�Student��
	//Student.InitStudent("Peter", "��", 18);//error,��������û�����Ե�
	s.InitStudent("Peter", "��", 10);
	s.PrintStudent();
	//s._age = 10;
	return 0;
}
								//ע��:struct�������Ĭ������·���Ȩ����public,class�������Ĭ������·���Ȩ����private
								//public:���εĳ�Ա���������ֱ�ӱ�����
								//protected:���εĳ�Ա�����ⲻ��ֱ�ӱ�����(��ʱ��ô���)
//ʲô�Ƿ�װ?ΪʲôҪ�з�װ?		//private:���εĳ�Ա�����ⲻ��ֱ�ӱ�����
//						class	�����޶���(private public protected),�޶����е���Щ��Ա����������������ʹ��
//��װ:�����ݺͲ������ݵķ����л����,�������Ժ�ʵ��ϸ��,�����⹫���ӿںͶ�����н���

//����:ʵ���Ͼ���һЩ����װ��һ��,���Կ����Ƿ�װ
//C����:����+�������ݵķ���(����)=����
//C++��:���ֲ�ͬ�Ķ���,����֮���໥�����������
//����:�ж��������(����),���ж������еĹ���(����)

//��������	ȫ��������	�����ռ�������		������ֲ�������

//��Ͷ���--->ʲô����?ʲô�Ƕ���?
//��:��Ҫ�Ƕ�ʵ��(����)������������,����ʵ�嶼����Щ����(��Ա����),������Щ����(��Ա����)
//	 ��Ҳ���¶����һ������
//	 ���ǱȽϳ����һ������,�Ǵ�����������ȡ������һЩ������Ϣ,�����ݺͷ�����װ����,���ܺõ�����ʵ��,����һ��ͼֽ

//����:ʵʵ���ڴ��ڵ�,����:һ��ѧ��,һ̨����,һ������
//	  �������һ��ʵ��(����)
//	  �������ǿ��Է����ݵ�
//    ����һ������
#endif
#if 0
class Student
{
public:
	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
	void InitStudent(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
private:
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1;
	Student s2;
	Student s3;

	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 20);
	s3.InitStudent("Lucy", "Ů", 19);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	s3.PrintStudentInfo();
	//����:�ڵ���λ��,�����ܹ�֪����ʼ�������ʹ�ӡ���������ڲ����Ǹ�����,������InitStudent��PrintStudentInfo������,û���κι��ڶ����˵��,
	//��ô����������������ô֪�����������ĸ�����?
	//��:�����صĲ���thisָ��
	return 0;
}
#endif
#if 0
//�����ģ��:�������ڴ��еĲ��ַ�ʽ

//��μ���һ����/������ռ�ռ���ֽڴ�С
//�������֪�������ж�������д����

//���õĵ���Լ��:
//__cdecl
//__thiscall
//__x64call
//__fastcall
//__stdcall
class Student
{
public:
	void PrintStudentInfo()
	{
		cout << this << endl;
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
	//��Ա����
	//�������ú�������������,ʵ������4������,
	//����һ�����������ص�thisָ��(�����ǵ�һ������),��д�����ڼ�,�û�������ʾ����thisָ��,�������ڱ������ʱ,���Զ�����thisָ�����

	//void __thiscall Student::InitStudent(char* const, char* const, int)
	void InitStudent(const char* name, const char* gender, int age)
	{
		//this = nullptr;//thisָ��������className* const this,���ܸ�thisָ�븳ֵ--->��:Student* const this
		cout << this << endl;
		//����thisָ��֮��,��Ա������֪���������ڲ����Ǹ�����
		//�Գ�Ա�����Ĳ�������ͨ��thisָ�������е�
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	void SetAge(int age)
	{
		cout << this << endl;
		_age = age;
	}

	//__cdecl�ǵ���Լ��,Լ�����ú����ڼ������ĸ��ֲ����Ĺ���
	//void __cdecl Student::TestFunc(...)
	void TestFunc(...)//�����γ�Ա����
	{

	}
public:
	char _name[20];
	char _gender[3];
	int _age;
};
//this��һ���ؼ���,��һ��ָ��,�ǵ�ǰ����ĵ�ַ(��Ա����ִ��ʱ,���øó�Ա�����Ķ���)
int main()
{
	//cout << this << endl;//thisָ��ֻ���ڷǾ�̬��Ա�������߷Ǿ�̬��Ա��ʼֵ������
	Student s1, s2, s3;
	//s1.//ͨ��������ķ�ʽ����:Student�����͵Ķ�������:_name, _age, _gender, InitStudentInfo(), SetAge(), PrintStudent()
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	s3.PrintStudentInfo();

	s1.TestFunc(1);
	s2.TestFunc(1, 2);
	s3.TestFunc(1, 2, 3);
	//����:s1, s2, s3��Ȼ��������ͬ�Ķ���,�������յ��õ�����ͬ�ķ��������г�ʼ���ʹ�ӡ
	//���ÿ�������ж��洢��ͬ�ĳ�Ա����ʱ,�˷ѿռ�
	cout << sizeof(s1) << "-" << sizeof(Student) << endl;//28-28
	return 0;
}
//ʲô��thisָ��?
//thisָ������"�Ǿ�̬��Ա����"�ββ����б��е�һ������,������������ص�,���ָ������ָ����ø÷Ǿ�̬��Ա�����Ķ���
//����:
//1.ֻ���ڷǾ�̬��Ա������ʹ��
//2.thisָ��ȫ��Ϊ:	className* const this,��thisָ���ָ�򲻿ɸ�
//3.thisָ��û�д洢�ڶ�����,��˲���Ӱ�����Ĵ�С,�����ڳ�Ա��������ʱʱʱ�̿�ָ��ǰ����,thisָ���Ǻ����β�,�洢��ջ��
//4.thisָ����"�Ǿ�̬��Ա����"�ĵ�һ�����ص��β�,"���ص�"--->�û���ʵ�ֳ�Ա������,������ʾ����,�ò����Ǳ������Զ���ӵ�,Ҳ���ɱ������Զ������д��ݵ�
//5.thisָ����Ҫ��ͨ��ecx�Ĵ������д���,Ч�ʺܸ�,���ǲ���������thisָ�붼��ͨ���Ĵ��������ݵ�,
//������ͨ����������ѹջ���ݵ�(��γ�Ա�����ĵ���ʱthisָ��Ĵ��ݾ���ѹջ)
#endif
#if 0
class A
{
public:
	void SetA(int a)
	{
		_a = a;
	}
private:
	int _a;
};
class B
{
public:
	void TestB() 
	{}
};
class C
{};
//������:�����С�Ƕ���?Ϊʲô?
//��:�����������п����Сռһ���ֽ�,ԭ��һ����������С��0,����ʵ��������ϵͳ����ռ�0�ֽ����벻����,
//ԭ����Ǿ�������0�ֽ����������,�ÿ���ʵ��������������,���ڴ溯��ջ֡�д洢,����������һ��λ��,��ַ��ͬ--->����������ͬһ������,�����������ǲ�ͬ����ì��,
//�����۴��ĸ�ԭ����������Ҫ��1������1�������ֽ���Ψһ��ʶ�����С,ֻ��������������������ı�ʶ��С��1�ֽڶ���
struct D
{};
struct AA
{
	int a;
	char b;
	double c;
	char d;
};
//#define MY_OFFSETOF(structName,memberName) (unsigned int)&(((structName*)0)->memberName)
//#define OFFSETOF(structName, memVarName) ((size_t)&(((structName)*0)->memVarName))
int main()
{
	//����:��һ����Ĵ�С--->ֻ��Ҫ������"��Ա����"������,ע���ڴ����
	//cout << sizeof(A) << endl;//4
	//cout << sizeof(B) << endl;//1
	//cout << sizeof(C) << endl;//1

	//�������Ĵ�С��0
	//C���ǿ���,Ȼ����C�ඨ������������,����������ͬ
	//C c1, c2, c3;
	//

	//cout << sizeof(D) << endl;//1,C++�пսṹ��(��)��СҲ��1
	
	//����:����һ���ṹ��AA,Ȼ���ٸ�AA�е�һ����Աc
	//��Ҫ֪��AA�ṹ���еĳ�Ա����ڽṹ����ʼλ�õ�ƫ����

	AA a;
	//printf("%d\n", OFFSETOF(struct AA, b));
	cout << sizeof(AA) << endl;
	//offsetof()//#define offsetof(s,m) ((size_t)&(((s*)0)->m))
	return 0;
}
//��:�ṹ�����ı���������ʲô?
//��:��C++�нṹ��������û��ʲô����
//����������֮ͬ��,����Ͷ�������ֻ��һ����ͬ--->Ĭ�Ϸ���Ȩ�޲�ͬ,ģ��λ����һ����ͬ,�̳�λ����һ����ͬ
#endif
#if 0
//thisָ��
//�ع鵽C����
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};
//����Ҫʵ��һЩ�����ṹ�����ͱ����ķ���
void InitStudent(Student* ps, const char* name, const char* gender, int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}
void PrintStudent(Student* ps)
{
	printf("%s, %s, %d\n", ps->_name, ps->_gender, ps->_age);
}
int main()
{
	Student s1, s2, s3;
	InitStudent(&s1, "zhouhongtao", "��", 22);//���δ���һ������ָ��,ֻ����C++���������ָ������thisָ��,ȫ����className* const this
	InitStudent(&s3, "wede", "��", 20);
	InitStudent(&s2, "qifeng", "��", 21);
	PrintStudent(&s1);						 //���δ���һ������ָ��,ֻ����C++���������ָ������thisָ��,ȫ����className* const this
	PrintStudent(&s2);
	PrintStudent(&s3);
	return 0;
}
#endif
#if 0
//��Ա���������ں�,��Ա����ʹ�ó�Ա������ǰ,��������ô��������?
//��Ϊ:�������������ӵĴ������:
//��һ��:��ʶ������
//�ڶ���:��ʶ�����еĳ�Ա����
//������:���ʶ�����еĳ�Ա����,���Գ�Ա���������޸�--->����thisָ��
class Student
{
public:
	//void InitStudent(Student* const this, const char* name, const char* gender, int age)
	//{
	//	strcpy(this->_name, name);
	//	strcpy(this->_gender, gender);
	//	this->_age = age;
	//}
	void InitStudent(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	//void PrintStudent(Student* const this)
	//{
	//	cout << this->_name << "-" << this->_gender << "-" << this->_age << endl;
	//}
	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
private:
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 19);
	s2.InitStudent("David", "��", 29);
	s3.InitStudent("Lucy", "Ů", 13);
	
	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
//��Ͷ���
//1.������̺����������˼��
//2.��Ķ���
//3.�����޶���
//4.ʲô�Ƿ�װ?C++�����ʵ�ַ�װ?
//5.һ�������һ��������
//6.���ʵ����:��Ͷ���
//7.��μ���һ����Ĵ�С?ע��:����Ĵ�С��ʲô?ԭ��
//8.thisָ��
#endif
#if 0
class A
{
public:
	//������������Ĳ���
	//1.ʶ������
	//2.ʶ�����Ա����
	//3.ʶ�����Ա����,���޸����Ա����,��classType * const thisָ��
	/*
	void TestFunc(A* const this)
	{
		this->_t = 10;
		cout << this << endl;
	}
	*/
	void TestFunc()
	{
		cout << this << endl;
		this->Test();
		//_t = 10;
	}
	void Test()
	{
		cout << "A::Test()" << endl;
	}
private:
	int _t;
};
int main()
{
	A a1, a2, a3;
	//A::TestFunc();//error,û�ж���,���ò��˳�Ա����
	a1.TestFunc();//call A::TestFunc(&a1)
	a2.TestFunc();//call A::TestFunc(&a2)
	a3.TestFunc();//call A::TestFunc(&a3)
	//��Ա��������Ҫͨ�����������е���,�ڸó�Ա��������֮ǰ,��������Ҫ����ǰ����ĵ�ַͨ��ecx�Ĵ������ݸ���Ա����

	A* pa = &a1;
	pa->TestFunc();//call A::TestFunc(pa);

	pa = &a2;
	pa->TestFunc();//call A::TestFunc(pa);

	//ע��:pa��A*���͵�ָ��,Ҳ����˵pa��������ָ��A���͵Ķ���
	//    ���paָ��û�кϷ�ָ��,һ�㶼�ǽ���ָ����Ϊnullptr
	pa = nullptr;
	pa->TestFunc();
	return 0;
}
#endif
#if 0
//������:
//1.thisָ���������?
//��:thisָ���ǷǾ�̬��Ա�����ĵ�һ�����ص�ָ�����,ָ����ó�Ա�����Ķ���,�洢��ջ��
//2.thisָ�����Ϊ����?
//����
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
 	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	p->PrintA();//����,������ָ���ֵ
	//p->Show();//������
	return 0;
}
#endif
#if 0
class Date1
{};
//����,������û�г�Ա�����ͳ�Ա����,��������������һ��Ψһ�ı�Ǵ�СΪ1�ֽ�
//ʵ������6��Ĭ�ϵĳ�Ա����
//1.���캯��(��ʼ��)	2.��������(����,�ͷ���Դ)	3.�������캯��(��ʼ������)	4.��ֵ���������(��ֵ)		5.&/*		6.&/const *
//Ĭ�ϳ�Ա����ָ����:�û�û����ʾʵ�ָó�Ա����,������������û�ʵ��һ��
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	//d._year = 2020;
	d1.SetDate(2020, 10, 11);
	d1.PrintDate();

	Date d2;
	d2.SetDate(2020, 11, 11);
	d2.PrintDate();

	Date d3;
	d3.SetDate(2020, 12, 11);
	d3.PrintDate();

	//Date d4(2020, 10, 13);
	//d4.PrintDate();

	int a;
	a = 10;
	cout << a << endl;

	int b = 10;
	cout << b << endl;

	int c(20);
	cout << c << endl;
	return 0;
}
#endif 
#if 0
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
    Date(int year, int month, int day)//���캯���޷���ֵ,дvoidҲ����
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int, int, int):" << this << endl;
	}
	Date()//���캯������,���Ը�������캯��,���ֳ�ʼ����ʽ
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	//Date(int year = 1900, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
private:
	int _year;
	int _month;
	int _day;
};
//���캯��������Ĭ�ϳ�Ա����֮һ,��������
//����ʵ����ʱ,�������Զ����ù��캯����ɶ���ĳ�ʼ��,��֤ÿ�����ݳ�Ա����һ�����ʵ�ֵ
//���캯������������ͬ,��û�з���ֵ,��������
//���캯���ڶ�������������ֻ����һ��
void TestFunc()
{
	Date d1(2020, 11, 11);
	cout << &d1 << endl;
	d1.PrintDate();

	//��������ʱ,�������Զ����ù��캯��,������������һЩ��ʼֵ
	Date d2;
	d2.PrintDate();

	Date d3();//�˾���벻�Ǵ�������d3����˼,��������һ��������Ϊd3,�����,����������Date�ĺ���
	//ע��:�������޲ι��캯����������ʱ,����֮��һ�����ܸ�(),�������()�ͳ�Ϊ��������,�����Ǵ�������
}
int main()
{
	//Date d1(2020, 10, 11);
	//d1.PrintDate();
	TestFunc();
	return 0;
}
#endif
#if 0
//�������û����ʾ���幹�캯��,��C++���������Զ�����һ���޲�Ĭ�Ϲ��캯��(����ɶҲû��),һ���û���ʾ�������������������
class Date
{
public:
	//�û�û����ʽ�����κι��캯��---��ʽ:�û��Լ�û��д
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	//�Ӹ�����:Ŀǰ��������û����ʾ���幹�캯��,���Ǹ����Ծɿ��Դ�������,����������ʱ��������Ҫ�Զ����ù��캯��,
	//�ù��캯����������?���Ǳ��������ɵ�Ĭ���޲ι��캯��
	Date d1;//��ϵ�,������࿴����Ĭ���޲ι��캯������
}
int main()
{
	TestDate();
	return 0;
}
#endif
#if 0
//�������û����ʾ���幹�캯��,��C++���������Զ�����һ���޲�Ĭ�Ϲ��캯��(����ɶҲû��),һ���û���ʾ�������������������
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}
	void PrintTime()
	{
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	//�û�û����ʽ�����κι��캯��---��ʽ:�û��Լ�û��д
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//�û���ʾ�����˴��в����Ĺ��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;

	Time _t;
};
void TestDate()
{
	//Date�����Ѿ���ʾ�����˴������������Ĺ��캯��
	//��֤:���������᲻�������޲εĹ��캯����?

	//����һ:��������������ɴ��޲εĹ��캯��,Date d2;���������ͨ��
	//����,�������ʧ��

	//���:���뱨��:error û�к��ʵ�Ĭ�Ϲ��캯������
	//����:��������ʾ���幹�캯��ʱ,�����������������޲ε�Ĭ�Ϲ��캯����

	//������:���Date������ʾ������һ���޲ι��캯��,���ұ���������Ĭ������һ���޲ι��캯��,��ô������������ͬһ��������
	//��������ͬ(��������),�����б���ͬ(�����޲�),�����������κ���������һ��һ����,�����ɺ������ص�����,ֻ�Ǻ����ض���
	//ì��,���Ա��������������޲εĹ��캯��

	//����������ͨ������������������޲ι��캯����
	//Date d1;//��ϵ�,�������,�ܿ���Ĭ���޲ι��캯������
}
int main()
{
	TestDate();
	return 0;
}
#endif
#if 0
//�޲εĹ��캯����ȫȱʡ���캯������ΪĬ�Ϲ��캯��(����û����ʾ�������캯��ʱ,�������Զ����ɵ�Ĭ���޲ι��캯��Ҳ��Ĭ�Ϲ��캯��),����Ĭ�Ϲ��캯��ֻ����һ��
//����:��û����ʾ�������캯��ʱ,�������Զ�����Ĭ���޲ι��캯��,����ȫȱʡ���캯�����޲ι��캯����ʾ����ʱ,
//��������������Ĭ���޲ι��캯��--->�������Զ����ɵ�Ĭ�Ϲ��캯��ֻ�ܵ�������
//��ȫȱʡ���캯�����޲ι��캯��ͬʱ����ʱ,���÷�ʵ��������ʱ:Date d;������������,��֪�������ĸ����캯�����г�ʼ��--->ȫȱʡ���캯�����޲ι��캯��ֻ�ܵ�������
//����:����Ĭ�Ϲ��캯��ֻ�ܴ���һ��
class Date
{
public:
	Date()//�޲ι��캯��
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)//ȫȱʡ���캯��
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2020, 2, 2);

	//����:�ȿ��Ե����޲ι��캯��������d2,Ҳ���Ե���ȫȱʡ���캯��������d2
	//�����˶�����,����ʧ��
	//Date d2;
	return 0;
}
#endif
#if 0
/*
1.���û�û����ʾ���幹�캯��ʱ,������������һ���޲ε�Ĭ�Ϲ��캯��
*/
class Date1
{
	//1.���û�û����ʾ���幹�캯��ʱ,������������һ���޲ε�Ĭ�Ϲ��캯��
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class Time 
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
		cout << "Time(int, int, int)" << endl;
		//cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
void TestDate1()
{
	Date1 d;//Date1����û����ʾ�������캯��,����Date1�ഴ������ʱ���ù��캯�����õ��Ǳ������Լ����ɵ�Ĭ���޲ι��캯��
}
void TestDate()
{
	Date d;
	d.PrintDate();//call Date::Date() [addr]
}
int main()
{
	TestDate1();
	TestDate();
	return 0;
}
#endif
#if 0
//Ĭ�ϳ�Ա����
//1.����
//2.����
//3.���ó���
//4.���������ɵ�Ĭ�ϳ�Ա����

typedef int DataType;
#define DEFAULT_SEQLIST_LENGTH 10
class SeqList
{
public:
	SeqList(size_t capacity = DEFAULT_SEQLIST_LENGTH)
	{
		_array = (DataType*)malloc(capacity * sizeof(DataType));
		if (nullptr == _array)
		{
			printf("_array malloc error!\n");
			exit(-1);
		}
		_capacity = capacity;
		_size = 0;
	}
	~SeqList()
	{
		if (_array != nullptr)
		{
			free(_array);
			_array = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}
	void PushBack(DataType data)
	{
		//...
	}
	void PopBack()
	{
		if (!Empty())
		{
			_size--;
		}
	}
	size_t Size()
	{
		return _size;
	}
	size_t Capacity()
	{
		return _capacity;
	}
	bool Empty()
	{
		return _size == 0;
	}
	bool Full()
	{
		return _size == _capacity;
	}
	//......
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
};
void TestSeqList()
{
	SeqList s;
	s.PushBack(10);
	s.PushBack(10);
	s.PushBack(10);
	s.PopBack();
	s.PopBack();
	s.PopBack();
}
int main()
{
	TestSeqList();
	return 0;
}
#endif
//C��û���ַ�������,C++�����ַ�����---string
class String
{
public:
	String(const char* str = "Jack")
	{
		_str = (char*)malloc((strlen(str) + 1) * sizeof(char));
		if (nullptr == _str)
		{
			printf("_str malloc error!\n");
			exit(-1);
		}
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};
class Person
{
private:
	String _name;
	int _age;
};
void TestPerson()
{
	Person p;
}
void TestString()
{
	String s("hello world!");
}
int main()
{
	TestPerson();
	TestString();
	return 0;
}