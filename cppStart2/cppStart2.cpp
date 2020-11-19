
//注意:
//1.C语言中标准输入输出在C++中仍旧可以使用
//scanf/getchar/gets/fgets
//printf/putchar/puts/fputs
//2.C++中的输入输出使用起来更加便捷
//cin输入 cout输出 #include <iostream> + using namespace std;
//比较老的编译器用<iostream.h>旧库,新的编译器摒弃了这套库
//std命名空间是C++语言提供的
//cin和cout包含在std的命名空间中,但不是说std的命名空间中只包含了cin和cout
//C语言标准库函数不在std标准命名空间中

#if 0
#include <iostream>
//using namespace std;
int main()
{
	//cout << "Hello World!\n" << endl;
	std::cout << "Hello World!\n" << std::endl;
	//system命令也在标准std命名空间中有
	std::system("pause");
	return 0;
}
#endif

//C和C++关于函数方面的区别:
//1.函数返回值类型
//2.函数参数类型
//结论:C++编译器比C语言编译器对函数参数,返回值检查更加严格
//3.C++函数参数可以带一些默认值
//4.函数命名规则不一样
#if 0
void testFunc()
{

}
//没有返回值,也没有参数 
//C语言环境中编译通过,可以传0,1,2,3...N个参数
int main()
{
	testFunc();
	testFunc(10);
	testFunc(10, 20);
	testFunc(10, 20, 30);
	return 0;
}
#endif

#if 0
void testFunc()
{

}
//没有返回值也没有参数
//C++中报错,调用非法,不能通过编译
int main()
{
	testFunc();
	testFunc(10);
	testFunc(10, 20);
	testFunc(10, 20, 30);
	return 0;
}
//综上:C++编译器比C语言语法检查更加严格
#endif

#if 0
#include <stdio.h>
//在C语言中以下函数可以通过编译,因为没有显式写返回值类型时,C语言默认函数返回整型
testFunc(void)
{
}
int main()
{
	int ret = testFunc();
	printf("%d\n", ret);
	//testFunc(1);//会有告警
	return 0;
}
#endif
#if 0
#include <cstdio>
//在C++中:以下函数不能通过编译
testFunc(void)
{
}
int main()
{
	int ret = testFunc();
	printf("%d\n", ret);
	return 0;
}
#endif
#if 0
#include <stdio.h>
//C语言中不支持默认参数
void testFunc(int a = 10, int b = 20)
{
	printf("%d %d\n", a, b);
}
int main()
{
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	//上述调用中,每次调用传递的都是同一组实参
	//不想传递,但是让该函数执行起来后,还可以拿到10,20

	//C语言中编译通不过,参数太少
	//testFunc(10);
	//testFunc();
	//testFunc();
	//testFunc();
	//testFunc();
	//testFunc();
	return 0;
}
#endif

#if 0
#include <iostream>
#include <cstdio>
//C++中支持默认参数/缺省参数
//缺省参数:看起来更像是一个备胎---感情备胎
//缺省参数是声明或定义函数时为函数的参数指定一个默认值,
//在调用该函数时,如果没有指定实参则采用该默认值,否则采用指定实参.

//形参a和b都带有默认值
//用户调用该函数时,如果没有传递实参,则a和b使用其默认值
//如果用户传递了实参,则使用用户传递的实参
void testFunc(int a = 10, int b = 20)
{
	printf("%d, %d\n", a, b);
}
int main()
{
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);
	testFunc(10, 20);

	//上述调用中每调用一次传递的都是一组实参
	//不想传递,但是想让函数执行起来后拿到的还是10,20

	//C++中编译通得过,因为C++支持默认参数
	testFunc();
	testFunc();
	testFunc();
	testFunc(30, 50);
	testFunc(300, 500);
	system("pause");
	return 0;
}
#endif

//#include <iostream>
//using namespace std;
//分类:
//1.全缺省参数:每个参数都带有默认值
#if 0
void testFunc(int a = 1, int b = 2, int c = 3)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
int main()
{
	testFunc();// 1 2 3
	//注意:10传递给第一个形参,后两个形参使用默认值
	testFunc(10);// 10 2 3
	//注意:10,20传递第一个第二个形参,最后一个形参使用默认值
	testFunc(10, 20);// 10 20 3
	testFunc(10, 20, 30);// 10 20 30
	system("pause");
	return 0;
}
#endif
//2.非全缺省参数:部分参数带有默认值
#if 0
//a  b  c
//0  1  1  代码可以通过编译
//1  0  1  代码编译失败
//1  1  0  代码编译失败
//0  0  1  代码可以通过编译

//规则:
//结论:半缺省参数只能从右往左依次给出,不能隔着,跳着给出
//半缺省参数中的缺省参数必须在不带缺省参数的右边
void testFunc(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}
int main()
{
	testFunc(10);
	testFunc(10, 20);
	testFunc(10, 20, 30);
	system("pause");
	return 0;
}
#endif
#if 0
//缺省参数可以在函数声明位置给出来,也可以在函数定义位置给出,
//但是不能在两个位置同时给出
//void testFunc(int a = 10);
//函数声明和定义不能同时给出默认参数,会造成重定义默认参数
//因为如果声明位置和定义位置给出的默认参数值不一样,编译器不知道用哪个参数了

//疑问:在声明位置给好?还是在定义位置给好?
//答:个人认为缺省参数在声明位置给好
//亮哥说:正常情况下写的代码把函数的定义和声明分开的
//定义放在xxx.cpp源文件中,声明放在对应的xxx.h头文件中
//假设:源代码非常有价值,靠源代码赚钱--->肯定不想让源代码每个人都看见
//就把源码封装成库(lib/dll)动态库/静态库 + 头文件提供给别人使用来收费
//库里面是二进制格式来存放源码,是功能的实现,得看头文件接口才能看到使用参数
//如果把默认参数写在函数定义中,等到封装成库以后头文件就看不到是否某个函数有
//默认参数,而把默认参数写在函数声明中,用户使用时还能通过头文件
//看到默认参数的存在,非常方便用户的使用

//缺省值必须是常量或者全局变量,一般是常量
//因为默认值要求代码在编译的时候就确定下来了
int g_a = 10;
void testFunc(int a = g_a);
void testFunc(int a/* = 10*/)
{
	cout << a << endl;
}
//C语言不支持默认参数/缺省参数
int main()
{
	testFunc();
	system("pause");
	return 0;
}
#endif

//函数重载
#if 0
//重载---一词多意
//你不美吗? 美字在该句话中是什么意思? 
//1.美丽,漂亮的意思 2.舒服,舒适的意思
//美字在这里就发生了重载

//函数重载:
//概念:在相同作用域中,函数名字必须相同,参数列表不同(参数个数或类型或顺序)必须不同
//常用来处理实现功能类似数据类型不同的问题

//注意:如果两个函数仅仅是返回值类型不同则不能构成重载
int Add(int left, int right)
{
	return left + right;
}
//C语言不支持函数重载,这些代码编译不过,报错,函数重复定义了
//cpp支持函数重载,这些代码编译通过,可以很好的运行
double Add(double left, double right)
{
	return left + right;
}

//参数列表不同的体现
//1.参数列表个数不同
//2.参数列表类型不同
//3.参数列表类型顺序不同
void testFunc()
{}
//int testFunc()//加上重载失败
//{
//	return 0;
//}
void testFunc(int a)
{}
void testFunc(char c)
{}
void testFunc(int a, char b)
{}
void testFunc(char a, int b)
{}
int main()
{
	Add(10, 20);//int
	Add(1.2, 3.4);//double
	//未重载有告警
	system("pause");
	return 0;
}
#endif
#if 0
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
//函数重载的调用原理:
//函数重载一定是在编译阶段具体确定应该调用哪个函数
//编译器在编译阶段会对函数实参类型进行推演,根据推演的实际结果找形参类型匹配的函数进行调用
//如果有类型完全匹配的函数则直接进行调用
//如果没有类型完全匹配的函数,则会进行隐式类型转化,如果隐式类型转换后有对应的函数则进行调用
//如果没有对应的函数或者说转化之后有二义性则报错
int main()
{
	//单纯从调用位置看---只看到了一个Add
	Add(10, 20);//int int ---> Add(int, int)
	Add(1.2, 3.4);//double double ---> Add(double, double)
	Add('1', '2');
	//char char ---> Add(char, char)不存在 ---> char和int之间可以发生隐式类型转换 ---> Add(int, int)
	//Add("hello", "world");//const char*, const char* ---> Add(const char*, const char*)不存在
	//--->const char*既不能隐式转换为int,也不能隐式转化为double,找不到合适的函数来进行调用了,报错

	//Add(1, 2.2);//有歧义 ambigous
	//编译阶段对形参类型进行推演:int, double --->
	//Add(int, double)该函数不存在 ---> 发现int和double之间可以进行隐式类型转换 int ---> double 并且 double ---> int
	//Add(int, int) || Add(double, double) 转化之后发现有两个函数都可以
	//计算机编译器最讨厌最不能做的就是选择了,它不知道到底要调用哪一个方法了
	//编译器就报错了

	Add(1, (int)2.2);//改进方法:自己的心里所想自己清楚,根据自己的需求来强转就完事了,不必要编译器来做选择
	system("pause");
	return 0;
}
#endif

//C语言不支持函数重载
//C++到底是怎么支持函数重载的?而C语言为什么就不能支持函数重载?
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
int main()
{
	return 0;
}
