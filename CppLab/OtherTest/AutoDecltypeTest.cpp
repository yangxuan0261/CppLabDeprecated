//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//
////----------------------------------test1 ��ʵ��
//#define  GetProperty(Var,VarName) inline auto Get##VarName() const ->decltype(Var) { return Var;}
//#define  SetProperty(Var,VarName) inline void Set##VarName(decltype(Var) _v){ Var = _v;}
//#define  GetSetProperty(Var,VarName)\
//	GetProperty(Var, VarName)\
//	SetProperty(Var, VarName)
//
////decltype(Var) ����Varʵ�ʵ������Ƶ������� 
//
//class Pig
//{
//private:
//	int mAge;
//	std::string mName;
//
//public:
//	GetSetProperty(mAge, Age); //һ��Ҫ�������ı���������(�е�ϰ���Եİѷ���д�����棬����������)����Ȼ���뱨��δ����mAge
//	GetSetProperty(mName, Name);
//};
//
//void testDeclType()
//{
//	int  iarr[10] = { 0 };
//	decltype(iarr) ib; //���ʱ��ib�Ķ���ȼ��� int ib[10];������һ���ģ���Ҫ��Ϊib��һ��ָ���ˣ�����һ�����ڵ����顣
//	printf("--- sizeof ib:%d\n",sizeof(ib)); //40
//
//	Pig p;
//	p.SetAge(123);
//	p.SetName("uuu");
//
//	printf("--- pig age:%d, name:%s\n",p.GetAge(), p.GetName().c_str());
//
//	/*
//	--- sizeof ib:40
//	--- pig age:123, name:uuu
//	*/
//}
//
////----------------------------------test3 ����ת��
//double foo(int _a) { return (double)_a + 0.1; }
//int foo(double _a){ return (int)_a + 1; }
//
//template <typename T>
//auto Forward(T _t) -> decltype(foo(_t))
//{
//	return foo(_t);
//}
//
//void testDeclType3()
//{
//	std::cout << Forward(2) << std::endl; //2.1
//	std::cout << Forward(0.2) << std::endl; //1
//}
//
//int main()
//{
//	testDeclType();
//	//testDeclType3();
//
//	system("pause");
//	return 0;
//}