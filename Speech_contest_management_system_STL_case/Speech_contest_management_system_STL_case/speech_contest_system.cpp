#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "speechManager.h"

using namespace std;

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
		case 1:
			break;
		case 2:
			break;
		case 3:
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







