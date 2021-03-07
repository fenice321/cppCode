#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include "F.h"
using namespace std;
//函数重载
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
//问:下面两个函数能形成函数重载吗?
//答:不能,因为采用gnu-c++的函数命名修饰规则,两个函数修饰后函数名都是 _Z8TestFunci,编译器无法区分它们
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
//	int& rb = a;//rb是a的别名,rb是a的引用,还需要注意的是这里&符号不是取地址
//	cout << a << " " << rb << endl;//10 10
//	cout << &a << " " << &rb << endl;
//	//&a和&rb地址"相同",a是int型,&a是int*型,rb是int&型,&rb是int*型
//	a = 20;
//	cout << a << " " << rb << endl;//20 20
//	cout << &a << " " << &rb << endl;
//	//&a和&rb地址"相同",a是int型,&a是int*型,rb是int&型,&rb是int*型
//	rb = 30;
//	cout << a << " " << rb << endl;//30 30
//	cout << &a << " " << &rb << endl;
//	//&a和&rb地址"相同",a是int型,&a是int*型,rb是int&型,&rb是int*型
//
//	int& rrb = rb;
//	//一个变量可以有多个别名
//	//可以给别名取别名
//	int& rc = a;
//	cout << &rrb << " " << &rc << endl;
//	//&rrb==&rc==&rb==&a,rc是int&型,&rc是int*型,rrb是int&型,&rrb是int*型
//
//	//double& rd = a;//编译错误,引用类型必须与引用实体类型一样
//
//	//int& re;
//	//编译错误,引用必须在定义的时候初始化,换个角度,C语言中指针可以初始化也可以不初始化
//	//但是不初始化可能会造成野指针,引用的引入就是为了解决指针中的一些不足,所以强制要求
//	//必须初始化,否则直接编译不通过,使编程更加安全了
//
//	int b = 200;
//	rb = b;//这句话的意思是把b赋值给rb,还是rb变成b的别名?答:通过调试可以判断出是把b赋值给rb
//	//引用一旦引用一个实体,再不能引用其他实体,只是赋值而已
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
//	//编译错误,a为常变量const int类型对应的引用类型应为const int&,引用类型必须和引用实体类型保持一致
//	//左边可读可写,右边只读--->权限放大了
//
//	const int a = 10;
//	const int& ra = a;
//	//编译通过,右边常变量只读不可写,左边常引用也是只渡不可写,权限相同,
//
//	int c = 10;
//	const int& d = c;//编译通过--->左边只能读,右边可读可写--->权限缩小
//
//	//size_t strlen(const char* str);--->入参是const char*,这样char*可以赋值,const char*也可以
//	//注意:指针和引用在初始化赋值时,权限可以缩小但是不能放大
//
//	//int& rc = 10;//编译错误
//	//右边常量区开的一块空间存10,只读,左边可读可写--->权限放大了--->错误
//
//	const int& rc = 10;//编译通过,引用常数要加const修饰
//
//	//整型和浮点型之间可以互相赋值,隐式类型转换
//	double dd = 2.22;
//	int i = dd;
//
//	//int& ri = dd;//编译错误--->引用类型必须和引用实体类型保持一致
//	const int& ri = dd;//编译成功--->产生警告"double"转换到"const int"可能发生数据丢失
//
//	double e = 12.34;
//	double& rd = e;
//	//int& ri = e;//编译错误,引用类型和引用实体类型要保持一致
//	return 0;
//}

//引用的作用:
//1.做参数
//2.做返回值

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
//引用传参可以做输出型参数
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
//引用传参可以提高效率
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
//	//warning C4172 : 返回局部变量或临时变量的地址: n
//	//访问了一段销毁的空间,类似于野指针的问题
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
//	//warning C4172: 返回局部变量或临时变量的地址: c
//	//Add返回值是int&引用,返回后c先返回给临时变量(类型是int&),然后临时变量返回给int&型引用ret,总的说ret是
//	//Add函数中c的别名,但是Add函数调用结束后,函数栈帧销毁,空间释放,所以ret是一个非法的空间,类似于访问了一个
//	//释放了的空间
//
//	//Add(3, 4);
//	//cout << ret << endl;//7
//	//没有对ret进行赋值,为什么ret的值变为了7?
//	//答:上述分析可知:总的来说ret是Add函数中变量c的别名(调试状态下ret的地址和c的地址相同可以验证这一点)
//	//Add(1,2)函数调用完毕,函数栈帧销毁,空间释放,然后调用Add(3,4),同一个函数,栈帧开辟同一个位置和同样的
//	//大小,然后调用完毕,ret还是c的别名,c变成7,ret就是7(虽然不合法)
//
//	printf("aafkjkl;akfkjjlajkl;fj\n");
//	cout << ret << endl;//是一个随机值
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
//	int a = 10;//a类型是int型
//	int& ra = a;//ra类型是int&型
//
//	cout << "&a = " << &a << endl;//&a是int*型
//	cout << "&ra = " << &ra << endl;//&ra是int*型
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
//高频考点:
//引用和指针的区别
//1.引用语法上是给变量定义一个别名,指针则是存储变量地址
//2.引用不初始化不能使用,指针可以
//3.引用没有多级引用,有多级指针
//4.有NULL指针,没有NULL引用
//5.指针需要显示解引用,引用编译器帮忙完成
//6.引用在引用一个实体以后,不能再引用另一个实体,指针指向一个变量后,可以指向另一个变
//7.引用+1就是实体+1,指针+1加的就是指针类型的大小
//8.sizeof引用是引用类型的大小,sizeof指针与OS平台,编译器平台有关,32/64bit--->4/8字节
//9.引用是对指针的一层包装
//10.引用比指针使用安全

//内联函数,关键字inline
//Swap函数是一个频繁调用的函数,调用函数要建立栈帧,建立栈帧是有空间和性能的消耗的
//如何解决?
//答:C语言的方式是宏函数,但是宏函数有很多缺点,缺点--->不方便调试(直接替换),复杂括号太多,容易出错
//C++的方式是内联函数,相比宏函数,inline内联函数完美解决问题(不建立栈帧,能调试,函数和普通函数写起来相似不容易出错)
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
//	cout << end1 - begin1 << endl;//差值比没有用inline修饰差值小,说明inline修饰函数有优化作用
//
//	//建议频繁调用的小函数加上inline
//
//	//f(1);
//	//内联函数不建议声明和定义分离,分离会导致链接错误,因为inline被展开,链接时就没有函数地址了,链接就会找不到
//	//会报链接错误
//	return 0;
//}
////C++中建议使用const, enum, inline替代宏常量,宏函数

//C++11 auto自动推导类型
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
//	//C++中打印一个变量/函数类型的用法,cout << typeid(variableName/functionName).name() << endl;
//
//	//auto使用场景
//	//std::map<std::string, std::string> m;
//	////std::map<std::string, std::string>::iterator it = m.begin;
//	//auto it = m.begin;
//	cout << "==============================================" << endl;
//	int x = 10;
//	auto aa = &x;
//	auto* bb = &x;
//	auto& cc = x;
//	cc = 20;
//	cout << x << endl;//20---说明cc是引用(即为x的别名)
//	int& ccc = x;
//	auto cccc = x;
//	cccc = 0;
//	cout << x << endl;//20---说明cccc不是引用
//	cout << typeid(ccc).name() << endl;//int&--->int?
//	cout << typeid(10).name() << endl;//int
//	cout << typeid(&x).name() << endl;//int*
//	cout << typeid(x).name() << endl;//int
//	cout << typeid(aa).name() << endl;//int*
//	cout << typeid(bb).name() << endl;//int*
//	cout << typeid(cc).name() << endl;//int&--->int?
//	cout << typeid(cccc).name() << endl;//int
//	//综上,使用auto声明指针类型时,auto和auto*均可,而使用auto声明引用类型的时候,
//	//只能用auto&,如果用auto会导致赋值和引用搞混淆
//	*aa = 20;
//	cout << x << endl;//20
//	*bb = 30;
//	cout << x << endl;//30
//	cc = 40;
//	cout << x << endl;//40
//
//	return 0;
//}

//auto在同一行定义多个变量
//在同一行定义多个变量时,这些变量必须是相同类型的,否则编译器将会报错,
//因为编译器只会对第一个类型进行推导,然后用这个推导出来的类型定义其他变量
//int main()
//{
//	auto a = 1, b = 2;
//	//auto c = 2.0, d = 3;//编译错误:在声明符列表中，“auto”必须始终推导为同一类型
//	return 0;
//}

//auto不能推导的场景
//1.不能推导函数形参,eg.
//void TestAuto1(auto a) {}//error,auto是编译器在编译阶段自动推导的,这里推导不出来,要到程序运行阶段才行
////2.不能推导数组的定义
//void TestAuto2()
//{
//	int arr1[] = { 1, 2 ,3 };
//	auto arr2[] = { 4, 5, 6 };//error,
//}

//基于范围的for循环(C++11)--->特点:看起来抽象,用起来简单
//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < (int)(sizeof(array) / sizeof(array[0])); ++i)
//	{
//		array[i] *= 2;
//		cout << array[i] << endl;//2 4 6 8 10
//	}
//	//具体原理是迭代器
//	for (auto e : array)//取array中的值拷贝给e,e改变了,不会改变array数组中的值
//		e *= 2;
//
//	for (auto e : array)
//		cout << e << " ";//2 4 6 8 10
//	cout << endl;
//
//	for (auto& e : array)//取array中的别名给e,e改变了,array数组中的值也改变了
//		e *= 2;
//
//	for (auto e : array)
//		cout << e << " ";//4 8 12 16 20
//	cout << endl;
//
//	//注意:范围for与普通循环类似,可以用continue关键字结束本次循环,也可以用break关键字来跳出整个循环
//}
//
////范围for的使用条件
////for循环的迭代范围必须是确定的
////对于数组而言,就是数组第一个元素和最后一个元素的范围
////对于类而言,应该提供begin和end方法,begin和end就是for循环迭代的范围
//void TestFor2(int array[])
//{
//	//for (auto& e : array)
//		//cout << e << endl;//error,for的范围不确定
//}
//int main()
//{
//	TestFor();
//	return 0;
//}

//指针空值nullptr(C++11)--->C++11中将nullptr引入成为关键字,取代C++98中的NULL使用

//NULL实际是一个宏,在传统C头文件(stddef.h)中,可以看到有如下代码
//#ifndef NULL
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void*)0)
//#endif
//#endif
//上述代码大意是:如果没定义NULL这个符号的前提下,如果定义了__cplusplus这个符号,宏定义NULL这个符号为0
//否则宏定义NULL这个符号为((void*)0)指针
//即:C++中NULL就是0,C中NULL是(void*)指针等价于0,导致使用NULL时会遇到如下函数重载的一些麻烦

//为了提高代码的健壮性,C++中使用指针空值的地方建议使用nullptr,因为nullptr是真正的空指针
void f(int)//C++中形参接收却不用,不写形参也是可以的,C语言中要写(不写会报错)
{
	cout << "f(int)" << endl;
}
void f(int*)//形参接收不用,不写形参也是可以的,C语言中要写(不写会报错)
{
	cout << "f(int*)" << endl;
}
void TestPtr()
{
	int* p1 = NULL;
	//等价于
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

	cout << sizeof(nullptr) << endl;//4/8--->64位机下是8,说明nullptr本质就是指针
	cout << sizeof((void*)0) << endl;//4/8--->64位机下是8,说明(void*)0是指针
	cout << sizeof(NULL) << endl;//4--->64位机下是4,说明NULL在C++中被定义为常数0,和指针没关系
	return 0;
}