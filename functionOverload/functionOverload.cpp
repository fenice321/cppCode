#include <iostream>
using namespace std;
//�������ػ���������ĺ���,�����ĺ���������ﾳ(ʵ��)����������
//���������Ҳ��һ�ֺ�������

//�������صĺô�:������Ҫ(����ʱ�������ֺ�������)

//���صĹ���:
//1.��������ͬ
//2.�����Ĳ���(����/����/˳��)��һ�����߶����ͬ���ɹ�������
//3.��������ֵ�����Ͳ�ͬ������Ϊ�������صı�־

//ambiguous������,ģ�����ɵ�

//�������ص������غ���ʱ��ƥ�����:
//1.�ϸ�ƥ��:ʵ�δ����������ʲô�͵���ʲô���͵Ķ�Ӧ�����غ���
//2.�ϸ�ƥ�䲻����ʱ:Ѱ���Ƿ�����ʽ����ת��Ѱ��һ��ƥ��,�ҵ������

//�������,�����ؼ�������,�������������������͵��ϸ�ƥ��

//���صĵײ�ʵ��:
//C++����������������(Name Mangling),���ı亯����(������ͬ�ĺ�����,�ڱ��������溯�������Ѿ�����ͬ��),���ֲ�����ͬ��ͬ������
//ʵ��ԭ��ʾ��:��v-c-i-l-f-d��ʾvoid char int long float double��������.����ƽ̨��ʵ���в���.
//��Linuxƽ̨��nm�������֤���:nm a.out
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
    int aa = 5;//ambiguous������
    foo(aa);       //foo_i
    return 0;
}

#if 0
int abs()//�Ƿ�������
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
