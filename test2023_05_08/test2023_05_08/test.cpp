#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//����
//1.#define �곣��
//2.const���εı���
#define DAY 7
int main()
{
	//������
	//˫����
	//������Ĭ��С����˫���ȣ���׺��f�Ǳ�������ΪС���ǵ�����
	float f1 = 3.14f;
	double d1 = 3.14;
	int a = 10;
	float f2 = 3e2;
	float f3 = 3e-2;
	const int month = 12;
	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;
	cout << "f3=" << f3 << endl;
	cout << "d1=" << d1 << endl;
	cout << "hello world C++" << endl;
	cout << "a = " << a << endl;
	cout << "һ��һ����" << month << "��" << endl;
	system("pause");
	return 0;
}
