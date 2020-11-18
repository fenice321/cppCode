#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
//注意:<iostream.h>在旧库中包含,现在高版本编译器摒弃不用了
//#include <iostream.h>//i/ostream input/output stream 输入/输出流
#include <iostream>//与C语言头文件写法不一样,没有.h后缀名
using namespace std;
//定义了一个命名空间就相当于定义了一个新的作用域,命名空间中的所有内容都局限于该命名空间中

#if 0
//命名空间的定义格式
//关键字:namespace命名空间
//命名空间为空可以编译通过
namespace N
{
	//定义变量
	//定义函数
	//将变量和函数统称为当前命名空间的成员
}

int a = 10;
//命名空间有三种定义方式
//方式一:最常见的方式
namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

//方式二:命名空间可以嵌套
//类似于一个学校中可以包含多个学院
namespace N2
{
	int a = 10;
	int b = 20;
	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int c = 10;
		int d = 20;
		int Mul(int left, int right)
		{
			return left * right;
		}
	}
}

//方式三:在同一个工程中可以定义多个名字相同的命名空间
//不会冲突
//编译器会将多个相同名称的命名空间合并成一个
namespace N1
{
	//相同作用域中不能出现相同的名字
	//相同名字的多个命名空间中:也不能出现相同的名字,
	//因为编译器会将多个相同的名字的命名空间最终合并成一个
	//int a = 30;//err:相同名称的命名空间中不能定义相同的变量
	int Div(int left, int right)
	{
		if (0 == right)
		{
			printf("error! Div Zero:\n");
			return -1;
		}
		return left / right;
	}
}
#endif
#if 0
//编译通过
namespace N
{
	int a = 10;
	//嵌套的方式定义命名空间,只不过内嵌命名空间名和外部命名空间名相同
	//该种方式也不会冲突,相当于外层N命名空间中有包含了一个N的命名空间
	namespace N
	{
		int b = 10;
		int a = 10;
	}
}
#endif

//命名空间中成员的使用方式
#if 0
//方式一:命名空间名::成员
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
}
int a = 20;
int main()
{
	//命名空间名::中的::是作用域运算符
	//N::N::b = 20;

	int a = 30;
	//就近原则
	printf("%d\n", a);//30

	//如果要访问全局作用域中的a
	//::作用域运算符
	//::a 明确告诉编译器说明要访问全局作用域中的a
	printf("%d\n", ::a);//20

	//访问N命名空间中的a
	//N::a 明确告诉编译器说明要访问的是N命名空间中的a
	printf("%d\n", N::a);
	return 0;
}
#endif

#if 0
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
}

//方式二:
//该场景中对N命名空间中某些成员访问的非常频繁

//该条语句加上之后,相当于将N命名空间中的a当成当前文件中的一个全局变量来使用
//优点:写代码简单了
//缺点:如果该文件中有相同名称的全局变量或者函数就会产生冲突
//如果产生冲突,怎么办?-----按照方式一 命名空间名::成员访问即可
using N::a;
//如果该文件中也有一个全局a,必然会产生冲突,只能按照方式一 命名空间名::成员来使用
//int a = 10;
int main()
{
	int a = 20;
	//访问N命名空间中的a
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);

	//为了写代码简单,想要直接访问N命名空间中的a
	printf("%d\n", N::a);
	printf("%d\n", a);//就近原则
	printf("%d\n", ::a);
	return 0;
}
#endif

#if 0
//方式三:假设N命名空间中许多成员在当前文件中非常频繁的使用
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
}
//using N::a;//N命名空间中的a被导出来当作全局变量访问
//using N::b;
//using N::Add;
//using N::Add;

//将当前N命名空间中所有的成员当成该文件中的全局变量
//优点:使用非常简单
//缺点:产生冲突的可能性非常大
//如果产生冲突,解决:按照方式一:命名空间名::成员 来使用 
using namespace N;
int a = 20;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	//printf("%d\n", a);//N命名空间中的a被导出来当作全局变量访问
	printf("%d\n", ::a);

	printf("%d\n", N::b);
	printf("%d\n", N::b);
	printf("%d\n", N::b);
	printf("%d\n", N::b);
	printf("%d\n", N::b);
	printf("%d\n", N::b);
	printf("%d\n", b);
	printf("%d\n", ::b);

	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	Add(1, 2);
	::Add(1, 2);
	N::Add(1, 2);
	return 0;
}
#endif

//C++中的输入和输出
//注意:C语言中输入和输出方式在C++中仍旧能使用---因为C++要兼容C语言

//C++自己还是搞了一套输入和输出的方式, 因为C语言中输入输出方式太麻烦了
//需要记忆大量的格式控制,一些输入输出错误编译器会忽略
#if 0
int main()
{
	//C/C++中都不会报错,编译能通过
	//int a = 10;
	//scanf("%d%d", &a);
	//printf("%d\n", a);
	//C/C++中都不会报错,编译能通过
	//printf("%d\n", 10, 20, 30);
	//printf("%d %s %f\n", 10);
	return 0;
}
#endif
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> a;
	cin >> b >> c;
	cout << a << " " << b << " " << c << endl;
	//C++中的输出
	//不需要记忆格式控制非常方便
	cout << 10;
	cout << 12.34 << "\n";
	cout << "hello" << 123 << "world!!!" << endl;//换行endl
	return 0;
}