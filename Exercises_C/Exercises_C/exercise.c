#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"function.h"

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


//int main()
//{
//	//获得一个年龄
//	int age;
//	int tianshu;
//	printf("请输入年龄：");
//	scanf("%d" , &age);
//	//年龄转化天数
//	tianshu = age * 365;
//	
//	//打印输出
//	printf("年龄为：%d\n", age);
//	printf("转化天数为：%d\n", tianshu);
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
//	printf("%d 的两倍是：%d，平方是：%d\n", toes, doubletoes, squretoes);
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
/*超出系统允许的最大int值*/
//int main()
//{
//	int i = 2147483647; 
//	unsigned int j = 4294967295; //2^32-1
//	float toobig = 3.4E38 * 100.0f;
//	float toosmall = (3.4E-38) / (100.0E100);
//	
//
//	printf("%d %d %d\n", i, i + 1, i + 2); //整数上溢
//	printf("%u %u %u\n", j, j + 1, j + 2); //整数上溢
//	printf("%e\n", toobig);//浮点数上溢
//	printf("%e", toosmall);//浮点数下溢
//
//	return 0;
//}


/*显示ASCLL码值对应的字符*/
//int main()
//{
//	int a;
//	printf("请输入一个ASCLL码值");
//	scanf("%d", &a);
//	printf("ASCLL码值%d对应的字符为:%c\n", a, a);
//
//	return 0;
//}


//*******************2023/8/2 19:05*********************//
//int main()
//{
//	printf("\a");
//	printf("Startled by the sudden sound,Sally shouted,\n");
//	printf("“Startled by the sudden sound,Sally shouted”\n");
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
//	printf("请输入年龄：");
//	scanf("%d", &age);
//	agesconde = age * yearsconde;
//	printf("年龄%d对应的秒数是：%f\n", age, agesconde);
//	printf("年龄%d对应的秒数是：%e\n", age, agesconde);
//
//	return 0;
//}


//*******************2023/8/3 19:24*********************//

//int main()
//{
//	//int water=0;
//	//float H2O = 3.156E-23;
//	//float H2Osum = water * H2O;
//	//printf("请输入水的夸脱数：");
//	//scanf("%d", &water);
//	//printf("%d的夸脱数水含有的水分子为：%a\n", water, H2Osum);
//
//	float quantity_mol = 3.0E-23;
//	float quantity_qt = 950;
//	float quarts;
//	float molecules;
//	printf("请输入水的跨脱数：");
//	scanf("%f", &quarts);
//	molecules = quarts * quantity_qt / quantity_mol;
//	printf("水分子的数量为：%e", molecules);
//
//	return 0;
//}

//int main()
//{
//	float inch_to_cm=2.54;
//	float height_inch;
//	float height_cm;
//	printf("请输入身高：(单位英寸)");
//	scanf("%f", &height_inch);
//	height_cm = height_inch * inch_to_cm;
//	printf("身高为：%f(厘米)", height_cm);
//	return 0;
//}


//int main()
//{
//	//加入pint用整数类型的话，若杯数是5.5杯，那么pint就会舍去小数位的数字，从而不会那么精确
//	float cup;
//	float pint; //一品脱等于两杯
//	float ounce; //一杯等于8盎司
//	float tablespoon;//一盎司等于两大汤勺
//	float teaspoon;  //一大汤勺等于三茶勺
//	printf("一品脱等于两杯\n");
//	printf("一杯等于8盎司\n");
//	printf("一盎司等于两大汤勺\n");
//	printf("一大汤勺等于三茶勺\n");
//	printf("请输入杯数：");
//	scanf("%f", &cup);
//	pint = cup / 2;
//	printf("%f等价于%f品脱\n", cup, pint);
//	ounce = cup * 8;
//	printf("%f等价于%f盎司\n", cup, ounce);
//	tablespoon = ounce * 2;
//	printf("%f等价于%f大汤勺\n", cup, tablespoon);
//	teaspoon = tablespoon * 3;
//	printf("%f等价于%f茶勺\n", cup, teaspoon);
//	return 0;
//}


//*******************2023/8/4 20:00*********************//

//int main()
//{
//	char name[20];
//	char surname[20];
//	printf("请输入你的名字和姓：\n");
//	printf("请输入你的名字：");
//	scanf("%s", &name);
//	printf("请输入你的姓：");
//	scanf("%s", &surname);
//
//	printf("名：%s;	姓：%s\n", name, surname);
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
//	printf("请输入你的名字和姓：\n");
//	printf("请输入你的名字：");
//	scanf("%s", &name);
//	printf("请输入你的姓：");
//	scanf("%s", &surname);
//
//	//printf("“%s%s”\n", surname, name);
//	//printf("“********************%s%s”\n", surname, name);
//	//printf("“%s%s********************”\n", surname, name);
//	//printf("“****************%s%s”\n", surname, name);
//
//    fname_length = strlen(surname);
//    lname_length = strlen(name);
//    printf("\"%s%s\"\n", surname, name);  //转义序列(\"),用于打印(")字符
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
//	printf("please input your name： ");
//	scanf("%s", name);
//	printf("please input your height in inches： ");
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

//#include <stdio.h>
//#include <stdlib.h>
//#define LITRE_PER_GALLON 3.785 //1加仑大约3.785升
//#define KM_PER_MILE 1.609      //1英里大约为1.609千米
//int main()
//{
//    float mileage;              //历程数（千米）
//    float gasoline;             //消耗的汽油量（升）
//    float mile_per_gallon;      //英里/加仑
//    float litre_per_hundred_km; //升/100公里
//    printf("请输入旅行总旅程数（千米）：");
//    scanf("%f", &mileage);
//    printf("请输入旅行消耗的汽油量（升）：");
//    scanf("%f", &gasoline);
//    mile_per_gallon = (mileage / KM_PER_MILE) / (gasoline / LITRE_PER_GALLON);
//    litre_per_hundred_km = gasoline / mileage * 100;
//    printf("消耗每加仑汽油行驶的英里数：%.1f\n", mile_per_gallon);
//    printf("每行驶100公里消耗的汽油数（升）：%.1f", litre_per_hundred_km);
//    return 0;
//}

//#include"SqList.h"
//#include<stdlib.h>
//int main()
//{
//	SqList L;
//	L.elem = (Book*)malloc(sizeof(Book) * MAXSIZE);
//
//	int* p1 = new int;
//
//	return 0;
//}

//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define MINUTES_PER_HOUR 60
//
//int main()
//{
//	int minute;
//	int time_h;
//	int time_m;
//
//	while (1)
//	{
//		printf("Please enter a number for minute (<= 0 to quit):");
//		scanf("%d", &minute);
//		if (minute <= 0)
//		{
//			break; //quit the programmer
//		}
//		time_h = minute / MINUTES_PER_HOUR;
//		time_m = minute % MINUTES_PER_HOUR;
//		printf("minute:%d equivalent hour:%d and minute:%d\n", minute, time_h, time_m);
//		printf("You can enter again (<= 0 to quit):\n");
//	}
//	printf("Done.\n");
//
//	return 0;
//}


//#include <stdio.h>
//#define MINUTES_PER_HOUR 60
//
//int main(void)
//{
//	int m = 0, hour, minutes;
//
//	printf("Please enter a number for minute (<= 0 to quit): ");
//	while ((scanf("%d", &m) == 1) && (m > 0))
//	{
//		hour = m / MINUTES_PER_HOUR;
//		minutes = m % MINUTES_PER_HOUR;
//		printf("%d minutes = %d hours and %d minutes.\n", m, hour, minutes);
//		printf("You can enter again (<= 0 to quit): ");
//	}
//	printf("Done.\n");
//
//	return 0;
//}


//int main()
//{
//	int input = 0;
//	int i = 0;
//	printf("please input the integer:");
//	scanf("%d", &input);
//	printf("display:\n");
//	for (i = input; i <= input + 10; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//	printf("Done.\n");
//	return 0;
//}

//#define DAYS_PER_WEEK  7

//int main()
//{
//	int day_num;
//	int day_total;
//	int week_num;
//	printf("please input the day(<=0 to quit):");
//	while (1)
//	{
//		scanf("%d", &day_total);
//		if (day_total > 0)
//		{
//			week_num = day_total / DAYS_PER_WEEK;
//			day_num = day_total % DAYS_PER_WEEK;
//			printf("%d days are %d weeks, %d days\n", day_total, week_num, day_num);
//			printf("You can enter again (<=0 to quit): ");
//		}
//		else
//		{
//			printf("input error!exit!\n");
//			break;
//		}
//	}
//
//	return  0;
//}


//#define FEET_TO_INCH  12
//#define INCH_TO_cm  2.54
//
//int main()
//{
//	float centimeters =0.0;
//	float inches =0.0;
//	float inches_total =0.0;
//	int feet = 0;
//
//	while (1)
//	{
//		printf("Enter a height in centimeters(<=0 to quit): ");
//		scanf("%f", &centimeters);
//		if (centimeters <= 0)
//		{
//			printf("bye\n");
//			break;
//		}
//	    inches_total = centimeters /  INCH_TO_cm;
//		feet = inches_total / FEET_TO_INCH;
//		inches = inches_total - feet * FEET_TO_INCH;
//		printf("%.1f cm = %d feet, %.1f inches\n", centimeters, feet, inches);
//	}
//
//	return 0;
//}



//int main()
//{
//	float a=10;
//	float b=3;
//	//int b=3;
//	float c=0;
//	int d = 0;
//	int e = 0;
//	c = a / b;  //3.333
//	d = a / b;  //3
//	e = (int)a / b;  //3
//
//
//
//	return 0;
//}





