//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <tuple>
//
////---------------------------- test1 for function
//enum  LuaParameterType
//{
//	LPT_NUM = 0,
//	LPT_STR,
//	LPT_BOOL,
//	LPT_CUSTOM,
//	LPT_COUNT,
//};
//struct  LuaParameter
//{
//	LuaParameterType type;     //����
//	void* value;		       //�Զ�������ֵ
//	double num;                //number
//	bool b;                //bool
//	std::string str;          //�ַ�������
//	std::string typeName;      //������Ϊ�Զ�������ʱ��Ч
//	std::string name;          //Ԥ��ʱ�õ��������
//};
//
//
//std::vector<LuaParameter> mutipleArgsVec;
//void insertArg(bool _b)
//{
//	LuaParameter para;
//	para.type = LPT_BOOL;
//	para.b = _b;
//	mutipleArgsVec.push_back(para);
//}
//void insertArg(char _c)
//{
//	LuaParameter para;
//	para.type = LPT_STR;
//	char tmp[2] = { _c, '\0' };
//	para.str = std::string(tmp);
//	mutipleArgsVec.push_back(para);
//}
//void insertArg(const char* _str)
//{
//	LuaParameter para;
//	para.type = LPT_STR;
//	para.str = std::string(_str);
//	mutipleArgsVec.push_back(para);
//}
//void insertArg(std::string _str)
//{
//	LuaParameter para;
//	para.type = LPT_STR;
//	para.str = std::string(_str);
//	mutipleArgsVec.push_back(para);
//}
//void insertArg(int _num)
//{
//	LuaParameter para;
//	para.type = LPT_NUM;
//	para.num = _num;
//	mutipleArgsVec.push_back(para);
//}
//void insertArg(float _num)
//{
//	LuaParameter para;
//	para.type = LPT_NUM;
//	para.num = _num;
//	mutipleArgsVec.push_back(para);
//}
//
//void printData()
//{
//	for (LuaParameter para : mutipleArgsVec)
//	{
//		if (para.type == LPT_NUM)
//		{
//			printf("--- is number:%lf\n", para.num);
//		}
//		else if (para.type == LPT_STR)
//		{
//			printf("--- is string:%s\n", para.str.c_str());
//		}
//		else if (para.type == LPT_BOOL)
//		{
//			printf("--- is bool:%d\n", (int)para.b);
//		}
//	}
//}
//
////--------------------- ʵ��ģ��ĵݹ� begin ------------------
//template <typename... Args>
//void showArgs(Args... _args); //�䳤ģ��������һ��Ҫ�����棬��Ȼ���뱨��
//
////definition for 0 parameters -- �޲���ʱ�����һ�εݹ�ʱ����ã�ֹͣ�ݹ飬ʵ��Ϊ�ռ���
//void showArgs() {} //�߽�����
//
////definition for 1 or more parameters -- �в����ǵ����������
//template < typename T, typename... Args> //ƫ�ػ��ݹ鶨��
//void showArgs(T value, Args... _args)
//{
//	insertArg(value);
//	showArgs(_args...);
//}
////--------------------- ʵ��ģ��ĵݹ� end ------------------
//
//void testArgsForFunc()
//{
//	mutipleArgsVec.clear();
//	showArgs(123, "aaa", 23.23f, 'c', true);
//	printData();
//}
//
////---------------------------- test2 for class
////--------------------- ʵ��ģ��ĵݹ� begin ------------------
//template < typename... Args>
//class MultiArgs; //�䳤ģ��������һ��Ҫ�����棬��Ȼ���뱨��
//
//template <>
//class MultiArgs<> {}; //�߽���������ֹ�̳еݹ�
//
//template < typename T, typename... Args>
//class MultiArgs<T, Args...> : public MultiArgs<Args...> //ƫ�ػ��ݹ鶨��
//{
//public:
//	MultiArgs(T _t, Args... _args) : MultiArgs<Args...>(_args...)
//	{ 
//		value = _t;
//		std::cout << "--- addr:0x" << this << ", value:" << _t << std::endl;
//		//TODO:�������ʵ�ִ������_t���߼���
//		//���綪���ظ���ƥ������ĺ��������Զ������ݽṹ��������
//	}
//public:
//	T value;
//};
////--------------------- ʵ��ģ��ĵݹ� begin ------------------
//
//template <typename... Args>
//void sendMsg(Args... _args)
//{
//	//����䳤���ĳ��ȣ�sizeof...(Args)
//	int argsLength = sizeof...(Args);
//	std::cout << "--- _args length:" << argsLength << std::endl; //�����ʹ��ʱһ��Ҫ����...
//	MultiArgs<Args...> ma(_args...);
//}
//
//void testArgsForClass()
//{
//	sendMsg(111, "yang", 22.22f, true);
//}
///*
//�����
//--- _args length:4
//--- addr:0x0016F72C, value:1
//--- addr:0x0016F72C, value:22.22
//--- addr:0x0016F72C, value:yang
//--- addr:0x0016F72C, value:111
//��ĳ�ʼ��˳�����ȳ�ʼ�����캯��������Ķ������ٳ�ʼ��{}����Ķ�����
//���Դ�ӡ��˳���Ǵ���sendMsg����ʱ��˳�򷴹���
//*/
//
////---------------------------- test3 std::tuple��ͷ�ļ�<tuple>��
//using MyPairRet = std::pair<int, std::string>;
//using MyTupleRet = std::tuple<int, std::string, float, char>; //�Զ�������͵�pair-tuple
//
////----- print begin
//template <typename Tuple, std::size_t N>
//struct TuplePrinter {
//	static void print(const Tuple& t)
//	{
//		TuplePrinter<Tuple, N - 1>::print(t);
//		std::cout << ", " << std::get<N - 1>(t);
//	}
//};
//
//template <typename Tuple>
//struct TuplePrinter<Tuple, 1>{
//	static void print(const Tuple& t)
//	{
//		std::cout << std::get<0>(t);
//	}
//};
//
//template <typename... Args>
//void PrintTuple(const std::tuple<Args...>& t)
//{
//	std::cout << "(";
//	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
//	std::cout << ")\n";
//}
////----- print end
//
//MyPairRet GetPairRet()
//{
//	return MyPairRet(111, "aaa");
//}
//
//MyTupleRet GetTupleRet()
//{
//	return MyTupleRet(222, "bbb", 333.33f, 'w');
//}
//
//void testTuple()
//{
//	MyPairRet pairRet = GetPairRet();
//	printf("--- pair first:%d, second:%s\n", pairRet.first, pairRet.second.c_str());
//
//	MyTupleRet tupleRet = GetTupleRet();
//	//std::tuple_element<0, MyTupleRet>::type e1 = std::get<0>(tupleRet); //û��auto�õķ���
//	//auto e1 = std::get<0>(tupleRet);
//	//auto e2 = std::get<1>(tupleRet);
//	//auto e3 = std::get<2>(tupleRet);
//	//auto e4 = std::get<3>(tupleRet);
//	//printf("--- e1:%d, e2:%s, e3:%f, e4:%c\n", e1, e2.c_str(), e3, e4); //�Ƚϴ�����
//
//	PrintTuple(tupleRet); //�Ƚϴ������
//}
//
//
//int main()
//{
//	//testArgsForFunc();
//	testArgsForClass();
//	//testTuple();
//
//	system("pause");
//	return 0;
//}