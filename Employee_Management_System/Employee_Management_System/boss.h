#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

//������

//������ȥ�̳����ǵ�ְ��������
//������Ҫ��д�����еĴ���������virtual��ɾ�ɲ�ɾ
class Boss : public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dId);

	//��ʾ������Ϣ
	//��������ڳ������в����κ�ʵ�֣����Ը���һ�����麯��
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};
