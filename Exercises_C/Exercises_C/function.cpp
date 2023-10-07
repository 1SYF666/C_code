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

	printf("Please enter the number:(1��2��3��4 or 5):");
	while (scanf("%d", &choice)!=1&&choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5) {
		while ((getchar())!='\n'){
			continue;
		}

		printf("Please re-enter the number:(1��2��3��4 or 5):");
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
	printf("1) ����---17850$��15%�ƣ��������ְ�28%��\n");
	printf("2) ����---17850$��15%�ƣ��������ְ�28%��\n");
	printf("3) �ѻ顢����---17850$��15%�ƣ��������ְ�28%��\n");
	printf("4) �ѻ顢����---17850$��15%�ƣ��������ְ�28%��\n");
	printf("0) quit\n");	
	printf("*****************************************************************\n");

	printf("Please enter the choice(1��2��3��4 or 0 to quit):");
	
	while ((scanf("%d", &choice)) != 1 || (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4)) {

		while ((getchar()) != '\n') {
			continue;
		}
		printf("enter error!Please re-enter the choice(1��2��3��4 or 0 to quit):");

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
	printf("a) ��---2.05$/pound                       b) ���---1.15$/pound\n");
	printf("c) ���ܲ�---1.09$/pound                     q) quit\n");
	printf("\n*****************************************************************\n");


}



//*******************2023/9/21 20:19*********************//
int BF(char* S, char* t)
{
	//�����ĳ���
	int lens = strlen(S);

	//�Ӵ��ĳ���
	int lent = strlen(t);

	//����i,j�ֱ���Ϊ�������Ӵ���ָʾ��
	int i = 0; int j = 0;
	
	//���������Ӵ�û��ƥ����ȫʱִ�и�while���
	while (i < lens && j < lent) {
		
		//�����ʱ�������Ӵ���Ԫ��ƥ��ɹ�
		if (S[i] == t[j])
		{
			//��������ָ���һ��Ԫ�ؼ�������ƥ�����
			i++;
			j++;
		}
		else 
		{
			//���ƥ�䲻�ɹ��Ļ���Ҫ���л��ݲ���
			//�������ݣ��Ӵ���jָ��0
			i = i - j + 1;
			j = 0;
		}

	}

	//�����ʱ��j���ڵ����Ӵ��ĳ���˵���Ѿ�ƥ��ɹ���
	if (j >= lent) {
		//����ƥ��ɹ���λ��
		//��Ϊ���Ǵ�ʱ�Ǵ��±�0��ʼ��
		//���������������һ��1���ص����Ӵ���������λ��
		return i - lent + 1;
	}

	else {

		return 0;
	}

}


//��ȡnext����
void GetNext(char* sub, int* next)
{
	int lensub = strlen(sub);
	next[0] = -1;
	next[1] = 0;

	//�Ӵ���һ���iֵ
	int i = 2;
	
	//ǰһ�next[1]��Ӧ��kֵ�������˵��±�
	int k = 0;

	//next���黹û������
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


//KMP�㷨
int KMP(char* str, char* sub, int pos)
{
	//�ж��������Ӵ��Ƿ�Ϊ�մ�
	assert(str != NULL && sub != NULL);
	//��������
	int lenstr = strlen(str);
	//�Ӵ�����
	int lensub = strlen(sub);

	if (lenstr == 0 || lensub == 0)
	{
		return -1;
	}

	//�ж�Ѱ�ҵ�λ���Ƿ����
	if (pos < 0 || pos >= lenstr)
	{
		return -1;
	}

	//�ڶ�������һ��next����
	int* next = (int*)malloc(sizeof(int) * lensub);

	//�����ж��ڴ��Ƿ�����ɹ�
	assert(next != NULL);

	//��ȡnext����
	GetNext(sub, next);


}


//*******************2023/9/22 17:05*********************//

//���scanf����û�гɹ���ȡ���룬�ͻὫ��������������С�
//�������ʵ�������ַ�����һ��ʵ���������ó�������ʹ��getchar()������ַ���
//��ȡ���롣

//ȷ������һ������
int get_int(void)
{
	int input;
	char ch;
	while (scanf("%d", &input) != 1)
	{
		while ((ch=getchar())!='\n')
		{
			putchar(ch);    //�޳����������
		}
		printf(" is not an integer.\nPlease enter an ");
		printf(" integer value,such as 25,-178,or 3: ");


	}
	return input;
}

//��������Ƿ�����ֵ�����ڣ�������ڣ��򷵻�true(��ʾ������Ч)
//ȷ�Ϸ�Χ�����½��Ƿ���Ч
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


//�����a �� b ֮���������ƽ����
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

//���������㷨ͨ�����ڶ�����������򣬶��������ڲ�����ֵ��
//������ҪĿ���ǽ�����Ԫ���������У��Ա㰴����������˳��������С�
//��Ȼ���������������Ի�������е���Сֵ�����ֵ�����ǿ������򲻻�ֱ�ӷ���������ԭʼ�����е�λ�á�
//�������Ҫ���������е���ֵ������Ҫ֪��������ԭʼ�����е�λ�ã�����Կ���ʹ�������㷨��
//�������Բ��һ��߸Ľ��Ĳ����㷨����Щ�㷨����ͬʱ�ҵ���ֵ������ԭʼ�����е�λ�á�
//���������ǵ�ʱ�临�Ӷ�ͨ���ϸߣ�����ڴ������ݼ��Ͽ��ܲ����������������㷨��Ч��


int partition(int* arr, int left, int right)
{

	int pivot = arr[left]; //ѡȡ��һ��Ϊ��׼Ԫ��

	while (left < right)
	{
		/* �ȴ��������ƶ���ֱ������С�� pivot ��Ԫ��*/
		while (left < right && arr[right] >= pivot)
		{
			right--;
		}
		arr[left] = arr[right];  //��¼С��pivot��ֵ

		while (left < right && arr[left] <= pivot)
		{
			left++;
		}
		arr[right] = arr[left];  //��¼���� pivot ��ֵ

	}

	arr[left] = pivot;           //��¼��׼Ԫ�ص�ǰָ��ָ�������

	return left;                 //���ػ�׼Ԫ�ص�����
}


void quickSort(int* arr, int left, int right)
{
	if (left < right)
	{
		//������ֿ�
		int pivot = partition(arr, left, right);

		//��׼Ԫ����ߵݹ�
		quickSort(arr, left, pivot - 1);

		//��׼Ԫ���ұߵݹ�
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
