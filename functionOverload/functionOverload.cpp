#include <iostream>
using namespace std;
//函数重载会出现重名的函数,重名的函数会根据语境(实参)来决定调用
//运算符重载也是一种函数重载

//函数重载的好处:简洁的需要(调用时不用区分函数名了)

//重载的规则:
//1.函数名相同
//2.函数的参数(类型/个数/顺序)有一个或者多个不同均可构成重载
//3.函数返回值的类型不同不能作为构成重载的标志

//ambiguous二义性,模棱两可的

//函数重载调用重载函数时的匹配规则:
//1.严格匹配:实参传入的类型是什么就调用什么类型的对应的重载函数
//2.严格匹配不满足时:寻求是否有隐式类型转换寻求一个匹配,找到则调用

//解决方法,多重载几个函数,尽量满足调用所需的类型的严格匹配

//重载的底层实现:
//C++利用命名倾轧技术(Name Mangling),来改变函数名(看似相同的函数名,在编译器层面函数名就已经不相同了),区分参数不同的同名函数
//实现原理示例:用v-c-i-l-f-d表示void char int long float double及其引用.具体平台的实现有差异.
//在Linux平台用nm命令即可佐证这点:nm a.out
void foo(double a)//foo_d
{
    cout << "double" << endl;
}
void foo(long b)  //foo_l
{
    cout << "long" << endl;
}
//void foo(int a) //foo_i
//{
//    cout << "int" << endl;
//}

int main()
{
    long a = 5;
    foo(a);//long  //foo_l
    double b = 5.5;
    foo(b);        //foo_d
    int aa = 5;//ambiguous二义性
    foo(aa);       //foo_i
    return 0;
}

#if 0
int abs()//非法的重载
{

}
float abs()
{

}

int main()
{
    int a = abs();
    float b = abs();
    return 0;
}
#endif
#if 0
void foo(int a)
{

}
void foo(float a)
{

}
void foo(int a, int b)
{

}
void foo(int a, float b)
{

}
void foo(float a, int b)
{

}

int main()
{

    return 0;
}
#endif
#if 0
//int absOfInt(int a)
//{
//    return a > 0 ? a : -a;
//}
//float absOfFloat(float a)
//{
//    return a > 0 ? a : -a;
//}
int abs(int a)
{
    return a > 0 ? a : -a;
}
float abs(float a)
{
    return a > 0 ? a : -a;
}
int main()
{
//    int a = -5;
//    cout << absOfInt(a) << endl;
//    float b = -1.23;
//    cout << absOfFloat(b) << endl;
    int a = -5;
    cout << abs(a) << endl;
    float b = -1.23;
    cout << abs(b) << endl;
    return 0;
}
#endif
#if 0
void func(int a)
{
    cout << "void func(int a)" << endl;
}

void func(float a)
{
    cout << "void func(float a)" << endl;
}
void func(char a)
{
    cout << "void func(char a)" << endl;
}

int main()
{
    int a = 1;
    func(a);
    float b = 1.1f;
    func(b);
    char c = 'a';
    func(c);
//    cout << "Hello World!" << endl;//>> <<
//    int a;
//    a << 1;
    return 0;
}
#endif
