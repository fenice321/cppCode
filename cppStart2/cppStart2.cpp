
//ע��:
//1.C�����б�׼���������C++���Ծɿ���ʹ��
//scanf/getchar/gets/fgets
//printf/putchar/puts/fputs
//2.C++�е��������ʹ���������ӱ��
//cin���� cout��� #include <iostream> + using namespace std;
//�Ƚ��ϵı�������<iostream.h>�ɿ�,�µı��������������׿�
//std�����ռ���C++�����ṩ��
//cin��cout������std�������ռ���,������˵std�������ռ���ֻ������cin��cout
//C���Ա�׼�⺯������std��׼�����ռ���

#if 0
#include <iostream>
//using namespace std;
int main()
{
	//cout << "Hello World!\n" << endl;
	std::cout << "Hello World!\n" << std::endl;
	//system����Ҳ�ڱ�׼std�����ռ�����
	std::system("pause");
	return 0;
}
#endif

//C��C++���ں������������:
//1.��������ֵ����
//2.������������
//����:C++��������C���Ա������Ժ�������,����ֵ�������ϸ�
//3.C++�����������Դ�һЩĬ��ֵ
//4.������������һ��
#if 0
void testFunc()
{

}
//û�з���ֵ,Ҳû�в��� 
//C���Ի����б���ͨ��,���Դ�0,1,2,3...N������
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
//û�з���ֵҲû�в���
//C++�б���,���÷Ƿ�,����ͨ������
int main()
{
	testFunc();
	testFunc(10);
	testFunc(10, 20);
	testFunc(10, 20, 30);
	return 0;
}
//����:C++��������C�����﷨�������ϸ�
#endif

#if 0
#include <stdio.h>
//��C���������º�������ͨ������,��Ϊû����ʽд����ֵ����ʱ,C����Ĭ�Ϻ�����������
testFunc(void)
{
}
int main()
{
	int ret = testFunc();
	printf("%d\n", ret);
	//testFunc(1);//���и澯
	return 0;
}
#endif
#if 0
#include <cstdio>
//��C++��:���º�������ͨ������
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
//C�����в�֧��Ĭ�ϲ���
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
	//����������,ÿ�ε��ô��ݵĶ���ͬһ��ʵ��
	//���봫��,�����øú���ִ��������,�������õ�10,20

	//C�����б���ͨ����,����̫��
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
//C++��֧��Ĭ�ϲ���/ȱʡ����
//ȱʡ����:������������һ����̥---���鱸̥
//ȱʡ�������������庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ,
//�ڵ��øú���ʱ,���û��ָ��ʵ������ø�Ĭ��ֵ,�������ָ��ʵ��.

//�β�a��b������Ĭ��ֵ
//�û����øú���ʱ,���û�д���ʵ��,��a��bʹ����Ĭ��ֵ
//����û�������ʵ��,��ʹ���û����ݵ�ʵ��
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

	//����������ÿ����һ�δ��ݵĶ���һ��ʵ��
	//���봫��,�������ú���ִ���������õ��Ļ���10,20

	//C++�б���ͨ�ù�,��ΪC++֧��Ĭ�ϲ���
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
//����:
//1.ȫȱʡ����:ÿ������������Ĭ��ֵ
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
	//ע��:10���ݸ���һ���β�,�������β�ʹ��Ĭ��ֵ
	testFunc(10);// 10 2 3
	//ע��:10,20���ݵ�һ���ڶ����β�,���һ���β�ʹ��Ĭ��ֵ
	testFunc(10, 20);// 10 20 3
	testFunc(10, 20, 30);// 10 20 30
	system("pause");
	return 0;
}
#endif
//2.��ȫȱʡ����:���ֲ�������Ĭ��ֵ
#if 0
//a  b  c
//0  1  1  �������ͨ������
//1  0  1  �������ʧ��
//1  1  0  �������ʧ��
//0  0  1  �������ͨ������

//����:
//����:��ȱʡ����ֻ�ܴ����������θ���,���ܸ���,���Ÿ���
//��ȱʡ�����е�ȱʡ���������ڲ���ȱʡ�������ұ�
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
//ȱʡ���������ں�������λ�ø�����,Ҳ�����ں�������λ�ø���,
//���ǲ���������λ��ͬʱ����
//void testFunc(int a = 10);
//���������Ͷ��岻��ͬʱ����Ĭ�ϲ���,������ض���Ĭ�ϲ���
//��Ϊ�������λ�úͶ���λ�ø�����Ĭ�ϲ���ֵ��һ��,��������֪�����ĸ�������

//����:������λ�ø���?�����ڶ���λ�ø���?
//��:������Ϊȱʡ����������λ�ø���
//����˵:���������д�Ĵ���Ѻ����Ķ���������ֿ���
//�������xxx.cppԴ�ļ���,�������ڶ�Ӧ��xxx.hͷ�ļ���
//����:Դ����ǳ��м�ֵ,��Դ����׬Ǯ--->�϶�������Դ����ÿ���˶�����
//�Ͱ�Դ���װ�ɿ�(lib/dll)��̬��/��̬�� + ͷ�ļ��ṩ������ʹ�����շ�
//�������Ƕ����Ƹ�ʽ�����Դ��,�ǹ��ܵ�ʵ��,�ÿ�ͷ�ļ��ӿڲ��ܿ���ʹ�ò���
//�����Ĭ�ϲ���д�ں���������,�ȵ���װ�ɿ��Ժ�ͷ�ļ��Ϳ������Ƿ�ĳ��������
//Ĭ�ϲ���,����Ĭ�ϲ���д�ں���������,�û�ʹ��ʱ����ͨ��ͷ�ļ�
//����Ĭ�ϲ����Ĵ���,�ǳ������û���ʹ��

//ȱʡֵ�����ǳ�������ȫ�ֱ���,һ���ǳ���
//��ΪĬ��ֵҪ������ڱ����ʱ���ȷ��������
int g_a = 10;
void testFunc(int a = g_a);
void testFunc(int a/* = 10*/)
{
	cout << a << endl;
}
//C���Բ�֧��Ĭ�ϲ���/ȱʡ����
int main()
{
	testFunc();
	system("pause");
	return 0;
}
#endif

//��������
#if 0
//����---һ�ʶ���
//�㲻����? �����ڸþ仰����ʲô��˼? 
//1.����,Ư������˼ 2.���,���ʵ���˼
//����������ͷ���������

//��������:
//����:����ͬ��������,�������ֱ�����ͬ,�����б�ͬ(�������������ͻ�˳��)���벻ͬ
//����������ʵ�ֹ��������������Ͳ�ͬ������

//ע��:����������������Ƿ���ֵ���Ͳ�ͬ���ܹ�������
int Add(int left, int right)
{
	return left + right;
}
//C���Բ�֧�ֺ�������,��Щ������벻��,����,�����ظ�������
//cpp֧�ֺ�������,��Щ�������ͨ��,���Ժܺõ�����
double Add(double left, double right)
{
	return left + right;
}

//�����б�ͬ������
//1.�����б������ͬ
//2.�����б����Ͳ�ͬ
//3.�����б�����˳��ͬ
void testFunc()
{}
//int testFunc()//��������ʧ��
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
	//δ�����и澯
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
//�������صĵ���ԭ��:
//��������һ�����ڱ���׶ξ���ȷ��Ӧ�õ����ĸ�����
//�������ڱ���׶λ�Ժ���ʵ�����ͽ�������,�������ݵ�ʵ�ʽ�����β�����ƥ��ĺ������е���
//�����������ȫƥ��ĺ�����ֱ�ӽ��е���
//���û��������ȫƥ��ĺ���,��������ʽ����ת��,�����ʽ����ת�����ж�Ӧ�ĺ�������е���
//���û�ж�Ӧ�ĺ�������˵ת��֮���ж������򱨴�
int main()
{
	//�����ӵ���λ�ÿ�---ֻ������һ��Add
	Add(10, 20);//int int ---> Add(int, int)
	Add(1.2, 3.4);//double double ---> Add(double, double)
	Add('1', '2');
	//char char ---> Add(char, char)������ ---> char��int֮����Է�����ʽ����ת�� ---> Add(int, int)
	//Add("hello", "world");//const char*, const char* ---> Add(const char*, const char*)������
	//--->const char*�Ȳ�����ʽת��Ϊint,Ҳ������ʽת��Ϊdouble,�Ҳ������ʵĺ��������е�����,����

	//Add(1, 2.2);//������ ambigous
	//����׶ζ��β����ͽ�������:int, double --->
	//Add(int, double)�ú��������� ---> ����int��double֮����Խ�����ʽ����ת�� int ---> double ���� double ---> int
	//Add(int, int) || Add(double, double) ת��֮��������������������
	//�����������������������ľ���ѡ����,����֪������Ҫ������һ��������
	//�������ͱ�����

	Add(1, (int)2.2);//�Ľ�����:�Լ������������Լ����,�����Լ���������ǿת��������,����Ҫ����������ѡ��
	system("pause");
	return 0;
}
#endif

//C���Բ�֧�ֺ�������
//C++��������ô֧�ֺ������ص�?��C����Ϊʲô�Ͳ���֧�ֺ�������?
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
