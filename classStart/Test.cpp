#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stddef.h>
using namespace std;
#if 0
//C语言是面向过程的,关注的是过程--->函数
//C++是基于面向对象的(不是纯粹的面向对象语言,既有面向过程,又有面向对象,因为C++要兼容C语言),关注的是对象--->类

//面向过程和面向对象不是一门编程语言,而是一种解决问题的思路/思想
//比如:洗衣服
//父母辈:1.取脏衣服	2.拿一个水盆	3.拿洗衣粉	4.将脏衣服放到水盆中	5.向盆中倒水	6.用手搓一搓	7.将脏水倒掉	8.再向盆中倒水
//9.放洗衣粉	10.再用手搓一搓/揉一揉	11.将脏水倒掉	12.再倒水,将衣服弄干净	13.将衣服拧干	14晾衣服
//上述父母辈洗衣服过程就是面向过程,将这些过程/解决问题的步骤按部就班的进行下去,不能随意打乱顺序,每个步骤可以封装成一个函数,这些函数按照一定的次序来进行调用,最终完成任务

//新一代:1.脏衣服		2.人		3.洗衣机      4洗衣液		5.水
//人拿着脏衣服放到洗衣机中,倒入洗衣液,按下洗衣机对应的按钮,加水,洗衣机就自己在洗衣服了,人不用关心到底是怎么洗的衣服,这是一种面向对象解决问题的方式
//人,脏衣服,洗衣机,洗衣液,水都可以看成是对象,洗衣服的事请是通过上述对象之间的相互协作完成的

//比如开车:
//面向过程:
//1.打开车门 2.上车 3.坐下系上安全带 4.打火 5.挂挡 6.拉手刹 7.踩油门 8.松离合 9.车走了

//面向对象:
//1.人	2.车
//人和车是实实在在存在的实体,在C++中把现实中看到的物体(包括也有看不到的)称为对象
//人和车的交互,就可以完成开车的动作
//自动驾驶--->科技非常发达了
//人--->往车前一走--->车门自动打开
//人坐到车中,语音:回家--->车载人到家

//主要看面向对象--->而C++中实现面向对象的编程思想的话,class定义的类是非常关键的一步

//在C语言中,可以使用struct来自定义一种新的类型,问题:C语言中struct中可以放函数吗?答:不能
struct Student
{
	//结构体中的变量
	char _name[20];
	char _gender[3];
	int _age;
	//结构体中的函数
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
	void SetAge(int age)//在C语言中,编译失败了--->说明:C语言中的结构体内部是不能放函数的
	{					//在C++中,编译成功--->说明:C++语言中结构体内部能放函数
		_age = age;
	}
};//在C++中struct定义出来的类型就可以看成是一个类了
  //C语言中的结构体,在C++中摇身一变,变成--->定义了一个类
  //只不过C++中,如果要定义类,我们更喜欢使用class的关键字
int main()
{
	//C语言中的方式
	struct Student s1;
	s1._age = 10;
	//C++中的方式
	Student s2;//C++中结构体名可以剥离struct单独使用来定义变量
	s2.InitStudent("Peter", "男", 18);
	s2.SetAge(10);
	return 0;
}
#endif
#if 0
//只不过C++中,如果要定义类,我们更喜欢使用class的关键字

//C语言中结构体内只能放一些数据,C++中类内除了可以放数据还可以放函数,为什么要这样子来进行设计:因为复合人对事物的认知
class Student//类就是对实体进行描述的--->实体的属性(类的成员变量),实体的功能(类的成员函数/方法)
{
	//一般数据给的访问限定符是私有的
private:
	char _name[20];
	char _gender[3];
protected:
	int _age;
	//一般方法给的访问限定符是公有的
public:
	void SetAge(int age)
	{
		_age = age;
	}
	void PrintStudent()//注意:成员函数如果在类内部进行定义,成员函数可能会被编译器当成内联函数来对待
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
	void InitStudent(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
};//面向对象三大特性:封装,继承,多态,类和对象模块主要是处理封装特性的

//类定义的两种方式:
//1.声明和定义全部放在类中
//2.类在.h的头文件中进行声明,在.cpp的源文件中进行定义,但是一般情况下,我们都使用方式2,练习代码时使用方式1

//类是对对象(实体)来进行描述的,但是类不是对象(实体)
//学生类别不等于某个具体的学生,类也可以看成是新定义了一种数据类型
//类			类定义的对象(实体)
//int		用int定义出来的变量
int main()
{
	//Student是类名,可以将其看成学生的一个群体 

	//s是用Student类定义出来的对象
	//s是一个具体存在的学生,我们才可以将名字,性别,年龄放到具体的学生对象中
	Student s;
	//编译报错:因为Student不是一个具体的学生,我们不能将名字,性别,年龄放到Student中
	//Student.InitStudent("Peter", "男", 18);//error,类类型是没有属性的
	s.InitStudent("Peter", "男", 10);
	s.PrintStudent();
	//s._age = 10;
	return 0;
}
								//注意:struct定义的类默认情况下访问权限是public,class定义的类默认情况下访问权限是private
								//public:修饰的成员在类外可以直接被访问
								//protected:修饰的成员在类外不能直接被访问(暂时这么理解)
//什么是封装?为什么要有封装?		//private:修饰的成员在类外不能直接被访问
//						class	访问限定符(private public protected),限定类中的哪些成员可以在类外来进行使用
//封装:将数据和操作数据的方法有机结合,隐藏属性和实现细节,仅对外公开接口和对象进行交互

//函数:实际上就是一些语句包装到一起,可以看成是封装
//C语言:数据+操作数据的方法(函数)=程序
//C++中:各种不同的对象,对象之间相互交互完成任务
//对象:有对象的属性(数据),还有对象所有的功能(方法)

//类作用域	全局作用域	命名空间作用域		函数体局部作用域

//类和对象--->什么是类?什么是对象?
//类:主要是对实体(对象)来进行描述的,描述实体都有哪些属性(成员变量),都有哪些方法(成员函数)
//	 类也是新定义的一种类型
//	 类是比较抽象的一个概念,是从许多对象中提取出来的一些公共信息,将数据和方法包装起来,更能好的描述实体,类似一张图纸

//对象:实实在在存在的,比如:一个学生,一台电脑,一个房子
//	  用类产生一个实体(对象)
//	  对象中是可以放数据的
//    类似一座房子
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

	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 20);
	s3.InitStudent("Lucy", "女", 19);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	s3.PrintStudentInfo();
	//问题:在调用位置,我们能够知道初始化函数和打印函数具体在操作那个对象,但是在InitStudent和PrintStudentInfo函数中,没有任何关于对象的说明,
	//那么这两个方法它们怎么知道操作的是哪个对象?
	//答:有隐藏的参数this指针
	return 0;
}
#endif
#if 0
//类对象模型:对象在内存中的布局方式

//如何计算一个类/对象所占空间的字节大小
//如果我们知道对象中都包含哪写内容

//常用的调用约定:
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
	//成员函数
	//看起来该函数有三个参数,实际上有4个参数,
	//另外一个参数是隐藏的this指针(而且是第一个参数),在写代码期间,用户不用显示给出this指针,编译器在编译代码时,会自动加上this指针参数

	//void __thiscall Student::InitStudent(char* const, char* const, int)
	void InitStudent(const char* name, const char* gender, int age)
	{
		//this = nullptr;//this指针类型是className* const this,不能给this指针赋值--->即:Student* const this
		cout << this << endl;
		//有了this指针之后,成员函数就知道现在是在操作那个对象
		//对成员变量的操作都是通过this指针来进行的
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	void SetAge(int age)
	{
		cout << this << endl;
		_age = age;
	}

	//__cdecl是调用约定,约定调用函数期间所做的各种操作的规则
	//void __cdecl Student::TestFunc(...)
	void TestFunc(...)//不定参成员函数
	{

	}
public:
	char _name[20];
	char _gender[3];
	int _age;
};
//this是一个关键字,是一个指针,是当前对象的地址(成员函数执行时,调用该成员函数的对象)
int main()
{
	//cout << this << endl;//this指针只能在非静态成员函数或者非静态成员初始值中引用
	Student s1, s2, s3;
	//s1.//通过对象打点的方式发现:Student类类型的对象中有:_name, _age, _gender, InitStudentInfo(), SetAge(), PrintStudent()
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 19);
	s3.InitStudent("Lily", "女", 18);

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	s3.PrintStudentInfo();

	s1.TestFunc(1);
	s2.TestFunc(1, 2);
	s3.TestFunc(1, 2, 3);
	//发现:s1, s2, s3虽然是三个不同的对象,但是最终调用的是相同的方法来进行初始化和打印
	//如果每个对象中都存储相同的成员函数时,浪费空间
	cout << sizeof(s1) << "-" << sizeof(Student) << endl;//28-28
	return 0;
}
//什么是this指针?
//this指针是类"非静态成员函数"形参参数列表中第一个参数,这个参数是隐藏的,这个指针总是指向调用该非静态成员函数的对象
//特性:
//1.只能在非静态成员函数中使用
//2.this指针全称为:	className* const this,即this指针的指向不可改
//3.this指针没有存储在对象中,因此不会影响对象的大小,而是在成员函数运行时时时刻刻指向当前对象,this指针是函数形参,存储在栈上
//4.this指针是"非静态成员函数"的第一个隐藏的形参,"隐藏的"--->用户在实现成员函数是,不用显示给出,该参数是编译器自动添加的,也是由编译器自动来进行传递的
//5.this指针主要是通过ecx寄存器进行传递,效率很高,但是并不是所有this指针都是通过寄存器来传递的,
//可能是通过函数参数压栈传递的(变参成员函数的调用时this指针的传递就是压栈)
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
//面试题:空类大小是多少?为什么?
//答:主流编译器中空类大小占一个字节,原因一是如果空类大小是0,用类实例化对象系统申请空间0字节申请不出来,
//原因二是就算申请0字节申请出来了,用空类实例化出三个对象,在内存函数栈帧中存储,它们三个在一个位置,地址相同--->三个对象是同一个对象,与三个对象是不同对象矛盾,
//故无论从哪个原因来看都需要有1个或者1个以上字节来唯一标识空类大小,只不过主流编译器给空类的标识大小是1字节而已
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
	//结论:求一个类的大小--->只需要将类中"成员变量"加起来,注意内存对齐
	//cout << sizeof(A) << endl;//4
	//cout << sizeof(B) << endl;//1
	//cout << sizeof(C) << endl;//1

	//假设空类的大小是0
	//C类是空类,然后用C类定义了三个对象,这三个对象不同
	//C c1, c2, c3;
	//

	//cout << sizeof(D) << endl;//1,C++中空结构体(类)大小也是1
	
	//需求:给定一个结构体AA,然后再给AA中的一个成员c
	//想要知道AA结构体中的成员相对于结构体起始位置的偏移量

	AA a;
	//printf("%d\n", OFFSETOF(struct AA, b));
	cout << sizeof(AA) << endl;
	//offsetof()//#define offsetof(s,m) ((size_t)&(((s*)0)->m))
	return 0;
}
//问:结构体和类的本质区别是什么?
//答:在C++中结构体和类基本没有什么区别
//共有三个不同之处,在类和对象这里只有一个不同--->默认访问权限不同,模板位置有一个不同,继承位置有一个不同
#endif
#if 0
//this指针
//回归到C语言
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};
//必须要实现一些操作结构体类型变量的方法
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
	InitStudent(&s1, "zhouhongtao", "男", 22);//传参传了一个对象指针,只不过C++中这个对象指针变成了this指针,全称是className* const this
	InitStudent(&s3, "wede", "男", 20);
	InitStudent(&s2, "qifeng", "男", 21);
	PrintStudent(&s1);						 //传参传了一个对象指针,只不过C++中这个对象指针变成了this指针,全称是className* const this
	PrintStudent(&s2);
	PrintStudent(&s3);
	return 0;
}
#endif
#if 0
//成员变量定义在后,成员函数使用成员变量在前,编译器怎么不报错呢?
//因为:编译器是这样子的处理类的:
//第一步:先识别类名
//第二步:再识别类中的成员变量
//第三步:最后识别类中的成员函数,并对成员函数进行修改--->增加this指针
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
	s1.InitStudent("Peter", "男", 19);
	s2.InitStudent("David", "男", 29);
	s3.InitStudent("Lucy", "女", 13);
	
	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
//类和对象
//1.面向过程和面向对象编程思想
//2.类的定义
//3.访问限定符
//4.什么是封装?C++是如何实现封装?
//5.一个类就是一个作用域
//6.类的实例化:类和对象
//7.如何计算一个类的大小?注意:空类的大小是什么?原因
//8.this指针
#endif
#if 0
class A
{
public:
	//编译器处理类的步骤
	//1.识别类名
	//2.识别类成员变量
	//3.识别类成员函数,并修改类成员函数,加classType * const this指针
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
	//A::TestFunc();//error,没有对象,调用不了成员函数
	a1.TestFunc();//call A::TestFunc(&a1)
	a2.TestFunc();//call A::TestFunc(&a2)
	a3.TestFunc();//call A::TestFunc(&a3)
	//成员函数必须要通过对象来进行调用,在该成员函数调用之前,编译器需要将当前对象的地址通过ecx寄存器传递给成员函数

	A* pa = &a1;
	pa->TestFunc();//call A::TestFunc(pa);

	pa = &a2;
	pa->TestFunc();//call A::TestFunc(pa);

	//注意:pa是A*类型的指针,也就是说pa将来可以指向A类型的对象
	//    如果pa指针没有合法指向,一般都是将该指针置为nullptr
	pa = nullptr;
	pa->TestFunc();
	return 0;
}
#endif
#if 0
//面试题:
//1.this指针存在哪里?
//答:this指针是非静态成员函数的第一个隐藏的指针参数,指向调用成员函数的对象,存储在栈上
//2.this指针可以为空吗?
//可以
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
	p->PrintA();//崩溃,访问了指针空值
	//p->Show();//不崩溃
	return 0;
}
#endif
#if 0
class Date1
{};
//空类,看起来没有成员函数和成员变量,主流编译器给他一个唯一的标记大小为1字节
//实际上有6个默认的成员函数
//1.构造函数(初始化)	2.析构函数(清理,释放资源)	3.拷贝构造函数(初始化对象)	4.赋值运算符重载(赋值)		5.&/*		6.&/const *
//默认成员函数指的是:用户没有显示实现该成员函数,则编译器会替用户实现一份
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
    Date(int year, int month, int day)//构造函数无返回值,写void也不行
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int, int, int):" << this << endl;
	}
	Date()//构造函数重载,可以给多个构造函数,多种初始化方式
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
//构造函数是六大默认成员函数之一,特性如下
//对象实例化时,编译器自动调用构造函数完成对象的初始化,保证每个数据成员都有一个合适的值
//构造函数名和类名相同,且没有返回值,可以重载
//构造函数在对象生命周期内只调用一次
void TestFunc()
{
	Date d1(2020, 11, 11);
	cout << &d1 << endl;
	d1.PrintDate();

	//创建对象时,编译器自动调用构造函数,给对象中设置一些初始值
	Date d2;
	d2.PrintDate();

	Date d3();//此句代码不是创建对象d3的意思,而是声明一个函数名为d3,无入参,返回类型是Date的函数
	//注意:当调用无参构造函数创建对象时,对象之后一定不能跟(),如果跟上()就成为函数声明,而不是创建对象
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
//如果类中没有显示定义构造函数,则C++编译器会自动生成一个无参默认构造函数(好像啥也没干),一旦用户显示定义编译器将不再生成
class Date
{
public:
	//用户没有显式定义任何构造函数---显式:用户自己没有写
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
	//从概念上:目前日期类中没有显示定义构造函数,但是该类仍旧可以创建对象,当创建对象时编译器需要自动调用构造函数,
	//该构造函数哪里来的?就是编译器生成的默认无参构造函数
	Date d1;//打断点,看反汇编看不到默认无参构造函数调用
}
int main()
{
	TestDate();
	return 0;
}
#endif
#if 0
//如果类中没有显示定义构造函数,则C++编译器会自动生成一个无参默认构造函数(好像啥也没干),一旦用户显示定义编译器将不再生成
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
	//用户没有显式定义任何构造函数---显式:用户自己没有写
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
	//用户显示定义了带有参数的构造函数
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
	//Date类中已经显示定义了带有三个参数的构造函数
	//验证:编译器还会不会生成无参的构造函数呢?

	//方法一:如果编译器还生成带无参的构造函数,Date d2;这句代码编译通过
	//否则,代码编译失败

	//结果:编译报错:error 没有合适的默认构造函数可用
	//结论:当类中显示定义构造函数时,编译器不会再生成无参的默认构造函数了

	//方法二:如果Date类中显示给定了一个无参构造函数,并且编译器还会默认生成一个无参构造函数,那么这两个函数在同一个类域中
	//函数名相同(都是类名),参数列表相同(都是无参),经过命名修饰后函数名都是一摸一样的,不构成函数重载的条件,只是函数重定义
	//矛盾,所以编译器不会生成无参的构造函数

	//如果代码可以通过编译则编译器生成无参构造函数了
	//Date d1;//打断点,看反汇编,能看到默认无参构造函数调用
}
int main()
{
	TestDate();
	return 0;
}
#endif
#if 0
//无参的构造函数和全缺省构造函数都称为默认构造函数(还有没有显示给定构造函数时,编译器自动生成的默认无参构造函数也是默认构造函数),并且默认构造函数只能有一个
//理由:当没有显示给定构造函数时,编译器自动生成默认无参构造函数,而当全缺省构造函数或无参构造函数显示给出时,
//编译器不在生成默认无参构造函数--->编译器自动生成的默认构造函数只能单独存在
//当全缺省构造函数和无参构造函数同时给出时,调用方实例化对象时:Date d;这句代码有歧义,不知道调用哪个构造函数进行初始化--->全缺省构造函数和无参构造函数只能单独存在
//综上:三种默认构造函数只能存在一个
class Date
{
public:
	Date()//无参构造函数
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)//全缺省构造函数
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

	//发现:既可以调用无参构造函数来创建d2,也可以调用全缺省构造函数来创建d2
	//产生了二义性,编译失败
	//Date d2;
	return 0;
}
#endif
#if 0
/*
1.当用户没有显示定义构造函数时,编译器会生成一个无参的默认构造函数
*/
class Date1
{
	//1.当用户没有显示定义构造函数时,编译器会生成一个无参的默认构造函数
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
	Date1 d;//Date1类中没有显示给定构造函数,在用Date1类创建对象时调用构造函数调用的是编译器自己生成的默认无参构造函数
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
//默认成员函数
//1.概念
//2.特性
//3.调用场景
//4.编译器生成的默认成员函数

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
//C中没有字符串类型,C++中有字符串类---string
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