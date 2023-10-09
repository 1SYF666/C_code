#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
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

//*******************2023/8/15 22:11*********************//


//int main()
//{
//	int input = 0;
//	int count = 1;
//	int sum_money = 0;
//	printf("enter the day nums:");
//	scanf("%d", &input);
//	while (count<=input)
//	{
//		sum_money = sum_money + count;
//		count++;
//	}
//	printf("%d days earned the money:%d $\n", input, sum_money);
//
//	return 0;
//}

//int main(void)
//{
//	int count;
//	int sum = 0;
//	int n = 0;
//	printf("Enter the integer number : ");
//	scanf("%d", &count);
//	n = count;
//	while (count > 0)
//	{
//		sum += count * count;
//		count--;
//	}
//	printf("the integer number %d squre sum is %d \n", count,sum);
//
//	return 0;
//}

//
//int main()
//{
//	double input;
//	printf("please enter the number in double type: ");
//	scanf("%lf", &input);
//    PrintCube(input);
//
//	return 0;
//}



//#include <stdio.h>
//
//void cube(double c);
//
//int main(void)
//{
//    double n;
//
//    printf("Please you enter a double number: ");
//    scanf("%lf", &n);
//    cube(n);
//
//    return 0;
//}
//
//void cube(double c)
//{
//    printf("The cube of %g is %g.\n", c, c * c * c);
//}

//*******************2023/8/17 14:43*********************//


//int main()
//{
//	int input2 = 0;
//	int input1 = 0;
//	
//	printf("Enter an integer to serve as the second operand:");
//	scanf("%d", &input2);
//	printf("Now enter the first operand:");
//
//	while ((scanf("%d", &input1)==1)&(input1>0))
//	{
//		printf("%d %% %d is %d\n", input1, input2, input1%input2);
//		printf("Enter next number for first operand(<= 0 to quit):");
//
//	}
//	printf("Done\n");
//	return 0;
//}


//
//int main()
//{
//	double Fahrenheit;
//	while (true)
//	{
//		int input = 0;
//		printf("enter the Fahrenheit:");
//		input=scanf("%lf", &Fahrenheit);
//		if (input == 1)
//		{
//			Temperatures(Fahrenheit);
//		}
//		else
//		{
//			break;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	double Fahrenheit;
//	printf("please enter the Fahrenheit number(q to quit):");
//	
//	while (scanf("%lf", &Fahrenheit) == 1)
//	{
//		Temperatures(Fahrenheit);
//		printf("You can enter again (q to quit):");
//	}
//	printf("Done.\n");
//
//	return 0;
//}


//*******************2023/8/19 8:48*********************//
//int main() {
//	int i = 0;
//	char arr[7] = { 'a','b','c','d','e','f','g' };
//	for (i = 0; i < 7; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//
//	return 0;
//}


//int main() {
//	int i = 0;
//	char arr[26];
//	
//	for (i = 0; i < 26; i++){
//		arr[i] = 'a' + i;
//	}
//
//	printf("Here are 26 letters:\n");
//
//	for (i = 0; i < 26; i++){
//		printf("%c ", arr[i]);
//	}
//
//	return 0;
//}


//int main() {
//
//	int i = 0;
//	int j = 0;
//	//row
//	for (i = 0; i < 5; i++) {
//		//column
//		for (j = 0; j <= i; j++) {
//			printf("&");
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}


//int main() {
//
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < 6; i++) {
//
//		for (j = 0; j <= i; j++) {
//			printf("%c", 'F' - j);
//		}
//
//		printf("\n");
//	}
//
//	return 0;
//}


//int main() {
//
//	int i = 0;
//	int j = 0;
//	
//	for (i = 0; i < 6; i++) {
//
//		for (j = 0; j <= i; j++) {
//
//			printf("%c", 'A'+ i*(i+1)/2 +j);
//		}
//		
//		printf("\n");
//	}
//
//	return 0;
//}

//int main() {
//
//	char ch = 'A';
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 6; i++) {
//		
//		for (j = 1; j <= i; j++) {
//			printf("%c", ch++);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//int main() {
//
//	printf("hello!\007\n");
//	return 0;
//}


//*******************2023/8/22 19:19*********************//


//int main() {
//	char input;
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int z = 0;
//
//	printf("Enter the char character (A-Z):");
//	scanf("%c", &input);
//
//	for (i = 0; i <= (input - 'A'); i++) {
//
//		//handle spaces
//		for (j = 0; j < (input - 'A')-i; j++) {
//
//			printf(" ");
//		}
//
//		//print in ascending order
//		for (k = 0; k <= i; k++) {
//			printf("%c", 'A' + k);
//		}
//		
//		//print in descending order
//		for (z = 1; z <= i; z++) {
//			printf("%c", ('A'+i) - z);
//		}
//
//		printf("\n");
//	}
//
//
//	return 0;
//}


//nice
//int main() {
//
//	char ch;
//
//	printf("Please enter a upper letter:");
//	scanf("%c", &ch);
//
//	int length = ch - 'A';
//	printf("The pyramid of %c is :\n", ch);
//
//	for (int i = 0; i <= length; i++) {
//
//		char t = 'A' - 1;
//		
//		for (int j = 0; j < length - i; j++) {
//			printf(" ");
//		}
//
//		for (int j = 0; j <= i; j++) {
//			printf("%c", ++t);
//		}
//
//		for (int j = 0; j < i; j++) {
//			printf("%c", --t);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//*******************2023/8/23 22:15*********************//
//int main() {
//
//	int upper = 0;
//	int lower = 0;
//	printf("Enter the form the upper limits:");
//	scanf("%d", &upper);
//	printf("Enter the form the lower limits:");
//	scanf("%d", &lower);
//
//	printf("%s\t%s\t%s\t\n", "number", "square", "cube");
//	for (int i = lower; i <= upper; i++) {
//
//		printf("%d\t%d\t%d\t\n", i, i * i, i * i * i);
//	}
//	printf("Done.\n");
//	
//	return 0;
//}


//*******************2023/8/23 17:29*********************//

//int main() {
//
//	int i = 0;
//	int length = 0;
//	char in_arr[20] = { 0 };
//	char out_arr[20] = { 0 };
//	printf("please enter the words:");
//	scanf("%s", in_arr);
//	length = strlen(in_arr);
//	for (i = 0; i < length; i++) {
//		out_arr[i] = in_arr[i];
//	}
//	printf("reverse printing:");
//	for (i = length-1; i >=0; i--) {
//		printf("%c", out_arr[i]);
//	}
//
//	return 0;
//}




//#include<stdio.h>
//#include<string.h>
//#define LEN 20
//
//int main() {
//	char str[LEN];
//
//	printf("Please enter a word:");
//	scanf("%19s", str);
//	printf("the word is:\n");
//	printf("%s\n", str);
//
//	printf("Reversing the word is: \n");
//	for (int i = strlen(str) - 1; i >= 0; i--) {
//
//		printf("%c", str[i]);
//	}
//
//	return 0;
//}

//*******************2023/8/26 17:29*********************//

//int main() {
//	float input1;
//	float input2;
//	float output;
//
//	printf("Enter two number(no float type to quit)\n");
//	
//	while (scanf("%f",&input1)&& scanf("%f", &input2)){
//
//		output = (input1 - input2) / input1 * input2;
//		
//		printf("%f\n", output);
//
//		printf("Enter the number again(no float to quit)\n");
//	
//	}
//
//	return 0;
//}

//int main() {
//
//	double a, b;
//
//	printf("Please enter two numbers(q to quit)：");
//	
//	while (scanf("%lf %lf", &a, &b) == 2) {
//		
//		//%g reprsents automatically selecting the appropriate notion for output 
//		output_0826(a, b);
//	}
//
//	return 0;
//}


//
//int main() {
//
//	int i = 0;
//	
//	int input1 = 0;
//	int input2 = 0;
//	printf("Enter lower and upper integer limits:");
//	
//	while (scanf("%d %d", &input1, &input2)==2&&input1<input2)
//	{
//		int sum = 0;
//		for (i = input1; i <= input2; i++) {
//
//			sum += i * i;
//		}
//		printf("The sums of the squares");
//		printf("from % d to % d is % d\n", input1*input1, input2*input2, sum);
//		printf("Enter next set of limits:");
//	}
//	printf("Done\n");
//	return 0;
//}



//*******************2023/8/29 19:33*********************//

//int main() {
//
//	int arr[8] = { 0 };
//	int i = 0;
//	printf("Enter the number:\n");
//	
//	for (i = 0; i < 8; i++) {
//
//		scanf("%d", &arr[i]);
//
//	}
//	printf("back print:\n");
//
//	for (i = 7; i >=0; i--) {
//
//		printf("%d ", arr[i]);
//	
//	}
//	return 0;
//}



//int main() {
//
//	float i = 0;
//	float times = 0;
//	float sum1=0;
//	float sum2=0;
//	float coefficients = -1;
//	printf("Please enter the times (<0 to quit) :");
//	while (scanf("%f", &times)==1&&times>0){
//		sum1 = 0;
//		sum2 = 0;
//		for (i = 1; i <= times; i++) {
//			coefficients = coefficients * (-1);
//			sum1 = sum1+1.0 / i;
//			sum2 = sum2+1.0 / i * coefficients;
//		}
//		printf("sum1+sum2=%f:\n", sum1 + sum2);
//		printf("Please enter again (<0 to quit) :");
//	}
//	return 0;
//}

//
//int main() {
//	int n = 0;
//
//	printf("Please enter a number (<=0 to quit):");
//
//	while ((scanf("%d", &n) == 1) && (n > 0)) {
//		int i = 1;
//		int flag = 1;
//		double res1 = 0.0;
//		double res2 = 0.0;
//
//		for (i = 1,flag = 1; i <= n; i++, flag *= -1) {
//			res1 += 1.0 / i;
//			res2 += (1.0 / i) * flag;
//		}
//
//		printf("1.0+ 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...");
//		printf("sum are %g\n", res1);
//		printf("1.0- 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...");
//		printf("sum are %g\n", res2);
//
//		printf("The sum of the first %d items of the two sequences is %g\n", n, res1 + res2);
//		
//		printf("\nYou can enter again (<=0 to quit): ");
//	}
//	printf("Done.\n");
//
//
//	return 0;
//}

//#include"stack.h"
//
//int main(){
//	struct SqStack S;
//	InitStack(S);
//
//	//S.base = NULL;
//	//S.top = NULL;
//	//S.stacksize = 0;
//
//	conversion(S);
//	
//	return 0;
//}


//*******************2023/8/30 19:22*********************//

//int main() {
//	int i = 0;
//	int arr[8] = { 0 };
//	int val = 2;
//	for (i = 0; i < 8; i++) {
//		arr[i] = val;
//		val *= 2;
//	}
//	i = 0;
//	printf("Here are the results for array:\n");
//	do
//	{
//		printf("%d ", arr[i++]);
//	} while (i<8);
//	printf("\nDnoe.\n");
//
//	return 0;
//}


//int main(){
//	
//	double arr1[8] = { 0 };
//	double arr2[8] = { 0 };
//	int i = 0;
//	printf("Please enter the number:\n");
//	while (i<8){
//		scanf("%lf", &arr1[i++]);
//	}
//	double sum = 0;
//	for (i = 0; i < 8; i++) {
//		sum += arr1[i];
//		arr2[i]=sum;
//	}
//
//	for (i = 0; i < 8; i++) {
//		printf("%lf		", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 8; i++) {
//		printf("%lf		", arr2[i]);
//	}
//	printf("\nDone.\n");
//	return 0;
//}

//#define N 8
//
//int main() {
//	int i = 0;
//	double a[N];
//	double b[N];
//
//	printf("Please enter %d numbers:\n", N);
//	for (i = 0; i < N; i++) {
//		scanf("%lf", &a[i]);
//	}
//
//	b[0] = a[0];
//	for (i = 1; i < N; i++) {
//		b[i] = a[i] + b[i - 1];
//	}
//
//	printf("Here are the results for array a:\n");
//	for (i = 0; i < N; i++) {
//		printf("%-3g", a[i]);
//	}
//	printf("\nHere are the results for array b:\n");
//	for (i = 0; i < N; i++) {
//		printf("%-3g", b[i]);
//	}
//	printf("\nDone.\n");
//	return 0;
//}

//#define LEN 255
//int main() {
//
//	int i = 0;
//
//	char arr[LEN] = { 0 };
//	printf("please enter a string :\n");
//	while (scanf("%c",&arr[i])&&arr[i]!='\n'&&i+1<255){
//		i++;
//	}
//
//	printf("Reversing print the string is :\n");
//	for (i--; i >= 0; i--) {
//
//		printf("%c", arr[i]);
//	}
//	printf("\nDone\n");
//	return 0;
//}


//#include"queue.h"
//
//int main()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//
//	printf("%d\n", QueueFront(&q)); //1
//	QueuePop(&q);//出队列
//	printf("%d\n", QueueFront(&q));//2   此时队首为2
//
//	printf("%d\n", QueueBack(&q));//4  队尾为4
//
//	return 0;
//}



//*******************2023/9/03 19:52*********************//

//#define COST 100.0
//#define DAP_INTERST_RATE 0.1
//#define DEI_INTERST_RATE 0.05
//
//int main() {
//	
//	float balance_Daphne = COST;
//	float balance_Deirdre = COST;
//	int year = 0;
//	
//
//	for (year = 1; balance_Deirdre <= balance_Daphne; year++) {
//		balance_Daphne += COST * DAP_INTERST_RATE;
//		balance_Deirdre *= (1.0 + DEI_INTERST_RATE);
//	}
//	//printf("Deirdre balance over Daphne in the %d-th year\n",--year);
//	//printf("Deirdre balance :%d		Daphne balance:%d\n",balance_Deirdre,balance_Daphne);
//	printf("Investment values after %d years:\n", --year);
//	printf("Daphne: $%.2f\n", balance_Daphne);
//	printf("Deirdre: $%.2f\n", balance_Deirdre);
//	printf("Deirdre(invest) > Daphne(invest)\n");
//
//	return 0;
//}


//int main(void)
//{
//    int years = 0;
//    double daphne = 100.0, deirdre = 100.0;
//
//    while (deirdre <= daphne)
//    {
//        daphne += 0.10 * 100.0;
//        deirdre += 0.05 * deirdre;
//        ++years;
//    }
//    printf("Investment values after %d years:\n", years);
//    printf("Daphne: $%.2f\n", daphne);
//    printf("Deirdre: $%.2f\n", deirdre);
//    printf("Deirdre(invest) > Daphne(invest)\n");
//
//    return 0;
//}

//#define COST 100.0 
//#define INTERST_RATE 0.08 
//#define TAKE_MONEY 10.0 
//
//int main() {
//	int years = 0;
//	float balance = COST;
//	for (years = 1; balance > 9; years++) {
//		balance *= (1.0 + INTERST_RATE); 
//		balance -= TAKE_MONEY;         //balance after take off the 100000$
//		printf("After %d years remains $%g.\n", years, balance);
//	}
//
//	printf("take over the moeny after %d years:\n", years);
//
//
//	return 0;
//}


//int main(void)
//{
//    int years = 0;
//    double chuckie = 100.0;
//
//    while (chuckie > 9)
//    {
//        ++years, chuckie += chuckie * 0.08, chuckie -= 10;
//        printf("After %d years remains $%g.\n", years, chuckie);
//    }
//    printf("After %d years:\n", years + 1);
//    printf("Chuckie has taken all of the money!\n");
//
//    return 0;
//}

//
//#define DUNBAR_NUMBER 150
//
//int main() {
//
//	int i = 0;
//	int total_friends = 5;
//
//	for (i = 1; total_friends < DUNBAR_NUMBER;i++) {
//
//		total_friends = (total_friends - i) * 2;
//	}
//	printf("After %d weeks:\n", --i);
//    printf("total_friends has taken all of the 150!\n");
//
//	return 0;
//}


//int main(void)
//{
//    int i = 1;
//    int friends = 5;
//
//    while (friends < 150)
//    {
//        printf("At %d weeks, Rabnud has", i);
//        friends = 2 * (friends - i++);
//        printf("%4d friends.\n", friends);
//    }
//    printf("At %d weeks, over Dunbar's number(150).\n", --i);
//
//    return 0;
//}



//*******************2023/9/05 18:59*********************//


//int main1() {
//
//	int i = 0;
//	int count1 = 0;
//	int count2 = 0;
//	int count3 = 0;
//	char arr[] = { 0 };
//	while (scanf("%c",&arr[i])&&arr[i]!='#')
//	{
//		if (arr[i] == ' ') count1++;
//		if (arr[i] == '\n') count2++;
//		i++;
//	}
//	count3 = i - count1 - count2-1;
//
//	printf("space is %d, next cha is %d,others is %d\n", count1, count2, count3);
//
//	return 0;
//}
//
//
//#define STOP '#'
//
//
//int main()
//{
//	int ch, space, enter, others;
//	space = enter = others = 0;
//	printf("Please enter some character (# to quit):\n");
//
//	while ((ch=getchar())!=STOP)
//	{
//		(ch == ' ' ? ++space : (ch == '\n' ? ++ enter : ++others));
//	}
//
//	printf("Here are the contents\n");
//	printf("Space:%d\n", space);
//	printf("Linefeed:%d\n", enter);
//	printf("Others:%d\n", others);
//
//
//	return 0;
//}




//*******************2023/9/08 8:31*********************//

//#define STOP '#' 
//
//int main() {
//
//	int ch = 0;
//	int i = 0;
//	int count = 0;
//	char buffer[30];
//	
//	printf("Please enter some character (# to quit):\n");
//	
//	for (i = 0; (ch = getchar()) != STOP; i++) {
//			
//		buffer[i] = (char)ch;
//
//	}
//
//	count = i;  //record the total numbers in buffer;
//	printf("Here are the characters :\n");
//	
//	for (i = 0; i < count; i++) {
//		
//		printf("%c ", buffer[i]);
//		
//		if ((i % 8)==7) printf("\n");
//	}
//	printf("\n");
//	printf("Here are the characters corresponding ASCII:\n");
//
//	for (i = 0; i < count; i++) {
//
//		printf("the character is %c  --  ASCLL is %d\n", buffer[i], (int)buffer[i]);
//	
//	}
//	return 0;
//}

//#define STOP '#'
//
//int main1() {
//
//	int ch;
//	int i = 0;
//
//	printf("Enter some characters('#' to quit):\n");
//
//	while ((ch=getchar())!=STOP){
//
//		if (i++ % 8 == 0){
//			putchar('\n');
//		}
//		if (ch == '\n') {
//			printf("'\\n'-%3d", ch);
//		}
//		else if (ch == '\t') {
//			printf("'\\t'-%3d", ch);
//		}
//		else{
//			printf("'%c'-%3d", ch);
//		}
//	}
//	printf("Done.\n");
//
//	return 0;
//}


//int main() {
//	int ch;
//	ch = getchar();
//	putchar(ch);
//	return 0;
//}

//#include<stdio.h>
//#define SPACE ' '
//int main() {
//
//	char ch;
//	ch = getchar();
//	while (ch!='\n'){
//
//		if (ch == SPACE)
//			putchar(ch);
//		else
//			putchar(ch + 1);
//		ch = getchar();
//	}
//	putchar(ch);
//
//	return 0;
//}

//int main() {
//
//	int i = 0;
//	int evens = 0;
//	int sum_even = 0;
//	int odds = 0;
//	int sum_odd = 0;
//
//	int buffer[30];
//
//	printf("Please enter the integer( 0 to quit):\n");
//	
//	while (scanf("%d",&buffer[i])&&buffer[i]!=0){
//		
//		if (!(buffer[i] % 2)){
//
//			sum_even += buffer[i];
//			evens++;
//		}
//		else{
//			sum_odd += buffer[i];
//			odds++;
//		}
//		i++;
//	}
//
//	printf("the even numbers is %d,the average evens is %f\n", evens, ((float)sum_even / evens));
//	printf("the odd numbers is %d,the average odds is %f\n", odds, ((float)sum_odd / odds));
//
//	return 0;
//}



//int main(void)
//{
//    int n, odd = 0, even = 0;
//    int e_sum = 0, o_sum = 0;
//
//    printf("Please enter a integer (0 to quit): ");
//    while (scanf("%d", &n) == 1 && n)
//    {
//        (n % 2 ? (++odd, o_sum += n) : (++even, e_sum += n));
//        printf("You can enter again (0 to quit): ");
//    }
//    printf("Even number: %d\n", even);
//    if (even > 0)
//    {
//        printf("The average of even: %g\n", (float)e_sum / even);
//    }
//    printf("Odd number: %d\n", odd);
//    if (odd > 0)
//    {
//        printf("The average of odd: %g\n", (float)o_sum / odd);
//    }
//    printf("Done.\n");
//
//    return 0;
//}


//*******************2023/9/09 21:34*********************//

//int main1() {
//
//	int ch;
//	int n = 0;
//	printf("Enter some character('#' to quit):\n");
//	while ((ch = getchar())!='#'){
//
//		if (ch == '.') {
//			putchar('!');
//			n++;
//		}
//		else if (ch == '!') {
//			printf("!!");
//			n++;
//		}
//		else{
//			putchar(ch);
//
//		}
//
//	}
//
//	printf("\nTotal replaced %d times.\n", n);
//	printf("('.'->'!')or('!'->'!!').\n");
//
//	return 0;
//}
//
//int main2() {
//
//	int ch;
//	int n = 0;
//	printf("Enter some character('#' to quit):\n");
//	while ((ch=getchar())!='#'){
//		
//		switch (ch){
//
//			case '.':{
//
//				putchar('!');
//				n++;
//				break; 
//			}
//			case '!':{
//
//				printf("!!");
//				n++;
//				break;
//			}
//			default:{
//
//				putchar(ch);
//				break;
//			}
//		}
//
//	}
//
//	printf("\nTotal replaced %d times.\n", n);
//	printf("('.'->'!')or('!'->'!!').\n");
//
//	return 0;
//}
//
//int main3() {
//
//	int ch;
//	int n = 0;
//	while ((ch=getchar())!='#')	{
//
//	
//		if (ch=='e'){
//			putchar(ch);
//			if (ch == 'i')
//			{
//				putchar(ch);
//				n++;
//			}
//				
//		}
//		else{
//			putchar(ch);
//		}
//		
//		
//	}
//	printf("\nTotal 'ei' is %d times.\n", n);
//
//	return 0;
//}
//
//int main() {
//
//	int cur, pre = '#', n = 0;
//	printf("Enter some characters('#' to quit):\n");
//	while ((cur=getchar())!='#')
//	{
//		if (pre == 'e' && cur == 'i')++n;
//		pre = cur;
//	}
//
//	printf("\nTotal 'ei' is %d times.\n", n);
//
//	return 0;
//}


//*******************2023/9/10 21:34*********************//
//
//#define BASIC_SALARY 10.00  //1000$ per hour
//#define OVERTIME 1.5    //multiple
//#define BASEWORKTIME 40
//#define TXA_RATE_300 0.15
//#define TXA_RATE_450 0.20
//#define TXA_RATE_LATER 0.25
//
//int main1() {
//
//	float work_times=0;
//	float total_basesalary=0;
//	float total_overtime_salary=0;
//	float total_salary=0;
//	float tax=0;
//	float net_income =0;
//
//	printf("Please enter the working hours a week:\n");
//	scanf("%f", &work_times);
//
//	//base salary
//	if (work_times <= BASEWORKTIME) {
//		
//		total_basesalary = work_times * BASIC_SALARY;
//		total_overtime_salary = 0;
//		total_salary = total_basesalary + total_overtime_salary;
//	}
//	//overtime salary
//	else {
//		total_basesalary = BASEWORKTIME * BASIC_SALARY;
//		total_overtime_salary = (work_times - BASEWORKTIME) * OVERTIME * BASIC_SALARY;
//		total_salary = total_basesalary + total_overtime_salary;
//	}
//
//	//pay taxes
//	if (total_salary <= 300) {
//		tax = total_basesalary* TXA_RATE_300;
//	}
//	else if(total_salary>300&&total_salary<=450){
//		tax = 300 * TXA_RATE_300 + (total_basesalary - 300) * TXA_RATE_450;
//	}
//	else{
//
//		tax = 300 * TXA_RATE_300 + 150 * TXA_RATE_450 + (total_salary - 450) * TXA_RATE_LATER;
//	}
//
//	//net income
//	net_income = total_salary - tax;
//
//	printf("the total salary :%.2f\n", total_salary);
//	printf("the pay tax :%.2f\n", tax);
//	printf("the net income :%.2f\n", net_income);
//
//
//	return 0;
//}


//*******************2023/9/11 20:37*********************//

//int main() {
//
//	int choice = 0;   //chose the option
//	double hours =0.0;
//
//	double base_salary=0.0 ;
//
//	choice=Menu_salary_0910();
//
//	base_salary=Chose_salary(&choice);
//
//	hours=Work_time();
//
//	Salary_statistic(&base_salary, &hours);
//
//	return 0;
//}




//int main1() {
//
//	double hours;
//
//	printf("Enter the working hours a week:");
//	while (scanf("%lf", &hours) != 1 || (hours < 0)) {
//
//		while ((getchar() != '\n')) {
//			continue;
//		}
//		printf("Please enter a number(>=0):");
//	}
//
//	return 0;
//}


//*******************2023/9/12 22:42*********************//

//int main1() {
//
//	unsigned int input = 0;
//	printf("Please enter the integer(only the positive integer):");
//	while ((scanf("%ud", &input))!=1||input<0){
//
//		while ((getchar()!='\n')){
//
//			continue;
//		}
//		printf("Please re-enter the integer:");
//	}
//
//
//	for (int i = 2; i <= input; i++) {
//
//		int j = 0;
//		for (j = 2; j < i; j++){
//			if (i % j == 0)
//				break;
//		}
//		if (j >= i)
//			printf("%d ",i);
//		
//	}
//	return 0;
//}
//
//
//#include <stdio.h>
//
//int isprime(int x)
//{
//    for (int i = 2; i <= x / i; ++i)
//    {
//        if (x % i == 0) return 0;
//    }
//    return 1;
//}
//
//int main(void)
//{
//    int number;
//
//    printf("Please enter a number (<= 0 to quit): ");
//    while (scanf("%d", &number) == 1 && (number > 0))
//    {
//        if (number == 1)
//        {
//            printf("1 isn't a prime!\n");
//        }
//        else
//        {
//            printf("Here are the prime (<= %d):\n", number);
//            for (int i = 2; i <= number; i++)
//            {
//                if (isprime(i))
//                {
//                    printf("%d ", i);
//                }
//            }
//        }
//        printf("\nYou can enter again (<= 0 to quit): ");
//    }
//    printf("Done.\n");
//
//    return 0;
//}
//



//*******************2023/9/13 22:07*********************//

//int main() {
//	
//	int choice = 0;
//	double tax_line = 0;
//	double salary;
//	while (1)
//	{
//		choice = Show_menu0913();
//
//		if (!choice) break;
//
//		tax_line = Tax_line(&choice);
//
//		salary = Salary_input();
//
//		Pay_tax(&salary, &tax_line);
//
//		printf("\n");
//
//	}
//
//	printf("quit\n");
//
//	return 0;
//}



//*******************2023/9/14 20:45*********************//

//#include <stdio.h>
//#define PLAN1 17850
//#define PLAN2 23900
//#define PLAN3 29750
//#define PLAN4 14875
//#define RATE1 0.15
//#define RATE2 0.28
//
//void eatline(void);
//
//int main(void)
//{
//    int n = 0;
//    double wage, tax;
//
//    while (1)
//    {
//        printf("********************************\n");
//        printf("1) single\n");
//        printf("2) householder\n");
//        printf("3) married\n");
//        printf("4) married but divorced\n");
//        printf("5) quit\n");
//        printf("********************************\n");
//        printf("Please you choose: ");
//        while (scanf("%d", &n) != 1 || (n > 5 || n < 1))
//        {
//            eatline();
//            printf("Please enter 1, 2, 3, 4 or 5: ");
//        }
//        if (n == 5)
//        {
//            break;
//        }
//        printf("Please enter your wage: ");
//        while (scanf("%lf", &wage) != 1 || (wage < 0))
//        {
//            eatline();
//            printf("Please enter a number(>= 0): ");
//        }
//        eatline();
//        switch (n)
//        {
//        case 1:
//        {
//            tax = (wage <= PLAN1 ? wage * RATE1 : PLAN1 * RATE1 + (wage - PLAN1) * RATE2);
//            break;
//        }
//        case 2:
//        {
//            tax = (wage <= PLAN2 ? wage * RATE1 : PLAN2 * RATE1 + (wage - PLAN2) * RATE2);
//            break;
//        }
//        case 3:
//        {
//            tax = (wage <= PLAN3 ? wage * RATE1 : PLAN3 * RATE1 + (wage - PLAN3) * RATE2);
//            break;
//        }
//        case 4:
//        {
//            tax = (wage <= PLAN4 ? wage * RATE1 : PLAN4 * RATE1 + (wage - PLAN4) * RATE2);
//            break;
//        }
//        }
//        printf("Your tax: %g\n\n", tax);
//    }
//    printf("Done.\n");
//
//    return 0;
//}
//
//void eatline()
//{
//    while (getchar() != '\n')
//        continue;
//}


//int main() {
//
//
//	char choice;
//	char x;
//	int times = 0;
//	int i = 0;
//	double yj_pound = 0;
//	double beet_pound = 0;
//	double carrot_pound = 0;
//
//	double sum_yj_pound ;
//	double sum_beet_pound ;
//	double sum_carrot_pound ;
//
//	sum_yj_pound = 0;
//	sum_beet_pound = 0;
//	sum_carrot_pound = 0;
//
//	Show_menu0914();
//	
//	printf("Please enter the choice(a、b、c or q ):");
//	do
//	{
//		while ((choice = getchar()) != 'q')
//		{
//			switch (choice)
//			{
//				case 'a': {
//					printf("请输入样蓟的磅数:> ");
//					scanf("%lf", &yj_pound);
//					sum_yj_pound += yj_pound;
//					break;
//				}
//				case 'b': {
//					printf("请输入甜菜的磅数:> ");
//					scanf("%lf", &beet_pound);
//					sum_beet_pound += beet_pound;
//					break;
//				}
//				case 'c': {
//					printf("请输入胡萝卜的磅数:> ");
//					scanf("%lf", &carrot_pound);
//					sum_carrot_pound += carrot_pound;
//					break;
//				}
//
//			}
//
//			if (choice == 'a') {
//				
//				break;
//			}
//			if (choice == 'b') {
//				
//				break;
//			}
//			if (choice == 'c') {
//				break;
//			}
//		}
//
//		if (choice == 'q') {
//			printf("quit\n");
//			break;
//		}
//
//		printf("please re-enter the choice(a,b,c,q to quit):\n");
//		
//	} while (1);
//
//	printf("样蓟买了%.3lf磅\n", sum_yj_pound);
//	printf("甜菜买了%.3lf磅\n", sum_beet_pound);
//	printf("胡萝卜买了%.3lf磅\n", sum_carrot_pound);
//
//	return 0;
//}

//
//#include <stdio.h>
//#include <ctype.h>
//
//int main(void)
//{
//    const double price_artichokes = 2.05;
//    const double price_beets = 1.15;
//    const double price_carrots = 1.09;
//    const double DISCOUNT_RATE = 0.05;
//    const double under5 = 6.50;
//    const double under20 = 14.00;
//    const double base20 = 14.00;
//    const double extralb = 0.50;
//
//    int ch;
//    double lb_artichokes = 0;
//    double lb_beets = 0;
//    double lb_carrots = 0;
//    double lb_temp;
//    double lb_total;
//
//    double cost_artichokes;
//    double cost_beets;
//    double cost_carrots;
//    double cost_total;
//    double final_total;
//    double discount;
//    double shipping;
//
//    printf("Enter a to buy artichokes, b for beets, ");
//    printf("c for carrots, q to quit: ");
//    while ((ch = tolower(getchar())) != 'q')
//    {
//        if (isspace(ch))
//        {
//            continue;
//        }
//        while (getchar() != '\n')
//            continue;
//        switch (ch)
//        {
//        case 'a':
//        {
//            printf("Enter pounds of artichokes: ");
//            scanf("%lf", &lb_temp);
//            lb_artichokes += lb_temp;
//            break;
//        }
//        case 'b':
//        {
//            printf("Enter pounds of beets: ");
//            scanf("%lf", &lb_temp);
//            lb_beets += lb_temp;
//            break;
//        }
//        case 'c':
//        {
//            printf("Enter pounds of carrots: ");
//            scanf("%lf", &lb_temp);
//            lb_carrots += lb_temp;
//            break;
//        }
//        default:
//        {
//            printf("%c is not a valid choice.\n", ch);
//        }
//        }
//        printf("Enter a to buy artichokes, b for beets, ");
//        printf("c for carrots, q to quit: ");
//    }
//
//    cost_artichokes = price_artichokes * lb_artichokes;
//    cost_beets = price_beets * lb_beets;
//    cost_carrots = price_carrots * lb_carrots;
//    cost_total = cost_artichokes + cost_beets + cost_carrots;
//    lb_total = lb_artichokes + lb_beets + lb_carrots;
//
//    if (lb_total <= 0)
//    {
//        shipping = 0.0;
//    }
//    else if (lb_total < 5.0)
//    {
//        shipping = under5;
//    }
//    else if (lb_total < 20.0)
//    {
//        shipping = under20;
//    }
//    else
//    {
//        shipping = base20 + extralb * (lb_total - base20);
//    }
//    if (cost_total > 100.0)
//    {
//        discount = DISCOUNT_RATE * cost_total;
//    }
//    else
//    {
//        discount = 0.0;
//    }
//    final_total = cost_total + shipping - discount;
//
//    printf("Your order:\n");
//    printf("%.2f lbs of artichokes at $%.2f per pound:$ %.2f\n",
//        lb_artichokes, price_artichokes, cost_artichokes);
//    printf("%.2f lbs of beets at $%.2f per pound: $%.2f\n",
//        lb_beets, price_beets, cost_beets);
//    printf("%.2f lbs of carrots at $%.2f per pound: $%.2f\n",
//        lb_carrots, price_carrots, cost_carrots);
//    printf("Total cost of vegetables: $%.2f\n", cost_total);
//    if (cost_total > 100)
//    {
//        printf("Volume discount: $%.2f\n", discount);
//    }
//    printf("Shipping: $%.2f\n", shipping);
//    printf("Total charges: $%.2f\n", final_total);
//
//    return 0;
//}



//*******************2023/9/16 23:47*********************//

//int main() {
//
//	char input = 0;
//	int a=0;
//	printf("Please enter the character:(a,b,c)：");
//
//	do
//	{
//		while (a=(scanf("%c", &input)) != 1 || (input != 'a' && input != 'b' && input != 'c')) {
//
//			while (getchar() != '\n') {
//				continue;
//			}
//
//			printf("Please re-enter the character:(a,b,c)：");
//
//		}
//
//
//	} while (1);
//
//	return 0;
//}




//*******************2023/9/17 19:56*********************//

//int main() {
//	
//	//下面一些程序要求输入以EOF终止。如果你的操作系统很难或根本无法使用重定向，请使用一些其他的测试来终止输入，如读到&字符时停止。
//	//设计一个程序，统计在读到文件结尾之前读取的字符数
//
//	//int ch;
//	//int ct = 0;
//	//printf("Please enter some characters:\n");
//
//	//while ((ch=getchar())!=EOF)
//	//{
//	//	ct++;
//	//}
//	//printf("Charaters:%d\n", ct);
//
//	//return 0;
//	//
//	
//	//编写一个程序，在遇到EOF之前，把输入作为字符流读取。程序要打印每个输入的字符及其相应的ASCII十进制。
//	//注意，在ASCII序列中，空格字符前面的字符都是非打印字符，要特殊处理这些字符。
//	//如果非打印字符是换行符或制表符，则分别打印\n或者\t，
//	//否则，使用控制字符表示法。例如，ASCII的I是Ctrl+A，可显示为^A。注意，A的ASCII值是Ctrl+A的值加上64。
//	//其他字符也有类似的关系。除每次遇到换行符打印新的一行之外，每行打印10对值。（注意：不同的操作系统其控制字符可能不同）
//
//	int ch;
//	int i = 0;
//	 
//	printf("Please enter some characters:\n");
//
//	while ((ch=getchar())!=EOF)
//	{
//		if (i++ == 10) {
//			putchar('\n');
//			i = 1;
//		}
//
//		if (ch >= 32) {
//
//			printf("\'%c\'-%3d", ch, ch);
//		}
//		else if (ch == '\n') {
//			printf(" \\n - \\n\n");
//			i = 0;
//		}
//		else if (ch == '\t') {
//
//			printf(" \\t - \\t");
//		}
//		else
//		{
//			
//			printf(" \'%c\' - ^%c", ch, ch + 64);
//
//		}
//
//	}
//	puts("Done.");
//
//	return 0;
//}



//*******************2023/9/19 22:56*********************//

//int main() {
//
//	int ch;
//	int small_count1 = 0;
//	int big_count2 = 0;
//	printf("Please enter the string:\n");
//
//	while ((ch=getchar())!=EOF)
//	{
//		if (ch >= 'a' && ch <= 'z')
//			small_count1++;
//		if (ch >= 'A' && ch <= 'Z')
//			big_count2++;
//	}
//
//	printf("Lowercase letters :%d\n", small_count1);
//	printf("majuscule letters :%d\n", big_count2);
//
//	return 0;
//}


//#include<stdio.h>
//#include<ctype.h>
//
//int main() {
//
//	int ch;
//	unsigned int uct = 0;
//	unsigned int lct = 0;
//	unsigned int oct = 0;
//
//	printf("Please enter some characters:\n");
//
//	while ((ch=getchar())!=EOF)
//	{
//		(isupper(ch)) ? ++uct : islower(ch) ? ++lct : ++oct;
//	}
//
//	printf("Upper:%u\n", uct);
//	printf("Lower:%u\n", lct);
//	printf("Others:%u\n", oct);
//
//	return 0;
//}


//C语言isupper函数介绍、示例和实现----from CSDN
//C语言isupper函数用于判断字符是否为大写字母（A - Z）
//#include <ctype.h>  包含的头文件
//int isupper(int c);  函数声明
//判断参数c是否为大写字母，您可能会问：isupper函数的参数是int c，是整数，不是字符，在C语言中，字符就是整数，请补充学习一下基础知识。
//返回值：0 - 不是大写字母，非0 - 是大写字母

//#include <stdio.h>
//#include<ctype.h>
//
//int main()
//{
//	printf("isupper('-')=%d\n", isupper('-'));
//	printf("isupper('0')=%d\n", isupper('0'));
//	printf("isupper('a')=%d\n", isupper('a'));
//	printf("isupper('A')=%d\n", isupper('A'));
//}

/*
 * 程序名：book.c，此程序演示C语言自定义的isupper函数。
 * 作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
//#include <stdio.h>
//
//// 自定义的isupper函数。
//int _isupper(int c)
//{
//	if (c >= 'A' && c <= 'Z') return 256;
//
//	return 0;
//}
//
//int main()
//{
//	printf("_isupper('-')=%d\n", _isupper('-'));
//	printf("_isupper('0')=%d\n", _isupper('0'));
//	printf("_isupper('a')=%d\n", _isupper('a'));
//	printf("_isupper('A')=%d\n", _isupper('A'));
//}






//int main() {
//
//	char S[100];
//	char t[100];
//	printf("请输入主串\n");
//	scanf("%s", S);
//	printf("请输入子串\n");
//	scanf("%s", t);
//
//	//printf("%d\n", strlen(S));
//	//printf("%d\n", strlen(t));
//	
//	int ret=BF(S, t);
//
//	if (ret == 0)
//	{
//		printf("匹配失败，没有在主串中找到子串的相关信息\n");
//	}
//	else
//	{
//		printf("匹配成功，匹配成功的位置为:%d\n", ret);
//	}
//
//	return 0;
//}


//
//int main() {
//
//	char S[100];
//	char t[100];
//
//	while (1)
//	{
//		printf("请输入主串\n");
//		scanf("%s", S);
//		printf("请输入子串\n");
//		scanf("%s", t);
//
//		int ret = KMP(S, t, 0);
//
//		if (ret == -1)
//		{
//			printf("匹配失败，在主串中未找到相关的子串位置\n");
//		}
//		else
//		{
//			printf("匹配成功，它的位置为：%d\n", ret);
//		}
//
//	}
//
//
//
//	return 0;
//}

///* guess.c  -- 一个低效且错误的猜数程序 */
//int main1()
//{
//	int guess = 1;
//	printf("Pick an integer from 1 to 100. I will try to guess ");
//	printf("it.\nRespond with a y if my guess is right and with");
//	printf("\nan n if it is wrong.\n");
//	printf("Uh...is your number %d?\n", guess);
//
//	while (getchar()!='y') /*获取用户响应并和y比较*/
//	{
//		printf("Well, then ,is it %d?\n", ++guess);
//	}
//
//	printf("I knew I could do it!\n");
//
//	return 0;
//}
//
//
///* guess.c  -- 一个低效且错误的猜数程序 */
//int main2()
//{
//	int guess = 1;
//	printf("Pick an integer from 1 to 100. I will try to guess ");
//	printf("it.\nRespond with a y if my guess is right and with");
//	printf("\nan n if it is wrong.\n");
//	printf("Uh...is your number %d?\n", guess);
//
//	while (getchar() != 'y') /*获取用户响应并和y比较*/
//	{
//		printf("Well, then ,is it %d?\n", ++guess);  
//
//		while (getchar()!='\n')     /*跳过输入行的剩余部分*/
//		{
//			continue;
//		}
//
//	}
//
//	printf("I knew I could do it!\n");
//
//	return 0;
//}
//
//
///* guess.c  -- 一个低效且错误的猜数程序 */
//int main()
//{
//	int guess = 1;
//	char response;
//	printf("Pick an integer from 1 to 100. I will try to guess ");
//	printf("it.\nRespond with a y if my guess is right and with");
//	printf("\nan n if it is wrong.\n");
//	printf("Uh...is your number %d?\n", guess);
//
//	while ((response = getchar()) != 'y') /*获取用户响应并和y比较*/
//	{
//		if (response == 'n')
//		{
//			printf("Well, then ,is it %d?\n", ++guess);
//		}
//		else
//		{
//			printf("Sorry, I understand only y or n.\n");
//		}
//
//		while (getchar() != '\n')     /*跳过输入行的剩余部分*/
//		{
//			continue;
//		}
//
//	}
//
//	printf("I knew I could do it!\n");
//
//	return 0;
//}


//void display(char cr, int lines, int width);
//
//int main1()
//{
//	int ch;					/* 要打印的字符 */
//	int rows, cols;			/* 行数和列数 */
//
//	printf("Enter a character and two integers:\n");
//
//	while ((ch=getchar())!='\n')
//	{
//		scanf("%d %d", &rows, &cols);
//		
//		display(ch,rows,cols);
//		
//		printf("Enter another character and two integers:\n");
//		
//		printf("Enter a newline to quit.\n");
//	}
//
//	printf("Bye.\n");
//
//	return 0;
//}
//
//int main()
//{
//	int ch;					/* 要打印的字符 */
//	int rows, cols;			/* 行数和列数 */
//
//	printf("Enter a character and two integers:\n");
//
//	while ((ch = getchar()) != '\n')
//	{
//		if (scanf("%d %d", &rows, &cols) != 2)
//			break;
//		
//		display(ch, rows, cols);
//
//		while (getchar()!='\n')
//		{
//			continue;
//		}
//
//		printf("Enter another character and two integers:\n");
//
//		printf("Enter a newline to quit.\n");
//	}
//
//	printf("Bye.\n");
//
//	return 0;
//}
//
//
//void display(char cr, int lines, int width)
//{
//	int row, col;
//	for (row = 1; row <= lines; row++)
//	{
//		for (col = 1; col <= width; col++)
//		{
//			putchar(cr);
//		}
//
//		putchar('\n');/* 结束本行，开始新的一行 */
//	}
//}


//#include<stdbool.h>
//int main()
//{
//	const int MIN = -1000;  //范围的下界限制
//	const int MAX = 1000;   //范围的上界限制
//
//	int start;              //范围的下界
//	int stop;              //范围的上界
//	double answer;
//
//	printf("This program computers the sum of the squares of "
//		"integers in a range.\nThe lower bound should not "
//		"be less than -1000 and \nthe upper bound should not "
//		"be more than +1000.\nEnter the limits (enter 0 for  "
//		"both limits to quit): \nlower limit:");
//
//	start = get_int();				//确认输入了一个整数
//	printf("upper limit:");			
//	stop = get_int();
//	while (start!=0||stop!=0)
//	{
//		if (bad_Iimits(start, stop, MIN, MAX))  //确认范围的上下界是否有效
//			printf("Please try again.\n");
//		else
//		{
//			answer = sum_squares(start, stop);  //计算a 到 b 之间的整数的平方和
//			printf("The sum of the squares of the integer from ");
//			printf("from %d to %d is %g\n",start,stop,answer);
//		}
//
//		printf("Enter the limits (Enter 0 for both limits to quit):\n");
//		printf("lower limit:");
//		start = get_int();
//		printf("upper limit:");
//		stop = get_int();
//
//	}
//	printf("Done.\n");
//
//	return 0;
//}
//



//*******************2023/9/22 17:05*********************//

//编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要报告平均每个单词的字母数。
//不要把空白统计为单词的字母。实际上，标点符号也不应该统计，但是现在暂时不用考虑这么多
//如果你在意这点，考虑使用ctype.h系列中的ispunct()函数
//#include<ctype.h>
//int main()
//{
//	bool inword = false;
//	int ch, words = 0;
//	int letter = 0;
//
//	printf("Please enter some words(EOF to quit):\n");
//	while ((ch = getchar())!=EOF)
//	{
//		putchar(ch);
//		//C 库函数 int ispunct(int c) 检查所传的字符是否是标点符号字符，并统计标点字符的个数。
//		//如果 c 是一个标点符号字符，则该函数返回非零值（true），否则返回 0（false）
//		if (ispunct(ch))
//		{
//			continue;
//		}
//
//		//isalpha函数用于判断字符是否为字母（a - z和A - Z）
//		//返回值：0-不是字母，非0-是字母。
//		if (isalpha(ch))
//		{
//			letter++;
//		}
//
//		//判断字符ch是否为空白符
//		//当ch为空白符时，返回非零值，否则返回零。（空白符指空格、水平制表、垂直制表、换页、回车和换行符。）
//		//下面两个if语句是判断是否是一个单词
//		if (!isspace(ch) && !inword)
//		{
//			inword = true;
//			words++;
//		}
//		if (isspace(ch) && inword)
//		{
//			inword = false;
//		}
//
//	}
//	double count = letter / words;
//	printf("Total words:%d\n", words);
//	printf("Total letters:%d\n", letter);
//	printf("Average letters of words :%g\n", count);
//
//
//	return 0;
//}


//*******************2023/9/24 11:39*********************//


/* guess.c  -- 一个低效且错误的猜数程序 */
//int main()
//{
//	int guess = 50;
//	int temp_max = 100;
//	int temp_min = 1;
//
//	char response;
//	char response2;
//	printf("Pick an integer from 1 to 100. I will try to guess ");
//	printf("it.\nRespond with a y if my guess is right and with");
//	printf("\nan n if it is wrong.\n");
//	printf("Uh...is your number %d?\n", guess);
//
//	while ((response = getchar()) != 'y') /*获取用户响应并和y比较*/
//	{
//		if (response == 'n')
//		{
//			printf("the %d is biger or smaller", guess);
//			printf("\nRespond with b s or c if my guess is biger 、");
//			printf("\n my guess is smaller or my guess is correct:(input b,s or c):");
//			while ((response2 = getchar()) != 'c')
//			{
//
//				if (response2 == 'b')
//				{
//
//					//猜大了
//					temp_max = guess;  //更新最大值
//					guess = (temp_max + temp_min) / 2;
//					printf("Well, then ,is it %d?\n", guess);
//					printf("my guess:%d is bigger smaller:(input b or s):", guess);
//
//				}
//
//				if (response2 == 's')
//				{
//					//猜小了
//					temp_min = guess; ////更新最小值
//					guess = (temp_min + temp_max) / 2;
//					printf("Well, then ,is it %d?\n", guess);
//					printf("my guess:%d is bigger smaller:(input b or s):", guess);
//				}
//			}
//
//				if (response2 == 'c')
//				{
//					break;
//				}
//
//				else
//				{
//					printf("Sorry, I understand only b 、s or c.\n");
//				}
//				
//				while (getchar() != '\n')     /*跳过输入行的剩余部分*/
//				{
//					continue;
//				}
//			
//		}
//		else
//		{
//			printf("Sorry, I understand only y or n.\n");
//		}
//
//		while (getchar() != '\n')     /*跳过输入行的剩余部分*/
//		{
//			continue;
//		}
//
//	}
//
//	printf("I knew I could do it!\n");
//
//	return 0;
//}

//#include<ctype.h>
//
//int main()
//{
//	int high = 100;
//	int low = -1;
//	int guess = (high + low) / 2;
//	char response;
//
//	printf("Pick an integer from 1 to 100. I will try to guess ");
//	printf("it.\nRespond with a y if my guess is right, with");
//	printf("\na h if it is high,and with an l if it is low.\n");
//	printf("Uh...is your number %d\n", guess);
//
//	while ((response = getchar()!='y'))
//	{
//		if (response == '\n')
//		{
//			continue;
//		}
//
//		if (tolower(response) != 'h' && tolower(response) != 'l')
//		{
//			printf("I don't understand that response. Please enter h for \n");
//			printf("high, l for low, y for correct.\n");
//			continue;
//		}
//
//		if (tolower(response) == 'h')
//		{
//			high = guess - 1;
//		}
//		else if (towlower(response) == 'l')
//		{
//			low = guess + 1;
//		}
//		guess = (high + low) / 2;
//		printf("Well, then, is it %d?\n", guess);
//	}
//
//	printf("I knew I could do it!\n");
//
//	return 0;
//}


#include<ctype.h>

//返回读取第一个非空白字符，否则返回  0；
//char get_first()
//{
//	int ch;
//
//	while ((ch = getchar())!='\n')
//	{
//		//当ch为空白符时，返回非零值，否则返回零。（空白符指空格、水平制表、垂直制表、换页、回车和换行符。）
//		if (!isspace(ch))
//		{
//			return ch;
//		}
//	}
//
//	while (getchar()!='\n')
//	{
//		continue;
//	}
//	return 0;
//}

//
//#define STOP '#'
//
//int get_first()
//{
//	int ch;
//	do
//	{
//		ch = getchar();
//	} while (isspace(ch));
//
//	while (getchar()!='\n')
//	{
//		continue;
//	}
//
//	return ch;
//}
//
//
//int main()
//{
//	int ch;
//	printf("Please enter some characters('#' to quit):\n");
//
//	while ((ch = get_first())!=STOP)
//	{
//		printf("Result:%c\n", ch);
//		printf("You can enter again('#' to quit):\n");
//
//	}
//	printf("Done.\n");
//
//
//	return 0;
//}



//*******************2023/9/25 21:22*********************//
//修改第7章编程练习8，用字符代替数字标记菜单的选项。用q代替5作为结束输入的标记
//
//#define EXTER_HOUR 1.5
//#define BASE_TAX 0.15
//#define EXTRA_TAX 0.2
//#define EXCEED_TAX 0.25
//
//int show_menu();
//void show_salary(double base_salary, double hours);
//
//int main()
//{
//	
//	int ch;
//	double n;
//
//	while ((ch = show_menu()) != 'q')
//	{
//		printf("Enter the working hours a week:");
//		while (scanf("%lf",&n)!=1||(n<0))
//		{
//			while (getchar()!='\n')
//			{
//				continue;
//			}
//
//			printf("Enter a positive number:");
//
//		}
//
//		switch (ch)
//		{
//			case 'a':
//			{
//				show_salary(8.75, n);
//				break;
//			}
//			case 'b':
//			{
//				show_salary(9.33, n);
//				break;
//			}
//			case 'c':
//			{
//				show_salary(10.00, n);
//				break;
//			}
//			case 'd':
//			{
//				show_salary(11.20, n);
//				break;
//			}
//			default:
//				break;
//
//
//		}
//
//		putchar('\n');
//		
//	}
//
//	printf("Done.\n");
//
//	return 0;
//}
//
//int get_choice()
//{
//	int ch;
//	do
//	{
//		ch = getchar();
//	} while (isspace(ch));
//
//	while (getchar()!='\n')
//	{
//		continue;
//	}
//	return ch;
//}
//
//
//int show_menu()
//{
//	int ch;
//
//	printf("*****************************************************************\n");
//	printf("Enter the number corresponding to the desired pay rate or action:\n");
//	printf("a)  $8.75/hr                                           b)&9.33/hr\n");
//	printf("c)  $10.00/hr                                          d)&11.20/hr\n");
//	printf("q) quit\n");
//	printf("*****************************************************************\n");
//	printf("Please your choose:");
//
//	ch = get_choice();
//	
//	while (ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd' && ch != 'q')
//	{
//		printf("Please enter a,b,c,d or q:");
//		ch = get_choice();
//	}
//
//	return ch;
//}
//
//
//void show_salary(double base_salary, double hours)
//{
//	double tax, taxed_salary;
//	double salary = (hours > 40 ? (40 + 1.5 * (hours - 40)) : hours) * base_salary;
//	if (salary < 300)
//	{
//		tax = salary * BASE_TAX;
//	}
//	else if(salary<=450)
//	{
//		tax = 300 * BASE_TAX + (salary - 300) * EXTRA_TAX;
//	}
//	else
//	{
//		tax = 300 * BASE_TAX + 150 * EXTRA_TAX + (salary - 450) * EXCEED_TAX;
//	}
//
//	taxed_salary = salary - tax;
//	printf("salary(before taxed):$%g\n", salary);
//	printf("tax:$%g\n", tax);
//	printf("salary(after taxed):$%g\n", taxed_salary);
//}

//
//
//int show_menu();
//
//float get_int0925()
//{
//	int ch2;
//	float input1;
//	while (scanf("%f", &input1) != 1)
//	{
//		while ((ch2 = getchar()) != '\n')
//		{
//			putchar(ch2);
//		}
//		printf(" is not an number\n");
//		printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
//	}
//
//	return input1;
//}
//
//void Add(float input1, float input2)
//{
//	printf("%f + %f = %f\n", input1, input2, input1 + input2);
//}
//
//void Subtract(float input1,float input2)
//{
//	printf("%f - %f = %f\n", input1, input2, input1 - input2);
//}
//
//void Multiply(float input1, float input2)
//{
//	printf("%f * %f = %f\n", input1, input2, input1 * input2);
//}
//
//void Divide(float input1,float input2)
//{
//	printf("%f / %f = %f\n", input1, input2, input1 / input2);
//}
//
//
//int main()
//{
//	int ch;
//	float input1;
//	float input2;
//	while ((ch=show_menu())!='q')
//	{
//		switch (ch)
//		{
//		case 'a':
//			{
//				printf("Enter the first number:");
//				input1 = get_int0925();
//				printf("Enter the second number:");
//				input2 = get_int0925();
//				Add(input1, input2);
//				break;
//			}
//		case 's':
//			{
//				printf("Enter the first number:");
//				input1 = get_int0925();
//				printf("Enter the second number:");
//				input2 = get_int0925();
//				Subtract(input1, input2);
//				break;
//			}
//		case 'm':
//			{
//				printf("Enter the first number:");
//				input1 = get_int0925();
//				printf("Enter the second number:");
//				input2 = get_int0925();
//				Multiply(input1, input2);
//				break;
//			}
//		case 'd':
//			{
//				printf("Enter the first number:");
//				input1 = get_int0925();
//				printf("Enter the second number:");
//				while (!(input2 = get_int0925()))
//				{
//					printf("Enter a number other than 0:");
//				}
//				Divide(input1, input2);
//				break;
//			}
//		}
//    
//	}
//
//	printf("Bye.\n");
//	return 0;
//}
//
//
//int get_choice()
//{
//	int ch;
//	do
//	{
//		ch = getchar();
//	} while (isspace(ch));
//
//	while (getchar()!='\n')
//	{
//		continue;
//	}
//	return ch;
//}
//
//
//int show_menu()
//{
//	int ch;
//	
//	printf("Enter the operation choice:\n");
//	printf("a. add          s. subtract\n");
//	printf("m. multiply     d. divide\n");
//	printf("q. quit\n");
//	
//	ch = get_choice();
//		
//	while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
//	{
//		printf("Please enter a,s,m,d or q:");
//		ch = get_choice();
//	}
//	
//	return ch;
//}


//double min(double x, double y)
//{
//	if (x < y)
//		return x;
//	else
//		return y;
//}
//
//int main()
//{
//	double x, y;
//	printf("Enter the two numbers('q' to quit):\n");
//
//	while (scanf("%lf %lf",&x,&y)==2)
//	{
//		printf("%lf", min(x, y));
//		putchar('\n');
//		printf("Enter the two numbers('q' to quit):\n");
//	}
//	printf("Bye.\n");
//	return 0;
//}


//void chline(char ch, int col, int row)
//{
//	int i=0;
//	int j=0;
//	for (i = 1; i <= row; i++)
//	{
//		for (j = 1; j <= col; j++)
//			putchar(ch);
//		putchar('\n');
//	
//
//	}
//
//}
//
//
//int main()
//{
//	chline('*', 3, 2);
//	
//	return 0;
//}

//*******************2023/9/27 22:52*********************//

//#define CHAR '#'
//
//void show(int ch, int cols, int rows);
//
//int main()
//{
//	int i, j;
//
//	printf("Please enter two numbers (q to quit):");
//
//	while (scanf("%d %d",&j,&i)==2)
//	{
//		printf("Printing %c in %d rows and %d columns is:\n", CHAR, i, j);
//		show(CHAR, j, i);
//		printf("You can enter two numbers again(q to quit):");
//	}
//	printf("Done.\n");
//
//	return 0;
//}
//
//
//void show(int ch, int cols, int rows)
//{
//	int a, b;
//
//	for (a = 1; a <= rows; a++)
//	{
//		for (b = 1; b <= cols; b++)
//		{
//			putchar(ch);
//		}
//		putchar('\n');
//	}
//
//}

//
//double Harmonic_mean(double x, double y);
//
//
//int main()
//{
//	double i, j;
//
//	printf("Please enter two numbers (q to quit):");
//
//	while (scanf("%lf %lf",&i,&j)==2)
//	{
//		printf("%lf is the harmonic mean with %lf and %lf.\n", Harmonic_mean(i, j), i, j);
//		printf("You can enter two numbers again(q to quit):");
//	}
//	printf("Done.\n");
//
//	return 0;
//}
//
//
//double Harmonic_mean(double x, double y)
//{
//	double mean;
//
//	mean = 1 / ((1 / x + 1 / y) / 2);
//
//	return mean;
//}

//void larget(double* x, double* y);
//
//int main()
//{
//	double x, y;
//
//	printf("Please enter two numbers(q to quit):");
//
//	while (scanf("%lf %lf",&x,&y) == 2)
//	{
//		printf("past: %lf and %lf\n", x, y);
//		larget(&x, &y);
//		printf("now: %lf and %lf\n", x, y);
//		printf("Please enter two numbers again (q to quit):");
//	}
//	
//
//	return 0;
//}
//
//void larget(double* x, double* y)
//{
//	//(*x < *y) ? (*x = *y) : (*y = *x);
//	*x = *y = (*x < *y) ? *y : *x;
//
//}


//void sort0927(double* a, double* b, double* c);
//
//int main()
//{
//
//	double x, y,z;
//	
//	printf("Please enter three numbers(q to quit):");
//	
//	while (scanf("%lf %lf %lf",&x,&y,&z) == 3)
//	{
//		printf("past: %lf 、%lf and %lf\n", x, y, z);
//		sort0927(&x, &y,&z);
//		printf("now: %lf、%lf and %lf \n", x, y, z);
//		printf("Please enter three numbers again (q to quit):");
//	}
//	return 0;
//}
//
//void sort0927(double* a, double* b, double* c)
//{
//	double tp;
//
//	if (*a > *b)
//	{
//		tp = *a;
//		*a = *b;
//		*b = tp;
//	}
//
//	if (*a > *c)
//	{
//		tp = *a;
//		*a = *c;
//		*c = tp;
//	}
//
//	if (*b > *c)
//	{
//		tp = *b;
//		*b = *c;
//		*c = tp;
//
//	}
//
//}

//*******************2023/9/28 21:32*********************//
//从标准输入中读取字符，直到遇到文件结尾，报告每个字符是否为字母。如果是，还要报告该字母
//在字母表中的数值位置。如果该字符是一个字母则返回一个数值位置，否则返回-1
//#include <stdio.h>
//#include <ctype.h>
//
//void attain_pos(void);
//int position(int ch);
//
//int main(void)
//{
//    attain_pos();
//
//    return 0;
//}
//
//void attain_pos(void)
//{
//    int ch;
//    int figure;
//
//    printf("Please enter a character (EOF to quit):\n");
//    while ((ch = getchar()) != EOF)
//    {
//        figure = position(ch);
//        if (figure)
//        {
//            printf("%c is %d in alphabet.\n", ch, figure);
//        }
//        else
//        {
//            printf("%c isn't a letter!\n", ch); //包括回车换行符和空白符;
//        }
//        while (getchar() != '\n')
//            continue;
//        printf("You can enter again (EOF to quit): ");
//    }
//    printf("Done.\n");
//}
//
//int position(int ch)
//{
//    if (isupper(ch))
//    {
//        return (ch - 'A' + 1);
//    }
//    else if (islower(ch))
//    {
//        return (ch - 'a' + 1);
//    }
//    return 0;
//}
//


//#include <stdio.h>
//
//double power(double n, int p);
//
//int main(void)
//{
//    double x, xpow;
//    int exp;
//
//    printf("Enter a number and the integer power");
//    printf(" to which\nthe number will be raised. Enter q");
//    printf(" to quit.\n");
//    while (scanf("%lf %d", &x, &exp) == 2)
//    {
//        xpow = power(x, exp);
//        printf("%.3g to the power %d is %.5g.\n", x, exp, xpow);
//        printf("Enter next pair of numbers or q to quit.\n");
//    }
//    printf("Hope you enjoyed this power trip -- bye!\n");
//
//    return 0;
//}
//
//double power(double n, int p)
//{
//    int i;
//    double pow = 1.0;
//
//    if ((0 == p) && (0 == n)) //指数和底均为0
//    {
//        printf("0 to the 0 undefined, using 1 as the value.\n");
//        return pow;
//    }
//
//    if (0 == n)      //底为0
//    {
//        pow = 0.0;
//        return pow;
//    }
//
//    if (0 == p)      //指数为0
//    {
//        return pow;
//    }
//
//    if (p > 0)       //指数大于0
//    {
//        for (i = 1; i <= p; i++)
//        {
//            pow *= n;
//        }
//        return pow;
//    }
//    else             //指数小于0
//    {
//        // 指数是负数
//
//        for (i = 1; i <= -p; i++)
//        {
//            pow *= 1 / n;
//        }
// 
//        return pow;
//    }
//}

//double power(double n, int p);
//
//int main(void)
//{
//    double x, xpow;
//    int exp;
//
//    printf("Enter a number and the integer power");
//    printf(" to which\nthe number will be raised. Enter q");
//    printf(" to quit.\n");
//    while (scanf("%lf %d", &x, &exp) == 2)
//    {
//        xpow = power(x, exp);
//        printf("%.3g to the power %d is %.5g.\n", x, exp, xpow);
//        printf("Enter next pair of numbers or q to quit.\n");
//    }
//    printf("Hope you enjoyed this power trip -- bye!\n");
//
//    return 0;
//}
//
//double power(double n, int p)
//{
//    double pow = 1.0;
//
//    if ((0 == p) && (0 == n))
//    {
//        printf("0 to the 0 undefined, using 1 as the value.\n");
//        return pow;
//    }
//    if (0 == n)
//    {
//        pow = 0.0;
//        return pow;
//    }
//    if (0 == p)
//    {
//        return pow;
//    }
//    if (p > 0)
//    {
//        return n * power(n, p - 1);
//    }
//    else
//    {
//        return power(n, p + 1) / n;
//    }
//}

//*******************2023/9/30 21:32*********************//

///*recur.c --递归举例*/
//
//void up_and_down(int);
//
//int main(void)
//{
//	up_and_down(1);
//
//	return 0;
//}
//
//void up_and_down(int n)
//{
//	printf("Level %d: n location %p\n", n, &n);   /*1*/
//
//	if (n < 4)
//	{
//		up_and_down(n + 1);
//	}
//	printf("LEVEL %d: n location %p\n", n, &n);
//}



//long fact(int n);
//long rfact(int n);
//
//int main()
//{
//	int num;
//
//	printf("This program calculate factorials.\n");
//	printf("Enter a value in the range 0-12(q to quit):\n");
//	while (scanf("%d",&num)==1)
//	{
//		if (num < 0)
//		{
//			printf("No negative numbers.please.\n");
//		}
//		else if(num>12)
//		{
//			printf("Keep input under 13.\n");
//		}
//		else
//		{
//			printf("loop %d factorial = %d\n", num, fact(num));
//			printf("recursion: %d factorial = %ld\n", num, rfact(num));
//
//		}
//		printf("Enter a value in the range 0-12(q to  quit):\n");
//
//	}
//
//	printf("Bye.\n");
//	return 0;
//}
//
//long fact(int n)
//{
//	long ans;
//
//	for (ans = 1; n > 1; n--)
//		ans *= n;
//
//	return ans;
//}
//
//long rfact(int n) //使用递归计算阶数
//{
//	long ans;
//
//	if (n > 0)
//		ans = n * rfact(n - 1);
//	else
//	{
//		ans = 1;
//	}
//	return ans;
//}
//
//void to_binary(unsigned long n);
//
//int main()
//{
//
//	unsigned long number;
//	printf("Enter an integer (q to quit):\n");
//
//	while (scanf("%ul", &number) == 1)
//	{
//		printf("Binary equivalent:");
//		to_binary(number);
//		putchar('\n');
//		printf("Enter an integer (q to quit):\n");
//
//	}
//
//	printf("Done.\n");
//
//
//	return 0;
//}
//
//void to_binary(unsigned long n)
//{
//	int r;
//	r = n % 2;
//	if (n >= 2)
//		to_binary(n / 2);
//	putchar('0' + r);
//
//}
//


//void to_base_n(unsigned long n,int input);
//void base_print(int input);
//int main()
//{
//	int input = 0;
//	unsigned long number;
//	
//	printf("Enter an integer (q to quit):\n");
//
//	while (scanf("%ul", &number) == 1)
//	{
//
//		printf("Please enter an integer(2-10):");
//		
//		while (scanf("%d", &input) != 1||input<2||input>10)
//		{
//			printf("sorry,should keep input under(2-10):");
//		}
//		base_print(input);
//		to_base_n(number, input);
//		putchar('\n');
//		printf("Enter an integer (q to quit):\n");
//	
//	}
//
//	printf("Done.\n");
//
//
//	return 0;
//}
//
//void base_print(int input)
//{
//	switch (input)
//	{
//	case 2:
//		printf("Binary equivalent:");
//		break;
//	case 3:
//		printf("ternary equivalent:");
//		break;
//	case 4:
//		printf("quaternary equivalent:");
//		break;
//	case 5:
//		printf("quinary equivalent:");
//		break;
//	case 6:
//		printf("senary equivalent:");
//		break;
//	case 7:
//		printf("septenary equivalent:");
//		break;
//	case 8:
//		printf("octal equivalent:");
//		break;
//	case 9:
//		printf("nonary equivalent:");
//		break;
//	case 10:
//		printf("decimal equivalent:");
//		break;
//
//	default:
//		break;
//	}
//
//}
//
//
//void to_base_n(unsigned long n,int input)
//{
//	int r;
//	r = n % input;
//	if (n >= input)
//		to_base_n(n / input,input);
//	putchar('0' + r);
//
//}



//void to_base_n(int x, int base);
//
//int main()
//{
//	int b;
//	long int n;
//
//	printf("Please enter a number(q to quit): ");
//
//	while (scanf("%ld", &n) == 1)
//	{
//		if (n <= 0)
//		{
//			printf("illegal data! Please enter again: ");
//			continue;
//		}
//
//		printf("Please enter a base system number(2-10): ");
//
//		while (scanf("%d",&b)!=1||(b<2||b>10))
//		{
//			while (getchar()!='\n')
//			{
//				continue;
//			}
//			printf("Please enter again(2-10): ");
//			
//		}
//		printf("%d in %d base system is: ", n, b);
//
//		to_base_n(n, b);
//
//		printf("\nYou can enter a number again (q to quit): ");
//	}
//	printf("Done.\n");
//	return 0;
//}
//
//
//
//
//void to_base_n(int x, int base)
//{
//	int r;
//	r = x % base;
//	if (x >= base)
//	{
//		to_base_n(x / base, base);
//	}
//	printf("%d", r);
//}

//void Fibonacci(int len);
//
//int main()
//{
//	int n;
//
//	printf("Please enter a integer (<=0 or q to quit): ");
//
//	while (scanf("%d", &n) == 1)
//	{
//		printf("Top %d items of Fibonacci sequence: \n", n);
//		Fibonacci(n);
//		printf("Please enter a integer (<=0 or q to quit): ");
//	}
//
//	printf("Done.\n");
//
//	return 0;
//}
//
//void Fibonacci(int len)
//{
//	int i;
//	unsigned long t, x, y;
//	x = y = 1;
//
//	for (i = 0; i < len; i++)
//	{
//		printf("%lu ", x);
//		t = x + y;
//		x = y;
//		y = t;
//
//	}
//	printf("\n");
//
//}


//*******************2023/10/02 21:32*********************//


//#define MONTHS 12         // 一年的月份数
//#define YEARS 5			  // 降水量数据的年数
//
//int main1()
//{
//	//把数组初始化为2000年到2004年的降水量数据
//
//	const float rain[YEARS][MONTHS] = {
//	{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
//	{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
//	{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
//	{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
//	{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
//	};
//
//	int year, month;
//	float subtot, total;
//
//	printf(" YEAR RAINFALL (inches) \n");
//
//	for (year = 0, total = 0; year < YEARS; year++)
//	{
//		//对于每一年，各月的总降水量
//		for (month = 0, subtot = 0; month < MONTHS; month++)
//		{
//			subtot += rain[year][month];
//		}
//
//		printf("%5d %15.1f\n", 2000 + year, subtot);
//
//		total += subtot;  //所有年度的总降水量
//
//	}
//
//	printf("\nThe yearly average is %.lf inches.\n\n", total / YEARS);
//	printf("MONTHLY AVERAGES: \n\n");
//	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct ");
//	printf(" Nov Dec\n");
//
//	for (month = 0, subtot = 0; month < MONTHS; month++)
//	{
//		//对于每一月，各年该月份的总降水量
//		for (year = 0, total = 0; year < YEARS; year++)
//		{
//				subtot += rain[year][month];
//		}
//
//		printf("%4.1f ", subtot/YEARS);
//	}
//	
//	printf("\n");
//	
//	return 0;
//}
//
//int main()
//{
//	//把数组初始化为2000年到2004年的降水量数据
//
//	const float rain[YEARS][MONTHS] = {
//	{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
//	{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
//	{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
//	{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
//	{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
//	};
//
//	int year, month;
//	float subtot, total;
//
//	printf(" YEAR RAINFALL (inches) \n");
//
//	for (year = 0, total = 0; year < YEARS; year++)
//	{
//		//对于每一年，各月的总降水量
//		for (month = 0, subtot = 0; month < MONTHS; month++)
//		{
//			subtot += *(*(rain + year) + month);
//		}
//
//		printf("%5d %15.1f\n", 2000 + year, subtot);
//
//		total += subtot;  //所有年度的总降水量
//
//	}
//
//	printf("\nThe yearly average is %.lf inches.\n\n", total / YEARS);
//	printf("MONTHLY AVERAGES: \n\n");
//	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct ");
//	printf(" Nov Dec\n");
//
//	for (month = 0, subtot = 0; month < MONTHS; month++)
//	{
//		//对于每一月，各年该月份的总降水量
//		for (year = 0, total = 0; year < YEARS; year++)
//		{
//			subtot += rain[year][month];
//
//			subtot += *(*(rain + year) + month);
//
//		}
//
//		printf("%4.1f ", subtot / YEARS);
//	}
//
//	printf("\n");
//
//	return 0;
//}

//
//void copy_arr(double target1[],const double source[],int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		target1[i] = source[i];
//	}
//
//}
//
//void copy_ptr(double* target2, const double* source, int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		*(target2 + i) = *(source + i);
//	}
//
//
//}
//
//void copy_ptrs(double* target3,const double* source, const double* end)
//{
//	while (source<end)
//	{
//		*(target3++) = *(source++);
//	}
//
//}
//
//void show_arr(const double x[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%-5g", x[i]);
//	}
//	putchar('\n');
//}
//
//
//int main()
//{
//	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
//	double target1[5];
//	double target2[5];
//	double target3[5];
//
//	printf("Source array:\n");
//	show_arr(source, 5);
//
//
//	copy_arr(target1, source, 5);
//	printf("Target1:\n");
//	show_arr(target1, 5);
//
//	copy_ptr(target2, source, 5);
//	printf("Target2:\n");
//	show_arr(target2, 5);
//
//	copy_ptrs(target3, source, source + 5);
//	printf("Target3:\n");
//	show_arr(target3, 5);
//
//	return 0;
//}


//*******************2023/10/03 10:07*********************//

////最大值算法
//void get_max_common(int* arr, int num,int* max,int* location)
//{
//	*max = *arr;
//	*location = 0;
//
//	for (int i = 1; i < num; i++)
//	{
//		if (*max < *(arr + i))
//		{
//			*max = *(arr + i);
//			*location = i;
//		}
//
//	}
//}
//
//int get_max(int* arr, int left, int right)
//{
//	//left 左下标 right 右下标
//	//首先判断，传入的数组是不是空数组
//	if (arr == NULL)
//		return -1;
//	//当数组中只有一个值的时候
//	if (right - left == 0)
//		return arr[left];
//	//此时数组中只有两个值，直接比较即可
//	if ((right - left) <= 1)
//	{
//		if (arr[left] > arr[right])
//			return arr[left];
//		return arr[right];
//	}
//
//	int middle = (right - left) / 2 + left;
//	int max_left = get_max(arr, left, middle);
//	int max_right = get_max(arr, middle + 1, right);
//
//	if (max_left > max_right)
//		return max_left;
//	return max_right;
//}
//
//void show_arr(const int x[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%-5d ", x[i]);
//	}
//	putchar('\n');
//}
//
//int main()
//{
//	int location = 0;
//	int max = 0;
//
//	int arr[] = { 30,4,200,4,5,2,5,67,8 };
//	
//	int length = sizeof(arr) / 4;
//	
//	printf("arr before sort: ");
//	show_arr(arr, length);
//
//	//get_max_common(arr, length, &max, &location);	
//	//printf("the max of the arr is %d: ", max);
//	//printf("\nthe location is %d: ", location+1);
//
//
//	//int left = partition(arr, 0, length - 1);
//	//quickSort(arr, 0, length - 1);
//	//show_arr(arr, length);
//	//printf("the max of the arr is %d: ", arr[length-1]);
//
//	max = get_max(arr, 0, length - 1);
//	printf("the max of the arr is %d: ", max);
//
//
//
//	return 0;
//}

//*******************2023/10/04 10:26*********************//


//void get_max_common(double* arr, int num,double* max,int* location)
//{
//	*max = *arr;
//	*location = 0;
//
//	for (int i = 1; i < num; i++)
//	{
//		if (*max < *(arr + i))
//		{
//			*max = *(arr + i);
//			*location = i;
//		}
//
//	}
//}


//
//
//int main()
//{
//	double max = 0;
//	int location = 0;
//	double arr[] = { 1.2,2.3,3.3,2.3,1.3,1.8,9.8 };
//	int length = sizeof(arr) / sizeof(double);
//
//	show_arr(arr, length);
//
//	get_max_common(arr, length, &max, &location);
//
//	printf("the max of the arr is %lf: ", max);
//	
//	printf("\nthe location is %d: ", location+1);
//
//	return 0;
//}

//int partion1004(double* arr, int left, int right)
//{
//	if (arr == NULL) return -1;
//
//	double pivot = arr[left];
//
//	while (left<right)
//	{
//		while (left<right&&arr[right]<=pivot)
//		{
//			right--;
//		}
//		arr[left] = arr[right];
//
//		while (left < right && arr[left] >= pivot)
//		{
//			left++;
//		}
//
//		arr[right] = arr[left];
//	}
//
//	arr[left] = pivot;
//
//	return left;
//}
//
//void quicksort1004(double* arr, int left, int right)
//{
//	if (arr == NULL) return;
//
//	if (left < right)
//	{
//		int pivot = partion1004(arr, left, right);
//
//		quicksort1004(arr, left, pivot - 1);
//		quicksort1004(arr, pivot + 1, right);
//	}
//}

//void reverse(double a[], int n)
//{
//	for (int i = 0; i < n / 2; i++)
//	{
//		double t = a[i];
//		a[i] = a[n - i - 1];
//		a[n - i - 1] = t;
//	}
//	return;
//}
//
//
//#define ROW 5
//#define COL 12
//
////two_dimensional
//void show_arr_2D(const double (*x)[COL], int row)
////void show_arr_2D(const double x[][COL], int row)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			printf("%-5g ", *(*(x + i) + j));
//		}
//		putchar('\n');
//	}
//}
//
//void copy_ptr04(double (*target)[COL], const double arr[][COL], int row)
////void copy_ptr04(double target[][COL], const double arr[][COL], int row)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			*(*(target + i) + j) = *(*(arr + i) + j);
//		}
//	}
//	putchar('\n');
//}

//int main()
//{
//	//double max = 0;
//	//int location = 0;
//	//double arr[] = { 1.2,2.3,3.3,2.3,1.3,1.8,9.8 };
//	//int length = sizeof(arr) / sizeof(double);
//
//	//show_arr(arr, length);
//
//	//reverse(arr, length);
//
//	//show_arr(arr, length);
//
//	//quicksort1004(arr, 0, length - 1);
//	//show_arr(arr, length);
//	//printf("in the arr, max-min=%-5g", arr[0] - arr[length - 1]);
//
//	double target[ROW][COL] = { 0 };
//	const double arr[ROW][COL] = 
//	{
//		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
//		{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
//		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
//		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
//		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
//	};
//	show_arr_2D(arr, ROW);
//	copy_ptr04(target, arr, ROW);
//	show_arr_2D(target, ROW);
//
//	return 0;
//}

//int main()
//{
//	double a[N][M] =
//	{
//		{1.0,2.0,3.0,4.0,5.0},
//		{6.0,7.0,8.0,9.0,10.0},
//		{11.0,12.0,13.0,14.0,15.0}
//	};
//	double b[N][M] = { 0 };
//
//	printf("Array a:\n");
//	show_array(N, M, a);
//	
//	printf("Array b:\n");
//	show_array(N, M, b);
//	copy_array(N, M, a, b);
//
//	printf("Copy array a to array b:\n");
//	show_array(N, M, b);
//
//	return 0;
//}


//*******************2023/10/06 9:03*********************//

//void copy_add(int* destination, int* source1, int* source2, int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//
//		*(destination + i) = *(source1 + i) + *(source2 + i);
//	}
//	return;
//
//}
//

//#define length 6
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[] = { 1,2,3,4,5,6 };
//	int arr3[length] = { 0 };
//	//int length = sizeof(arr1) / sizeof(int);
//	show_arr(arr1, length);
//	show_arr(arr2, length);
//
//	copy_add(arr3, arr2, arr1, length);
//	show_arr(arr3, length);
//	return 0;
//}

//#define ROW 3
//#define COL 5
//

//
//void Double_value(int x[][COL], int row)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			*(*(x + i) + j) *= 2;
//		}
//	}
//}
//
//int main()
//{
//	int arr[ROW][COL] =
//	{
//		{1,2,3,4,5},
//		{6,7,8,9,10},
//		{11,12,13,14,15},
//	};
//
//	Show_arr_2D(arr, ROW);
//
//	Double_value(arr, ROW);
//
//	Show_arr_2D(arr, ROW);
//
//	return 0;
//}



//#define ROW 3
//#define COL 5
//
//void Enter_arr_2D(double arr[][COL],int row)
//{
//	printf("Please enter (3*5) numbers:\n");
//
//	for (int i = 0; i < row; i++)
//	{
//		printf("Please enter %d-th row  numbers:", i+1);
//		for (int j = 0; j < COL; j++)
//		{
//			scanf("%lf", (*(arr + i) + j));
//		}
//	}
//
//	putchar('\n');
//}
//
//void Show_arr_2D(const double x[][COL], int row)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			printf("%-5g", *(*(x + i) + j));
//		}
//		putchar('\n');
//	}
//	putchar('\n');
//}
//
//void Mean_arr_2D(double arr[][COL], int row, double* mean_arr,double* mean)
//{
//	double total_row = 0;
//	double total = 0;
//
//	for (int i = 0; i < row; i++)
//	{
//		total_row = 0;
//		for (int j = 0; j < COL; j++)
//		{
//			total_row += *(*(arr + i) + j);
//			total += *(*(arr + i) + j);
//		}
//		
//		*(mean_arr + i) = total_row / COL;
//	}
//
//	*mean = total / (row * COL);
//}
//
//void Get_max_arr_2D(const double(*arr)[COL], int row, double* max)
//{
//	*max = *(*(arr)); //arr[0][0]
//
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			if (*max < *(*(arr + i) + j))
//				*max = *(*(arr + i) + j);
//		}
//	}
//
//}
//
//
//void show_arr(const double x[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%-5g ", x[i]);
//	}
//	putchar('\n');
//}
//
//int main()
//{
//	double arr[ROW][COL] = { 0 };
//
//	double mean_arr[ROW] = { 0 };
//	
//	double mean = { 0 };
//	double max = { 0 };
//
//	//input
//	Enter_arr_2D(arr, ROW);
//	
//	//display
//	Show_arr_2D(arr, ROW);
//	
//	//mean of each row
//	Mean_arr_2D(arr, ROW, mean_arr, &mean);
//	printf("the mean of row is : ");
//	show_arr(mean_arr, ROW);
//	
//	//mean of the (3*5)array
//	printf("the mean of array is: %-5g\n", mean);
//
//	//get max of array
//	Get_max_arr_2D(arr, ROW, &max);
//	printf("the max of array is: %-5g\n", max);
//
//	return 0;
//}
//

//#define ROWS 3
//#define COLS 5
//
//void store(int n, double stuff[])
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("Please enter a number for position %d: ", i + 1);
//		scanf("%lf", &stuff[i]);
//	}
//
//
//}
//void showarr2(int rows, double stuff[][COLS])
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < COLS; j++)
//		{
//
//			printf("%-5g", *(*(stuff + i) + j));
//		}
//		putchar('\n');
//	}
//
//}
//
//double average(int n, const double stuff[])
//{
//	double sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += stuff[i];
//	}
//	return n > 0 ? sum / n : 0.0;
//}
//
//double average2d(int rows, double(*stuff)[COLS])
//{
//	double sum = 0.0;
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < COLS; j++)
//		{
//			sum += *(*(stuff + i) + j);
//		}
//	}
//
//	return sum / (rows * COLS);
//}
//
//double  max2d(int rows, double(*stuff)[COLS])
//{
//	double max = *(*(stuff));
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < COLS; j++)
//		{
//			max = max > *(*(stuff + i) + j) ? max : *(*(stuff + i) + j);
//		}
//	}
//	return max;
//}
//
//int main()
//{
//	double stuff[ROWS][COLS];
//
//	for (int row = 0; row < ROWS; row++)
//	{
//		printf("Please enter %d numbers for %d row\n", COLS, row + 1);
//		store(COLS, stuff[row]);
//	}
//	printf("Array:\n");
//	showarr2(ROWS, stuff);
//
//	for (int row = 0; row < ROWS; row++)
//	{
//		printf("Average for row %d is %g.\n", row + 1, average(COLS, stuff[row]));
//
//	}
//
//	printf("Average is %g.\n", average2d(ROWS, stuff));
//	printf("Maximum is %g.\n", max2d(ROWS, stuff));
//	printf("Done.\n");
//
//
//
//	return 0;
//}

//*******************2023/10/07 22:03*********************//

//void arr_string(char* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("please enter the %d-th character: ", i + 1);
//
//		scanf("%c", (arr + i));
//		while (getchar() != '\n')
//		{
//			continue;
//		}
//	}
//
//}
//
//void show_string(char* arr, int n)
//{
//	printf("enter the characters below: \n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%c ", *(arr + i));
//	}
//}
//
//int main1()
//{
//	int num;
//	char arr[20];
//	printf("Please enter the character numbers: ");
//	scanf("%d", &num);
//	while (getchar()!='\n')
//	{
//		continue;
//	}
//	arr_string(arr, num);
//	show_string(arr, num);
//	return 0;
//}


//#define LEN 10

//void getnchar(char str[], int n)
//{
//	int i = 0;
//	for ( i = 0; i < n - 1; ++i)
//	{
//		str[i] = getchar();
//		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
//			break;
//	}
//	if (i < n - 1)
//	{
//		str[i] = '\0';
//	}
//	else
//	{
//		str[n - 1] = '\0';
//	}
//}

//void getnchar(char str[], int n)
//{
//	int i = 0;
//	while (i < n - 1)
//	{
//		str[i] = getchar();
//		if (isspace(str[i]))
//		{
//			break;
//		}
//		++i;
//	}
//	str[i] = '\0';
//}
//
///*
//   isspace 若判断字符ch为空空格、制表符或换行符，函数返回非零值，否则返回零值。
//*/
//
//int main()
//{
//	char str[LEN];
//
//	printf("Please enter %d characters:\n", LEN - 1);
//	getnchar(str, LEN);
//	printf("Result:\n");
//	puts(str);
//	printf("Done.\n");
//
//	return 0;
//}


//#define LEN 10
//
//char* getword(char* str)
//{
//	int ch;
//	int n = 0;
//	char* pt = str;
//
//	while ((ch = getchar()) != EOF && isspace(ch))
//	{
//		continue;
//	}
//
//	if (ch == EOF)
//	{
//		return NULL;
//	}
//	else
//	{
//		n++;
//		*str++ = ch;
//	}
//	while ((ch=getchar())!=EOF&&!isspace(ch)&&(n<LEN-1))
//	{
//		*str++ = ch;
//		n++;
//	}
//	*str = '\0';
//
//	if (ch == EOF)
//	{
//		return NULL;
//	}
//	else
//	{
//		while ((getchar())!='\n')
//		{
//			continue;
//		}
//		return pt;
//
//	}
//
//}
//
//int main(int argc,char *argv[])
//{
//	char input[LEN];
//
//	printf("Please enter a word (EOF to quit):\n");
//
//	while (getword(input) != NULL)
//	{
//		printf("Result:\n");
//		puts(input);
//		printf("You can enter a word again (EOF to quit):\n");
//	}
//
//	printf("Done.\n");
//	return 0;
//}


//*******************2023/10/09 8:57*********************//

//string.c----使用字符串与用户交互
//#define MSG "You must have many talents.Tell me some."    //一个字符串常量
//
//#define LIM 5
//#define LINELEN 81  //最大字符串长度+1
//
//int main()
//{
//	char name[LINELEN];
//	char talents[LINELEN];
//	int i;
//	const char m1[40] = "Limits yourself to one line's worth.";   //初始化一个大小已经确定的char 数组
//	const char m2[] = "If you can't think of anything,fake it.";  //让编译七计算数组的大小
//	const char* m3 = "\nEnough about me - what's a your name?";
//	const char* mytal[LIM] = { "Adding numbers swiftly",          //初始化一个字符串指针数组,数组存放的是指针元素，指针指向char类型字符串
//								"Multiplying accurately","Stashing data",//*mytal[0]=='A', *mytal[1]=='M',
//								"Following instructions to the letter",
//								"Understanding the C language" };
//
//	printf("Hi! I'm Clyde the computer. I have many talents.\n");
//	printf("Let me tell you some of them.\n");
//	puts("what were they? Ah,yes,here's a partial list.");
//	for (i = 0; i < LIM; i++)
//	{
//		//puts(mytal[i]);   //打印计算机功能的列表
//		puts(*(mytal + i));   //打印计算机功能的列表
//	}
//
//	puts(m3);
//	gets_s(name);
//	
//	printf("Well,%s,%s\n", name, MSG);
//	printf("%s\n%s\n", m1, m2);
//
//	gets_s(talents);
//
//	puts("Let's a see if I've got that list:");
//
//	puts(talents);
//
//	printf("Thanks for the information,%s.\n", name);
//
//	return 0;
//
//}

int main()
{
	const char* mesq = "Don't be a fool";
	const char* copy;

	copy = mesq;

	printf("%s\n", copy);
	printf("mesq =%s;&mesq=%p;value=%p\n", mesq, &mesq, mesq);
	printf("copy =%s;&copy=%p;value=%p\n", copy, &copy, copy);


	return 0;
}



