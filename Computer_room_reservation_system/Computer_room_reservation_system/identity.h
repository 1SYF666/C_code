#pragma once //防止头文件重复包含

#include<iostream>
using namespace std;


//身份抽象基类
//在整个系统中，有三种身份，分别为：学生代表、老师以及管理员
//三种身份有其共性也有其特性，因此我们可以将三种身份抽象出一个身份基类identity
//在头文件下创建identity.h

class Identity
{
public:
	//操作菜单，纯虚函数
	virtual void openMenu() = 0;

	//用户名
	string m_Name;
	//密码
	string m_Pwd;
};

