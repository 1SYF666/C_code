#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

//������

//������ȥ�̳����ǵ�ְ��������
//������Ҫ��д�����еĴ���������virtual��ɾ�ɲ�ɾ
class Manager : public Worker
{
public:
	//���캯��
	Manager(int id, string name, int dId);

	//��ʾ������Ϣ
	//��������ڳ������в����κ�ʵ�֣����Ը���һ�����麯��
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};
