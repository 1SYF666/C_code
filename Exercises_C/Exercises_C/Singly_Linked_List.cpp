#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include"Singly_Linked_List.h"
//*******************2023/8/18 22:00*********************//

//singly linked list with head node below
using namespace std;

Status InitList_L(LinkList& L)
{
	L = new Lnode;  //L=(LinkList)malloc(sizeof(LNode));
	L->next = NULL;

	return OK;
}

Status ListEmpty(LinkList L)
{
	if (L->next) //no empty
		return 0;
	else
		return 1;
}
//destroyed the singly linked list empty
Status DestroyList_L(LinkList& L)
{
	Lnode* p;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}

	return OK;
}


//clear the singly linked list(save head and node) 
Status ClearList(LinkList& L){
	Lnode* p;
	Lnode* q;
	p = L->next;
	while (p){
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
}


//calculate the LengthofaSingly Linked List"¡£
Status ListLength_L(LinkList L) {
	LinkList p;
	p = L->next;  // pointing to the head node
	int i = 0;
	while (p){
		i++;
		p = p->next; // pointing to the next node
	}

	return i;
}


//get the Elem of a Singly Linked List"¡£
Status GetElem_L(LinkList L, int i, ElemType& e) {
	
	//initial
	int j = 1;
	LinkList p;
	p = L->next;

	//scan backwards until p points to the i-th element or p is empty
	while (p&&j<i){
		p = p->next;
		j++;
	}

	//i-th element does not exist or the linked list is empty
	if (!p || j > i) {
		return ERROR;
	}
	
	e = p->data;  //OK

	return OK;

}


//search the Elem of a singly linked list first
Lnode* LocateElem_L_first(LinkList L, ElemType e) {

	Lnode* p;
	p = L->next;

	while (p&&p->data.name!=e.name&&p->data.num!=e.num&&p->data.score!=e.score)
	{
		p = p->next;
	}

	return p;
}

//search the Elem of a singly linked list
Status LocateElem_L_second(LinkList L, ElemType e) {
	Lnode* p;
	p = L->next;
	int j = 1;

	while (p&& p->data.name != e.name && p->data.num != e.num && p->data.score != e.score){

		p = p->next;
		
		j++;
	}

	if (p) return j;

	else return 0;
}


//Insert the data element e before the i-th element in L.
Status ListInsert_L(LinkList& L, int i, ElemType e) {

	//initial head node 
	int j = 0;
	LinkList p;
	p = L;
	
	//search i-th node;p points (i-1)-th node
	while (p && j < i - 1) {   //atention the condition not equal to delete...
		p = p->next;
		j++;
	}

	if (!p) return ERROR;

	//insert new node
	Lnode* s;
	s = new Lnode; s->data = e;
	s->next = p->next; p->next = s;
	  
	return OK;
}


//delete the data element of the i-th in L.
Status ListDelete_L(LinkList& L, int i, ElemType e) {

	Lnode* p=L;
	Lnode* q;
	int j = 0;

	//search  i-th node
	while (p->next&&j<i-1) {
		p = p->next; j++;
	}

	if (!(p->next) || j > i - 1) return ERROR;  //delete location no reasonable

	q = p->next;         //save delete node to free place
	p->next = q->next;   //changde the before node 
	e = q->data;         //save the of element of delete node
	delete q;            //free

	return OK;
}



//creat the singly linked list
void CreatList_H(LinkList& L, int n) {

	//First, create a singly linked list with a head node
	int i = 0;
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	for (i = n; i > 0; --i) {
		//creat new node
		Lnode* p;
		p= (Lnode*)malloc(sizeof(Lnode));
		
		//enter new data to insert
		cin>>p->data.name;
		cin>>p->data.num;
		cin>>p->data.score;

		//insert the head location of list
		p->next = L->next;
		L->next = p;
	}

}


//creat the singly linked list on Tail insertion method
void CreatList_R(LinkList& L, int n) {
	
	int i = 0;

	//First, create a singly linked list with a head node
	//and create the tail pointer
	Lnode* r;
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;
	r = L;

	for (i = 0; i < n; ++i) {
		//creat the new node
		Lnode* p;
		p = (Lnode*)malloc(sizeof(Lnode));  
		
		//enter the data
		cin >> p->data.name;
		cin >> p->data.num;
		cin >> p->data.score;
		
		//insert the tail
		p->next = NULL;
		r->next = p;
		
		//new tail point
		r = p;
	}

}


//*******************2023/8/22 23:09*********************//
//creat the circular linked list--tail insertion method
void CreatList(LinkList& L) {

	int number = 0;
	
	L = (Lnode*)malloc(sizeof(Lnode));
	L->next = NULL;

	LinkList s = L;
	LinkList p;

	cout << "please enter inserting number:";
	cin >> number;


	for (int i = 0; i < number; i++) {
		cout << "please enter the (i+1)-th element---name->num->score" << endl;
		ElemType elem;
		cin >> elem.name >> elem.num >> elem.score ;
		p = new Lnode;
		p->data = elem;
		s->next = p;
		p->next = L->next;
		s = s->next;
	}
}



