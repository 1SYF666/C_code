#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Bubble_Sort(int arr[], int sz)
{
	int j = 0;//趟数标志
	int i = 0;//每一趟比较标志
	for (j = 0;j<=sz-1; j++)
	{
		int flag = 1;//假设有序
		for (i = 1;i<=sz-j-1; i++)
		{
			int temp = 0;
			if (arr[j] > arr[j + i])
			{
				temp = arr[j];
				arr[j] = arr[j + i];
				arr[j + i] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

int main()
{
	int i = 0;
	int arr[] = { 6,8,4,9,5,7,1,2,3,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, sz);
	for (i = 0; i < 10;i++)
	{
		printf("%d,", arr[i]);
	}
	return 0;
}
