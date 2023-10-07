#define _CRT_SECURE_NO_WARNINGS 1
#include"function.h"
#include"SqList.h"

void jolly()
{
	printf("For he's a jolly good fellow!\n");
}

void deny()
{
	printf("Which nobody can deny!\n");
}

void br()
{
	printf("Brazil,Russia,");
}
void ic()
{
	printf("India,China\n");
}

void Smile()
{
	printf("Smile!");
	
}


//*******************2023/7/31 19:12*********************//
void one_three()
{
	printf("one\n");
	two();
	printf("three\n");
}

void two()
{
	printf("two\n");
}


void PrintCube(double input)
{
	printf("the cube of number:%g\n", (input * input * input));
}

void  Temperatures(const double Fahrenheit)
{
	double Celsius_temperature;
	double Kelvin_temperature;
	const double f_val = 32.0;
	const double k_val = 273.16;
	Celsius_temperature = 5.0 / 9.0 * (Fahrenheit - f_val);

	Kelvin_temperature = Celsius_temperature + k_val;
	printf("%.2f (F) equal to %.2f (C) ,also equal to %.2f (K) \n", Fahrenheit, Celsius_temperature, Kelvin_temperature);
}



void output_0826(float a, float b) {

	printf("(%g-%g)/(%g*%g)", a, b, a, b);

	printf("=%g\n", (a - b) / (a * b));

	printf("You can enter again(q to quit):");

}


//*******************2023/9/10 17:02*********************//

int Menu_salary_0910() {
	int choice = 0;
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $8.75/hr                                2) $9.33/hr\n");
	printf("3) $10.00/hr                               4) $11.20/hr\n");
	printf("5) quit\n");
	printf("*****************************************************************\n");

	printf("Please enter the number:(1、2、3、4 or 5):");
	while (scanf("%d", &choice)!=1&&choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5) {
		while ((getchar())!='\n'){
			continue;
		}

		printf("Please re-enter the number:(1、2、3、4 or 5):");
	}

	return choice;
}



//*******************2023/9/11 20:55*********************//

#define EXTRA_HOUR 1.5
#define BASE_TAX 0.15
#define EXTRA_TAX 0.20
#define EXCEED_TAX 0.25

double Chose_salary(const int* choice) {
	
	double base_salary = 0;
	
	switch (*choice)
	{
	case 1: {
		base_salary = 8.75;
		break;
	}
	case 2: {
		base_salary = 9.33;
		break;
	}
	case 3: {
		base_salary = 10.00;
		break;
	}
	case 4: {
		base_salary = 11.20;
		break;
	}
	case 5: {
		printf("quit\n");
		break;
	}
	default:
		break;
	}

	return base_salary;

}


double Work_time() {

	double hours;

	printf("Enter the working hours a week:");
	while (scanf("%lf", &hours) != 1 || (hours < 0)) {

		while ((getchar() != '\n')) {
			continue;
		}

		printf("Please enter a number(>=0):");

	}

	return hours;

}


void Salary_statistic(const double* base_salary, const double* hours) {

	double tax, taxed_salary;
	double salary;

	salary = ((*hours > 40) ? ((*hours - 40) * 1.5 + 40) : *hours) * *base_salary;

	if (salary <= 300) {

		tax = salary * BASE_TAX;

	}
	else if (salary <= 450) {
		tax = 300 * BASE_TAX + (salary - 300) * EXTRA_TAX;
	}
	else {
		tax = 300 * BASE_TAX + 150 * EXTRA_TAX + (salary - 450) * EXCEED_TAX;
	}

	taxed_salary = salary - tax;

	printf("salary(before taxed):$%g\n", salary);
	printf("tax:$%g\n", tax);
	printf("salary(after taxed):$%g\n", taxed_salary);
}


//*******************2023/9/13 22:11*********************//
int Show_menu0913() {

	int choice = 0;

	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) 单身---17850$按15%计，超出部分按28%计\n");
	printf("2) 户主---17850$按15%计，超出部分按28%计\n");
	printf("3) 已婚、共有---17850$按15%计，超出部分按28%计\n");
	printf("4) 已婚、离异---17850$按15%计，超出部分按28%计\n");
	printf("0) quit\n");	
	printf("*****************************************************************\n");

	printf("Please enter the choice(1、2、3、4 or 0 to quit):");
	
	while ((scanf("%d", &choice)) != 1 || (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4)) {

		while ((getchar()) != '\n') {
			continue;
		}
		printf("enter error!Please re-enter the choice(1、2、3、4 or 0 to quit):");

	}

	return choice;
}


double Tax_line(const int* choice) {

	double Tax_line = 0;

	switch (*choice)
	{
	case 1: {
		Tax_line =17850;
		break;
	}
	case 2: {
		Tax_line = 23900;
		break;
	}
	case 3: {
		Tax_line = 29750;
		break;
	}
	case 4: {
		Tax_line = 14875;
		break;
	}

	default:
		break;
	}

	return Tax_line;

}


double Salary_input() {

	double salary;

	printf("Please enter your wage $(>=0): ");


	while (scanf("%lf", &salary) != 1 || (salary < 0)) {

		while ((getchar() != '\n')) {
			continue;
		}

		printf("Please enter the earning(>=0):");

	}

	return salary;

}


void Pay_tax(const double* salary, const double* tax_line) {

	double tax;

	tax = ( (*salary > *tax_line) ? ( (*salary - *tax_line) * 0.28 + *tax_line * 0.15) : *salary * 0.15 );

	printf("salary(before taxed):$%g\n", *salary);
	printf("tax:$%g\n", tax);
	printf("salary(after taxed):$%g\n", (*salary - tax));
}



//*******************2023/9/14 22:11*********************//
void Show_menu0914() {

	printf("*****************************************************************\n");
	printf("**************   sales below list of items   *******************:\n");
	printf("\n");
	printf("a) 洋蓟---2.05$/pound                       b) 甜菜---1.15$/pound\n");
	printf("c) 胡萝卜---1.09$/pound                     q) quit\n");
	printf("\n*****************************************************************\n");


}



//*******************2023/9/21 20:19*********************//
int BF(char* S, char* t)
{
	//主串的长度
	int lens = strlen(S);

	//子串的长度
	int lent = strlen(t);

	//定义i,j分别作为主串和子串的指示器
	int i = 0; int j = 0;
	
	//当主串和子串没有匹配完全时执行该while语句
	while (i < lens && j < lent) {
		
		//如果此时主串和子串的元素匹配成功
		if (S[i] == t[j])
		{
			//就让他们指向后一个元素继续进行匹配操作
			i++;
			j++;
		}
		else 
		{
			//如果匹配不成功的话就要进行回溯操作
			//主串回溯，子串的j指向0
			i = i - j + 1;
			j = 0;
		}

	}

	//如果此时的j大于等于子串的长度说明已经匹配成功了
	if (j >= lent) {
		//返回匹配成功的位置
		//因为我们此时是从下标0开始的
		//所以我们往后加了一个1返回的是子串在主串的位置
		return i - lent + 1;
	}

	else {

		return 0;
	}

}


//获取next数组
void GetNext(char* sub, int* next)
{
	int lensub = strlen(sub);
	next[0] = -1;
	next[1] = 0;

	//子串下一项的i值
	int i = 2;
	
	//前一项即next[1]对应的k值，即回退的下标
	int k = 0;

	//next数组还没遍历完
	while (i<lensub)
	{
		if (k = -1 || sub[k] == sub[i - 1])
		{
			next[i] = k + 1;
			i++;
			k++;
		}
		else
		{
			k = next[k];

		}



	}

}


//KMP算法
int KMP(char* str, char* sub, int pos)
{
	//判断主串和子串是否为空串
	assert(str != NULL && sub != NULL);
	//主串长度
	int lenstr = strlen(str);
	//子串长度
	int lensub = strlen(sub);

	if (lenstr == 0 || lensub == 0)
	{
		return -1;
	}

	//判断寻找的位置是否合理
	if (pos < 0 || pos >= lenstr)
	{
		return -1;
	}

	//在堆区开辟一个next数组
	int* next = (int*)malloc(sizeof(int) * lensub);

	//断言判断内存是否申请成功
	assert(next != NULL);

	//获取next数组
	GetNext(sub, next);


}


//*******************2023/9/22 17:05*********************//

//如果scanf函数没有成功读取输入，就会将其留在输入队列中。
//这里，输入实际上是字符流这一事实就派上了用场，可以使用getchar()来逐个字符地
//读取输入。

//确认输入一个整数
int get_int(void)
{
	int input;
	char ch;
	while (scanf("%d", &input) != 1)
	{
		while ((ch=getchar())!='\n')
		{
			putchar(ch);    //剔除错误的输入
		}
		printf(" is not an integer.\nPlease enter an ");
		printf(" integer value,such as 25,-178,or 3: ");


	}
	return input;
}

//检查输入是否在阈值区间内，如果大于，则返回true(表示输入无效)
//确认范围的上下界是否有效
bool bad_Iimits(int begin, int end, int low, int high)
{
	bool not_good = false;
	if (begin > end)
	{
		printf("%d isn't smaller than %d.\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)
	{
		printf("Value must be %d or greater.\n", low);
		not_good = true;
	}
	if (begin > high || end > high)
	{
		printf("Value must be %d or less.\n",high);
		not_good = true;
	}

	return not_good;
}


//计算从a 到 b 之间的整数的平方和
double sum_squares(int a, int b)
{
	double total = 0;
	int i;
	for (i = a; i <= b; i++)
	{
		total += i * i;
	}
	return total;
}

//*******************2023/10/03 10:07*********************//

//快速排序算法通常用于对数组进行排序，而不是用于查找最值。
//它的主要目的是将数组元素重新排列，以便按照升序或降序的顺序进行排列。
//虽然在排序过程中你可以获得数组中的最小值和最大值，但是快速排序不会直接返回它们在原始数组中的位置。
//如果你想要查找数组中的最值并且需要知道它们在原始数组中的位置，你可以考虑使用其他算法，
//例如线性查找或者改进的查找算法，这些算法可以同时找到最值和其在原始数组中的位置。
//不过，它们的时间复杂度通常较高，因此在大型数据集上可能不如快速排序等排序算法高效。


int partition(int* arr, int left, int right)
{

	int pivot = arr[left]; //选取第一个为基准元素

	while (left < right)
	{
		/* 先从右往左移动，直到遇见小于 pivot 的元素*/
		while (left < right && arr[right] >= pivot)
		{
			right--;
		}
		arr[left] = arr[right];  //记录小于pivot的值

		while (left < right && arr[left] <= pivot)
		{
			left++;
		}
		arr[right] = arr[left];  //记录大于 pivot 的值

	}

	arr[left] = pivot;           //记录基准元素当前指针指向的区域

	return left;                 //返回基准元素的索引
}


void quickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		//把数组分块
		int pivot = partition(arr, left, right);

		//基准元素左边递归
		quickSort(arr, left, pivot - 1);

		//基准元素右边递归
		quickSort(arr, pivot + 1, right);

	}
}

//*******************2023/10/03 23:50*********************//
//
//void show_array(int n, int m, double x[N][M])
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			printf("%-5g", x[i][j]);
//		}
//		putchar('\n');
//	}
//}
//
//void copy_array(int n, int m, double a[N][M], double b[N][M])
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			b[i][j] = a[i][j];
//		}
//	}
//}
