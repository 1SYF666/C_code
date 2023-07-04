#define _CRT_SECURE_NO_WARNINGS 1

#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>

//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������
	this->InitSpeech();

	//����12��ѡ��
	this->creatSpeaker();


}


void SpeechManager::show_Menu()
{
	cout << "****************************************" << endl;
	cout << "**********	 ��ӭ�μ��ݽ�����  **********" << endl;
	cout << "**********	 1����ʼ�ݽ�����   **********" << endl;
	cout << "**********	 2���鿴�����¼   **********" << endl;
	cout << "**********	 3����ձ�����¼   **********" << endl;
	cout << "**********	 0���˳���������   **********" << endl;
	cout << "****************************************" << endl;
	cout << endl;

}

//�˳�ϵͳ
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	cout << endl;
	system("pause");
	exit(0);
}


void SpeechManager::InitSpeech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ���������
	this->m_Index = 1;

}


//����12��ѡ��
void SpeechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_Name= name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//����ѡ�ֱ�ţ����ҷ��뵽v1������
		this->v1.push_back(i + 10001);

		//ѡ�ֱ���Լ���Ӧѡ�ַ��뵽map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}

}


//��ʼ����������������̿��ƺ���
void SpeechManager::startSpeech()
{
	//��һ�ֿ�ʼ����

	//1����ǩ
	this->speechDraw();

	//2������
	this->speechContest();
	//3����ʾ�������

	//�ڶ��ֿ�ʼ����

	//1����ǩ

	//2������

	//3����ʾ���ս��

}

//��ǩ
void SpeechManager::speechDraw()
{
	cout << "�� << " << this->m_Index << ">>�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (this->m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	else
	{
		//�ڶ��ֱ���
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


//��������
void SpeechManager::speechContest()
{
	cout << "-----------��	" << this->m_Index << "�ֱ�����ʽ��ʼ------------" << endl;
	//cout << endl;
	
	//׼����ʱ���������С��ɼ�
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//��¼��Ա���� 6��һ��

	vector<int>v_Src;//����ѡ������

	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			//����60-100�������
			double score = (rand() % 401 + 600)/10.f;//rand()%401����0-400֮���������� 
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		
		//��������
		sort(d.begin(), d.end(), greater<double>());	//����
		d.pop_front(); //ȥ����߷�
		d.pop_back();  //ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size(); //ƽ����

		//��ӡƽ����
		//cout << "��ţ�" << *it << "	������" << this->m_Speaker[*it].m_Name << "    ��ȡƽ���֣�" << avg << endl;
		//��ƽ���ַ��뵽map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//cout << endl;

		//��������ݷŵ���ʱС��������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��

		//ÿ����ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��	" << num / 6 << "    С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end();it++)
			{
				cout << "��ţ�" << it->second << "	������" << this->m_Speaker[it->second].m_Name << "	�ɼ���"
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			//ȡ��ǰ����
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
	cout << "-------------------��   " << this->m_Index << "   �ֱ�����ϣ�-------------" << endl;
	system("pause");
}


//��������
SpeechManager::~SpeechManager()
{
	

}

