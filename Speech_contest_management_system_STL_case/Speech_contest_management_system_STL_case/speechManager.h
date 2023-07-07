#pragma once

#include <iostream>
#include <vector>
#include <map>

#include"speaker.h"
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


	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int>v1;

	//第一轮晋级选手编号容器
	vector<int>v2;

	//胜出前三名选手编号容器
	vector<int>vVictory;

	//存放编号以及对应具体选手容器
	map<int, Speaker>m_Speaker;
	
	//比赛轮毂
	int m_Index;

	//对上面属性进行初始化操作
	void InitSpeech();

	/*
	
	开始创建选手

	*/

	//创建选手
	void creatSpeaker();
	
	/*
	
	开始抽签
	
	开始比赛，比赛整个流程
	*/

	//开始比赛，比赛这个流程控制函数
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示得分
	void showScore();

	//保存记录
	void saveRecord();

	/*读取记录分数*/
	//读取记录
	void loadRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>>m_Record;

	//显示往届记录
	void showRecord();







	//析构函数
	~SpeechManager();



};


