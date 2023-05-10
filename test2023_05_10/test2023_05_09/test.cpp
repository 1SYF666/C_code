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
//	//两个小数是不可以取余运算的
//	int a = 10;
//	a++;
//	cout << "a=" << a << endl;
//
//	return 0;
//}
//引用的基本语法
//int main()
//{
//	//数据类型  &别名=原名
//	int a = 0;
//	//创建别名
//	int &b = a;
//	b = 20;
//	cout << "b=" << b << endl;
//
//
//	//引用必须要初始化
//	//int& b;
//	//引用初始化后不可以改变
//	int c = 20;
//	b = c;		//这是赋值操作，不是更改引用
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//	return 0;
//}


//交换函数
//1、地址传递
//void mySwap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//引用传递
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
//	cout << "交换前" << endl;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	mySwap(a, b);
//	cout << "交换后" << endl;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	
//	return 0;
//}

//引用函数的返回值
//1、不要返回局部变量的引用
//int& tets01()
//{
//	int a = 10;
//	return a;
//}
//int main()
//{
//	int& ref = tets01();
//	cout << "ref=" << ref << endl;//第一次结果正确，是因为编译器做了保留
//	cout << "ref=" << ref << endl;//第二次结果错误，因为a的内存已经释放
//
//	return 0;
//}

//2、函数的调用可以作为左值
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


//引用的本质
//发现是引用，转换为 int* const ref=&a;
//void func(int& ref)
//{
//	ref = 100; //ref是引用，转换为*ref=100
//}
//int main()
//{
//	int a = 10;
//	
//	//自动转换为 int* const ref=&a;指针常量是指针指向不可改，也说明为什么引用不可更改
//	int& ref = a;
//	ref = 20;//内部发现ref是引用，自动帮我们转换为*ref=20;
//
//	cout << "a:" << a << endl;
//	cout << "ref:" << a << endl;
//
//
//	return 0;
//}


//函数默认参数
//如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值
//语法：返回值类型，函数名（形参=默认值）
//int func(int a, int b = 20, int c = 30)
//{
//	return a + b + c;
//}
//如果某个位置参数有默认值，那么从这个位置往后，从左向后，必须都要有默认值
//如果函数声明有默认值，函数实现的时候就不能有默认值，二者最多有一个有默认值


//函数重载
//1.同一个作用域下
//2.函数名相同
//3.函数参数类型不同，或者个数不同，或者顺序不同
//注意事项
//函数返回值类型不同作为函数重载的条件
//void func()
//{
//	cout << "func()调用" << endl;
//}
////int func()
////{
////	cout << "func()调用" << endl;
////}
//void func(int a)
//{
//	cout << "func(int a)调用" << endl;
//}
//
//int main()
//{
//	func();
//	return 0;
//}

//函数重载的注意事项
//1.引用作为重载的条件
//2.函数重载碰到默认参数
void func(int &a)
{
	cout << "func(int a)调用" << endl;
}

void func(const int& a)
{
	cout << "func(const int a)调用" << endl;
}

int main()
{
	int a = 10;
	func(a);
	//func(10);

	//system("pause");
	return 0;
}