//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//
//class Base
//{
//public:
//	Base() { printf("--- Base construce\n"); }
//
//	//��������麯������������ָ��ָ��֮�����ʱ��delete����ָ�룬�޷����õ������������������̬�ԣ�
//	//~Base() { printf("--- Base deconstruce\n"); } 
//	virtual ~Base() { printf("--- Base virtual deconstruce\n"); }
//};
//
//class Dev : public Base
//{
//public:
//	Dev() { printf("--- Dev construce\n"); }
//	//~Dev() { printf("--- Dev deconstruce\n"); }
//	virtual ~Dev() { printf("--- Dev virtual deconstruce\n"); }
//};
//
//
//
//
//void testDeconstruce()
//{
//	Dev* d = new Dev;
//	delete d;
//	printf("\n");
//
//	Base* d2 = new Dev;
//	delete d2;
//	printf("\n");
//}
//
//int main()
//{
//	testDeconstruce();
//
//	system("pause");
//	return 0;
//}