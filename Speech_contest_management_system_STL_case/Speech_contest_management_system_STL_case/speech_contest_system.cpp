#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
#include "speechManager.h"

using namespace std;


//测试
int main1()
{
	//创建管理类对象
	SpeechManager sm;

	//测试12名选手创建
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{

		cout << "选手编号：" << it->first << "		姓名：" << it->second.m_Name << "	分数：" << it->second.m_Score[0] << endl;

	}

	return 0;
}
//?53272370?


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
		case 1:sm.startSpeech();
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







