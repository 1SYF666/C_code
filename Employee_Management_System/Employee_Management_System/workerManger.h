#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

class WorkerManager
{
public:

	//���캯��
	WorkerManager();
	
	//չʾ�˵�
	void Show_Menu();
	
	//�˳�ϵͳ
	void ExitSystem();


	//��¼ְ������
	int m_EmpNum;
	
	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//��������
	~WorkerManager();

};

