#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"function.h"

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


//int main()
//{
//	//���һ������
//	int age;
//	int tianshu;
//	printf("���������䣺");
//	scanf("%d" , &age);
//	//����ת������
//	tianshu = age * 365;
//	
//	//��ӡ���
//	printf("����Ϊ��%d\n", age);
//	printf("ת������Ϊ��%d\n", tianshu);
//	
//
//	return 0;
//}

//int main()
//{
//	jolly();
//	jolly();
//	jolly();
//	deny();
//	return 0;
//}

//int main()
//{
//	br();
//	ic();
//	printf("India,China\n");
//	printf("Brazil,Russia\n");
//	return 0;
//}

//int main()
//{
//	int toes = 10;
//	int doubletoes = toes * 2;
//	int squretoes = toes * toes;
//	printf("%d �������ǣ�%d��ƽ���ǣ�%d\n", toes, doubletoes, squretoes);
//
//	return 0;
//}

//int main()
//{
//	Smile();Smile();Smile();
//	printf("\n");
//	Smile(); Smile();
//	printf("\n");
//	Smile();
//	return 0;
//}


//*******************2023/7/31 19:12*********************//

//int main()
//{
//	printf("starting now:\n");
//	one_three();
//	printf("done\n");
//	return 0;
//}

//*******************2023/8/1 21:16*********************//
/*����ϵͳ��������intֵ*/
//int main()
//{
//	int i = 2147483647; 
//	unsigned int j = 4294967295; //2^32-1
//	float toobig = 3.4E38 * 100.0f;
//	float toosmall = (3.4E-38) / (100.0E100);
//	
//
//	printf("%d %d %d\n", i, i + 1, i + 2); //��������
//	printf("%u %u %u\n", j, j + 1, j + 2); //��������
//	printf("%e\n", toobig);//����������
//	printf("%e", toosmall);//����������
//
//	return 0;
//}


/*��ʾASCLL��ֵ��Ӧ���ַ�*/
//int main()
//{
//	int a;
//	printf("������һ��ASCLL��ֵ");
//	scanf("%d", &a);
//	printf("ASCLL��ֵ%d��Ӧ���ַ�Ϊ:%c\n", a, a);
//
//	return 0;
//}


//*******************2023/8/2 19:05*********************//
//int main()
//{
//	printf("\a");
//	printf("Startled by the sudden sound,Sally shouted,\n");
//	printf("��Startled by the sudden sound,Sally shouted��\n");
//	return 0;
//}

//int main()
//{
//	float i;
//	printf("Enter a floating-point value:");
//	scanf("%f", &i);
//	printf("fixed-point notation:%f\n", i);
//	printf("exponential notation:%e\n", i);
//	printf("p notation:%a\n", i);
//
//	return 0;
//}

int main()
{
	int age=0;
	float yearsconde = 3.156E7;
	float agesconde=0;
	printf("���������䣺");
	scanf("%d", &age);
	agesconde = age * yearsconde;
	printf("����%d��Ӧ�������ǣ�%f\n", age, agesconde);
	printf("����%d��Ӧ�������ǣ�%e\n", age, agesconde);

	return 0;
}