#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int main()
//{
//	size_t a = sizeof(int);
//	cout << "hello world\n";
//	cout << "hello world" << endl;
//	cout << "a=" << a << endl;
//	cout << "a=" << sizeof(size_t) << endl;
//	
//
//
//	return 0;
//}


//int main()
//{
//	//����С���ǲ�����ȡ�������
//	int a = 10;
//	a++;
//	cout << "a=" << a << endl;
//
//	return 0;
//}
//���õĻ����﷨
//int main()
//{
//	//��������  &����=ԭ��
//	int a = 0;
//	//��������
//	int &b = a;
//	b = 20;
//	cout << "b=" << b << endl;
//
//
//	//���ñ���Ҫ��ʼ��
//	//int& b;
//	//���ó�ʼ���󲻿��Ըı�
//	int c = 20;
//	b = c;		//���Ǹ�ֵ���������Ǹ�������
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//	return 0;
//}


//��������
//1����ַ����
//void mySwap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//���ô���
//void mySwap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << "����ǰ" << endl;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	mySwap(a, b);
//	cout << "������" << endl;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	
//	return 0;
//}

//���ú����ķ���ֵ
//1����Ҫ���ؾֲ�����������
//int& tets01()
//{
//	int a = 10;
//	return a;
//}
//int main()
//{
//	int& ref = tets01();
//	cout << "ref=" << ref << endl;//��һ�ν����ȷ������Ϊ���������˱���
//	cout << "ref=" << ref << endl;//�ڶ��ν��������Ϊa���ڴ��Ѿ��ͷ�
//
//	return 0;
//}

//2�������ĵ��ÿ�����Ϊ��ֵ
//int& test02()
//{
//	static int a = 10;
//	return a;
//}
//int main()
//{
//	int& ref = test02();
//	cout << "ref=" << ref << endl;
//	cout << "ref=" << ref << endl;
//	test02() = 1000;
//	cout << "ref=" << ref << endl;
//	cout << "ref=" << ref << endl;
//
//	return 0;
//}


//���õı���
//���������ã�ת��Ϊ int* const ref=&a;
//void func(int& ref)
//{
//	ref = 100; //ref�����ã�ת��Ϊ*ref=100
//}
//int main()
//{
//	int a = 10;
//	
//	//�Զ�ת��Ϊ int* const ref=&a;ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
//	int& ref = a;
//	ref = 20;//�ڲ�����ref�����ã��Զ�������ת��Ϊ*ref=20;
//
//	cout << "a:" << a << endl;
//	cout << "ref:" << a << endl;
//
//
//	return 0;
//}


//����Ĭ�ϲ���
//��������Լ��������ݣ������Լ������ݣ����û�У���ô��Ĭ��ֵ
//�﷨������ֵ���ͣ����������β�=Ĭ��ֵ��
//int func(int a, int b = 20, int c = 30)
//{
//	return a + b + c;
//}
//���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ�����󣬴�����󣬱��붼Ҫ��Ĭ��ֵ
//�������������Ĭ��ֵ������ʵ�ֵ�ʱ��Ͳ�����Ĭ��ֵ�����������һ����Ĭ��ֵ


//��������
//1.ͬһ����������
//2.��������ͬ
//3.�����������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
//ע������
//��������ֵ���Ͳ�ͬ��Ϊ�������ص�����
//void func()
//{
//	cout << "func()����" << endl;
//}
////int func()
////{
////	cout << "func()����" << endl;
////}
//void func(int a)
//{
//	cout << "func(int a)����" << endl;
//}
//
//int main()
//{
//	func();
//	return 0;
//}

//�������ص�ע������
//1.������Ϊ���ص�����
//2.������������Ĭ�ϲ���
void func(int &a)
{
	cout << "func(int a)����" << endl;
}

void func(const int& a)
{
	cout << "func(const int a)����" << endl;
}

int main()
{
	int a = 10;
	func(a);
	//func(10);

	//system("pause");
	return 0;
}