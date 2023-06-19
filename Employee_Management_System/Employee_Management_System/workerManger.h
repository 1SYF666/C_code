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

	//析构函数
	~WorkerManager();

};

