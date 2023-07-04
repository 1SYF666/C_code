#define _CRT_SECURE_NO_WARNINGS 1

#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>

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
	this->speechContest();
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
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
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
	cout << "-----------第	" << this->m_Index << "轮比赛正式开始------------" << endl;
	//cout << endl;
	
	//准备临时容器，存放小组成绩
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//记录人员个数 6人一组

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
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			//产生60-100的随机数
			double score = (rand() % 401 + 600)/10.f;//rand()%401产生0-400之间的随机数， 
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		
		//降序排列
		sort(d.begin(), d.end(), greater<double>());	//排序
		d.pop_front(); //去除最高分
		d.pop_back();  //去除最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size(); //平均分

		//打印平均分
		//cout << "编号：" << *it << "	姓名：" << this->m_Speaker[*it].m_Name << "    获取平均分：" << avg << endl;
		//将平均分放入到map容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//cout << endl;

		//将打分数据放到临时小组容器中
		groupScore.insert(make_pair(avg, *it));//key是得分，value是具体选手编号

		//每六人取出前三名
		if (num % 6 == 0)
		{
			cout << "第	" << num / 6 << "    小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end();it++)
			{
				cout << "编号：" << it->second << "	姓名：" << this->m_Speaker[it->second].m_Name << "	成绩："
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index = 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();
			cout << endl;
		}

	}

	//cout << endl;
	cout << "-------------------第   " << this->m_Index << "   轮比赛完毕！-------------" << endl;
	system("pause");
}


//析构函数
SpeechManager::~SpeechManager()
{
	

}

