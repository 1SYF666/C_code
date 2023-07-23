#define _CRT_SECURE_NO_WARNINGS 1
#include"student.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

//默认构造
Student::Student()
{

}
//有参构造 参数：学号、姓名、密码
Student::Student(int id, string name, string pwd)
{
	//初始化属性
	this->m_Id=id;
	this->m_Name=name;
	this->m_Pwd=pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);
	
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		//读取信息放入到容器中
		vCom.push_back(com);
	}

	ifs.close();
}

//菜单界面
void Student::openMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|        1、申请预约               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|        2、查看我的预约           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|        3、查看所有预约           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|        4、取消预约               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|        0、注销登录               |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作：" << endl;
	

}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放的时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date = 0;  //日期
	int interval = 0;  //时间段
	int room = 0;  //机房编号

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;

		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入申请预约的时间段:" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	
	cout << "请选择机房:" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "号机房容量为：" << vCom[i].m_MaxNum << endl;

	}
	
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功，审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << " status:" << 1 << endl;
	
	ofs.close();
	system("pause");
	system("clc");

}

//查看自身预约
void Student::showMyOrder()
{
	OrderFile of;



}

//查看所有预约
void Student::showAllOrder()
{


}

//取消预约
void Student::cancelOrder()
{


}

