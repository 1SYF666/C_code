#pragma once
#include<stdio.h>


//*******************2023/8/18 22:00*********************//

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef struct {
	char name[8];
	char num[8];
	int score;
}ElemType;

typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode, * LinkList;


//*******************2023/8/23 22:58*********************//

//Doubly Linked List
typedef struct DuLnode {
	ElemType data;
	struct DuLnode* next;
	struct DuLnode* prior;
}DuLnode, * DuLinkList;


//initial the singly linked list
Status InitList_L(LinkList& L);

//Is the singly linked list empty
Status ListEmpty(LinkList L);

//destroyed the singly linked list empty
Status DestroyList_L(Lnode* L);

//clear the singly linked list(save head and node) 
Status ClearList(LinkList& L);


//*******************2023/8/20 12:17*********************//

//calculate the Length of a Singly Linked List"¡£
Status ListLength_L(LinkList L);

//get the Elem of a Singly Linked List"¡£
Status GetElem_L(LinkList L, int i, ElemType& e);

//search the Elem of a singly linked list
Lnode* LocateElem_L_first(LinkList L, ElemType e);

//search the Elem of a singly linked list
Status LocateElem_L_second(LinkList L, ElemType e);

//Insert the data element e before the i-th element in L.
Status ListInsert_L(LinkList& L, int i, ElemType e);

//delete the data element of the i-th in L.
Status ListDelete_L(LinkList& L, int i, ElemType e);

//creat the singly linked list
void CreatList_H(LinkList& L, int n);

//creat the singly linked list on Tail insertion method
void CreatList_R(LinkList& L, int n);

//creat the circular linked list--tail insertion method
void CreatList(LinkList& L);




