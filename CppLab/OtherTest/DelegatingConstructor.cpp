//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//
///*
//ί�ɹ��캯����ʹ�ã������빹�����
//*/
//
//class Info
//{
//public:
//	Info() { init(); }
//	//Info(int _age) : Info(), mName("qwe") //�޷�����ͨ��������ͬʱ ί�� �� ��ʼ����Ա�������Ҫ��ʼ����Ա��������ڹ��캯������
//	Info(int _age) : Info()
//	{ 
//		mAge = _age; 
//		printf("--- one param mAge:%d\n", mAge);
//	}
//	Info(int _age, std::string _name) : Info(_age)
//	{
//		mName = _name; 
//		printf("--- two param mName:%s\n", mName.c_str());
//	}
//
//private:
//	void init(){ mHeight = 1.23f; printf("--- init mheight:%f\n", mHeight); }
//	int mAge;
//	std::string mName;
//	float mHeight;
//};
//
//void testDelegatingConstructor()
//{
//	Info info(77, "yang");
//	/*
//	--- init mheight:1.230000
//	--- one param mAge:77
//	--- two param mName:yang
//	�밴���������. . .
//	*/
//}
//
//int main()
//{
//	testDelegatingConstructor();
//	system("pause");
//	return 0;
//}