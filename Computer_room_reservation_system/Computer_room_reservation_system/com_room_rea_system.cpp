#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


int main()
{
	int select = 0;
	while (true)
	{
		cout << "================= 欢迎来到传智博客机房预约系统 ===================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -----------------------------\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|        1、学生代表           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|        2、老    师           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|        3、管 理 员           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|        0、退    出           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t -----------------------------\n";
		cout << "请输入您的选择：";
		cin >> select;


		switch (select)
		{
		case 1://学生身份
			break;
		case 2://老    师
			break;
		case 3://管 理 员
			break;
		case 0://退    出
		{	cout << "欢迎下次使用" << endl;
			system("pause");
			return 0; 
		}
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("clc");
			break;
		}


	}






	system("pause");

	return 0;
}

