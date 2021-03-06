#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdlib>
#include <stdio.h>	
#include "Test.h"
#if 0
//C++版本的hello world
#include <iostream>
using namespace std;
int main()
{
	cout << "Hello World!" << endl;
	return 0;
}
#endif
#if 0
//C++兼容C语言
//命名空间
//C语言语法规定定义标识符不能定义为关键字以及系统内部包含的,但是定义库中的函数名为变量名也可以
//但是此处还是编译不过,因为头文件在预处理阶段循环展开,出现scanf函数的声明,与此处的scanf变量名名字冲突,产生歧义
int scanf = 0;
#endif
#if 0
//命名冲突问题:项目协作中两名同事取名冲突了怎么办?
//C++引入了命名空间来解决这个问题
namespace tzh
{
	int scanf = 0;//scanf还是全局变量,放到tzh命名空间中了
}
#if 0
//这两处使用导致命名空间tzh中的scanf变量导出来了,与展开的scanf函数声明冲突了,编译通不过
using tzh::scanf;
using namespace tzh;
#endif
int main()
{
	//printf("%d ", scanf);//有歧义,打印失败
	printf("%p ", scanf);//打印的是头文件展开的函数名,函数名就是地址
	printf("%d ", tzh::scanf);//打印成功,打印的是命名空间tzh中的变量scanf的值,其中::是作用域限定符
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
//方式二:直接导出---容易与全局变量冲突
using tzh::a;
using tzh::b;
using tzh::c;
#endif

//方式三:全部导出---更容易与全局变量冲突
using namespace tzh;
int main()
{
#if 0
	//直接访问命名空间中的a,b,c出错---未定义
	printf("%d ", a);
	printf("%d ", b);
	printf("%d ", c);
#endif

#if 0
	//方式一:直接通过作用域限定符
	printf("%d ", tzh::a);
	printf("%d ", tzh::b);
	printf("%d ", tzh::c);
#endif

#if 0
	//方式二:直接导出---容易与全局变量冲突
	printf("%d ", a);
	printf("%d ", b);
	printf("%d ", c);
#endif

	//方式三:全部导出---更容易与全局变量冲突
	printf("%d ", a);
	printf("%d ", b);
	printf("%d ", c);

	//综上:推荐在项目中,尽量不要全部展开,最好用作用域限定符或者单独展开命名空间中的某一项或者某几项,防止命名冲突
	//而日常练习时推荐使用方法三全部导出,更加方便
	return 0;
}
#endif

//#include <iostream>
////C++库中的东西都放在std命名空间中
//using namespace std;
////int cout = 0;//冲突
//int main()
//{
//	cout << "Hello World!" << endl;
//	//printf("%d ", cout);//冲突
//	return 0;
//}

//#include <iostream>
//#include <vector>
////C++库中的东西都放在std命名空间中
//int main()
//{
//	std::cout << "Hello C++!" << std::endl;
//	int i = 0;
//	std::vector<int> v;//模板
//	std::cin >> i;
//	std::cout << i << std::endl;
//	return 0;
//}

//#include <vector>
//#include <iostream>
////可以把命名空间中常用的变量或者类型展开使用
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

////N1为命名空间名,命名空间中可以定义变量,函数,类型等等
//namespace N1
//{
//	int a;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
////命名空间可以嵌套
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
////命名空间可以嵌套,并且嵌套的命名空间可以与外层的命名空间名字相同
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
////同一个工程中允许存在多个名字相同的命名空间,编译器最终会将它们合成一个命名空间,
////注意两个名字相同命名空间中不能有相同的标识符,否则编译器合并后会冲突
//namespace N
//{
//	int e = 3;
//	int g = 9;
//	//int a = 3;//注意两个名字相同命名空间中不能有相同的标识符,否则编译器将其合并命名空间后会冲突
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
////#include <iostream.h>//vc6.0支持,现在新的编译器都不支持
//int main()
//{
//	//1.cout/cin相对printf/scanf可以自动识别类型,控制输出格式
//	//2.可以一行连续输出,也可以一行连续输入
//	//3.endl---换行符等价于'\n'
//	//类型自动识别底层原理:cout cin到底是什么? 答:cout和cin是类定义的对象,是全局的对象
//	//底层用了:类和对象+运算符重载+函数重载
//	cout << "hello world!\n" << endl;
//	cout << "Hello Worle!" << endl;
//	int i = 0;
//	char ch = 48;
//	cout << ch << endl;//此处输出ASCII码表48对应的字符0
//	double d = 3.33;
//	cout << i << endl;
//	cout << d << endl;
//	cout << &i << endl;//int*按地址输出
//	cout << &ch << endl;//char*被当成字符串了,打印到'\0'结束,输出乱码
//
//	cout << i << "---" << d << "---" << &i << "---" << &ch << "---" << ch << endl;//一行连续输出,混合类型
//
//	cin >> i;//输入不需要使用取地址,因为C++中的引用
//	cout << i << endl;
//
//	cin >> i;
//	cin >> ch >> d;//一行连续输入,不同类型都可以
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
//	//实际使用时,cin/cout和printf/scanf各有优势,混着用,哪个方便用哪个,混着用是没有问题的
//	//这种场景cin/cout很方便
//	int i = 0;
//	double d = 0.0;
//	//cin >> i >> d;
//	//cout << i << "---" << d;
//
//	//这种场景printf方便
//	struct Student s = { "peter", 18 };
//	printf("name:%s, age:%d\n", s.name, s.age);
//	cout << "name:" << s.name << ", " << "age:" << s.age << endl;
//
//	//保留小数点后两位
//	//这种场景printf方便
//	d = 10.0 / 3.0;
//	printf("d = %.2lf\n", d);
//	cout << d << endl;
//	cout.unsetf(ios::fixed);
//	cout << "d = " << setprecision(3) << d << endl;//输出d = 3.33
//	return 0;
//}

#include <iostream>
using namespace std;
//缺省参数
void TestFunc1(int a = 1)
{
	cout << a << endl;
}
//全缺省参数
void TestFunc2(int a = 10, int b = 20, int c = 30)
{
	cout << a << " " << b << " " << c << endl;
}
//半缺省参数
void TestFunc3(int a, int b = 10, int c = 20)
{
	cout << a << " " << b << " " << c << endl;
}
//关于缺省参数注意事项:
//1.半缺省参数必须从右往左依次来给出,不能间隔着给出
//2.缺省参数不能在函数声明和定义中同时出现
//void TestFunc4(int a = 100);
//void TestFunc4(int a = 200)
//{
//
//}
//3.缺省参数在做项目时最好放到函数声明中
//4.缺省值必须是常量或者全局变量
//5.C语言不支持缺省参数
//int main()
//{
//	TestFunc1();//输出默认1
//	TestFunc1(10);//输出给定的10
//
//	TestFunc2();//输出默认的10 20 30
//	TestFunc2(40);//输出40 20 30
//	TestFunc2(50, 60);//输出50 60 30
//	TestFunc2(70, 80, 90);//输出给定的70 80 90
//
//	TestFunc3(10);//10 10 20
//	TestFunc3(20, 30);//20 30 20
//	TestFunc3(40, 50, 60);//40 50 60
//	return 0;
//}

//C++中缺省参数的一种使用场景
//void StackInit(Stack* pst, int n = 8)
//{
//	pst->a = (STDataType*)malloc(n * sizeof(STDataType));
//	//......
//}
//StackInit(&s);//如果不知道开多大的空间就使用默认的大小
//StackInit(&s, 100);//如果知道开始至少要插入100个数据,就可以给定100,避免后续频繁增容以提高效率

//C语言中,不支持同名函数
//C++为了解决这个问题,引入了函数重载,支持同名函数,但是又要求,参数不同(个数or类型or顺序)
int add(int i, int j)//C语言中编译出错,C++中可以运行
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

//函数重载
//函数重载是函数的一种特殊情况,C++允许在同一作用域中声明几个功能类似的同名函数,这些同名函数的形参列表(参数个数or
//参数类型or参数顺序不同时)均可构成函数重载,常用来处理实现功能类似但是数据类型不同的问题

void f(int i, double j) {}
void f(double i, int j) {}
void f(double i) {}
//int f(double i) {}//error 返回值不同不构成函数重载

//下面两个函数构成重载吗?
//答:不构成,因为返回值不同不是函数重载的条件
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

//面试题:
//1.什么是函数重载
//答:同一个作用域内函数名相同的不同函数,参数个数,顺序,类型不同构成函数重载
//2.为什么C语言不支持函数重载,C++支持函数重载

//test.h test.cpp main.cpp
//预处理---头文件循环展开/宏替换/去除注释/条件编译
//		test.i	 main.i
//编译---检查语法(语法分析->词法分析->语义分析->符号汇总),生成汇编代码
//		test.s   main.s
//汇编---把汇编代码转成可重定向的二进制机器代码,形成符号表
//		test.o   main.o
//链接---把*.o和libc.so库链接成可执行性程序,合并段表,合并符号表和符号表的重定位

//C++底层用了name Mangling命名倾轧技术,相同函数名不同参数列表的函数会被处理成不同的函数名,不会有冲突,
//C语言没有这个技术,所以C语言会显示标识符重定义