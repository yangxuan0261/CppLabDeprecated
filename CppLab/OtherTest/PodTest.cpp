//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <type_traits>
////-------------------------- defaut ��ʾָ��Ϊȱʡ���������Զ����޲����Ĺ��캯������ָ�POD����
////-------------------------------test1 ƽ���ģ�trivial��
//struct Trivial1 {};
//
//struct Trivial2 { 
//public:
//	int a;
//private:
//	int b;
//};
//
//struct Trivial3 {
//	Trivial1 a;
//	Trivial2 b;
//};
//
//struct Trivial4 {
//	Trivial2 a[23];
//};
//
//struct Trivial5 {
//	int x;
//	static int y;
//};
//
//struct Trivial6 {
//	Trivial6() = default; //�����˹��캯������ͬʱָ��Ϊdefault
//	int w;
//};
//
//struct Trivial7 {
//	Trivial7() = default; //�����˹��캯������ͬʱָ��Ϊdefault��
//	Trivial7(int _w) : w(_w) {} //ֻҪ������Ĭ���ṩ�ı����Զ��壬��defaultָ��ΪĬ�ϵģ�
//	int w;						//��ʱ�����Ƿ����������캯��������trivial����
//};								//���ǣ�ֻ����������ָ�������ⲿʵ��ָ����Ч���������NonTrivial2
//
//struct NonTrivial1 { //�����˹��캯���������ϣ�1��
//	NonTrivial1() : z(24) {}
//	int z;
//};
//
//struct NonTrivial2 {
//	NonTrivial2(); //�����˹��캯������ʹʵ����ָ��Ϊdefault��Ҳ�� nonTrivial�������ϣ�1��
//	int w;
//};
//NonTrivial2::NonTrivial2() = default;
//
//struct NonTrivial3 {
//	Trivial5 c;
//	virtual void f(); //�������麯����������(4)
//};
//
//void testTrivial()
//{
//	std::cout << std::is_trivial<Trivial1>::value << std::endl; // 1
//	std::cout << std::is_trivial<Trivial2>::value << std::endl; // 1
//	std::cout << std::is_trivial<Trivial3>::value << std::endl; // 1
//	std::cout << std::is_trivial<Trivial4>::value << std::endl; // 1
//	std::cout << std::is_trivial<Trivial5>::value << std::endl; // 1
//	std::cout << std::is_trivial<Trivial6>::value << std::endl; // 1
//	std::cout << std::is_trivial<Trivial7>::value << std::endl; // 1
//	std::cout << std::is_trivial<NonTrivial1>::value << std::endl; // 0
//	std::cout << std::is_trivial<NonTrivial2>::value << std::endl; // 0
//	std::cout << std::is_trivial<NonTrivial3>::value << std::endl; // 0
//}
//
//
////-------------------------------test2 ��׼���ֵģ�standard layout��
//struct B1{};
//struct B2{};
//
//struct D1 : B1 {
//	B1 b;
//	int i;
//};
//
//struct D2 : B1 {
//	B2 b;
//	int i;
//};
//
//void testStandardLayout()
//{
//	D1 d1;
//	D2 d2;
//	std::cout << (&d1) << std::endl; //0018F730 
//	std::cout << (&d1.b) << std::endl; //0018F730 //�����ϵĲ�������������๲���ַ
//	std::cout << (&d1.i) << std::endl; //0018F734
//
//	std::cout << std::endl;
//
//	std::cout << (&d2) << std::endl; //0018F720
//	std::cout << (&d2.b) << std::endl; //0018F720
//	std::cout << (&d2.i) << std::endl; //0018F724
//	std::cout << std::endl;
//
//	std::cout << std::is_standard_layout<D1>::value << std::endl; // 0
//	std::cout << std::is_standard_layout<D2>::value << std::endl; // 1
//}
//
////-------------------------- delete ��ʾɾ��ȱʡ�������ﵽprivateĳ������Ч��
//class NoCopy
//{
//public:
//	NoCopy() = default; //��������������NoCopy(int a, int b);���캯��������Ĭ�Ϲ��캯���ᱻɾ��������ͨ������ָ��Ϊdefault������NoCopy a;��������
//	NoCopy(const NoCopy& _nc) = delete;//����������ʾָ��Ϊdelete������NoCopy b(a); ����뱨��
//
//	NoCopy(int a, int b);
//
//	void* operator new(std::size_t) = delete;//new������ָ��Ϊdelete������new NoCopy();����뱨��
////private:
////	NoCopy(const NoCopy& _nc) {}
//};
//#include <typeinfo>
//
//void testDeleteFunc()
//{
//	NoCopy a;
//	//NoCopy b(a); //���뱨����ɾ���ĺ���
//	//NoCopy* d = new NoCopy(); //���뱨����ɾ���ĺ���
//	std::cout << std::is_trivial<NoCopy>::value << std::endl; //0����ʾɾ���˿�������ͱ���˷�pod��
//	NoCopy& b = a;
//	const char* name = typeid(b).name();
//	printf("------- name:%s\n", name);
//}
//
//int main()
//{
//	//testTrivial();
//	//testStandardLayout();
//	testDeleteFunc();
//
//	system("pause");
//	return 0;
//}