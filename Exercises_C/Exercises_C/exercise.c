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

//int main()
//{
//	int age=0;
//	float yearsconde = 3.156E7;
//	float agesconde=0;
//	printf("���������䣺");
//	scanf("%d", &age);
//	agesconde = age * yearsconde;
//	printf("����%d��Ӧ�������ǣ�%f\n", age, agesconde);
//	printf("����%d��Ӧ�������ǣ�%e\n", age, agesconde);
//
//	return 0;
//}


//*******************2023/8/3 19:24*********************//

//int main()
//{
//	//int water=0;
//	//float H2O = 3.156E-23;
//	//float H2Osum = water * H2O;
//	//printf("������ˮ�Ŀ�������");
//	//scanf("%d", &water);
//	//printf("%d�Ŀ�����ˮ���е�ˮ����Ϊ��%a\n", water, H2Osum);
//
//	float quantity_mol = 3.0E-23;
//	float quantity_qt = 950;
//	float quarts;
//	float molecules;
//	printf("������ˮ�Ŀ�������");
//	scanf("%f", &quarts);
//	molecules = quarts * quantity_qt / quantity_mol;
//	printf("ˮ���ӵ�����Ϊ��%e", molecules);
//
//	return 0;
//}

//int main()
//{
//	float inch_to_cm=2.54;
//	float height_inch;
//	float height_cm;
//	printf("��������ߣ�(��λӢ��)");
//	scanf("%f", &height_inch);
//	height_cm = height_inch * inch_to_cm;
//	printf("���Ϊ��%f(����)", height_cm);
//	return 0;
//}


//int main()
//{
//	//����pint���������͵Ļ�����������5.5������ôpint�ͻ���ȥС��λ�����֣��Ӷ�������ô��ȷ
//	float cup;
//	float pint; //һƷ�ѵ�������
//	float ounce; //һ������8��˾
//	float tablespoon;//һ��˾������������
//	float teaspoon;  //һ�����׵���������
//	printf("һƷ�ѵ�������\n");
//	printf("һ������8��˾\n");
//	printf("һ��˾������������\n");
//	printf("һ�����׵���������\n");
//	printf("�����뱭����");
//	scanf("%f", &cup);
//	pint = cup / 2;
//	printf("%f�ȼ���%fƷ��\n", cup, pint);
//	ounce = cup * 8;
//	printf("%f�ȼ���%f��˾\n", cup, ounce);
//	tablespoon = ounce * 2;
//	printf("%f�ȼ���%f������\n", cup, tablespoon);
//	teaspoon = tablespoon * 3;
//	printf("%f�ȼ���%f����\n", cup, teaspoon);
//	return 0;
//}


//*******************2023/8/4 20:00*********************//

//int main()
//{
//	char name[20];
//	char surname[20];
//	printf("������������ֺ��գ�\n");
//	printf("������������֣�");
//	scanf("%s", &name);
//	printf("����������գ�");
//	scanf("%s", &surname);
//
//	printf("����%s;	�գ�%s\n", name, surname);
//
//	return 0;
//}

//int main1()
//{
//	char name[20];
//	char surname[20];
//
//	int fname_length = 0;
//	int lname_length = 0;
//	
//	printf("������������ֺ��գ�\n");
//	printf("������������֣�");
//	scanf("%s", &name);
//	printf("����������գ�");
//	scanf("%s", &surname);
//
//	//printf("��%s%s��\n", surname, name);
//	//printf("��********************%s%s��\n", surname, name);
//	//printf("��%s%s********************��\n", surname, name);
//	//printf("��****************%s%s��\n", surname, name);
//
//    fname_length = strlen(surname);
//    lname_length = strlen(name);
//    printf("\"%s%s\"\n", surname, name);  //ת������(\"),���ڴ�ӡ(")�ַ�
//    printf("\"%20s%20s\"\n", surname, name);
//    printf("\"%-20s%-20s\"\n", surname, name);
//    printf("%*s%*s", fname_length + 3, surname, lname_length + 3, name);
//
//	return 0;
//}


//*******************2023/8/7 18:48*********************//

//int main()
//{
//	float a = 21.3;
//
//	printf("The input is %3.1f or %2.1e\n", a, a);
//	printf("The input is %5.3f or %4.3e\n", a, a);
//
//
//	return 0;
//}
// 
//int main()
//{
//	float height;
//	char name[20];
//	printf("please input your name�� ");
//	scanf("%s", name);
//	printf("please input your height in inches�� ");
//	scanf("%f", &height);
//
//	printf("%s ,you are %.3f feet tall\n",name,height/12.0);
//
//	return 0;
//}

//int main()
//{
//	float downspeed;
//	float filesize;
//	printf("please input the loaddown speed in Mb/s : ");
//	scanf("%f", &downspeed);
//	printf("please input the file size in MB : ");
//	scanf("%f", &filesize);
//
//	printf(" At %.2f megabits per second,a file of %.2f megabytes\n",downspeed,filesize);
//	printf(" download in %.2f second\n",filesize*8.0/downspeed);
//	return 0;
//}

//int main1()
//{
//	char name[20];
//	char surname[20];
//	int length_name = 0;
//	int length_surname = 0;
//
//	printf("please input your name:");
//	scanf("%s", name);
//	printf("please input your surname:");
//	scanf("%s", surname);
//	length_name = strlen(name);
//	length_surname = strlen(surname);
//
//	printf("%s %s\n", name, surname);
//	printf("%*d %*d\n", length_name,length_name, length_surname,length_surname);
//	printf("%-*d %-*d\n", length_name,length_name, length_surname,length_surname);
//	printf("%d %*d\n", length_name, length_name, length_surname);
//	
//
//	return 0;
//}

//#include<float.h>
//int main()
//{
//	double d_value = 1.0 / 3.0;
//	float f_value = 1.0 / 3.0;
//	
//	printf("FLT_DIG:%d DBL_DIG:%d\n", FLT_DIG, DBL_DIG);
//
//	printf("display after point six: %.6f(double) %.6f(float)\n", d_value,f_value);
//	printf("display after point twelve: %.12f(double) %.12f(float)\n", d_value,f_value);
//	printf("display after point sixteen: %.16f(double) %.16f(float)\n", d_value,f_value);
//
//	return 0;
//}

//*******************2023/8/9 23:29*********************//

//int main()
//{
//	float miles;
//	float petrol;
//	float kilome;
//	float liter;
//	printf("please input travel miles in mile:");
//	scanf("%f", &miles);
//	printf("please input petrol in gallon:");
//	scanf("%f", &petrol);
//	printf("miles per gallon:%.1f\n", miles / petrol);
//	kilome = miles * 1.609;
//	liter = petrol * 3.785;
//
//	
//	printf("liter per hundred kilometers :%.1f\n", liter / kilome*100);
//
//	
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#define LITRE_PER_GALLON 3.785 //1���ش�Լ3.785��
#define KM_PER_MILE 1.609      //1Ӣ���ԼΪ1.609ǧ��
int main()
{
    float mileage;              //��������ǧ�ף�
    float gasoline;             //���ĵ�������������
    float mile_per_gallon;      //Ӣ��/����
    float litre_per_hundred_km; //��/100����
    printf("�������������ó�����ǧ�ף���");
    scanf("%f", &mileage);
    printf("�������������ĵ���������������");
    scanf("%f", &gasoline);
    mile_per_gallon = (mileage / KM_PER_MILE) / (gasoline / LITRE_PER_GALLON);
    litre_per_hundred_km = gasoline / mileage * 100;
    printf("����ÿ����������ʻ��Ӣ������%.1f\n", mile_per_gallon);
    printf("ÿ��ʻ100�������ĵ���������������%.1f", litre_per_hundred_km);
    return 0;
}









