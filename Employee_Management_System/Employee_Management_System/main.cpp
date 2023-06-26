#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "workerManger.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main()
{
	//实例化管理者对象
	WorkerManager wm;

	int choice = 0;
	while (true)
	{
		//调用展示菜单成员函数
		wm.Show_Menu();

		cout << "请输入您的选择" << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //增加职工
			wm.Add_Emp();
			break;
		case 2: //显示职工
			wm.Show_Emp();
			break;
<<<<<<< HEAD
		case 3: //ɾ��ְ��
			//����
		//{
		//	int ret = wm.IsExist(5);
		//	if (ret != -1)
		//	{
		//		cout << "ְ������" << endl;
		//	}
		//	else
		//	{
		//		cout << "ְ��������" << endl;
		//	}
		//	break;
		//}
=======
		case 3: //删除职工
>>>>>>> 24750e15f25eb4eb0c2a4c98357894a9b97062aa
			wm.Del_Emp();
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文档
			break;
		
		default:
			system("clc");
			break;
		}


	}
	system("pause");

	return 0;
}

//测试代码
int main1()
{
	//测试代码
	Worker* worker = NULL;
	
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
	
	return 0;
}
