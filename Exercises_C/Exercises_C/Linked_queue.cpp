#define _CRT_SECURE_NO_WARNINGS 1
#include"Linked_queue.h"

//initial of linked queue
Status InitQueue(LinkQueue& Q) {

	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));

	if (!Q.front) exit(OVERFLOW);
	
	Q.front->next = NULL;
	
	return OK;
}

//destroy the queue
Status DestroyQueue(LinkQueue& Q) {

	QueuePtr p;
	while (Q.front)
	{
		p = Q.front->next;
		free(Q.front);
		Q.front = p;
	}
	
	//the second method 
	//Q.rear = Q.front->next;
	//free(Q.front);
	//Q.front = Q.rear;

	return OK;
}


//Enqueue elements
Status EnQueue(LinkQueue& Q, QElemType e) {

	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;

	return OK;
}


//Dequeue elements
Status DeQueue(LinkQueue& Q, QElemType& e) {

	QueuePtr p;
	if (Q.front == Q.rear)return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;

	if (Q.rear = p) Q.rear = Q.front;  // if delete the element is the elem of queue rear 
	delete(p);

	return OK;
}

//Get the head element
Status GetHeadQueue(LinkQueue& Q, QElemType& e) {

	if (Q.front == Q.rear) return ERROR;
	e = Q.front->next->data;
	return OK;

}
