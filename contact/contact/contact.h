#pragma once
//#define MAX 1000
#define DEFAULT_SZ  3
#define NAME 20
#define SEX 5
#define TELE 12
#define ADDR 30

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*

��̬�����汾
Ĭ�Ͽ��Դ��3���˵���Ϣ
�����ֵ�ǰͨѶ¼����ʱ�����ǿ������ݣ�ÿ������2���ռ�

*/



enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};


typedef struct PeoInfo
{
	char name[NAME];
	char sex[SEX];
	char tele[TELE];
	char addr[ADDR];
	int age;
}PeoInfo;

//ͨѶ¼��Ϣ
typedef struct Contact
{
	//�ṹ��Ƕ��
	//struct PeoInfo data[MAX];		//���һ����Ϣ
	struct PeoInfo* data;		    //���һ����Ϣ
	int size;						//��¼��ǰ�Ѿ��е�Ԫ�ظ���
	int capacity;					//��ǰͨѶ¼���������
}Contact;


//��������

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);
//����ָ���˵���Ϣ
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void DestoryContact(Contact* ps);

//������Ϣ
void SaveContact(Contact* ps);
//������Ϣ
void LoadContact(Contact* ps);
