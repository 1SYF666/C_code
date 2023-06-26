#pragma once
#include <iostream>
#include <string>
using namespace std;

//职工抽象类
class Worker
{
public:

	//显示个人信息
	//这个函数在抽象类中不做任何实现，所以给它一个村虚函数
	virtual void showInfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0;

	//职工编号
	int m_Id;

	//职工姓名
	string m_Name;

	//部门编号
	int m_DeptId;

};

