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

	//构造函数
	WorkerManager();
	
	//展示菜单
	void Show_Menu();
	
	//退出系统
	void ExitSystem();


	//记录职工人数
	int m_EmpNum;
	
	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void Save();
	
	//判断文件是否为空标志
	bool m_FileIsEmpty;
	
	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

<<<<<<< HEAD
	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int  IsExist(int id);

	//��������
=======
	//删除职工
	void Del_Emp();

	//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
	int  IsExist(int id);

	//析构函数
>>>>>>> 24750e15f25eb4eb0c2a4c98357894a9b97062aa
	~WorkerManager();

};

