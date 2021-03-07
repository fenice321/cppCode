#pragma once
//内联函数不建议声明和定义分离,分离会导致链接错误,因为inline被展开,链接时就没有函数地址了,链接就会找不到
//inline void f(int i);
