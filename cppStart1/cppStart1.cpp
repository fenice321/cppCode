#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
//ע��:<iostream.h>�ھɿ��а���,���ڸ߰汾����������������
//#include <iostream.h>//i/ostream input/output stream ����/�����
#include <iostream>//��C����ͷ�ļ�д����һ��,û��.h��׺��
using namespace std;
//������һ�������ռ���൱�ڶ�����һ���µ�������,�����ռ��е��������ݶ������ڸ������ռ���

#if 0
//�����ռ�Ķ����ʽ
//�ؼ���:namespace�����ռ�
//�����ռ�Ϊ�տ��Ա���ͨ��
namespace N
{
	//�������
	//���庯��
	//�������ͺ���ͳ��Ϊ��ǰ�����ռ�ĳ�Ա
}

int a = 10;
//�����ռ������ֶ��巽ʽ
//��ʽһ:����ķ�ʽ
namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

//��ʽ��:�����ռ����Ƕ��
//������һ��ѧУ�п��԰������ѧԺ
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

//��ʽ��:��ͬһ�������п��Զ�����������ͬ�������ռ�
//�����ͻ
//�������Ὣ�����ͬ���Ƶ������ռ�ϲ���һ��
namespace N1
{
	//��ͬ�������в��ܳ�����ͬ������
	//��ͬ���ֵĶ�������ռ���:Ҳ���ܳ�����ͬ������,
	//��Ϊ�������Ὣ�����ͬ�����ֵ������ռ����պϲ���һ��
	//int a = 30;//err:��ͬ���Ƶ������ռ��в��ܶ�����ͬ�ı���
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
//����ͨ��
namespace N
{
	int a = 10;
	//Ƕ�׵ķ�ʽ���������ռ�,ֻ������Ƕ�����ռ������ⲿ�����ռ�����ͬ
	//���ַ�ʽҲ�����ͻ,�൱�����N�����ռ����а�����һ��N�������ռ�
	namespace N
	{
		int b = 10;
		int a = 10;
	}
}
#endif

//�����ռ��г�Ա��ʹ�÷�ʽ
#if 0
//��ʽһ:�����ռ���::��Ա
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
	//�����ռ���::�е�::�������������
	//N::N::b = 20;

	int a = 30;
	//�ͽ�ԭ��
	printf("%d\n", a);//30

	//���Ҫ����ȫ���������е�a
	//::�����������
	//::a ��ȷ���߱�����˵��Ҫ����ȫ���������е�a
	printf("%d\n", ::a);//20

	//����N�����ռ��е�a
	//N::a ��ȷ���߱�����˵��Ҫ���ʵ���N�����ռ��е�a
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

//��ʽ��:
//�ó����ж�N�����ռ���ĳЩ��Ա���ʵķǳ�Ƶ��

//����������֮��,�൱�ڽ�N�����ռ��е�a���ɵ�ǰ�ļ��е�һ��ȫ�ֱ�����ʹ��
//�ŵ�:д�������
//ȱ��:������ļ�������ͬ���Ƶ�ȫ�ֱ������ߺ����ͻ������ͻ
//���������ͻ,��ô��?-----���շ�ʽһ �����ռ���::��Ա���ʼ���
using N::a;
//������ļ���Ҳ��һ��ȫ��a,��Ȼ�������ͻ,ֻ�ܰ��շ�ʽһ �����ռ���::��Ա��ʹ��
//int a = 10;
int main()
{
	int a = 20;
	//����N�����ռ��е�a
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);

	//Ϊ��д�����,��Ҫֱ�ӷ���N�����ռ��е�a
	printf("%d\n", N::a);
	printf("%d\n", a);//�ͽ�ԭ��
	printf("%d\n", ::a);
	return 0;
}
#endif

#if 0
//��ʽ��:����N�����ռ�������Ա�ڵ�ǰ�ļ��зǳ�Ƶ����ʹ��
namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
}
//using N::a;//N�����ռ��е�a������������ȫ�ֱ�������
//using N::b;
//using N::Add;
//using N::Add;

//����ǰN�����ռ������еĳ�Ա���ɸ��ļ��е�ȫ�ֱ���
//�ŵ�:ʹ�÷ǳ���
//ȱ��:������ͻ�Ŀ����Էǳ���
//���������ͻ,���:���շ�ʽһ:�����ռ���::��Ա ��ʹ�� 
using namespace N;
int a = 20;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	printf("%d\n", N::a);
	//printf("%d\n", a);//N�����ռ��е�a������������ȫ�ֱ�������
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

//C++�е���������
//ע��:C����������������ʽ��C++���Ծ���ʹ��---��ΪC++Ҫ����C����

//C++�Լ����Ǹ���һ�����������ķ�ʽ, ��ΪC���������������ʽ̫�鷳��
//��Ҫ��������ĸ�ʽ����,һЩ���������������������
#if 0
int main()
{
	//C/C++�ж����ᱨ��,������ͨ��
	//int a = 10;
	//scanf("%d%d", &a);
	//printf("%d\n", a);
	//C/C++�ж����ᱨ��,������ͨ��
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
	//C++�е����
	//����Ҫ�����ʽ���Ʒǳ�����
	cout << 10;
	cout << 12.34 << "\n";
	cout << "hello" << 123 << "world!!!" << endl;//����endl
	return 0;
}