#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	//��һ
//	printf("Shen Yifu\n");
//	
//	//�ڶ�
//	printf("Shen\nYifu\n");
//
//	//����
//	printf("Shen ");
//	printf("Yifu\n");
//
//
//	return 0;
//}


//int main()
//{
//	
//	printf("������SHEN YIFU\n");
//	printf("��ַ��BENGBU CITY OF ANHUI PROVINCE\n");
//
//	return 0;
//}


int main()
{
	//���һ������
	int age;
	int tianshu;
	printf("���������䣺");
	scanf("%d" , &age);
	//����ת������
	tianshu = age * 365;
	
	//��ӡ���
	printf("����Ϊ��%d\n", age);
	printf("ת������Ϊ��%d\n", tianshu);
	

	return 0;
}