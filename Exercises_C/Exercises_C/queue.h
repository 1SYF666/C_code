#pragma once

//#include <stdio.h>
//#include <malloc.h>


//#define TRUE  1
//#define FALSE 0
//#define MAXSIZE 100
//
////typedef int ElemType;
//
//
//// ����ѭ�����нṹ��
//typedef struct Queue {
//
//	int* base;	// �����׵�ַ
//	int front;	// ����ͷ�±�
//	int rear;	// ����β�±�
//
//}Queue;



//
///********************* ѭ�����еĳ������ **************************/
//
//void     InitQueue();             	// ��ʼ��ѭ������
//int      QueueFull();               // ѭ����������
//int      QueueEmpty();              // ѭ�������п�
//int      QueueLength();             // ��ѭ�����г���(Ԫ�ظ���)
//int      EnQueue();                 // ѭ������ ���
//int      DeQueue();                 // ѭ������ ����
//
//void     QueueStatus();             // ��ӡ�������ӿա��ӳ�״̬
///****************************************************************/


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>
#include <iostream>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


#define MAXQSIZE 100

typedef int QElemType;
typedef int Status;

typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;


// the initial of queue
Status InitQueue(SqQueue& Q);

//get the length of queue
int QueueLength(SqQueue Q);

//push in the queue 
Status ENQueue(SqQueue& Q, QElemType e);

//pop in the queue 
Status DeQueue(SqQueue& Q, QElemType e);

//get the head element of queue
QElemType GetHead(SqQueue Q);