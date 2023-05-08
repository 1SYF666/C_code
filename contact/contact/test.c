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
	//����ͨѶ¼
	//struct Contact con;//��Ÿ��˵���Ϣ�����ж��ٸ��ˣ��������1000��Ԫ�ص������size
	struct Contact con;//con��ͨѶ¼�����������dataָ���size�Լ�capacity
	//ͨѶ¼���Ի�
	InitContact(&con);//�ṹ�崫������ܴ���ַ���������Ըı�ṹ������
	do
	{
		//�˵�
		menu();
		printf("��ѡ��>");
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
			//����ͨѶ¼-�ͷŶ�̬���ٵ��ڴ�
			SaveContact(&con);//�˳��ȱ���һ��
			DestoryContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);

	return 0;
}

