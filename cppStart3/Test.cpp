#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdlib>
#include <stdio.h>	
#include "Test.h"
#if 0
//C++�汾��hello world
#include <iostream>
using namespace std;
int main()
{
	cout << "Hello World!" << endl;
	return 0;
}
#endif
#if 0
//C++����C����
//�����ռ�
//C�����﷨�涨�����ʶ�����ܶ���Ϊ�ؼ����Լ�ϵͳ�ڲ�������,���Ƕ�����еĺ�����Ϊ������Ҳ����
//���Ǵ˴����Ǳ��벻��,��Ϊͷ�ļ���Ԥ����׶�ѭ��չ��,����scanf����������,��˴���scanf���������ֳ�ͻ,��������
int scanf = 0;
#endif
#if 0
//������ͻ����:��ĿЭ��������ͬ��ȡ����ͻ����ô��?
//C++�����������ռ�������������
namespace tzh
{
	int scanf = 0;//scanf����ȫ�ֱ���,�ŵ�tzh�����ռ�����
}
#if 0
//������ʹ�õ��������ռ�tzh�е�scanf������������,��չ����scanf����������ͻ��,����ͨ����
using tzh::scanf;
using namespace tzh;
#endif
int main()
{
	//printf("%d ", scanf);//������,��ӡʧ��
	printf("%p ", scanf);//��ӡ����ͷ�ļ�չ���ĺ�����,���������ǵ�ַ
	printf("%d ", tzh::scanf);//��ӡ�ɹ�,��ӡ���������ռ�tzh�еı���scanf��ֵ,����::���������޶���
	return 0;
}
#endif
#if 0
namespace tzh
{
	int a = 1;
	int b = 2;
	int c = 3;
}
#if 0
//��ʽ��:ֱ�ӵ���---������ȫ�ֱ�����ͻ
using tzh::a;
using tzh::b;
using tzh::c;
#endif

//��ʽ��:ȫ������---��������ȫ�ֱ�����ͻ
using namespace tzh;
int main()
{
#if 0
	//ֱ�ӷ��������ռ��е�a,b,c����---δ����
	printf("%d ", a);
	printf("%d ", b);
	printf("%d ", c);
#endif

#if 0
	//��ʽһ:ֱ��ͨ���������޶���
	printf("%d ", tzh::a);
	printf("%d ", tzh::b);
	printf("%d ", tzh::c);
#endif

#if 0
	//��ʽ��:ֱ�ӵ���---������ȫ�ֱ�����ͻ
	printf("%d ", a);
	printf("%d ", b);
	printf("%d ", c);
#endif

	//��ʽ��:ȫ������---��������ȫ�ֱ�����ͻ
	printf("%d ", a);
	printf("%d ", b);
	printf("%d ", c);

	//����:�Ƽ�����Ŀ��,������Ҫȫ��չ��,������������޶������ߵ���չ�������ռ��е�ĳһ�����ĳ����,��ֹ������ͻ
	//���ճ���ϰʱ�Ƽ�ʹ�÷�����ȫ������,���ӷ���
	return 0;
}
#endif

//#include <iostream>
////C++���еĶ���������std�����ռ���
//using namespace std;
////int cout = 0;//��ͻ
//int main()
//{
//	cout << "Hello World!" << endl;
//	//printf("%d ", cout);//��ͻ
//	return 0;
//}

//#include <iostream>
//#include <vector>
////C++���еĶ���������std�����ռ���
//int main()
//{
//	std::cout << "Hello C++!" << std::endl;
//	int i = 0;
//	std::vector<int> v;//ģ��
//	std::cin >> i;
//	std::cout << i << std::endl;
//	return 0;
//}

//#include <vector>
//#include <iostream>
////���԰������ռ��г��õı�����������չ��ʹ��
//using std::cout;
//using std::endl;
//using std::vector;
//using std::cin;
//int main()
//{
//	std::cout << "Hello C++ !" << std::endl;
//	cout << "Hello C++ !" << endl;
//	std::cout << "Hello Bit !" << std::endl;
//	cout << "Hello Bit !" << endl;
//	std::vector<int> v;
//	vector<int> x;
//	int i = 0;
//	std::cin >> i;
//	cin >> i;
//	std::cout << i << std::endl;
//	cout << i << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	double b = 0.0;
//	char c = 0;
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}

////N1Ϊ�����ռ���,�����ռ��п��Զ������,����,���͵ȵ�
//namespace N1
//{
//	int a;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
////�����ռ����Ƕ��
//namespace N2
//{
//	int a = 1;
//	int b = 2;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N3
//	{
//		int c = 3;
//		int d = 2;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
////�����ռ����Ƕ��,����Ƕ�׵������ռ���������������ռ�������ͬ
//namespace N
//{
//	int a = 3;
//	int b = 5;
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//	namespace N
//	{
//		int c = 3;
//		int d = 5;
//		int Div(int left, int right)
//		{
//			if (right == 0)
//			{
//				printf("error!\n");
//				exit(-1);
//			}
//			return left / right;
//		}
//	}
//}
////ͬһ��������������ڶ��������ͬ�������ռ�,���������ջὫ���Ǻϳ�һ�������ռ�,
////ע������������ͬ�����ռ��в�������ͬ�ı�ʶ��,����������ϲ�����ͻ
//namespace N
//{
//	int e = 3;
//	int g = 9;
//	//int a = 3;//ע������������ͬ�����ռ��в�������ͬ�ı�ʶ��,�������������ϲ������ռ����ͻ
//	int Half(int left, int right)
//	{
//		return (left & right) + ((left ^ right) >> 1);
//	}
//}
//int main()
//{
//	printf("%d\n", N::N::c);
//	printf("%d\n", N::Mul(2, 3));
//	printf("%d\n", N::N::Div(1, 3));
//	printf("%d\n", N::Half(3, 5));
//	printf("%d\n", N::Xor(3, 5));
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
////#include <iostream.h>//vc6.0֧��,�����µı���������֧��
//int main()
//{
//	//1.cout/cin���printf/scanf�����Զ�ʶ������,���������ʽ
//	//2.����һ���������,Ҳ����һ����������
//	//3.endl---���з��ȼ���'\n'
//	//�����Զ�ʶ��ײ�ԭ��:cout cin������ʲô? ��:cout��cin���ඨ��Ķ���,��ȫ�ֵĶ���
//	//�ײ�����:��Ͷ���+���������+��������
//	cout << "hello world!\n" << endl;
//	cout << "Hello Worle!" << endl;
//	int i = 0;
//	char ch = 48;
//	cout << ch << endl;//�˴����ASCII���48��Ӧ���ַ�0
//	double d = 3.33;
//	cout << i << endl;
//	cout << d << endl;
//	cout << &i << endl;//int*����ַ���
//	cout << &ch << endl;//char*�������ַ�����,��ӡ��'\0'����,�������
//
//	cout << i << "---" << d << "---" << &i << "---" << &ch << "---" << ch << endl;//һ���������,�������
//
//	cin >> i;//���벻��Ҫʹ��ȡ��ַ,��ΪC++�е�����
//	cout << i << endl;
//
//	cin >> i;
//	cin >> ch >> d;//һ����������,��ͬ���Ͷ�����
//	cout << i << "---" << ch << "---" << d << endl;
//	return 0;
//}

//#include <iostream>
//#include <iomanip>
//using namespace std;
//struct Student
//{
//	char name[12];
//	int age;
//};
//int main()
//{
//	//ʵ��ʹ��ʱ,cin/cout��printf/scanf��������,������,�ĸ��������ĸ�,��������û�������
//	//���ֳ���cin/cout�ܷ���
//	int i = 0;
//	double d = 0.0;
//	//cin >> i >> d;
//	//cout << i << "---" << d;
//
//	//���ֳ���printf����
//	struct Student s = { "peter", 18 };
//	printf("name:%s, age:%d\n", s.name, s.age);
//	cout << "name:" << s.name << ", " << "age:" << s.age << endl;
//
//	//����С�������λ
//	//���ֳ���printf����
//	d = 10.0 / 3.0;
//	printf("d = %.2lf\n", d);
//	cout << d << endl;
//	cout.unsetf(ios::fixed);
//	cout << "d = " << setprecision(3) << d << endl;//���d = 3.33
//	return 0;
//}

#include <iostream>
using namespace std;
//ȱʡ����
void TestFunc1(int a = 1)
{
	cout << a << endl;
}
//ȫȱʡ����
void TestFunc2(int a = 10, int b = 20, int c = 30)
{
	cout << a << " " << b << " " << c << endl;
}
//��ȱʡ����
void TestFunc3(int a, int b = 10, int c = 20)
{
	cout << a << " " << b << " " << c << endl;
}
//����ȱʡ����ע������:
//1.��ȱʡ�������������������������,���ܼ���Ÿ���
//2.ȱʡ���������ں��������Ͷ�����ͬʱ����
//void TestFunc4(int a = 100);
//void TestFunc4(int a = 200)
//{
//
//}
//3.ȱʡ����������Ŀʱ��÷ŵ�����������
//4.ȱʡֵ�����ǳ�������ȫ�ֱ���
//5.C���Բ�֧��ȱʡ����
//int main()
//{
//	TestFunc1();//���Ĭ��1
//	TestFunc1(10);//���������10
//
//	TestFunc2();//���Ĭ�ϵ�10 20 30
//	TestFunc2(40);//���40 20 30
//	TestFunc2(50, 60);//���50 60 30
//	TestFunc2(70, 80, 90);//���������70 80 90
//
//	TestFunc3(10);//10 10 20
//	TestFunc3(20, 30);//20 30 20
//	TestFunc3(40, 50, 60);//40 50 60
//	return 0;
//}

//C++��ȱʡ������һ��ʹ�ó���
//void StackInit(Stack* pst, int n = 8)
//{
//	pst->a = (STDataType*)malloc(n * sizeof(STDataType));
//	//......
//}
//StackInit(&s);//�����֪�������Ŀռ��ʹ��Ĭ�ϵĴ�С
//StackInit(&s, 100);//���֪����ʼ����Ҫ����100������,�Ϳ��Ը���100,�������Ƶ�����������Ч��

//C������,��֧��ͬ������
//C++Ϊ�˽���������,�����˺�������,֧��ͬ������,������Ҫ��,������ͬ(����or����or˳��)
int add(int i, int j)//C�����б������,C++�п�������
{
	return i + j;
}

double add(double i, double j)
{
	return i + j;
}

long Add(long left, long right)
{
	return left + right;
}

//��������
//���������Ǻ�����һ���������,C++������ͬһ�����������������������Ƶ�ͬ������,��Щͬ���������β��б�(��������or
//��������or����˳��ͬʱ)���ɹ��ɺ�������,����������ʵ�ֹ������Ƶ����������Ͳ�ͬ������

void f(int i, double j) {}
void f(double i, int j) {}
void f(double i) {}
//int f(double i) {}//error ����ֵ��ͬ�����ɺ�������

//����������������������?
//��:������,��Ϊ����ֵ��ͬ���Ǻ������ص�����
//short Add(short left, short right)
//{
//	return left + right;
//}
//int Add(short left, short right)
//{
//	return left + right;
//}
int main()
{
	cout << Add(10, 20) << endl;
	cout << Add(10.0, 20.0) << endl;
	cout << Add(10L, 20L) << endl;
	return 0;
}

//������:
//1.ʲô�Ǻ�������
//��:ͬһ���������ں�������ͬ�Ĳ�ͬ����,��������,˳��,���Ͳ�ͬ���ɺ�������
//2.ΪʲôC���Բ�֧�ֺ�������,C++֧�ֺ�������

//test.h test.cpp main.cpp
//Ԥ����---ͷ�ļ�ѭ��չ��/���滻/ȥ��ע��/��������
//		test.i	 main.i
//����---����﷨(�﷨����->�ʷ�����->�������->���Ż���),���ɻ�����
//		test.s   main.s
//���---�ѻ�����ת�ɿ��ض���Ķ����ƻ�������,�γɷ��ű�
//		test.o   main.o
//����---��*.o��libc.so�����ӳɿ�ִ���Գ���,�ϲ��α�,�ϲ����ű�ͷ��ű���ض�λ

//C++�ײ�����name Mangling������������,��ͬ��������ͬ�����б�ĺ����ᱻ����ɲ�ͬ�ĺ�����,�����г�ͻ,
//C����û���������,����C���Ի���ʾ��ʶ���ض���