//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
////------------ test1
//template <typename T = int> //c++98����ͨ����c++11����ͨ��
//class DefClass{};
//
//template <typename T = int> //c++98����ʧ�ܣ�c++11����ͨ��������ģ���Ĭ��ģ��������Ʊ����
//void DefTempParm(){};
//
////------------ test2 ��ģ��
//template <typename T1, int i = 0> //��ģ���Ĭ��ģ������������ա��������󡱵Ĺ���ָ��Ĭ�ϲ���һ��Ҫ�����Ҷ�
//class DefClass1{};
//
////template <int i = 0, typename T2> //�����������ʧ��
////class DefClass2{};
//
////------------ test3 ����ģ�壬���ں���ģ�壬��c++11�в���Ҫ���ա��������󡱵Ĺ���
//template <typename T1 = int, typename T2>
//void DefFunc1(T1 a, T2 b){}
//
//template <int i = 0, typename T2> 
//void DefFunc2(T2 a) {}
//
//void testTemplate()
//{
//	
//}
//
//int main()
//{
//	testTemplate();
//	system("pause");
//	return 0;
//}