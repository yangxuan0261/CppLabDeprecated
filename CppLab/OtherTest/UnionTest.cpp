#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace UnionTest {


	void test222()
	{
		union testasd
		{
			char mark;
			long num;
			float score;
		}a;

		// cout<<a<<endl; // wrong
		a.mark = 'b';
		cout << a.mark << endl; // ���'b'
		cout << a.num << endl; // 98 �ַ�'b'��ACSIIֵ
		cout << a.score << endl; // �������ֵ

		a.num = 10;
		cout << a.mark << endl; // ������� �ǳ���лsuxinͬѧ��ָ��
		cout << a.num << endl; // ���10
		cout << a.score << endl; // �������ֵ

		a.score = 10.01;
		cout << a.mark << endl; // �����
		cout << a.num << endl; // �������ֵ
		cout << a.score << endl; // ���10
	}

	void testUnion()
	{
		union UBoy {
			int age;
			short num;
		} bo;

		bo.age = 5;

		struct SGirl
		{
			int age;
			short num;
		} gi;

		printf("size u:%d\n", sizeof(bo));
		printf("size u:%d\n", sizeof(gi));
		printf("size u:%d\n", bo.age);
	}

	void testLittleOrBigEndian()
	{
		union w
		{
			int a;
			char b;
		} c;
		c.a = 1;
		printf("ptr address:%x\n", &c.b);
		if (c.b == 1)
			printf("is little endian\n");
		else
			printf("is big endian\n");
	}
};

//int main()
//{
//	//testUnion();
//	//test222();
//	UnionTest::testLittleOrBigEndian();
//	system("pause");
//	return 0;
//}