#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Student
{
public:
    void setname(const char *name);
    void setage(int age);
    void setscore(float score);
    void show();
    void printThis();

private:
    const char *name;
    int age;
    float score;
};

//this �� const ָ�룬����ֵ�ǲ��ܱ��޸ĵģ�һ����ͼ�޸ĸ�ָ��Ĳ������縳ֵ���������ݼ��ȶ��ǲ�����ġ�
//this ֻ���ڳ�Ա�����ڲ�ʹ�ã����������ط�û�����壬Ҳ�ǷǷ��ġ�
//ֻ�е����󱻴����� this �������壬��˲����� static ��Ա������ʹ�ã������ὲ�� static ��Ա����

void Student::setname(const char *name)
{
    this->name = name;
}

void Student::setage(int age)
{
    this->age = age;
}

void Student::setscore(float score)
{
    this->score = score;
}

void Student::show()
{
    cout<<this->name<<"��������"<<this->age<<"���ɼ���"<<this->score<<endl;
}

void Student::printThis() 
{
    cout << this << endl;
}

int main()
{
    Student *pstu = new Student;
    pstu -> setname("�");
    pstu -> setage(16);
    pstu -> setscore(96.5);
    pstu -> show();

    Student* pstu1 = new Student;
    pstu1->printThis();
    cout << pstu1 << endl;
    Student* pstu2 = new Student;
    pstu2->printThis();
    cout << pstu2 << endl;


    return 0;
}
