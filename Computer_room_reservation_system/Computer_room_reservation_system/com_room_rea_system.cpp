#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include"identity.h"
#include<fstream>
#include"student.h"
//登录功能   参数1  操作文件名  参数2  操作身份类型
void LoginIn(string fileName, int type)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份，
	if (type == 1)//学生信息
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId; //从文件中读取的id号
		string fName;//从文件中获取的姓名
		string fPwd;
		while (ifs>>fId&&ifs>>fName&&ifs>>fPwd)
		{
			cout << fId << endl;
			cout << fName << endl;
			cout << fPwd << endl;
			cout << endl;
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("clc");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单


				return;
			}
		}

	}
	else if (type == 2)
	{
		//教师身份验证
	}
	else if (type == 3)
	{
		//管理员身份验证
	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("clc");




}



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

