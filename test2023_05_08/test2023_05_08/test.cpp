#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//常量
//1.#define 宏常量
//2.const修饰的变量
#define DAY 7
int main()
{
	//单精度
	//双精度
	//编译器默认小数是双精度，后缀加f是编译器认为小数是单精度
	float f1 = 3.14f;
	double d1 = 3.14;
	int a = 10;
	float f2 = 3e2;
	float f3 = 3e-2;
	const int month = 12;
	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;
	cout << "f3=" << f3 << endl;
	cout << "d1=" << d1 << endl;
	cout << "hello world C++" << endl;
	cout << "a = " << a << endl;
	cout << "一年一共有" << month << "年" << endl;
	system("pause");
	return 0;
}
