#define _CRT_SECURE_NO_WARNINGS 1

#include "speechManager.h"
#include <algorithm>
#include <deque>

//构造函数
SpeechManager::SpeechManager()
{
	//初始化属性
	this->InitSpeech();

	//创建12名选手
	this->creatSpeaker();


}


void SpeechManager::show_Menu()
{
	cout << "****************************************" << endl;
	cout << "**********	 欢迎参加演讲比赛  **********" << endl;
	cout << "**********	 1、开始演讲比赛   **********" << endl;
	cout << "**********	 2、查看往届记录   **********" << endl;
	cout << "**********	 3、清空比赛记录   **********" << endl;
	cout << "**********	 0、退出比赛程序   **********" << endl;
	cout << "****************************************" << endl;
	cout << endl;

}

//退出系统
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	cout << endl;
	system("pause");
	exit(0);
}


void SpeechManager::InitSpeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮毂
	this->m_Index = 1;

}


//创建12名选手
void SpeechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_Name= name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//创建选手编号，并且放入到v1容器中
		this->v1.push_back(i + 10001);

		//选手编号以及对应选手放入到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}

}


//开始比赛，比赛这个流程控制函数
void SpeechManager::startSpeech()
{
	//第一轮开始比赛

	//1、抽签
	this->speechDraw();

	//2、比赛
	
	//3、显示晋级结果

	//第二轮开始比赛

	//1、抽签

	//2、比赛

	//3、显示最终结果

}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第 << " << this->m_Index << ">>轮比赛选手正在抽签" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (this->m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;


	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;

	}
	cout << "----------------------------------------------------" << endl;

	system("pause");
	cout << endl;


}


//比赛流程
void SpeechManager::speechContest()
{
	cout << "-----------第	" << this->m_Index << "		轮比赛正式开始------------" << endl;

	vector<int>v_Src;//比赛选手容器

	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			//产生60-100的随机数
			double score = (rand() % 401 + 600)/10.f;//rand()%401产生0-400之间的随机数， 
			cout << score << " ";
			d.push_back(score);
		}




	}




}


//析构函数
SpeechManager::~SpeechManager()
{
	

}

