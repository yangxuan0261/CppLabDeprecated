//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <map>
//
////---------------------------------------test1
//using namespace std;
//
//class Base
//{
//public:
//	void menfcn()
//	{
//		cout << "Base function" << endl;
//	}
//
//	void menfcn(int n)
//	{
//		cout << "Base function with int" << endl;
//	}
////private: 
////	void menfcn(std::string _name) {}//���û���usingʱ�����ɷ��ʵĴ�
//};
//
//class Derived : private Base
//{
//public:
//	using Base::menfcn;//using����ֻ��ָ��һ�����֣����ܴ��βα��һ���ĸú���������˽�а汾��������뱨��
//						//using���෽������Ҫ������ʵ�ֿ���������ʵ���е��õ���������ذ汾
//	int menfcn(int num)
//	{
//		cout << "Derived function with int : "<< num << endl;
//		return num;
//	}
//};
//
///*
//�����ء���ָ������ĺ�������������ͬ���Ļ��ຯ�����������£�
//1�����������ĺ��������ĺ���ͬ�������ǲ�����ͬ����ʱ����������virtual�ؼ��֣�����ĺ����������أ�ע��������ػ�����
//2�����������ĺ��������ĺ���ͬ�������Ҳ���Ҳ��ͬ�����ǻ��ຯ��û��virtual�ؼ��֡���ʱ������ĺ��������أ�ע����븲�ǻ�����
//ʹ����using�ؼ��֣��Ϳ��Ա���1��������ǵĸ���ͬ�������������е������أ���������
//*/
//
//void testUsing1()
//{
//	Base b;
//	Derived d;
//	b.menfcn();
//	d.menfcn();//���ȥ��Derived���е�using����������ִ���error C2660: 'Derived::menfcn' : function does not take 0 arguments    
//	d.menfcn(123);
//	/*
//	Base function
//	Base function
//	Derived function with int : 123
//	*/
//}
//
////---------------------------------------test2 ����ȡ��typedef��,���Ҹ������
//using myIntVec = std::vector<int>;
//void testUsing2()
//{
//	myIntVec mvec = { 1, 2, 3, 4, 5 };
//	mvec.push_back(123);
//	for (int num : mvec)
//		printf("--- num:%d\n", num);
//
//	std::cout << is_same < std::vector<int>, myIntVec>::value << std::endl; // 1
//}
//
//template <typename T>
//using MapStr = std::map<T, std::string>;
//void testUsing3()
//{
//	MapStr<int> intStrMap;
//	intStrMap.insert(make_pair(123, "aaa"));
//	intStrMap.insert(make_pair(456, "bbb"));
//
//	MapStr<std::string> strstrMap;
//	strstrMap.insert(make_pair("ccc", "ddd"));
//	strstrMap.insert(make_pair("eee", "fff"));
//}
//
//int main()
//{
//	testUsing1();
//	//testUsing2();
//	//testUsing3();
//	system("pause");
//	return 0;
//}