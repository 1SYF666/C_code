#define _CRT_SECURE_NO_WARNINGS 1
#include"SqList.h"

Status InitList_Sq(SqList& L)
{
	L.elem =new ElemType[LIST_INIT_SIZE];
	if (!L.elem) return OVERFLOW;
	L.length = 0;
	return OK;
}

void DestroyList(SqList& L)
{
	if (L.elem)delete L.elem;
}

void ClearList(SqList& L)
{
	L.length = 0;
}

//get the length of linear list
int GetLength(SqList L)
{
	return (L.length);
}

//check if the linear list is empty
int IsEmpty(SqList L)
{

	if (L.length == 0)return 1;
	else return 0;
}


//access the elements of the sequential list
int GetElem(SqList L, int i, ElemType& e)
{
	if (i<1 || i>L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}

//search in the sequential list
int LocateElem(SqList L, ElemType e)
{
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e) return i + 1;
	}
	return 0;
}
//ASL-----average search length
//int LocateElem(SqList L, ElemType e)
//{
//	int i = 0;
//	while (i < L.length & L.elem[i] != e)i++;
//	
//	if (L.elem[i] == e) return i + 1;
//	
//	return 0;
//}


//insert in the sequential list
int InsertElem(SqList& L, int i, ElemType e)
{
	int j = 0;
	//is i legal?
	if (i<1 || i>L.length + 1)return ERROR;
	
	//is the current storage space full?
	if (L.length == LIST_INIT_SIZE)return ERROR;
	
	//insert operation 
	for (j = L.length - 1; j > i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[j] = e;
	
	L.length++;

	return OK;
}



//delete in the sequential list
Status ListDelete_Sq(SqList& L, int i)
{
	int j = 0;
	
	if (i<1 || i>L.length)return ERROR;
	
	for (j = i; j <= L.length-1; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}

	L.length--;

	return OK;

}

//*******************2023/8/29 13:20*********************//

//Merge of Linear Lists ----Unordered
void Union_list(SqList& La, SqList Lb) {
	
	int i = 0;
	int La_len = 0;
	int Lb_len = 0;
	La_len = GetLength(La);
	La_len = GetLength(Lb);
	ElemType e;
	
	for (i = 1; i <= Lb_len; i++) {
		GetElem(Lb, i, e);

		if (!(LocateElem(La, e)))
			InsertElem(La, ++La_len, e);
	}

}

//Merge of Linear Lists ---ordered
void MergeList_Sq(SqList LA, SqList LB, SqList& LC) {
	ElemType *pa;
	ElemType *pb;
	ElemType *pc;
	ElemType *pa_last;
	ElemType *pb_last;
	
	pa = LA.elem;
	pb = LB.elem;

	LC.length = LA.length + LB.length;
	//LC.elem = (ElemType*)malloc(sizeof(ElemType) * LC.length);
	LC.elem = new ElemType[LC.length];
	
	pc = LC.elem;
	pa_last = LA.elem + LA.length - 1;
	pb_last = LB.elem + LB.length - 1;

	while (pa<=pa_last&&pb<=pb_last){    //Both lists are non-empty

		if (*pa <= *pb)					//Select nodes with smaller values from both lists in sequence
			*pc++ = *pa++;
		else 
			*pc++ = *pb++;
	}

	while (pa<=pa_last){                //When the LB list has reached its end, add the remaining elements from LA to LC

		*pc++ = *pa++;
	
	}
	
	while (pb <= pb_last) {             //When the LA list has reached its end, add the remaining elements from LB to LC
	
		*pc++ = *pb++;
	
	}
}
