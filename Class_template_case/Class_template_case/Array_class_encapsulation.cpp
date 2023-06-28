#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include "MyArray.hpp"

void printIntArray(MyArray <int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}

}

void test01()
{
	MyArray <int>arr1(5);
	//MyArray <int>arr2(arr1);
	//MyArray <int>arr3(100);
	//arr3 = arr1;

	for (int i = 0; i < 5; i++)
	{
		//利用尾插法像数组中插入数据
		arr1.Push_Back(i);

	}
	cout << "arr1的打印输出为：" << endl;
	printIntArray(arr1);



}


int main()
{
	test01();

	system("pause");

}