#pragma once

#include<stdio.h>
#include<assert.h>
//*******************2023/7/30 21:31*********************//
void jolly();
void deny();

void br();
void ic();

void Smile();

//*******************2023/7/31 19:12*********************//
void one_three();
void two();


//*******************2023/8/15 19:12*********************//

void PrintCube(double input);

//*******************2023/8/17 23:15*********************//
void  Temperatures(const double Fahrenheit);

//*******************2023/8/26 11:14*********************//
void output_0826(float a, float b);


//*******************2023/9/10 17:02*********************//

int Menu_salary_0910();

//*******************2023/9/11 20:55*********************//

double Chose_salary(const int* x);

double Work_time();

void Salary_statistic(const double* x, const double* y);


//*******************2023/9/13 22:11*********************//
int Show_menu0913();

double Tax_line(const int* choice);

double Salary_input();

void Pay_tax(const double* salary, const double* tax_line);

//*******************2023/9/14 22:40*********************//
void Show_menu0914();



//*******************2023/9/21 20:19*********************//
//BF�㷨
int BF(char* S, char* t);

//KMP�㷨
int KMP(char* S, char* t, int pos);

//��ȡnext����
void GetNext(char* sub, int* next);



//*******************2023/9/22 17:05*********************//

//���scanf����û�гɹ���ȡ���룬�ͻὫ��������������С�
//�������ʵ�������ַ�����һ��ʵ���������ó�������ʹ��getchar()������ַ���
//��ȡ���롣

int get_int(void);

bool bad_Iimits(int begin, int end, int low, int high);

double sum_squares(int a, int b);


//*******************2023/10/03 10:07*********************//

int partition(int* arr, int left, int right);
void quickSort(int* arr, int left, int right);


//*******************2023/10/05 23:49*********************//
//#define N 3
//#define M 5
//
//void show_array(int n, int m, double x[N][M]);
//void copy_array(int n, int m, double a[N][M], double b[N][M]);