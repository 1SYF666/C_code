#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("***********************************************\n");
	printf("*******  1.add               2.del       ******\n");
	printf("*******  3.Search            4.modify    ******\n");
	printf("*******  5.show              6.sort      ******\n");
	printf("*******  0.exit              7.save      ******\n");
	printf("***********************************************\n");
}

int main()
{
	int input = 0;
	//创建通讯录
	//struct Contact con;//存放个人的信息和现有多少个人；里面包含1000个元素的数组和size
	struct Contact con;//con是通讯录，里面包含：data指针和size以及capacity
	//通讯录初试化
	InitContact(&con);//结构体传参最好能传地址，这样可以改变结构体内容
	do
	{
		//菜单
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			//销毁通讯录-释放动态开辟的内存
			SaveContact(&con);//退出先保存一下
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);

	return 0;
}

