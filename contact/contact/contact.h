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

动态增长版本
默认可以存放3个人的信息
当发现当前通讯录满的时候，我们可以扩容，每次增加2个空间

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

//通讯录信息
typedef struct Contact
{
	//结构体嵌套
	//struct PeoInfo data[MAX];		//存放一个信息
	struct PeoInfo* data;		    //存放一个信息
	int size;						//记录当前已经有的元素个数
	int capacity;					//当前通讯录的最大容量
}Contact;


//函数声明

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
//删除指定的联系人
void DelContact(struct Contact* ps);
//查找指定人的信息
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void DestoryContact(Contact* ps);

//保存信息
void SaveContact(Contact* ps);
//加载信息
void LoadContact(Contact* ps);
