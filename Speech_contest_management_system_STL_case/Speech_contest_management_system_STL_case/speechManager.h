#pragma once

#include <iostream>
using namespace std;

//设计演讲管理类
/*
	功能描述：
	提供菜单界面与用户
	对演讲比赛流程进行控制
	与文件的读写交互
*/
class SpeechManager
{
public:
	//构造函数
	SpeechManager();

	//菜单功能
	void show_Menu();

	//退出系统
	void exitSystem();

	/*
	演讲比赛功能：
	功能分析：
	--比赛流程--
	抽签----开始演讲比赛----显示第一轮比赛结果
	抽签----开始演讲比赛----显示前三名结果----保存分数
	
	既然第一步要抽签，就应该有选手，故先要创建一个选手类
	选手类属性：
	---选手姓名、分数
	头文件中创建speaker.h文件，并添加代码

	*/
	








	//析构函数
	~SpeechManager();



};


