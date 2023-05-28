//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string.h>
//using namespace std;
//
////建筑物类
//class Building
//{
//	friend void goodgay(Building* building);
//public:
//	Building()
//	{
//		m_SittingRoom = "客厅";
//		m_BedRoom = "卧室";
//	}
//
//public:
//	string m_SittingRoom;  //客厅
//
//private:
//	string m_BedRoom;  //卧室
//};
//
////全局函数
//void goodgay(Building* building)
//{
//	cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;
//	cout << "好基友全局函数 正在访问：" << building->m_BedRoom << endl;
//}
//
//void test()
//{
//	Building building;
//	goodgay(& building);
//}
//
//int main1()
//{
//	test();
//	return 0;
//}