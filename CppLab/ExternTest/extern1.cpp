//// extern.cpp : Defines the entry point for the console application.
////
//
//#include "stdlib.h"
//#include <iostream>
//using namespace std;
//
////ͬһ�ļ��� ��������ǰ�� ʵ���ں�
//extern int i;  //���ﲻ��extern���뱨��������� int i = 1�ض���
//extern void func(); //����Ӳ��Ӷ�����ν��ֻҪ������ʵ�־�ok
//
//int main()//typedef wchar_t     _TCHAR;#define _tmain      wmain
//{
//	func();
//	system("pause");
//	return 0;
//}
//
//
//int i = 1;
//void func()
//{
//	i++;
//	cout << "i = " << i << endl;
//}
//
////��������б���i�ͺ���func���ļ�ĩβ���壬
////���Ա�����Ҫʹ��extern�ؼ��ָ��߱�������
////�����ڱ�ĵط����塣
////extern int i��ԭ����Ϊextern i�Ϳ��ԣ�
////���������������ϸ����ȷʵӦ�ã�
////�����������֪��i��ʲô���͵����ݣ�
////����ô���ж�i = 0�Ƿ���һ����ȷ�ĸ�ֵ����أ�