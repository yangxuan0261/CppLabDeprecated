//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//
//struct BB
//{
//	int id;             //[0]....[3]
//	double weight;      //[8].....[15]������������ԭ��
//	short height;      //[16]..[19],�ܳ�ҪΪ����������,����[20]...[23]����������ԭ��
//};
//
//struct AA
//{
//	char name[2];     //[0],[1]
//	int  id;         //[4]...[7]��������������������ԭ��
//	float score;     //[8]....[11]��������
//	short grade;    //[12],[13]����������������
//	BB b;             //[16]......[47]��������������������ԭ��
//};
//
////�ֽڶ������
//void testSizeof2()
//{
//	printf("--- sizeAA:%d, sizeBB:%d\n", sizeof(AA), sizeof(BB)); //AA:40 BB:24
//}
//
//void testSizeof()
//{
//	//ǰ�ᶼ��32λ����������
//
//	int size = 0;
//	size = sizeof(char);
//	printf("--- sizeof int = %d\n", size); //1
//	size = sizeof(bool);
//	printf("--- sizeof bool = %d\n", size);//1
//	size = sizeof(short);
//	printf("--- sizeof short = %d\n", size);//2
//	size = sizeof(int);
//	printf("--- sizeof int = %d\n", size);//4
//	size = sizeof(long);
//	printf("--- sizeof long = %d\n", size);//4
//	size = sizeof(long long);
//	printf("--- sizeof long long = %d\n", size);//8
//	size = sizeof(float);
//	printf("--- sizeof float = %d\n", size);//4
//	size = sizeof(double);
//	printf("--- sizeof double = %d\n", size);//8
//
//	printf("\n");
//	int arrInt[10];
//	size = sizeof(arrInt);
//	printf("--- sizeof arrInt[10] = %d\n", size);//40
//
//	int arrInt2[] = { 1, 2, 3, 4, 5 };
//	size = sizeof(arrInt2);
//	printf("--- sizeof arrInt2[] = %d\n", size);//20
//
//	int* pInt = arrInt2;
//	size = sizeof(pInt);
//	printf("--- sizeof pInt = %d\n", size);//4
//
//	//string ������ ,_Myres,_Mysize,_Alval,_Myfirstiter �ȳ�Ա���� �� һ�� char*ָ��ָ���ַ�������
//	//����string ���������۶೤��sizeof(std::string)��С�������
//	std::string str("321sdfsdfsfsdfsdssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssfsdf");
//	str.length();
//	size = sizeof(str);
//	printf("--- sizeof str = %d\n", size);//28
//
//}
//
//class Door
//{
//public:
//	static int g; //g����ȫ�־�̬��������������Door����ڴ��С��Ҳ���ֲ��ڶ���ģ����
//	int a;
//	int b;
//};
//
//void testSizeof3()
//{
//	Door d;
//	printf("--- door size:%d\n", sizeof(Door));
//	printf("--- g size:%d\n", sizeof(Door::g));
//}
//
//int main()
//{
//	//testSizeof();
//	//testSizeof2();
//	testSizeof3();
//	system("pause");
//	return 0;
//}