#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//���캯���ķ��༰����
//���ַ��෽ʽ��
//��������Ϊ���вι�����޲ι���
//�����ͷ�Ϊ����ͨ����Ϳ�������
/*
class Person
{
public:
	//���캯��
	Person()//Ĭ��������ṩ���޲ι���
	{
		cout << "Person�Ĺ��캯������" << endl;
	}
	
	Person(int a)
	{
		age = a;
		cout << "Person���вι��캯������" << endl;
	}


	//�������캯��
	Person(const Person& p)
	{	//������������ϵ��������ԣ�������������
		age = p.age;
		cout << "�������캯������" << endl;

	}


	~Person()
	{
		cout << "Person��������������" << endl;
	}
	int age;


};


//���ֵ��÷�ʽ��
//���ŷ�����ʾ������ʽת����

void test01()
{
	//1.���ŷ�
	//Person p1;  //Ĭ�Ϲ��캯������
	//Person p2(10);  //�вι��캯������
	//Person p3(p2);  //�������캯������



	//ע������:
	// ����Ĭ�Ϲ��캯��ʱ�򣬲�Ҫ�ӣ���
	// 
	//cout << "p2������Ϊ��" << p2.age << endl;
	//
	//cout << "p3������Ϊ��" << p3.age << endl;

	//2.��ʾ��
	//Person p1;
	//Person p2= Person(10);//�вι������
	//Person p3= Person(p2);//�вι������

	//Person(10);				//��������
	//cout << "aaaa" << endl;
	//��Ҫ���ÿ������캯�������Ի���������
	//����������ΪPerson(p3)==Person p3;
	//Person(p3);

	//3.��ʽת����
	Person p4 = 10;//�뵱�� д�� Person P4=Person(10);
	Person p5 = Person(p4);

}

int main()
{
	test01();
}
*/

/*
class Person
{
public:
	Person()
	{
		cout << "PersonĬ�Ϲ��캯������" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person�вι��캯������" << endl;
	}
	Person(const Person& p)
	{
		age= p.age;
		cout << "Person�������캯������" << endl;
	}

	~Person()
	{
		cout << "Person������������" << endl;
	}
	int age;
};

//�������캯������ʱ��
//c++�п�����������ʱ��ͨ�����������
//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2������Ϊ��" << p2.age << endl;
}



//2.ֵ���ݵķ�ʽ��������������
void doWork(Person p)
{

}

void test02()
{
	Person p;
	doWork(p);
}

//3.��ֵ��ʽ���ؾֲ�����
Person doWork2()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test03()
{
	Person p = doWork2();
	cout << (int*)&p << endl;
}
int main()
{
	//test01();
	//test02();
	test03();
}*/


//���캯�����ù���
//Ĭ������£�c++���������ٸ�һ�������3������
// 1.Ĭ�Ϲ��캯�����޲Σ�������Ϊ�գ�
// 2.Ĭ�������������޲Σ�������Ϊ�գ�
// 3.Ĭ�Ͽ������캯���������Խ���ֵ����



//���캯�����ù�������:
//1.����û������вι��캯����c++�����ṩ�޲ι��죬�����ṩĬ�Ͽ�������
//2������û����忽�����캯����c++�������ṩ�������캯��

/*
class Person
{
public:
	//Person()
	//{
	//	cout << "PersonĬ�Ϲ��캯������" << endl;
	//}
	Person(int a)
	{
		age = a;
		cout << "Person�вι��캯������" << endl;
	}

	//Person(const Person& p)
	//{
	//	age = p.age;
	//	cout << "PersonĬ�Ϲ��캯������" << endl;
	//}

	~Person()
	{
		cout << "Person�����캯������" << endl;
	}
	int age;

};
//
//void test01()
//{
//	Person p;
//	p.age = 0;
//	Person p2(p);
//	cout << "p2�������ǣ�" << p2.age << endl;
//}

void test02()
{
	Person p(18);
	Person p2(p);
	cout << "p2�������ǣ�" << p2.age << endl;
}

int main()
{
	//test01();
	test02();

	return 0;
}
*/


