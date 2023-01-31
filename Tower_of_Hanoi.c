#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


void Tower_of_Hanoi(int n,char a1,char a2,char a3)//从a1移动到a3
{
	int count = 0;
	if (n == 1)
	{
		printf("从塔%c移到塔%c\n", a1, a3);
	}
	else if (n == 2)
	{
		printf("从塔%c移动到塔%c\n",a1,a2);
		printf("从塔%c移动到塔%c\n",a1,a3);
		printf("从塔%c移动到塔%c\n",a2,a3);
	}
	else
	{
		Tower_of_Hanoi(n - 1,a1,a3,a2);
		Tower_of_Hanoi(1, a1, a2, a3);
		Tower_of_Hanoi(n - 1, a2, a1, a3);
	}

}


int main()
{
	int n = 0;
	char a1= 'A';
	char a2 = 'B';
	char a3 = 'C';
	printf("********汉诺塔游戏***********\n");
	printf("***将汉诺塔从塔A移动到塔C**\n");
	printf("请输入放在塔A的汉诺塔层数:>");
	scanf("%d", &n);
	Tower_of_Hanoi(n,a1,a2,a3);
	return 0;
}
