#pragma once

#include <iostream>
#include <vector>
#include <map>

#include"speaker.h"
using namespace std;

//����ݽ�������
/*
	����������
	�ṩ�˵��������û�
	���ݽ��������̽��п���
	���ļ��Ķ�д����
*/
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//�˵�����
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	/*
	�ݽ��������ܣ�
	���ܷ�����
	--��������--
	��ǩ----��ʼ�ݽ�����----��ʾ��һ�ֱ������
	��ǩ----��ʼ�ݽ�����----��ʾǰ�������----�������
	
	��Ȼ��һ��Ҫ��ǩ����Ӧ����ѡ�֣�����Ҫ����һ��ѡ����
	ѡ�������ԣ�
	---ѡ������������
	ͷ�ļ��д���speaker.h�ļ�������Ӵ���

	*/


	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int>v1;

	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;

	//ʤ��ǰ����ѡ�ֱ������
	vector<int>vVictory;

	//��ű���Լ���Ӧ����ѡ������
	map<int, Speaker>m_Speaker;
	
	//�������
	int m_Index;

	//���������Խ��г�ʼ������
	void InitSpeech();

	/*
	
	��ʼ����ѡ��

	*/

	//����ѡ��
	void creatSpeaker();
	
	/*
	
	��ʼ��ǩ
	
	��ʼ������������������
	*/

	//��ʼ����������������̿��ƺ���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();

	/*��ȡ��¼����*/
	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>>m_Record;

	//��ʾ�����¼
	void showRecord();







	//��������
	~SpeechManager();



};


