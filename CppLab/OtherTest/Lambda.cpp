//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <functional>
//
//typedef std::function<int(const std::string&)> CustomFunc;
//
//void testFunc(CustomFunc _pFunc)
//{
//	std::string arg0 = "aaabbb";
//	int result = _pFunc(arg0);
//	printf("--- result:%d\n", result);
//}
//
//void testptrFunc()
//{
//	int num = 123;
//	int num2 = 789;
//
//	//��ֵ����
//	auto func = [&](const std::string&  _str)->int 
//	{
//		printf("--- input str:%s\n", _str.c_str());
//		num = 456;
//		return 100 + num;
//	};
//
//	//�ⲿ������ֵ����num2�����ò���
//	auto func2 = [=, &num2](const std::string&  _str)->int
//	{
//		printf("--- input str:%s\n", _str.c_str());
//		//num = 456; //ȡ��ע�ͱ��뱨����Ϊ�ǰ�ֵ�������޸��ⲿ����ֵ
//		num2 = 987; //num2�ǰ����ò������Կ����޸ı���ֵ
//		return 100 + num;
//	};
//
//	testFunc(func2);
//
//	printf("--- num:%d\n", num);
//	printf("--- num2:%d\n", num2);
//}
//
//void testLambda()
//{
//	/*
//	�����ǹ��ڲ�׽�����ϸ���ܣ�
//	[=]ͨ��ֵ��׽���б���
//	[&]ͨ�����ò�׽���б���
//	[value]ͨ��ֵ��׽value������׽��������
//	[&value]ͨ�����ò�׽value������׽��������
//	[=, &value]Ĭ��ͨ��ֵ��׽������value���⣬ͨ�����ò�׽
//	[&, value]Ĭ��ͨ�����ò�׽������value���⣬ͨ��ֵ��׽
//	*/
//
//	printf("--------- test1\n");
//	//β��������ʹ�ñ��ʽ������ִ�У�}����ǰ�ͱ�ʾһ����������()��ʾִ�и÷���
//	[]{std::cout << "Hello from Lambda!" << std::endl; }();
//
//	printf("--------- test2\n");
//	std::string result = [](const std::string& str)->std::string{return "Hello from " + str; }("second Lambda");
//	std::cout << result << std::endl;
//
//	printf("--------- test3\n");
//	auto fn = [](const std::string& str)->std::string{return "Hello from " + str; };
//	std::cout << fn("call 1") << std::endl;
//	std::cout << fn("call 2") << std::endl;
//
//	printf("--------- test4\n");
//	std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int num = 7;
//	auto func = [=](int value)->bool{return value > num; };
//	int counter = std::count_if(vec.begin(), vec.end(), func);
//	std::cout << "Found " << counter << " values > " << num << std::endl;
//
//	printf("--------- test5\n");
//	std::vector<int> vec2 = { 11, 22, 33, 44 };
//	int index = 0;
//	for_each(vec2.begin(), vec2.end(), 
//		[&index](int i)
//	{
//		printf("index:%d, value%d\n", index, i);
//		index++;
//	});
//}
//
//class Animal
//{
//public:
//	Animal(int _age, std::string _name) : mAge(0), mName("")
//	{
//		mAge = _age;
//		mName = _name;
//	}
//
//	virtual ~Animal() {}
//
//	int Show(const std::string& _str, int _num)
//	{
//		printf("---- show str:%s\n", _str.c_str());
//		printf("---- show num:%d\n", _num);
//		return mAge;
//	}
//
//public:
//	int mAge;
//	std::string mName;
//};
//
//void testBind()
//{
//	Animal* am = new Animal(22, "uuu");
//	CustomFunc func = std::bind(&Animal::Show, am, std::placeholders::_1, 123);
//	std::string str = "hello2";
//	int ret = func(str);
//	printf("--- age:%d\n", ret);
//
//	delete am;
//	/*
//	std::placeholders::_1 �ǵ���ʱ����������ռλ����CustomFunc���˼��������ͱ���ռ����λ���ϸ�һ��
//	123 �ǰ�ʱ���Դ����ú�����ֵ
//	*/
//}
//
//void testRefAndValCapture()
//{
//	int j = 12;
//	auto by_val = [=]() ->int{ return j + 1; };
//	auto by_ref = [&]() ->int{ return j + 1; };
//	printf("--- by_val:%d\n", by_val()); //13
//	printf("--- by_ref:%d\n", by_ref()); //13
//
//	j++;
//	printf("--- by_val:%d\n", by_val()); //13
//	printf("--- by_ref:%d\n", by_ref()); //14
//	//��ֵ��׽��j����Ϊ��һ��������һ����ʼ����Ͳ����ٸı�
//	//�����ò�����j����ʹ�ø��������е�ֵ
//}
//
//void testModifyVal()
//{
//	//lambda���ʽ{}�߼�����Ĭ����const�ģ���������޸��ⲿֵ�Ļ������밴���ò�׽���ⲿֵ�����Ÿı�
//	//����ǰ�ֵ��׽����Ҫ�޸Ĳ�׽�����������ⲿֵ���ͱ���ָ��mutable�����ⲿֵ����ı�
//
//	int j = 12;
//	printf("--- j addr:0x%x\n", &j); 
//	auto by_ref = [&]()->void
//	{ 
//		j++; 
//		printf("--- by_ref j addr:0x%x\n", &j);
//	};
//	by_ref();
//	printf("--- by_ref:%d\n", j); //13
//
//	//auto by_val = [=]()->void{ j++; };//����ʧ��
//	auto by_val = [=]() mutable->void
//	{ 
//		j = 10; //j���Ա��޸��ˣ����ⲿ����13
//		printf("--- by_val j addr:0x%x\n", &j);
//	}; 
//	by_val();
//	printf("--- by_val:%d\n", j); //13
//	/*
//	--- j addr:0x23fe10
//	--- by_ref j addr:0x23fe10
//	--- by_ref:13
//	--- by_val j addr:0x23fdf8
//	--- by_val:13
//	���԰�ֵ��׽���ǿ��������ģ���ַ����һ����
//	*/
//}
//
//int main()
//{
//	//testLambda();
//	//testptrFunc();
//	//testBind();
//	//testRefAndValCapture();
//	testModifyVal();
//
//	system("pause");
//	return 0;
//}