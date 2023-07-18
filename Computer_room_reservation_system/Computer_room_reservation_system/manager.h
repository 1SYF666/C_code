#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include"identity.h"
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	
	//�вι���
	Manager(string name, string pwd);
	
	//�˵�����
	virtual void openMenu();
	
	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();
	
	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//����ظ�,����1 ���ѧ��orְ���ţ�����2 ������� ѧ��or��ʦ
	bool checkRepeat(int id,int type);

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//������Ϣ
	vector<ComputerRoom>vCom;

	


};