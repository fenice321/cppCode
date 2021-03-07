#define _CRT_SECURE_NO_WARNINGS 1
#include "F.h"
#include <iostream>
using namespace std;
//内联函数不建议声明和定义分离,分离会导致链接错误,因为inline被展开,链接时就没有函数地址了,链接就会找不到
//void f(int i)
//{
//	cout << i << endl;
//}