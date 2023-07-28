#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	//第一
//	printf("Shen Yifu\n");
//	
//	//第二
//	printf("Shen\nYifu\n");
//
//	//第三
//	printf("Shen ");
//	printf("Yifu\n");
//
//
//	return 0;
//}


//int main()
//{
//	
//	printf("姓名：SHEN YIFU\n");
//	printf("地址：BENGBU CITY OF ANHUI PROVINCE\n");
//
//	return 0;
//}


int main()
{
	//获得一个年龄
	int age;
	int tianshu;
	printf("请输入年龄：");
	scanf("%d" , &age);
	//年龄转化天数
	tianshu = age * 365;
	
	//打印输出
	printf("年龄为：%d\n", age);
	printf("转化天数为：%d\n", tianshu);
	

	return 0;
}