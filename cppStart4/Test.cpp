#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include "F.h"
using namespace std;
//��������
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//int main()
//{
//	cout << Add(10, 20) << endl;
//	cout << Add(10.0, 20.0) << endl;
//	cout << Add(10L, 20L) << endl;
//	return 0;
//}

#if 0
//��:���������������γɺ���������?
//��:����,��Ϊ����gnu-c++�ĺ����������ι���,�����������κ��������� _Z8TestFunci,�������޷���������
void TestFunc(int a)
{
	cout << "void TestFunc(int a)" << endl;
}
void TestFunc(int a = 10)
{
	cout << "void TestFunc(int a = 10)" << endl;
}
#endif

//int main()
//{
//	int a = 10;
//	int& rb = a;//rb��a�ı���,rb��a������,����Ҫע���������&���Ų���ȡ��ַ
//	cout << a << " " << rb << endl;//10 10
//	cout << &a << " " << &rb << endl;
//	//&a��&rb��ַ"��ͬ",a��int��,&a��int*��,rb��int&��,&rb��int*��
//	a = 20;
//	cout << a << " " << rb << endl;//20 20
//	cout << &a << " " << &rb << endl;
//	//&a��&rb��ַ"��ͬ",a��int��,&a��int*��,rb��int&��,&rb��int*��
//	rb = 30;
//	cout << a << " " << rb << endl;//30 30
//	cout << &a << " " << &rb << endl;
//	//&a��&rb��ַ"��ͬ",a��int��,&a��int*��,rb��int&��,&rb��int*��
//
//	int& rrb = rb;
//	//һ�����������ж������
//	//���Ը�����ȡ����
//	int& rc = a;
//	cout << &rrb << " " << &rc << endl;
//	//&rrb==&rc==&rb==&a,rc��int&��,&rc��int*��,rrb��int&��,&rrb��int*��
//
//	//double& rd = a;//�������,�������ͱ���������ʵ������һ��
//
//	//int& re;
//	//�������,���ñ����ڶ����ʱ���ʼ��,�����Ƕ�,C������ָ����Գ�ʼ��Ҳ���Բ���ʼ��
//	//���ǲ���ʼ�����ܻ����Ұָ��,���õ��������Ϊ�˽��ָ���е�һЩ����,����ǿ��Ҫ��
//	//�����ʼ��,����ֱ�ӱ��벻ͨ��,ʹ��̸��Ӱ�ȫ��
//
//	int b = 200;
//	rb = b;//��仰����˼�ǰ�b��ֵ��rb,����rb���b�ı���?��:ͨ�����Կ����жϳ��ǰ�b��ֵ��rb
//	//����һ������һ��ʵ��,�ٲ�����������ʵ��,ֻ�Ǹ�ֵ����
//	return 0;
//}
//
//int main()
//{
//	//int a = 10;
//	//int& ra = a;
//
//	//const int a = 10;
//	//int& ra = a;
//	//�������,aΪ������const int���Ͷ�Ӧ����������ӦΪconst int&,�������ͱ��������ʵ�����ͱ���һ��
//	//��߿ɶ���д,�ұ�ֻ��--->Ȩ�޷Ŵ���
//
//	const int a = 10;
//	const int& ra = a;
//	//����ͨ��,�ұ߳�����ֻ������д,��߳�����Ҳ��ֻ�ɲ���д,Ȩ����ͬ,
//
//	int c = 10;
//	const int& d = c;//����ͨ��--->���ֻ�ܶ�,�ұ߿ɶ���д--->Ȩ����С
//
//	//size_t strlen(const char* str);--->�����const char*,����char*���Ը�ֵ,const char*Ҳ����
//	//ע��:ָ��������ڳ�ʼ����ֵʱ,Ȩ�޿�����С���ǲ��ܷŴ�
//
//	//int& rc = 10;//�������
//	//�ұ߳���������һ��ռ��10,ֻ��,��߿ɶ���д--->Ȩ�޷Ŵ���--->����
//
//	const int& rc = 10;//����ͨ��,���ó���Ҫ��const����
//
//	//���ͺ͸�����֮����Ի��ำֵ,��ʽ����ת��
//	double dd = 2.22;
//	int i = dd;
//
//	//int& ri = dd;//�������--->�������ͱ��������ʵ�����ͱ���һ��
//	const int& ri = dd;//����ɹ�--->��������"double"ת����"const int"���ܷ������ݶ�ʧ
//
//	double e = 12.34;
//	double& rd = e;
//	//int& ri = e;//�������,�������ͺ�����ʵ������Ҫ����һ��
//	return 0;
//}

//���õ�����:
//1.������
//2.������ֵ

//int Add(const int& a, const int& b)
//{
//	return a + b;
//}
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}
//void MySwap(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//���ô��ο���������Ͳ���
//void MySwap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 1;
//	cout << a << " " << b << endl;
//	MySwap(&a, &b);
//	cout << a << " " << b << endl;
//	MySwap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}
//���ô��ο������Ч��
//struct A
//{
//	int a[10000];
//};
//void TestFunc1(A a) { return; }
//void TestFunc2(A& a) { return; }
//int main()
//{
//	A a = { 0 };
//	size_t begin = clock();
//	for (size_t i = 0; i < 10000; i++)
//		TestFunc1(a);
//	size_t end = clock();
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; i++)
//		TestFunc2(a);
//	size_t end1 = clock();
//	cout << end - begin << endl;//13
//	cout << end1 - begin1 << endl;//0
//	return 0;
//}

//int& Count()
//{
//	static int n = 0;
//	n++;
//	//...
//	return n;
//}
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		cout << Count() << endl;
//	}
//	return 0;
//}

//int& Count()
//{
//	int n = 0;
//	n++;
//	//...
//	return n;
//}
//int count()
//{
//	int n = 0;
//	n++;
//	//...
//	return n;
//}
//int main()
//{
//	cout << Count() << endl;
//	//warning C4172 : ���ؾֲ���������ʱ�����ĵ�ַ: n
//	//������һ�����ٵĿռ�,������Ұָ�������
//	cout << count() << endl;
//	return 0;
//}
//
//int& Add(const int& a,const int& b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << ret << endl;//3
//	//warning C4172: ���ؾֲ���������ʱ�����ĵ�ַ: c
//	//Add����ֵ��int&����,���غ�c�ȷ��ظ���ʱ����(������int&),Ȼ����ʱ�������ظ�int&������ret,�ܵ�˵ret��
//	//Add������c�ı���,����Add�������ý�����,����ջ֡����,�ռ��ͷ�,����ret��һ���Ƿ��Ŀռ�,�����ڷ�����һ��
//	//�ͷ��˵Ŀռ�
//
//	//Add(3, 4);
//	//cout << ret << endl;//7
//	//û�ж�ret���и�ֵ,Ϊʲôret��ֵ��Ϊ��7?
//	//��:����������֪:�ܵ���˵ret��Add�����б���c�ı���(����״̬��ret�ĵ�ַ��c�ĵ�ַ��ͬ������֤��һ��)
//	//Add(1,2)�����������,����ջ֡����,�ռ��ͷ�,Ȼ�����Add(3,4),ͬһ������,ջ֡����ͬһ��λ�ú�ͬ����
//	//��С,Ȼ��������,ret����c�ı���,c���7,ret����7(��Ȼ���Ϸ�)
//
//	printf("aafkjkl;akfkjjlajkl;fj\n");
//	cout << ret << endl;//��һ�����ֵ
//	return 0;
//}

//struct A
//{
//	int a[10000];
//};
//
//A a;
//
//A Func1()
//{
//	return a;
//}
//A& Func2()
//{
//	return a;
//}
//int main()
//{
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000; i++)
//		Func1();
//	size_t end1 = clock();
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000; i++)
//		Func2();
//	size_t end2 = clock();
//	cout << end1 - begin1 << endl;//3
//	cout << end2 - begin2 << endl;//0
//	return 0;
//}

//int main()
//{
//	int a = 10;//a������int��
//	int& ra = a;//ra������int&��
//
//	cout << "&a = " << &a << endl;//&a��int*��
//	cout << "&ra = " << &ra << endl;//&ra��int*��
//	//&a == &ra
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//	//cout << "a = " << a << endl;//a = 10
//	//int& ra = a;
//	//ra = 20;
//	//cout << "a = " << a << "ra = " << ra << endl;//a = 20ra = 20
//	//int* pa = &a;
//	//*pa = 30;
//	//cout << "a = " << a << "ra = " << ra << "*pa = " << *pa << endl;//a = 30ra = 30*pa = 30 
//
//	short d = 2;
//	short& rd = d;
//	cout << sizeof(rd) << sizeof(d) << sizeof(&d) << sizeof(&rd) << endl;
//	//2 2 4/8 4/8
//	cout << d + 1 << endl;//3
//	cout << rd + 1 << endl;//3
//	cout << &d << endl;
//	cout << &d + 1 << endl;
//	cout << &rd << endl;
//	cout << &rd + 1 << endl;
//	return 0;
//}
//��Ƶ����:
//���ú�ָ�������
//1.�����﷨���Ǹ���������һ������,ָ�����Ǵ洢������ַ
//2.���ò���ʼ������ʹ��,ָ�����
//3.����û�ж༶����,�ж༶ָ��
//4.��NULLָ��,û��NULL����
//5.ָ����Ҫ��ʾ������,���ñ�������æ���
//6.����������һ��ʵ���Ժ�,������������һ��ʵ��,ָ��ָ��һ��������,����ָ����һ����
//7.����+1����ʵ��+1,ָ��+1�ӵľ���ָ�����͵Ĵ�С
//8.sizeof�������������͵Ĵ�С,sizeofָ����OSƽ̨,������ƽ̨�й�,32/64bit--->4/8�ֽ�
//9.�����Ƕ�ָ���һ���װ
//10.���ñ�ָ��ʹ�ð�ȫ

//��������,�ؼ���inline
//Swap������һ��Ƶ�����õĺ���,���ú���Ҫ����ջ֡,����ջ֡���пռ�����ܵ����ĵ�
//��ν��?
//��:C���Եķ�ʽ�Ǻ꺯��,���Ǻ꺯���кܶ�ȱ��,ȱ��--->���������(ֱ���滻),��������̫��,���׳���
//C++�ķ�ʽ����������,��Ⱥ꺯��,inline�������������������(������ջ֡,�ܵ���,��������ͨ����д�������Ʋ����׳���)
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//inline void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	size_t begin1 = clock();
//	for (int i = 0; i < 10000000; i++)
//	{
//		//cout << "a = " << a << ", b = " << b << endl;
//		Swap(a, b);
//		//cout << "a = " << a << ", b = " << b << endl;
//	}
//	size_t end1 = clock();
//	cout << end1 - begin1 << endl;//��ֵ��û����inline���β�ֵС,˵��inline���κ������Ż�����
//
//	//����Ƶ�����õ�С��������inline
//
//	//f(1);
//	//�������������������Ͷ������,����ᵼ�����Ӵ���,��Ϊinline��չ��,����ʱ��û�к�����ַ��,���Ӿͻ��Ҳ���
//	//�ᱨ���Ӵ���
//	return 0;
//}
////C++�н���ʹ��const, enum, inline����곣��,�꺯��

//C++11 auto�Զ��Ƶ�����
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//
//	char ch = 'a';
//	auto d = ch;
//	auto e = TestAuto();
//
//	auto c = 'd';
//	int* p = NULL;
//	cout << typeid(p).name() << endl;//int *
//	cout << typeid(c).name() << endl;//char
//	cout << typeid(a).name() << endl;//int
//	cout << typeid(b).name() << endl;//int
//	cout << typeid(ch).name() << endl;//char
//	cout << typeid(d).name() << endl;//char
//	cout << typeid(e).name() << endl;//int
//	cout << typeid(TestAuto).name() << endl;//int __cdecl(void)
//	cout << typeid(TestAuto()).name() << endl;//int
//	//C++�д�ӡһ������/�������͵��÷�,cout << typeid(variableName/functionName).name() << endl;
//
//	//autoʹ�ó���
//	//std::map<std::string, std::string> m;
//	////std::map<std::string, std::string>::iterator it = m.begin;
//	//auto it = m.begin;
//	cout << "==============================================" << endl;
//	int x = 10;
//	auto aa = &x;
//	auto* bb = &x;
//	auto& cc = x;
//	cc = 20;
//	cout << x << endl;//20---˵��cc������(��Ϊx�ı���)
//	int& ccc = x;
//	auto cccc = x;
//	cccc = 0;
//	cout << x << endl;//20---˵��cccc��������
//	cout << typeid(ccc).name() << endl;//int&--->int?
//	cout << typeid(10).name() << endl;//int
//	cout << typeid(&x).name() << endl;//int*
//	cout << typeid(x).name() << endl;//int
//	cout << typeid(aa).name() << endl;//int*
//	cout << typeid(bb).name() << endl;//int*
//	cout << typeid(cc).name() << endl;//int&--->int?
//	cout << typeid(cccc).name() << endl;//int
//	//����,ʹ��auto����ָ������ʱ,auto��auto*����,��ʹ��auto�����������͵�ʱ��,
//	//ֻ����auto&,�����auto�ᵼ�¸�ֵ�����ø����
//	*aa = 20;
//	cout << x << endl;//20
//	*bb = 30;
//	cout << x << endl;//30
//	cc = 40;
//	cout << x << endl;//40
//
//	return 0;
//}

//auto��ͬһ�ж���������
//��ͬһ�ж���������ʱ,��Щ������������ͬ���͵�,������������ᱨ��,
//��Ϊ������ֻ��Ե�һ�����ͽ����Ƶ�,Ȼ��������Ƶ����������Ͷ�����������
//int main()
//{
//	auto a = 1, b = 2;
//	//auto c = 2.0, d = 3;//�������:���������б��У���auto������ʼ���Ƶ�Ϊͬһ����
//	return 0;
//}

//auto�����Ƶ��ĳ���
//1.�����Ƶ������β�,eg.
//void TestAuto1(auto a) {}//error,auto�Ǳ������ڱ���׶��Զ��Ƶ���,�����Ƶ�������,Ҫ���������н׶β���
////2.�����Ƶ�����Ķ���
//void TestAuto2()
//{
//	int arr1[] = { 1, 2 ,3 };
//	auto arr2[] = { 4, 5, 6 };//error,
//}

//���ڷ�Χ��forѭ��(C++11)--->�ص�:����������,��������
//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < (int)(sizeof(array) / sizeof(array[0])); ++i)
//	{
//		array[i] *= 2;
//		cout << array[i] << endl;//2 4 6 8 10
//	}
//	//����ԭ���ǵ�����
//	for (auto e : array)//ȡarray�е�ֵ������e,e�ı���,����ı�array�����е�ֵ
//		e *= 2;
//
//	for (auto e : array)
//		cout << e << " ";//2 4 6 8 10
//	cout << endl;
//
//	for (auto& e : array)//ȡarray�еı�����e,e�ı���,array�����е�ֵҲ�ı���
//		e *= 2;
//
//	for (auto e : array)
//		cout << e << " ";//4 8 12 16 20
//	cout << endl;
//
//	//ע��:��Χfor����ͨѭ������,������continue�ؼ��ֽ�������ѭ��,Ҳ������break�ؼ�������������ѭ��
//}
//
////��Χfor��ʹ������
////forѭ���ĵ�����Χ������ȷ����
////�����������,���������һ��Ԫ�غ����һ��Ԫ�صķ�Χ
////���������,Ӧ���ṩbegin��end����,begin��end����forѭ�������ķ�Χ
//void TestFor2(int array[])
//{
//	//for (auto& e : array)
//		//cout << e << endl;//error,for�ķ�Χ��ȷ��
//}
//int main()
//{
//	TestFor();
//	return 0;
//}

//ָ���ֵnullptr(C++11)--->C++11�н�nullptr�����Ϊ�ؼ���,ȡ��C++98�е�NULLʹ��

//NULLʵ����һ����,�ڴ�ͳCͷ�ļ�(stddef.h)��,���Կ��������´���
//#ifndef NULL
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void*)0)
//#endif
//#endif
//�������������:���û����NULL������ŵ�ǰ����,���������__cplusplus�������,�궨��NULL�������Ϊ0
//����궨��NULL�������Ϊ((void*)0)ָ��
//��:C++��NULL����0,C��NULL��(void*)ָ��ȼ���0,����ʹ��NULLʱ���������º������ص�һЩ�鷳

//Ϊ����ߴ���Ľ�׳��,C++��ʹ��ָ���ֵ�ĵط�����ʹ��nullptr,��Ϊnullptr�������Ŀ�ָ��
void f(int)//C++���βν���ȴ����,��д�β�Ҳ�ǿ��Ե�,C������Ҫд(��д�ᱨ��)
{
	cout << "f(int)" << endl;
}
void f(int*)//�βν��ղ���,��д�β�Ҳ�ǿ��Ե�,C������Ҫд(��д�ᱨ��)
{
	cout << "f(int*)" << endl;
}
void TestPtr()
{
	int* p1 = NULL;
	//�ȼ���
	int* p2 = 0;
	//...
}
int main()
{
	TestPtr();
	f(0);//f(int)
	f(NULL);//f(int)
	f((int*)NULL);//f(int*)
	f(nullptr);//f(int*)

	cout << sizeof(nullptr) << endl;//4/8--->64λ������8,˵��nullptr���ʾ���ָ��
	cout << sizeof((void*)0) << endl;//4/8--->64λ������8,˵��(void*)0��ָ��
	cout << sizeof(NULL) << endl;//4--->64λ������4,˵��NULL��C++�б�����Ϊ����0,��ָ��û��ϵ
	return 0;
}