#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
/*
--公司今天招聘10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在哪个部门工作
--员工信息有：姓名  工资组成 ；部门分为：策划、美术、研发
--随机给10名员工分配部门和工资
--通过multimap进行信息的插入  key(部门编号) value(员工)
--分部门显示员工信息
*/

#define CEHUA 0
#define MBISHU 1
#define YANFA 2


class Worker
{
public:
	string m_Name;
	int m_Salary;

};

void creatWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;//10000~19999
		//
		//将员工放入到容器中
		v.push_back(worker);
	}
}

//员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>&  m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int deptId = rand() % 3;  //0,1,2

		//将员工插入到分组中
		//key部门编号，value具体分工
		m.insert(make_pair(deptId, *it));
	}
}


//分组显示
void  showWorkerByGourp(multimap<int, Worker>& m)
{
	//0 A B C  ; 1 D E ; 2 F G..... 
	cout << "策划部门" << endl;

	multimap<int,Worker>::iterator pos= m.find(CEHUA);

	int count = m.count(CEHUA);   //统计策划部门具体人数
	int index = 0;

	//遍历
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名 ：" << pos->second.m_Name << "	工资：" << pos->second.m_Salary << endl;
	}

	cout << "------------------------------------" << endl;

	cout << "美术部门" << endl;

	pos = m.find(MBISHU);

	count = m.count(MBISHU);   //统计策划部门具体人数
	index = 0;

	//遍历
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名 ：" << pos->second.m_Name << "	工资：" << pos->second.m_Salary << endl;
	}

	cout << "------------------------------------" << endl;

	cout << "研发部门" << endl;

	pos = m.find(YANFA);

	count = m.count(YANFA);   //统计策划部门具体人数
	index = 0;

	//遍历
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名 ：" << pos->second.m_Name << "	工资：" << pos->second.m_Salary << endl;
	}


}

int main()
{
	//1、创建员工
	vector<Worker>vWorker;
	
	creatWorker(vWorker);

	////测试
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "姓名：" << it->m_Name << "	工资：" << it->m_Salary << endl;
	//}

	//2、员工分组
	multimap<int,Worker>mWorker;

	setGroup(vWorker, mWorker);

	//3、分组显示
	showWorkerByGourp(mWorker);


	system("pause");

	return 0;
}


