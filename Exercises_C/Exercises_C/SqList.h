#pragma once

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
//using namespace std;
//*******************2023/8/10 19:43*********************//

//¡¶data structures and algorithms¡·
// templates about SqList
/*#define LIST_INIT_SIZE 100
typedef struct
{
	ElemType elem[LIST_INIT_SIZE];
	int length

}SqList;
*/

//definition of sequential storage structure type  for polynomial
//#define MAXSIZE 100
//typedef struct
//{
//	float p;
//	int e;
//}Polynomial;
//
//typedef struct
//{
//	Polynomial* elem;
//	int length;
//}SqList;


//definition of sequential storage structure type  for bool catalog

//#define MAXSIZE 10000
//typedef struct
//{
//	char no[20];   //book ISBN
//	char name[50]; //book name
//	float price;   //book price
//}Book;
//
//typedef struct
//{
//	Book* elem;
//	int length;
//}SqList;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;

#define LIST_INIT_SIZE 100
typedef struct
{
	ElemType *elem;
	int length;

}SqList;

//intialize
Status InitList_Sq( SqList& L);

//destroy the linear list
void DestroyList( SqList& L);

//clear the linear list
void ClearList( SqList& L);

//get the length of linear list
int GetLength( SqList L);  //not need to change the SqList,so no use the & 

//check if the linear list is empty
int IsEmpty( SqList L);

//access the elements of the sequential list
int GetElem( SqList L, int i, ElemType& e);
 
//search in the sequential list
int LocateElem( SqList L, ElemType e);

//insert in the sequential list
int InsertElem(SqList& L, int i, ElemType e);

//delete in the sequential list
Status ListDelete_Sq(SqList& L, int i);



//*******************2023/8/29 13:20*********************//
//Merge of Linear Lists ---unordered
void Union_list(SqList& La,SqList Lb);

//Merge of Linear Lists ---ordered
void MergeList_Sq(SqList LA, SqList LB, SqList& LC);
