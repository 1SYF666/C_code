#define _CRT_SECURE_NO_WARNINGS 1

#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>

//构造函数
SpeechManager::SpeechManager()
{
	//初始化属性
	this->InitSpeech();

	//创建12名选手
	this->creatSpeaker();

	//加载往届记录
	this->loadRecord();

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
	this->showScore();
	
	//第二轮开始比赛
	this->m_Index++;
	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechContest();

	//3、显示最终结果
	this->showScore();
	
	//4、保存分数到文件中
	this->saveRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("clc");


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
				if (this->m_Index ==1)
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

//显示得分
void SpeechManager::showScore()
{
	cout << "--------------第   " << this->m_Index << "   轮晋级选手信息如下：--------------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << "	姓名：" << this->m_Speaker[*it].m_Name << "    得分：" <<
			this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("clc");
	this->show_Menu();

}

//保存记录
void SpeechManager::saveRecord()
{
	ofstream ofs;
	//如果没有下面speech.csv文件，会自动创建
	ofs.open("speech.csv", ios::out | ios::app);//以追加的方式写文件

	//将每个选手数据写入到文件中
	int count = 1;
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end()&&count<4; it++,count++)
	{
		//将前三名数据写入到文件中
		//ofs << "第"<<count<<"名：" << *it << "," <<"成绩是：" << this->m_Speaker[*it].m_Score[1] << "	,";
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	//写完数据就换行
	ofs << endl;
	
	//关闭文件
	ofs.close();

	cout << "记录已经保存" << endl;

}

//读取记录
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //读文件
	//文件不存在
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，不为空
	this->fileIsEmpty = false;

	ifs.putback(ch);//将上面读取的单个字符 放回来

	string data;
	int index = 0;  //第几届变量数
	while (ifs >> data)
	{
		//cout << data << endl;
		//10002,86.675,10009,81.3,10007,78.55
		int pos = -1;//查到逗号“，”位置的变量
		int start = 0;

		vector<string>v; //存放六个string字符串
	
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//没有找到情况
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;
		
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();

	//简单遍历一下

	for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << it->first << "冠军编号：" << it->second[0] << "分数：" << it->second[1] << endl;
	}
}



//析构函数
SpeechManager::~SpeechManager()
{
	

}

