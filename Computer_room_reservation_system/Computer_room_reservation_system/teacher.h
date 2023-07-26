#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<iostream>
#include"identity.h"
#include"orderFile.h"
#include<vector>
//教师类设计
class Teacher :public Identity
{
public:

	//默认构造
	Teacher();

	//有参构造
	Teacher(int empId, string name, string pwd);

	//菜单界面
	virtual void openMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//职工号
	int m_EmpId;



};