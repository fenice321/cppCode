#define _CRT_SECURE_NO_WARNINGS 1
#include "Person.h"
#include "Date.h"
#include <iostream>
#include <cstring>
#include <assert.h>
#include <cerrno>
#include <cstdio>
using namespace std;
//C语言中结构体中只能定义变量,而且结构体名不能剥离struct单独使用,要不然就使用typedef取别名,如下
//struct Student1
//{
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
////C++中首先兼容C语言结构体的用法,并且在此基础上把struct升级成了类,特点:
////C++结构体中不仅能定义变量,还能定义函数,而且结构体名可以剥离struct单独使用,也可以typedef取别名使用,非常方便,如下
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
////上述结构体的定义,在C++中更喜欢用class来替代
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
//	//cout << sizeof(A) << endl;//1--->C++支持空结构体,空结构体大小是1,但是C语言不支持空结构体
//	//cout << sizeof(B) << endl;//1--->空类大小也是1
//	//cout << sizeof(Student) << endl;//28
//	//cout << sizeof(Student1) << endl;//28
//
//	Student s = { "Peter", "男", 19 };
//	s.PrintStudentInfo();//Peter 男 19
//	s.SetStudentInfo("Fenice", "男", 22);
//	cout << s._name << " " << s._gender << " " << s._age << endl;//Fenice 男 22
//	s.PrintStudentInfo();//Fenice 男 22
//	return 0;
//}

//类的定义:
//class className
//{
//	//类体,里面定义函数和变量---即由成员函数和成员变量组成
//};//和struct结构体定义类似,末尾不要漏掉分号

//如下:Person类中,声明和定义放到了一起,需要注意的是:成员函数如果在类中定义,编译器可能会将其处理成内联函数
//为什么是可能呢?
//答:我们知道inline修饰函数可以编译阶段直接展开减少函数调用的开销,但是如果内联函数声明和定义分开成.h文件和
//.cpp文件中,会报错,.h文件一般放函数,变量声明,但是内联函数声明定义一般直接放入.h文件中,同理,类中成员函数
//如果定义和声明都在里面会导致就是内联函数,只不过要看成员函数代码多少,如果函数代码多则被编译器忽略,如果函数代码
//少则被视为内联函数,所以是可能,一般工程中我们写类的时候,如果其中成员函数代码很少,可以将声明和定义都放在类中,
//否则,成员函数声明放在类中,定义放在.cpp文件中,形如
//void Person::showinfo()
//{
//	cout << _name << " " << _sex << " " << _age << endl;
//}

//class Person
//{
//public:
//	//显示基本信息
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

//面向对象语言三大特性:封装性,继承性,多态性
//类和对象阶段我们只探讨其中的封装性
//类的访问限定符及封装
//public,protected,private
//封装:
//1.数据和方法进行有机结合放到类中
//2.通过访问限定符来控制外面能否访问
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
//注意:访问限定符在类的外面访问时要看能不能访问,类里面不受限制
//一般而言:成员变量都是私有的,成员函数通常是公有的
//int main()
//{
//	A aa;
//	aa.Print();//随机值,随机值
//	aa.Init(1, 2);
//	//aa._a1;//error,无法访问private成员
//	//aa._a3;//error,无法访问protected成员
//	aa.Print();//1 2
//	return 0;
//}
//class中没给限定符默认是私有的
//struct也可以用来定义类,跟class区别,也为了兼容C语言没有给限定符时是公有的
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
//	bb.Print();//随机值
//	bb.Init(1, 2);
//	bb.Print();//2 1
//	return 0;
//}

//类的作用域
//类定义了一个新的作用域,类的所有成员都在类的作用域中,类体外定义成员(一般指函数),需要使用::作用于限定符指明成员函数属于哪个类域
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
//	//p.Init("周鸿", "男", 22);
//	p.PrintPersonInfo();
//	return 0;
//}

//class Person
//{
//public:
//	//显示基本信息
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

////类中既有成员函数,又有成员变量
//class A1
//{
//public:
//	void f1() {};
//private:
//	int _a;
//};
////类中仅有成员函数
//class A2
//{
//public:
//	void f2() {};
//};
////类中什么也没有
//class A3
//{
//};
////类中仅有成员变量
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
////类应该定义在Stack.h
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
////对应的成员函数应该定义在Stack.cpp
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
//	//st._size;//error,访问了私有的成员变量导致错误
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
//	//成员变量对于每个对象是独立的,成员函数对于每个对象是公共的,如果单独存储成员函数会浪费空间
//	//类对象大小,只计算成员变量大小之和考虑内存对齐即可
//	a1._a = 3;
//	a2._a = 4;
//	a3.PrintA();
//	a4.PrintA();
//
//	A2 aa2;
//	A2 aaa2;
//	//如果空类是0字节,第一:开辟0字节空间不合理,第二:空类实例化两个对象字节都是0,对这两个对象取地址没有区别
//	//空类给1个字节是为了占位,表示实例化出的对象存在,不是为了存储数据,空类比较特殊,编译器给了空类一个字节来唯一标识这个类
//	cout << sizeof(A2) << endl;//1
//	cout << sizeof(A3) << endl;//1
//	cout << &aa2 << endl;
//	cout << &aaa2 << endl;
//	return 0;
//}

////日期类和栈结构
//class Date
//{
//	//成员方法一般是公有的
//public:
//	//void Init(Date* this, int year, int month, int day)//手动添加this指针形参编译出错
//	void Init(int year, int month, int day)
//	{
//		cout << "this -> " << this << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//
//		//隐含的this指针只能写在成员函数内部,不能手动添加到方法调用实参列表和成员函数形参列表中
//		//与上面的的等价
//		//this->_year = year;
//		//this->_month = month;
//		//this->_day = day;
//	}
//	void Print();
//	//数据成员变量一般都是私有的--->不能随便改,为了安全角度
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
//	d1.Init(2021, 2, 2);//call Init(0x00234334),成员函数保存在公共代码区使用时call一下就可以调用了
//	cout << "&d1 -> " << &d1 << endl;
//	d1.Print();
//	//打印结果d1对象的地址&d1和对应调用方法中的this指针地址一样
//	//打印结果d2对象的地址&d2和对应调用方法中的this指针地址一样
//	Date d2;
//	d2.Init(2021, 2, 3);//call Init(0x00234334)
//	cout << "&d2 -> " << &d2 << endl;
//	d2.Print();
//	//d2.Init(&d2);//手动添加对象地址实参编译错误
//
//
//	//有个问题,编译器怎么区分对象d1,d2调用的方法分别是什么
//	//答:编译器为非静态成员函数引入了一个隐藏的this指针,指针类型是className* const this
//	//该指针指向当前对象,在成员函数体中所有成员变量的操作都通过该指针去访问,只不过所有操作对用户是透明的,不用用户操作,编译器自动完成
//	
//	//this指针特性:
//	//1.this指针类型是:类类型* const this型指针,上述Demo中this指针是Date* const型
//	//2.this指针只能在成员函数内部使用
//	//3.this指针本质上其实是一个成员函数的形参,是对象调用成员函数时将对象地址作为实参传递给this形参,所以对象中不存在this指针
//	//4.this指针是成员函数第一个隐藏的指针形参,一般情况由编译器通过ecx寄存器自动传递,不需要用户传递
//	//5.this指针是隐含的,实参和形参的位置我们不能手动去加,但是在成员函数内部可以使用this指针
//	return 0;
//}
//面试题:
//1.this指针存在哪里?--->这里的哪里指的是进程空间中的哪里
//	A.堆区	B.栈区	C.常量区		D.静态区		E.对象中
//A错误,因为this指针是一个隐藏的类类型*const型指针做为指针形参,不在堆中申请
//B对,由A分析可知,形参和局部变量在栈帧中,this指针在栈区
//C错误,若在常量区则导致不能修改指向的对象
//D错误,由ABC分析可知不在静态区
//E错误,计算类大小,空类大小,静态变量时没有计算this指针

//2.this指针可以为空吗?
//答:不能

//下面程序能编译通过吗?--->能
//下面程序会崩溃吗?在哪里崩溃--->459行崩溃
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
//	//自己定义的构造函数
//	//构造函数很特殊--->特殊的成员函数
//	//1.构造函数函数名和类名相同,构造函数是六大默认的成员函数之一,且构造函数自己写就调用自己的
//	//2.构造函数没有返回值,且返回值没有也不能写void,构造函数有参调用和普通函数不同,是类名 + 对象名(实参列表)
//	//构造函数无参调用时就是类名+对象名,不用在对象名后面加(),加了括号就成了函数声明了,普通函数是函数名+(实参列表)
//	//3.对象实例化时编译器自动调用构造函数
//	//4.构造函数可以函数重载,给出多个构造函数,给出多种初始化方式
//	//5.构造函数也有隐藏的this指针
//	Date(int year, int month, int day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//无参构造函数
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
//	//我们没写构造函数,编译器已经默认生成了构造函数,并且已经调了
//
//	//Date d1;//自己没写构造函数时,已经调了构造函数,但是d1里面的值还是随机值,说明默认的成员函数---构造函数在这里不行,我们得自己写
//
//	Date d1(2021, 2, 3);//构造函数调用和普通函数调用不一样,普通函数调用是在函数名后面,构造函数调用是在对象后面
//	//d1._year = 20;//error, _year是私有的,类中必须有一个初始化成员函数
//
//	//未初始化,忘记初始化,打出乱码,影响很大,想要对象定义(构造)出来就初始化了
//
//	//C++中提供了默认成员函数---构造函数--->初始化构造出来的对象
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

//小demo,写一个栈的构造函数
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
//	//类似这样的场景,我们直接可以给出一个全缺省参数的构造函数,既可以做到无参构造函数的作用,也可以做到带参构造函数的作用
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		cout << "Date(int year = 1900, int month = 1, int day = 1)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//Date()//这个无参构造函数和上面的全缺省构造函数构成重载,但是有歧义,有一个就行,如果调用构造函数时直接Date d;那编译器不知道调用哪个
//	//{		//报错:类Date包含多个默认构造函数,而默认构造函数虽然有三个,但是只能出现一个
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
//	Date d1;//无参构造
//	d1.Print();
//	Date d2(2021);//带参构造
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
//	//基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	//自定义类型
//	Time _t;
//public:
//	void PrintD();
//};
//void Date::PrintD()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
////通常情况下,写一个全缺省的构造函数就够用了
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
//		//自己赋给自己,都是形参,成员变量没有初始化,很僵硬
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

//析构函数
//1.析构函数名是在类名前加上字符~
//2.析构函数无参无返回值
//3.析构函数不支持函数重载(无参),有且只有一个析构函数,若未显示定义析构函数,则编译器自动生成默认的析构函数
//4.一个对象声明周期结束以后,C++编译器系统会自动调用析构函数
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
//	//	//该类中没有需要清理的工作,析构函数不写也可以
//	//	//所以严格来说Date类不需要写析构函数,因为我们不写,编译器默认生成就可以用
//
//	//	cout << "~Date" << endl;//打印证明析构函数调用了
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
//	//像日期类没有资源需要清理,所以不需要自己实现析构函数,编译器自动生成的默认析构函数就可用
//	//像栈类有堆空间需要清理释放资源,所以一定要自己实现析构函数
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
//	//默认析构函数,针对内置类型不处理
//	//默认析构函数,针对自定义类型要处理的,调用它的析构函数
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
	Date d2(2021, 2, 29);//2021年2月没有29日,非法日期构造出来了
	d2.PrintD();
	Date d3(2021, 3, 32);//2021年3月没有31日,非法日期构造出来了
	d3.PrintD();
	return 0;
}