#define _CRT_SECURE_NO_WARNINGS 1
#include"manager.h"
#include"globalFile.h"
#include<algorithm>

Manager::Manager()
{


}

//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������ ��ȡ�������ļ��� ѧ������ʦ��Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	
	while (ifs>>com.m_ComId&&ifs>>com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();

	cout << "����������Ϊ��" << vCom.size() << endl;

}

//�˵�����
void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|        1�������˺�           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|        2���鿴�˺�           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|        3���鿴����           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|        4�����ԤԼ           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|        0��ע����¼           |\n";
	cout << "\t\t -----------------------------\n";
	cout << "��ѡ�����Ĳ�����" << endl;

}

//�����˺�
void Manager::addPerson()
{
	cout << "�����������˺ŵ�����" << endl;
	cout << "1������ѧ��" << endl;
	cout << "2��������ʦ" << endl;
	
	string fileName;  //�����ļ���
	string tip;  //��ʾid��
	string errorTip;

	ofstream ofs;  //�ļ���������

	int select = 0;

	cin >> select;  //�����û���ѡ��
	
	if (select == 1)
	{
		//���ӵ�ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";

	}

	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�������������";
	}

	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;//ѧ��/ְ����
	string name; //����
	string pwd;  //����

	cout << tip << endl;

	while (true)
	{
		cin >> id;

		bool ret = checkRepeat(id, select);
		if (ret) //���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	//���ļ�����������

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "���ӳɹ�" << endl;

	system("pause");
	system("clc");

	ofs.close();

	//���ó�ʼ�������ӿڣ����»�ȡ���ļ��е�����
	this->initVector();
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << "������" << s.m_Name << "���룺" << s.m_Pwd << endl;

}

void printTeacher(Teacher& s)
{
	cout << "ְ���ţ�" << s.m_EmpId << "������" << s.m_Name << "���룺" << s.m_Pwd << endl;

}


//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����" << endl;
	cout << "1���鿴����ѧ����" << endl;
	cout << "2���鿴������ʦ��" << endl;

	int select;  //�����û�ѡ��
	cin >> select;

	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(),printStudent);

	}

	if (select == 2)
	{

		//�鿴��ʦ
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);

	}


}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << "�����������" << it->m_MaxNum << endl;

	}
	system("pause");
	system("clc");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("clc");

}


//��ʼ������
void Manager::initVector()
{
	//ȷ���������״̬
	vStu.clear();
	vTea.clear();

	//��ȡ��Ϣ  ѧ������ʦ
	ifstream ifs;

	//��ȡѧ����Ϣ
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "ѧ���ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}

	cout << "��ǰ��ѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʦ�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs>> t.m_Pwd)
	{
		vTea.push_back(t);
	}

	cout << "��ǰ����ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}


bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}

		}

	}

	return false;

}