#pragma once
#include <iostream>
#include <fstream>

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

#define FILENAME "empFile.txt"

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

	//����ְ��
	void Add_Emp();

	//�����ļ�
	void Save();
	
	//�ж��ļ��Ƿ�Ϊ�ձ�־
	bool m_FileIsEmpty;
	
	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int  IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkerManager();

};
