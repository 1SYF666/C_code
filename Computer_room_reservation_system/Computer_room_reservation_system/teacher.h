#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<iostream>
#include"identity.h"
#include"orderFile.h"
#include<vector>
//��ʦ�����
class Teacher :public Identity
{
public:

	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//ְ����
	int m_EmpId;



};