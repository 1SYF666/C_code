#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//构造函数的分类及调用
//两种分类方式：
//按参数分为：有参构造和无参构造
//按类型分为：普通构造和拷贝构造
/*
class Person
{
public:
	//构造函数
	Person()//默认情况下提供的无参构造
	{
		cout << "Person的构造函数调用" << endl;
	}
	
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}


	//拷贝构造函数
	Person(const Person& p)
	{	//将传入的人身上的所有属性，拷贝到我身上
		age = p.age;
		cout << "拷贝构造函数调用" << endl;

	}


	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	int age;


};


//三种调用方式：
//括号法、显示法、隐式转换法

void test01()
{
	//1.括号法
	//Person p1;  //默认构造函数调用
	//Person p2(10);  //有参构造函数调用
	//Person p3(p2);  //拷贝构造函数调用



	//注意事项:
	// 调用默认构造函数时候，不要加（）
	// 
	//cout << "p2的年龄为：" << p2.age << endl;
	//
	//cout << "p3的年龄为：" << p3.age << endl;

	//2.显示法
	//Person p1;
	//Person p2= Person(10);//有参构造调用
	//Person p3= Person(p2);//有参构造调用

	//Person(10);				//匿名对象
	//cout << "aaaa" << endl;
	//不要利用拷贝构造函数，初试化匿名对象
	//编译器会认为Person(p3)==Person p3;
	//Person(p3);

	//3.隐式转换法
	Person p4 = 10;//想当于 写了 Person P4=Person(10);
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
		cout << "Person默认构造函数调用" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		age= p.age;
		cout << "Person拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}
	int age;
};

//拷贝构造函数调用时机
//c++中拷贝函数调用时机通常有三种情况
//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2的年龄为：" << p2.age << endl;
}



//2.值传递的方式给函数参数传递
void doWork(Person p)
{

}

void test02()
{
	Person p;
	doWork(p);
}

//3.以值方式返回局部对象
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


//构造函数调用规则
//默认情况下，c++编译器至少给一个类添加3个函数
// 1.默认构造函数（无参，函数体为空）
// 2.默认析构函数（无参，函数体为空）
// 3.默认拷贝构造函数，对属性进行值拷贝



//构造函数调用规则如下:
//1.如果用户定义有参构造函数，c++不在提供无参构造，但会提供默认拷贝构造
//2。如果用户定义拷贝构造函数，c++不会再提供其他构造函数

/*
class Person
{
public:
	//Person()
	//{
	//	cout << "Person默认构造函数调用" << endl;
	//}
	Person(int a)
	{
		age = a;
		cout << "Person有参构造函数调用" << endl;
	}

	//Person(const Person& p)
	//{
	//	age = p.age;
	//	cout << "Person默认构造函数调用" << endl;
	//}

	~Person()
	{
		cout << "Person析构造函数调用" << endl;
	}
	int age;

};
//
//void test01()
//{
//	Person p;
//	p.age = 0;
//	Person p2(p);
//	cout << "p2的年龄是：" << p2.age << endl;
//}

void test02()
{
	Person p(18);
	Person p2(p);
	cout << "p2的年龄是：" << p2.age << endl;
}

int main()
{
	//test01();
	test02();

	return 0;
}
*/


