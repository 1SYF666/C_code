#define _CRT_SECURE_NO_WARNINGS 1

#include "speechManager.h"

//���캯��
SpeechManager::SpeechManager()
{


}


void SpeechManager::show_Menu()
{
	cout << "****************************************" << endl;
	cout << "**********	 ��ӭ�μ��ݽ�����  **********" << endl;
	cout << "**********	 1����ʼ�ݽ�����   **********" << endl;
	cout << "**********	 2���鿴�����¼   **********" << endl;
	cout << "**********	 3����ձ�����¼   **********" << endl;
	cout << "**********	 0���˳���������   **********" << endl;
	cout << "****************************************" << endl;
	cout << endl;

}

//�˳�ϵͳ
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	cout << endl;
	system("pause");
	exit(0);
}


//��������
SpeechManager::~SpeechManager()
{


}

