//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <typeinfo>
//
///*
//ƫ�ػ����ǲ����ػ���
//*/
//
//template <typename T>
//class A			//ͨ�õ�ģ������
//{
//public:
//	A(T _t)
//	{
//		std::cout << "--- common type:" << typeid(T).name() << ", value:" << _t << std::endl;
//	}
//
//	template<typename TP2>
//	void output(TP2 _arg) {
//		std::cout << "------ output type:" << typeid(TP2).name() << ", value:" << _arg << std::endl;
//	}
//};
//
//template<>
//class A<int>	//������int��ʹ֮ʹ�����ģ������
//{
//public:
//	A(int _t)
//	{
//		std::cout << "--- special int value:" << _t << std::endl;
//	}
//
//	template<typename TP3>
//	void myPrintf() {
//		std::cout << "------ myPrintf type:" << typeid(TP3).name() << std::endl;
//	}
//};
//
//
////------------ ����ĳЩ�ػ��ǲ�������ͨ�����������µ�int�����ػ�ʱ��������ͨ��
//template <typename T>
//class B
//{
//public:
//	B(T _t)
//	{
//		std::cout << "--- value:" << _t << std::endl;
//	}
//};
//
//template<>
//class B<int>; //������int�Ͳ���ʵ�֣��ñ���ʱ����δ����
//
//void testTemplate()
//{
//	A<int> a(111);
//	a.myPrintf<double>(); //int�ػ���ʵ������myPrintf����
//	//a.template myPrintf<double>(); //��ȻҲ���������Ӹ�template���ã���cocos�е�rapidjson�п�����֪��
//	std::cout << std::endl;
//
//	A<double> b(123.23f);//����int�ػ���ʵ������output����
//	b.output(false);
//	std::cout << std::endl;
//
//	A<bool> c(true);
//	c.output(123.456f);
//	std::cout << std::endl;
//
//	float x = 123.4f;
//	B<decltype(x)> b1(x); //����decltype�Ƶ�����ʼ������������
//
//	//int y = 111;
//	//B<decltype(y)> b2(y); //error, δ����int��B��
//
//}
//
//
//
//template <typename T>
//inline T myClamp(T value, T low, T high)
//{
//	return value < low ? low : (value > high ? high : value);
//}
//
//void testTemplate3()
//{
//	int num = myClamp(2.f, 1.f, 3.f);
//	printf("--- num:%d\n", num);
//}
//
//int main()
//{
//	testTemplate();
//	//testTemplate3();
//
//	system("pause");
//	return 0;
//}