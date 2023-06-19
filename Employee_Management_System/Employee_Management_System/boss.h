#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

//经理类

//经理类去继承我们的职工抽象类
//子类需要重写父类中的存续函数，virtual可删可不删
class Boss : public Worker
{
public:
	//构造函数
	Boss(int id, string name, int dId);

	//显示个人信息
	//这个函数在抽象类中不做任何实现，所以给它一个村虚函数
	virtual void showInfo();

	//获取岗位名称
	virtual string getDeptName();
};
