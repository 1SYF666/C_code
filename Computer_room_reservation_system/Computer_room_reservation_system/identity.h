#pragma once //��ֹͷ�ļ��ظ�����

#include<iostream>
using namespace std;


//��ݳ������
//������ϵͳ�У���������ݣ��ֱ�Ϊ��ѧ��������ʦ�Լ�����Ա
//����������乲��Ҳ�������ԣ�������ǿ��Խ�������ݳ����һ����ݻ���identity
//��ͷ�ļ��´���identity.h

class Identity
{
public:
	//�����˵������麯��
	virtual void openMenu() = 0;

	//�û���
	string m_Name;
	//����
	string m_Pwd;
};

