#pragma once
//类是对对象(实体)来进行描述的
class Person
{
	void InitPerson(const char* name, const char* gender, int age);
	void Eat();
	void Sleep();
	void PrintPersonInfo();
	char _name[20];
	char _gender[3];
	int _age;
};
