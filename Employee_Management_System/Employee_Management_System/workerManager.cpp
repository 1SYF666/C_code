#define _CRT_SECURE_NO_WARNINGS 1
#include "workerManger.h"

WorkerManager::WorkerManager()
{
	//1、文件不存在
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		
		// 初试化记录人数
		this->m_EmpNum = 0;
		
		//初试化数组指针
		this->m_EmpArray = NULL;
		
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//cout << "文件为空" << endl;
		//初始化属性

		// 初试化记录人数
		this->m_EmpNum = 0;

		//初试化数组指针
		this->m_EmpArray = NULL;

		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3、文件存在，并且记录数据
	int num = this->get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();
	
	//测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_Id
	//		<< "姓名：" << this->m_EmpArray[i]->m_Name
	//		<< "部门编号：" << this->m_EmpArray[i]->m_DeptId
	//		<< endl;
	//}

}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0; //
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间人数=原来记录人数+新增人数

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}

		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//更新职工不为空标志
		this->m_FileIsEmpty = false;


		//提示添加成功
		cout << "成功添加" << addNum << "名新职工：" << endl;
	
		//保存数据到文件中
		this->Save();
	}
	else
	{
		cout << "输入数据有误" << endl;

	}

	//按任意键后，清屏回到上级目录
	system("pause");
	system("clc");
}

//展示菜单
void WorkerManager::Show_Menu()
{
	cout << "*************************************" << endl;
	cout << "******* 欢迎使用职工管理系统! *******" << endl;
	cout << "*********  0.退出管理程序  **********" << endl;
	cout << "*********  1.增加职工信息  **********" << endl;
	cout << "*********  2.显示职工信息  **********" << endl;
	cout << "*********  3.删除离职职工  **********" << endl;
	cout << "*********  4.修改职工信息  **********" << endl;
	cout << "*********  5.查找职工信息  **********" << endl;
	cout << "*********  6.按照编号排序  **********" << endl;
	cout << "*********  7.清空所有文档  **********" << endl;
	cout << "*************************************" << endl;
	cout << endl;

}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//保存文件
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件  --写文件

	//将每个数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读

	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数变量
		num++;
	}
	return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else //老板
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//显示职工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");


}


//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工的编号：" << endl;
		int id = 0;
		cin >> id;
		
		int index = this->IsExist(id);

		if (index != -1)//"说明职工存在",并且index为职工数组中要删除职工的下标
		{
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组中记录人员个数
		   
			//将数据同步更新到文件中
			this->Save();

			cout << "删除成功！" << endl;
		}
		else
		{ 
			cout << "删除失败,无要删除的职工" << endl;
		}	
	}

	//按任意键盘清屏操作
	system("pause");
	system("clc");
}

//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//找到职工
			index = i;
			break;
		}	
	}
	return index;
}



WorkerManager::~WorkerManager()
{
	//堆区的东西手动开辟，手动释放
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


