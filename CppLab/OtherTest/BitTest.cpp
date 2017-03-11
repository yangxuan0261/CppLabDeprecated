#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;



// ��������
void test1()
{
	for (int i = 0; i < 100; ++i)
	{
		if (i & 1)
			printf("%d ", i);
	}

}

// ��������
void test2()
{
	auto func = [](int& a, int& b)
	{
		if (a != b)
		{
			a ^= b;
			b ^= a;
			a ^= b;
		}
	};

	int a = 10;
	int b = 20;
	printf("--- before a:%d, b:%d\n", a, b);
	func(a, b);
	printf("--- after a:%d, b:%d\n", a, b);
}

struct Data1
{
	int a;
	int b;
	int c;
};

struct Data2
{
	int a : 16; //��1~16λ
	int : 14; //��17~30λ,14λ����ʹ��
	int b : 10; //����һ��Ԫ��ʼ��
	int c : 16;
};

struct Data3
{
	int a : 2;
	int b : 2;
};

struct Date4 {
	unsigned short nWeekDay : 3;    // 0..7   (3 bits)
	unsigned short nMonthDay : 6;    // 0..31  (6 bits)
	unsigned short nMonth : 5;    // 0..12  (5 bits)
	unsigned short nYear : 8;    // 0..100 (8 bits)
};

struct Date5 {
	unsigned nWeekDay : 3;    // 0..7   (3 bits)
	unsigned nMonthDay : 6;    // 0..31  (6 bits)
	unsigned : 0;    // Force alignment to next boundary.
	unsigned nMonth : 5;    // 0..12  (5 bits)
	unsigned nYear : 8;    // 0..100 (8 bits)
};

struct Date6 {
	unsigned nWeekDay : 1;    
	unsigned nYear : 1;   
};

void testBitFields()
{
	Data1 d1;
	Data2 d2;
	Data3 d3;
	Date4 d4;
	Date5 d5;
	Date6 d6;
	int size1 = sizeof(d1);	//12�ֽ�
	int size2 = sizeof(d2); //8�ֽ�
	int size3 = sizeof(d3); //4�ֽ�
	int size4 = sizeof(d4); 
	int size5 = sizeof(d5); 
	int size6 = sizeof(d6); 
	printf("size1:%d, size2:%d, size3:%d\n", size1, size2, size3);
	printf("size4:%d\n", size4);
	printf("size5:%d\n", size5);
	printf("size6:%d\n", size6);
}

//int main()
//{
//	//test1();
//	//test2();
//	testBitFields();
//	
//	system("pause");
//	return 0;
//}
