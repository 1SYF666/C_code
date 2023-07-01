#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "speechManager.h"

using namespace std;

int main()
{
	//创建管理类对象
	SpeechManager sm;
	int choice;
	
	while (true)
	{
		sm.show_Menu();
		cout << "请输入您的选择：";
		cin >> choice;

		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:sm.exitSystem();
			break;
		default:
			system("clc");			//清屏
			break;
		}
		cout << endl;
		cout << endl;
	}
	




	system("pause");
	return 0;
}







