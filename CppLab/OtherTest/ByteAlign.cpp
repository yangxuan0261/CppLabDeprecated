//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <functional>
///*
//�� ʹ��αָ��#pragma pack (n)��C������������n���ֽڶ��롣
//�� ʹ��αָ��#pragma pack ()��ȡ���Զ����ֽڶ��뷽ʽ��
//*/
//
////------------------------------------- test1 -----------------------------
//
//typedef void(*CustFunc)(void);
//typedef std::function<void(void)> CustFunc2;
//
//class Base1
//{
//public:
//	virtual void Func1(){ printf("--- Base1 Func1()\n"); }
//};
//
//class Base2
//{
//public:
//	 virtual void Func3(){ printf("--- Base2 Func3()\n"); }
//};
//
//class MyStruct1 : public Base1 , public Base2
//{
//public:
//	void Func2(){ printf("--- MyStruct1 Func2()\n"); };
//	void Func3(){ printf("--- MyStruct1 Func3()\n"); };
//	void Func4(){ printf("--- MyStruct1 Func4()\n"); };
//
//public:
//	//char x1;
//	//short x2;
//	//float x3;
//	//int x4;
//
//	int x1;
//	short x2;
//	int x5;
//	////short x6;
//	////short x7;
//	double x3;
//	int x4;
//	//int x9;
//};
//
//void testByteAlign()
//{
//	printf("--- MyStruct1 size:%d\n", sizeof(MyStruct1));
//
//	MyStruct1 ms;
//	//ms.x1 = 'w';
//	//ms.x2 = 123;
//	//ms.x3 = 456.f;
//	//ms.x4 = 789;
//
//	ms.x1 = 12;
//	ms.x2 = 34;
//	ms.x5 = 44;
//	ms.x3 = 56;
//	ms.x4 = 78;
//
//	//int x1 = (int)*((short*)(&ms) + 0);
//	short x2 = (short)*((short*)(&ms) + 2);
//	int x5 = (int)*((short*)(&ms) + 4);
//	double x3 = (double)*((short*)(&ms) + 8);
//	int x4 = (int)*((short*)(&ms) + 12);
//
//
//	printf("--- ms:0x%x\n", &ms);
//	//printf("--- x1:0x%x, val=%d\n", &ms.x1, x1);
//	printf("--- x2:0x%x, val=%d\n", &ms.x2, (int)x2);
//	printf("--- x5:0x%x, val=%d\n", &ms.x5, x5);
//	printf("--- x3:0x%x, val=%lf\n", &ms.x3, x3);
//	printf("--- x4:0x%x, val=%d\n", &ms.x4, x4);
//
//	void* voidPtr = (short*)(&ms) + 8;
//	printf("--- voidPtr:0x%x\n", voidPtr);
//
//	double dstNum = (double)*((short*)(&ms) + 12);
//	printf("--- dstNum:%lf\n", dstNum);
//
//	//void* vtPtr = (int*)(&ms);
//	//CustFunc cf = (CustFunc)*((int*)*(int*)(&ms));
//	//printf("--- cf:0x%x\n", vtPtr);
//	//cf();
//
//	//CustFunc2 cf2 = std::bind(&MyStruct1::Func2, &ms);
//	//printf("--- cf2:0x%x\n", cf2);
//
//}
//
////------------------------------------- test2 -----------------------------
//struct BB
//{
//	int id;             //[0]....[3]
//	double weight;      //[8].....[15]������������
//	short height;      //[16]..[19],�ܳ�ҪΪ����������,����[20]...[23]��������
//};
//
//struct AA
//{
//	char name[2];     //[0],[1]
//	int  id;         //[4]...[7]��������������������
//	float score;     //[8]....[11]��������
//	short grade;    //[12],[13]����������������
//	BB b;             //[16]......[47]��������������������
//};
//
//void testByteAlign2()
//{
//	printf("--- sizeAA:%d, sizeBB:%d\n", sizeof(AA), sizeof(BB)); //40, 24
//}
//
////------------------------------------- test3 -----------------------------
//struct stu{
//	////4 + 10 + 1 + 1(���뵽16��(int)4�ı���)����С��16
//	//int length;//[0-3]
//	//char name[10];//[4-13]
//	//char sex;//[14]
//
//	//1 + 3(���뵽4��(int)4�ı���) + 4 + 10 + 2(���뵽20����(int)4�ı���)����С��20
//	char sex; //[0]
//	int length;//[4-7]
//	char name[10];//[8-17]
//};
//
//void testByteAlign3()
//{
//	printf("--- stu:%d\n", sizeof(stu)); //16
//}
//
////------------------------------------- test4 -----------------------------
////ȫ��������һ��
//class Concrete0 
//{
//private:
//	int val;
//	char c1;
//	char c2;
//	char c3;
//	char c4;
//};
//
////�ֿ��ţ�ͨ���̳м������б���
//class Concrete1
//{
//private:
//	int val;
//	char c1;
//	char c2;
//};
//
//class Concrete2 : public Concrete1
//{
//private:
//	char c3;
//};
//
//class Concrete3 : public Concrete2
//{
//private:
//	char c4;
//};
//
//void testByteAlign4()
//{
//	printf("--- size of Concrete0:%d\n", sizeof(Concrete0)); //8
//	printf("--- size of Concrete3:%d\n", sizeof(Concrete3)); //16
//	//����һ���Ĵ�С
//	/*
//	������
//	Concrete0 : 4 + 1 + 1 + 1 + 1(����) = 8
//	Concrete3 : 4 + 1 + 1 + 2(����) + 1 + 3(����) + 1 + 3(����) = 16
//	*/
//}
//
//int main()
//{
//	//testByteAlign();
//	testByteAlign2();
//	//testByteAlign3();
//	//testByteAlign4();
//
//	system("pause");
//	return 0;
//}
//
///*
//1�����ֽڵı�������ǰ�棬С�ķź���
//2���ֽڴ�С��ͬ�ı�����һ�����ڰڷţ����� int,int,short,bool, ��Ҫ int,bool,int, short
//*/