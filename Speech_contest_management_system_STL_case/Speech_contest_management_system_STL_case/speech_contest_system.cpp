#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <ctime>
#include "speechManager.h"

using namespace std;


//����
int main1()
{
	//���������
	srand((unsigned int)time(NULL));

	//�������������
	SpeechManager sm;

	//����12��ѡ�ִ���
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{

		cout << "ѡ�ֱ�ţ�" << it->first << "		������" << it->second.m_Name << "	������" << it->second.m_Score[0] << endl;

	}

	return 0;
}
//?53272370?


int main()
{
	//�������������
	SpeechManager sm;
	int choice;
	
	while (true)
	{
		sm.show_Menu();
		cout << "����������ѡ��";
		cin >> choice;

		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴���������¼
			sm.showRecord();
			break;
		case 3://��ձ�����¼

			break;
		case 0:sm.exitSystem();
			break;
		default:
			system("clc");			//����
			break;
		}
		cout << endl;
		cout << endl;
	}
	




	system("pause");
	return 0;
}







