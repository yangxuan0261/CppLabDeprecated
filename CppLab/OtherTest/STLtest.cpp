//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <map>
//#include <vector>
//#include <array>
//#include <algorithm>
//#include <numeric>
//#include <utility>
//#include <list>
//#include <queue>
//#include <functional>
//#include <time.h>
//#include <random>
//#include <unordered_map>
//
////lambda���ʽ ���vector
//auto printVec = [](const std::vector<int>& _vec)
//{
//	int index = 0;
//	std::for_each(_vec.begin(), _vec.end(),
//		[&index](int value)
//	{
//		printf("--- index:%d, value:%d\n", index, value);
//		index++;
//	});
//	printf("\n");
//};
//
//auto printMap = [](const std::map<int, std::string>& _map)
//{
//	for (auto iter = _map.begin(); iter != _map.end(); iter++)
//		printf("--- key:%d, value:%s\n", iter->first, iter->second.c_str());
//	printf("\n");
//};
//
//class Person
//{
//public:
//	Person(int _age, std::string _name) : mName(""), mAge(0) 
//	{
//		mAge = _age;
//		mName = _name;
//	}
//
//	virtual ~Person() {}
//
//	//��д==������
//	bool operator ==(const Person& ps) const
//	{
//			return ps.mAge == mAge ? true : false;
//	}
//
//	bool operator <(const Person& ps) const
//	{
//			return mAge > ps.mAge ? true : false;
//	}
//
//	void operator()() const
//	{
//		printf("------------ operator(), name:%s\n", mName.c_str());
//	}
//
//	void ShowName() const { printf("--- name:%s, age:%d\n", mName.c_str(), mAge); }
//
//public:
//	std::string mName;
//	int mAge;
//};
//
//void testSTLVec()
//{
//	//lambda���ʽ ���vector
//	auto printVec = [](std::vector<int>& _vec)
//	{
//		int index = 0;
//		std::for_each(_vec.begin(), _vec.end(),
//			[&index](int value)
//		{
//			printf("--- index:%d, value:%d\n", index, value);
//			index++;
//		});
//	};
//
//	std::vector<int> vec = { 100, 2, 30, 4, 5, 6, 17, 8, 39 };
//
//	printVec(vec);
//	printf("--- \n");
//
//	//std::stable_sortʹ��
//	//std::sort()��std::stable_sort() ,ԭ���ǿ�������, 
//	//������stable_sort�����������������ʱ�������佻��˳��Ҳ�������ȶ�����
//	std::stable_sort(std::begin(vec), std::end(vec));
//
//	printVec(vec);
//	printf("--- \n");
//
//	//std::findʹ�� vec���ǻ�������int
//	auto iter = std::find(vec.begin(), vec.end(), 101);
//	if (iter != vec.end())
//		printf("--- find dest num:%d\n", *iter);
//	else
//		printf("--- not find\n");
//
//	printf("--- \n");
//
//	//lambda���ʽ ���vector
//	auto printVecPs = [](std::vector<Person>& _vec)
//	{
//		int index = 0;
//		std::for_each(_vec.begin(), _vec.end(),
//			[&index](Person& value)
//		{
//			printf("--- index:%d, name:%s, age:%d\n", index, value.mName.c_str(), value.mAge);
//			index++;
//		});
//	};
//
//	//std::findʹ�� vec�����Զ�����
//	Person p1(12, "aaa");
//	Person p2(65, "bbb");
//	Person p3(78, "ccc");
//	Person p4(26, "ddd");
//	Person p5(34, "eee");
//	std::vector<Person> vecPs = { p1, p2, p3, p4, p5 };
//
//	printVecPs(vecPs);
//	printf("--- \n");
//
//	Person p6(78, "www");
//
//	//std::findʹ�� vec������
//	auto iterPs = std::find(vecPs.begin(), vecPs.end(), p6);
//	if (iterPs != vecPs.end())
//		printf("--- find dest Pserson name:%s, age:%d\n", (*iterPs).mName.c_str(), (*iterPs).mAge);
//	else
//		printf("--- not find\n");
//
//	printf("--- \n");
//
//	//����һ�� lambda��
//	//std::stable_sort(std::begin(vecPs), std::end(vecPs),
//	//	[](const Person& _a,const Person& _b)
//	//{
//	//	if (_a.mAge > _b.mAge)
//	//		return true;
//	//	else
//	//		return false;
//	//}
//	//	);
//	//	printVecPs(vecPs);
//
//	//����һ�� ��д<��������
//	std::stable_sort(std::begin(vecPs), std::end(vecPs));
//	printVecPs(vecPs);
//}
//
//void testSTLMap()
//{
//	//lambda���ʽ ���map
//	auto printMap = [](std::map<int, std::string>& _map)
//	{
//		for (auto iter = _map.begin(); iter != _map.end(); iter++)
//			printf("--- key:%d, value:%s\n", iter->first, iter->second.c_str());
//	};
//
//	//std::make_pair ��ͷ�ļ�<utility>��
//	std::map<int, std::string> myMap;
//	myMap.insert(std::make_pair(3, "aaa"));
//	myMap.insert(std::make_pair(2, "bbb"));
//	myMap.insert(std::make_pair(5, "ccc"));
//	myMap.insert(std::make_pair(8, "ddd"));
//
//	printMap(myMap);
//}
//
//void testVecDel()
//{
//	std::vector<int> vec = {};
//	for (size_t i = 0; i < 10; i++)
//		vec.push_back(i);
//
//	printVec(vec);
//	printf("--- \n");
//
//	//ɾ��Ԫ��
//	for (auto iter = vec.begin(); iter != vec.end();)
//	{
//		if (*iter > 4 && *iter < 8)
//			iter = vec.erase(iter);
//		else
//			++iter;
//	}
//
//	printVec(vec);
//	printf("--- \n");
//}
//
//void testMapDel()
//{
//	//lambda���ʽ ���map
//	auto printMap = [](std::map<int, int>& _map)
//	{
//		for (auto iter = _map.begin(); iter != _map.end(); iter++)
//			printf("--- key:%d, value:%d\n", iter->first, iter->second);
//	};
//
//	std::map<int, int> tmpMap;
//	tmpMap.clear();
//	for (size_t i = 0; i < 10; i++)
//		tmpMap.insert(std::make_pair(i, i));
//
//	printMap(tmpMap);
//	printf("--- \n");
//
//	for (auto iter = tmpMap.begin(); iter != tmpMap.end();)
//	{
//		if (iter->first > 4 && iter->first < 8)
//			iter = tmpMap.erase(iter);
//		else
//			++iter;
//	}
//
//	printMap(tmpMap);
//}
//
//void testInsertVector()
//{
//	std::vector<int> numVec = {};
//	numVec.push_back(1);
//	numVec.push_back(2);
//	numVec.push_back(3);
//	printVec(numVec);
//	printf("\n");
//
//	auto iter = numVec.begin();
//	numVec.insert(iter + 0, 99); //���뵥��Ԫ��
//	iter = numVec.begin();
//	numVec.insert(iter + 3, 88);//���뵥��Ԫ��
//	printVec(numVec);
//	printf("\n");
//
//	std::vector<int> tmp = { -1, -2, -3 };
//	numVec.insert(numVec.begin() + 3, tmp.begin(), tmp.end()); //��������
//	printVec(numVec);
//}
//
//void testList()
//{
//	auto func = [](const std::list<int>& _list)
//	{
//		for (auto iter = _list.begin(); iter != _list.end(); iter++)
//			printf("%d ", (*iter));
//		printf("\n");
//	};
//
//	std::list<int> tmplist = {5, 7, 2, 4, 9, 7};
//	func(tmplist);
//	printf("--- list size:%d\n", tmplist.size());
//
//	//tmplist.remove(7); //list�ڱ�׼�����Ƚ����⣬remove����Ҫerase��ʵ�ʴ�СҲ����
//	//func(tmplist);
//	//printf("--- list size:%d\n", tmplist.size());
//
//	//ɾ������������Ԫ��
//	//tmplist.remove_if([](const int& _src)->bool{ return _src == 7 ? true : false; });
//	//func(tmplist);
//	//printf("--- list size:%d\n", tmplist.size());
//
//	//ֻ���ҵ���һ��iter
//	//auto iter = std::find_if(tmplist.begin(), tmplist.end(), [](const int& _src)->bool{ return _src == 7 ? true : false; });
//	//tmplist.erase(iter);
//	//func(tmplist);
//	//printf("--- list size:%d\n", tmplist.size());
//
//	std::stable_sort(tmplist.begin(), tmplist.end(), [](const int& _a, const int& _b){ return _a > _b ? true : false; });
//	func(tmplist);
//	printf("--- list size:%d\n", tmplist.size());
//}
//
//void testVecInsert()
//{
//	int data[5] = {1,2,3,4,5};
//	std::vector<int> vec;
//	vec.insert(vec.begin(), data, data + 5);
//	printVec(vec);
//
//	std::vector<int> vec2;
//	vec2.insert(vec2.begin(), vec.begin(), vec.end()); //����һ������
//	vec2.insert(vec2.begin() + 2, 100); //���뵥��Ԫ��
//	printVec(vec2);
//
//	bool b = std::binary_search(vec.begin(), vec.end(), 0);
//	std::cout << "--- find result : " << b << std::endl;
//}
//
//void testPartialSort()
//{
//	std::vector<int> values = { 5, 6, 2, 7, 4, 1, 8, 9, 0, 3 };
//	printVec(values);
//
//	std::partial_sort(values.begin(), // �Ѷ�������õ�3��Ԫ��
//		values.begin() + 3, // ����˳�򣩷���values��ǰ��
//		values.end(),
//		[](const int& _a, const int& _b)->bool //����������Ԫ�ص��жϣ�����������
//	{
//		return _a > _b ? true : false;
//	});
//
//	printVec(values);
//}
//
//void testNth_element()
//{
//	std::vector<int> values = { 5, 6, 2, 7, 4, 1, 8, 9, 0, 3 };
//	printVec(values);
//
//	std::nth_element(values.begin(), // �Ѷ�������õ�3��Ԫ��
//		values.begin() + 3, // ������˳�򣩷���values��ǰ��
//		values.end(),
//		[](const int& _a, const int& _b)->bool //����������Ԫ�ص��жϣ�����������
//	{
//		return _a > _b ? true : false;
//	});
//
//	printVec(values);
//}
//
//
//void testPartition()
//{
//	std::vector<int> values = { 5, 6, 2, 7, 4, 1, 8, 9, 0, 3 };
//	printVec(values);
//
//	//����������>3���ŵ�����ǰ�ˣ����� iter �ǲ�����>3�ĵ�һ�������������Ա���ʱ������ != iter����
//	auto iter = std::partition(values.begin(), //
//		values.end(),
//		[](const int& _a)->bool //�����е���Ԫ�ض��ر��жϣ�ֻ��һ������
//	{
//		return _a > 3 ? true : false;
//	});
//
//	for (auto iter2 = values.begin(); iter2 != iter; iter2++)
//		printf("--- value:%d\n", *iter2);
//}
//
//void testRemoveAndErase()
//{
//	std::vector<int> values = { 5, 6, 2, 7, 4, 1, 8, 9, 0, 3 };
//	printVec(values);
//	printf("--- size:%d\n", values.size());
//
//	int beDelNum = 99;
//	values[3] = values[5] = values[8] = beDelNum;
//	auto iter = std::remove(values.begin(), values.end(), beDelNum);
//		
//	values.erase(iter, values.end());
//	printVec(values);
//	printf("--- size:%d\n", values.size());
//}
//
//void testSearch()
//{
//	auto cmpFunc = [](const int& a, const int& b)->bool
//	{
//		return a < b ? true : false;
//	};
//
//	auto printIter = [](const std::vector<int>& _vec, const std::vector<int>::iterator& _iter)
//	{
//		for (auto iter = _vec.begin(); iter != _iter; iter++)
//			printf("--- value:%d\n", (*iter));
//	};
//
//	std::vector<int> values = { 5, 6, 2, 7, 4, 1, 8, 4, 4, 9, 4, 0, 3, 4 };
//	std::stable_sort(values.begin(), values.end(), cmpFunc);
//	printVec(values); //�Ƚ�����������
//
//	//lower_bound ���ص�һ�������������ĵ������� ָ��4
//	auto iter = std::lower_bound(values.begin(), values.end(), 4, cmpFunc);
//	printf("----- *iter value:%d\n", *iter);
//	printIter(values, iter);
//	printf("\n");
//
//	//upper_bound �������һ�����������ĵ���������һ����������ָ�� 5 
//	auto iter2 = std::upper_bound(values.begin(), values.end(), 4, cmpFunc);
//	printf("----- *iter2 value:%d\n", *iter2);
//	printIter(values, iter2);
//	printf("\n");
//
//	//equal_range ���� lower_bound �� upper_bound �ĵ�����
//	auto aaapair = std::equal_range(values.begin(), values.end(), 4, cmpFunc);
//	int dist = distance(aaapair.first, aaapair.second);
//	std::for_each(aaapair.first, aaapair.second,
//		[](const int& num)
//	{
//		printf("--- num:%d\n", num);
//	});
//	printf("\n");
//
//	bool exist = std::binary_search(values.begin(), values.end(), 4, cmpFunc);
//	if (exist)
//		printf("--- exist\n");
//	else
//		printf("--- not exist\n");
//	printf("\n");
//
//	printf("--- erase some date\n");
//	//values.erase(values.begin(), iter);
//	values.erase(values.begin(), iter2);
//	printVec(values);
//}
//
//void testSearchForMap()
//{
//	std::map<int, std::string> datas;
//	datas.insert(std::make_pair(5, "aaa"));
//	datas.insert(std::make_pair(3, "bbb"));
//	datas.insert(std::make_pair(8, "ccc"));
//	datas.insert(std::make_pair(7, "ddd"));
//	datas.insert(std::make_pair(1, "eee"));
//
//	std::for_each(datas.begin(), datas.end(),
//		[](const std::pair<int, std::string>& iter)
//	{
//		std::cout << iter.first << "\t" << iter.second << std::endl;
//	});
//	printf("\n");
//
//	printf("--- map lower_bound 3\n");
//	auto iter1 = datas.lower_bound(3); // ָ��3
//	printf("--- iter1.first:%d\n", iter1->first);
//	for (auto iter = datas.begin(); iter != iter1; iter++)
//		std::cout << iter->first << "\t" << iter->second << std::endl;
//	printf("\n");
//
//	printf("--- map upper_bound 7\n");
//	auto iter2 = datas.upper_bound(7); //ָ��7
//	for (auto iter = datas.begin(); iter != iter2; iter++)
//		std::cout << iter->first << "\t" << iter->second << std::endl;
//	printf("\n");
//
//	printf("--- map lower_bound 3 upper_bound 7\n");
//	for (auto iter = iter1; iter != iter2; iter++)
//		std::cout << iter->first << "\t" << iter->second << std::endl;
//	printf("\n");
//}
//
////�������й鲢
//void testMerge()
//{
//	auto cmpFunc = [](const int& a, const int& b)->bool
//	{
//		return a < b ? true : false;
//	};
//
//	std::vector<int> v1 = { 7, 5, 9 };
//	std::vector<int> v2 = { 4, 8, 6 };
//	std::stable_sort(v1.begin(), v1.end(), cmpFunc);
//	std::stable_sort(v2.begin(), v2.end(), cmpFunc);
//
//	std::vector<int> v3(v1.size() + v2.size());
//	std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//	printVec(v3);
//}
//
//void ppfunctest(const Person* _p)
//{
//	_p->ShowName();
//}
//
//void testMemFun()
//{
//	Person* p1 = new Person(111, "aaa");
//	Person* p2 = new Person(222, "bbb");
//	Person* p3 = new Person(333, "ccc");
//
//	//��Ҫinclude <functional>
//	std::vector<Person*> perVec = { p1, p2, p3 };
//
//	//ptr_fun
//	std::for_each(perVec.begin(), perVec.end(), std::ptr_fun(ppfunctest));
//	printf("\n");
//
//	//vec����ָ�����ʱʹ��mem_fun
//	std::for_each(perVec.begin(), perVec.end(), std::mem_fun(&Person::ShowName));
//	printf("\n");
//
//	//vec����ʵ�����ʱʹ��mem_fun_ref
//	std::vector<Person> perVec2 = { *p1, *p2, *p3 };
//	std::for_each(perVec2.begin(), perVec2.end(), std::mem_fun_ref(&Person::ShowName));
//}
//
//void testbind1stAndBind2nd()
//{
//	std::vector<int> coll;
//	for (int i = 1; i <= 10; ++i)
//		coll.push_back(i);
//
//	/*
//	�򵥵�˵��bind1st(const Operation& op, const T& x)������ôһ��������value op x��
//	��bind2nd(const Operation& op, const T& x)������ôһ��������x op value��
//	����value�Ǳ�Ӧ��bind�Ķ�������������������ڽ�һ����Ԫ����ת����һ��һԪ���ӡ�
//	*/
//
//	//����Ԫ��ֵ����10��Ԫ�صĸ���
//	//Ҳ����ʹ��10 < elem������Ԫ�ظ��� 
//	int res = std::count_if(coll.begin(), coll.end(), std::bind1st(std::less<int>(), 10));
//	printf("--- res:%d\n", res); //0
//
//	//����Ԫ��ֵС��10��Ԫ�صĸ���
//	//Ҳ����ʹ��elem < 10������Ԫ�ظ��� 
//	res = std::count_if(coll.begin(), coll.end(), std::bind2nd(std::less<int>(), 10));
//	printf("--- res:%d\n", res);  //9
//
//	//�������Լ�ʵ�ֵ�lambda���ʽ��������
//	res = std::count_if(coll.begin(), coll.end(), [&](const int& a)->bool{ return 10 > a ? true : false; });
//	printf("--- res:%d\n", res);  //9
//}
//
//void testTransform()
//{
//	std::vector<int> src = { 1, 2, 3, 4, 5 }; // �����������飬
//	std::vector<int> d = { 10, 11, 12 };
//
//	//��data��ͷ���Ԫ���Ƶ�dǰ�Σ�����data�е�����Ԫ�ض� + 41
//	std::transform(src.begin(), src.begin() + 5,
//		std::inserter(d, d.begin() + 1),//���뵽dָ��λ��
//		//std::back_inserter(d), //���뵽dβ��
//		std::bind2nd(std::plus<int>(), 40));  //��Ҫinclude <functional>
//	printVec(d);
//}
//
//void testFindIfRemoveIfReplaceIf()
//{
//	//������_if�Ķ��ǿ���ָ���Զ���ĺ������󲿷�����¶��ǱȽϺ�����return true or false
//
//	int findNum = 6;
//	std::vector<int> values = { 2, 6, 2, 7, 4, 1, 8, 9, 0, 2 };
//	printf("--- size:%d\n", values.size());
//
//	//���ҵ�һ�����������Ķ���
//	auto iter = std::find_if(values.begin(), values.end(), [&](const int& _src)->bool{ return _src == findNum ? true : false; });
//	if (iter != values.end())
//		printf("--- find:%d\n", *iter);
//	else
//		printf("--- not find\n");
//	printf("\n");
//
//	int srcNum = 2;
//	int dstNum = 99; //�ѷ��������Ķ��滻��
//	std::replace_if(values.begin(), values.end(), [&](const int& _src)->bool{ return _src == srcNum ? true : false; }, dstNum);
//	 printVec(values);
//	printf("\n");
//
//	int delNum = dstNum; //�ѷ��������Ķ�ɾ����
//	auto iter2 = std::remove_if(values.begin(), values.end(), [&](const int& _src)->bool{ return _src == delNum ? true : false; });
//	values.erase(iter2, values.end());
//	printf("--- size:%d\n", values.size());
//	printVec(values);
//}
//
//void testBinarysearch()
//{
//	auto printPer = [](const Person* _p) { _p->ShowName(); };
//	auto sortFunc = [](const Person* _p1, const Person* _p2)->bool { return _p1->mAge > _p2->mAge ? true : false; };
//
//	Person* p0 = new Person(5, "aaa");
//	Person* p1 = new Person(3, "bbb");
//	Person* p2 = new Person(1, "ccc");
//	Person* p3 = new Person(0, "ddd");
//	Person* p4 = new Person(6, "eee");
//	Person* p5 = new Person(2, "fff");
//	Person* p6 = new Person(7, "ggg");
//	Person* p7 = new Person(4, "hhh");
//	Person* p8 = new Person(9, "iii");
//	Person* p9 = new Person(8, "jjj");
//	Person* p10 = new Person(100, "zzz");
//	std::vector<Person*> perVec = { p0, p1, p2, p3, p4, p5, p6, p7, p8, p9 };
//
//	std::for_each(perVec.begin(), perVec.end(), printPer);
//	printf("\n");
//	std::stable_sort(perVec.begin(), perVec.end(), sortFunc); //��ָ���ȽϺ�������
//	std::for_each(perVec.begin(), perVec.end(), printPer);
//	printf("\n");
//
//	bool b = std::binary_search(perVec.begin(), perVec.end(), p10, sortFunc); //ָ����������������ĺ���һ��
//	if (b)
//		printf("--- find\n");
//	else
//		printf("--- not find\n");
//
//	(*p10)();//������д������()
//}
//
//void testShinkToFit()
//{
//	std::vector<int> vec3;
//	vec3.reserve(100);
//	printf("--- vec3 size1:%d\n", vec3.capacity());
//	vec3.push_back(1);
//	vec3.push_back(1);
//	vec3.push_back(1);
//	std::vector<int>(vec3).swap(vec3); //��������������size��С
//	printf("--- vec3 size2:%d\n", vec3.capacity());
//}
//
//void testArr()
//{
//	//std::array<int, 5> arr1; //ȫ��ֵδ��ʼ��
//	//std::array<int, 5> arr1 = { 1 }; //��һ����ʼ��Ϊ1������ȫ��Ϊ0
//	std::array<int, 5> arr1 = { 20, 1, 1, 10, 1 }; //ȫ����ʼ��Ϊ1
//	printf("--- arr1 size : %d, addr:0x%x\n", sizeof(arr1), &arr1);
//	printf("--- arr1 first element:%d\n", arr1);
//	printf("--- arr1[3] element:%d\n", arr1[3]);
//
//	//std::for_each(arr1.begin(), arr1.end(),
//	//	[](const int& num)
//	//{
//	//	printf("--- value:%d\n", num);
//	//});
//
//	std::array<int, 5> arr2 = arr1; //ȫ����ʼ��Ϊ1
//	printf("--- arr2 size : %d, addr:0x%x\n", sizeof(arr2), &arr2);
//}
//
////������Ԫ���ۼ�
//void testAccumulate()
//{
//	std::vector<int> values = { 5, 6, 2 };
//	//int sum = accumulate(values.begin(), values.end(), 3, std::multiplies<int>());
//	int sum = std::accumulate(values.begin(), values.end(), 0, //ps: accumulate��<numeric>ͷ�ļ���
//		[](const int& _a, const int& _b)->int
//	{
//		return _a + _b;
//	});
//	printf("--- sum:%d\n", sum);
//}
//
//void testInnerProduct()
//{
//	auto myaccumulator = [](int x, int y)->int{ return x - y; };
//	auto myproduct = [](int x, int y)->int{ return x + y; };
//
//	int init = 100;
//	std::vector<int> series1 = { 10, 20, 30 };
//	std::vector<int> series2 = { 1, 2, 3 };
//
//    //  ����ǰ:[beg1,end1)��[beg2,...)��ʾ��������.init�ǵ�һ�����������ֵ.  
//    //  ������:����init���μ������������и��Զ�ӦԪ�صĳ˻�.  
//    //  ����ֵ:�������õ�ֵ.  
//    //  ��ע:     init�ǵ�һ�����������Ԫ��.init�����;�������ֵ������.  
//    //                  [beg2,...)��������ͬ[beg1,end1)����һ����.�����׳��쳣.  
//    //                  [beg2,...)�г���[beg1,end1)���ȵ����в���������.  
//	//10*1 + 20*2 + 30*3 + 100 = 240;
//	std::cout << "--- using default inner_product: ";
//	std::cout << std::inner_product(series1.begin(), series1.end(), series2.begin(), init);
//	std::cout << '\n'; //240
//
//	//  inner_product (beg1, end1, beg2, init, minus<int> (), divides<int> ()) ;  
//	//  ����ǰ:[beg1,end1)��[beg2,...)��ʾ��������.init�ǵ�һ�����������ֵ.minus<int> ()��divides<int> ()�Ƕ�Ԫ��������.  
//	//  ������:����init���μ������������и��Զ�ӦԪ�صĳ˻�.  
//	//  ����ֵ:�������õ�ֵ.  
//	//  ��ע:     init�ǵ�һ�����������Ԫ��.init�����;�������ֵ������.  
//	//                  [beg2,...)��������ͬ[beg1,end1)����һ����.�����׳��쳣.  
//	//                  [beg2,...)�г���[beg1,end1)���ȵ����в���������.  
//	//                  minus<int> ()����λ�������滻�����˲����汾�㷨�ļ�.  
//	//                  divides<int> ()����λ�������滻�����˲����汾�㷨�ĳ�.  
//	//100-(10/1) = 90
//	//90-(20/2) = 80
//	//80-(30/3) = 70
//	std::cout << "--- using functional operations: ";
//	std::cout << std::inner_product(series1.begin(), series1.end(), series2.begin(), init,
//		std::minus<int>(), std::divides<int>());
//	std::cout << '\n'; //70
//
//	//100-(10+1) = 89
//	//89-(20+2) = 67
//	//67-(30+3) = 34
//	std::cout << "--- using custom functions: ";
//	std::cout << std::inner_product(series1.begin(), series1.end(), series2.begin(), init,
//		myaccumulator, myproduct);
//	std::cout << '\n'; //34
//}
//
//void testPartialSum()
//{
//	auto  myop = [](int x, int y) { return x + y + 1; };
//
//	std::vector<int> val = { 1, 2, 3, 4, 5 };
//	std::vector<int> result(5);
//
//	//Ĭ���ۼ�
//	std::partial_sum(val.begin(), val.end(), result.begin());
//	std::cout << "using default partial_sum: \n";
//	printVec(result);
//
//	//result�����Ӧ��5��Ԫ��
//	//1=1
//	//1*2=2
//	//2*3=6
//	//6*4=24
//	//24*5=120
//	std::partial_sum(val.begin(), val.end(), result.begin(), std::multiplies<int>());
//	std::cout << "using functional operation multiplies: \n";
//	printVec(result);
//
//	//result�����Ӧ��5��Ԫ��
//	//1=1
//	//1+2+1 = 4
//	//4+3+1 = 8
//	//8+4+1 = 13
//	//13+5+1 = 19
//	std::partial_sum(val.begin(), val.end(), result.begin(), myop);
//	std::cout << "using custom function: \n";
//	printVec(result);
//}
//
//void testAdjacentDifference()
//{
//	std::array<int, 6> ia = { 1, 1, 2, 3, 5, 8 };
//	std::list<int> ilist(ia.begin(), ia.end());
//	std::list<int> ilist_result(ilist.size());
//	std::adjacent_difference(ilist.begin(), ilist.end(), ilist_result.begin());
//	std::for_each(ilist_result.begin(), ilist_result.end(), [](const int& num){ printf("--- num:%d\n", num); });
//	printf("\n"); //1 0 1 1 2 3
//
//
//	//1	2	3	5	8
//	//1	1	2	3	5
////1 1	2	6	15 40 //ilist_result
//	std::adjacent_difference(ilist.begin(), ilist.end(), ilist_result.begin(), std::multiplies<int>());
//	std::for_each(ilist_result.begin(), ilist_result.end(), [](const int& num){ printf("--- num:%d\n", num); });
//	printf("\n"); //1 1 2 6 15 40
//}
//
//void testMinMaxElement()
//{
//	int val1 = 2;
//	int val2 = 5;
//	const int& c = std::min(val2, val1, [](const int& _a, const int& _b) {return _a < _b ? true : false; });
//	const int& d = std::max(val1, val2, [](const int& _a, const int& _b) {return _a < _b ? true : false; });
//	printf("--- val1:0x%x, val2:0x%x\n", &val1, &val2);
//	printf("--- min val:%d, 0x%x\n", c, &c);
//	printf("--- max val:%d, 0x%x\n", d, &d);
//
//	auto  e = std::minmax(val1, val2, [](const int& _a, const int& _b) {return _a < _b ? true : false; });
//	printf("--- min:%d, max:%d\n", e.first, e.second);
//	printf("\n");
//
//	std::array<int, 6> ia = { 1, 1, 2, 3, 5, 8 };
//	// ���ݸ����ıȽϺ������ҳ���СԪ��
//	auto ret1 = std::min_element(ia.begin(), ia.end(), [](const int& _a, const int& _b) {return _a < _b ? true : false; });
//	printf("--- min:%d\n", *ret1);
//
//	// ���ݸ����ıȽϺ������ҳ����Ԫ��
//	auto ret2 = std::max_element(ia.begin(), ia.end(), [](const int& _a, const int& _b) {return _a < _b ? true : false; });
//	printf("--- max:%d\n", *ret2);
//
//	// ���ݸ����ıȽϺ������ҳ�������СԪ��
//	auto ret3 = std::minmax_element(ia.begin(), ia.end(), [](const int& _a, const int& _b) {return _a < _b ? true : false; });
//	printf("--- min:%d, max:%d\n", *ret3.first, *ret3.second);
//}
//
//void testShuffle()
//{
//	//�����ϴ�ƣ����������
//	std::default_random_engine generator1(time(NULL)); //�����������
//	std::vector<int> datas = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	std::shuffle(datas.begin(), datas.end(), generator1); //
//	printVec(datas);
//
//	//ÿ�����ж���һ���Ľ��
//	auto myrandom = [](int i) { return std::rand() % i; };
//	std::vector<int> datas2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	//std::random_shuffle(datas2.begin(), datas2.end());
//	std::random_shuffle(datas2.begin(), datas2.end(), myrandom);
//	printVec(datas2);
//}
//
//void testHeap()
//{
//	//�󶥶�
//	auto cmpFunc = [](const int& _a, const int& _b)->bool{ return _a < _b ? true: false; };
//	std::vector<int> datas = { 5, 1, 9, 4, 3, 6, 2, 7, 8, 0 };
//
//	printf("--- �ѻ�����\n");
//	std::make_heap(datas.begin(), datas.end(), cmpFunc);
//	printVec(datas); //
//
//	printf("--- �Ƴ��Ѷ�Ԫ��\n");
//	std::pop_heap(datas.begin(), datas.end(), cmpFunc);
//	datas.pop_back();//ɾ���ýڵ㣬��Ϊֻ�ǰѶѶ�Ԫ���ƶ����˶�β
//	printVec(datas);
//
//	printf("--- �Ƴ��Ѷ�Ԫ��\n");
//	std::pop_heap(datas.begin(), datas.end(), cmpFunc);
//	datas.pop_back();//ɾ���ýڵ㣬��Ϊֻ�ǰѶѶ�Ԫ���ƶ����˶�β
//	printVec(datas);
//
//	printf("--- ��β���Ԫ��5\n");
//	datas.push_back(5);
//	std::push_heap(datas.begin(), datas.end(), cmpFunc);
//	printVec(datas);
//
//	printf("--- ���ѱ����������\n");
//	std::sort(datas.begin(), datas.end(), cmpFunc);
//	printVec(datas);
//}
//
//void testNextPermutation()
//{
//	/*
//	�ڡ�STLԴ����������ҵ�������������ڴ�Ҳ������һ��ԭ��
//	��STL�У�����next_permutation�⣬����һ������prev_permutation��
//	���߶�����������������ϵĺ�����ǰ���������һ��������ϣ��������������һ��������ϡ�
//	��ν����һ�����͡���һ���������о���һ���򵥵����ӣ�
//	������ {a, b, c}��ÿһ��Ԫ�ض��Ⱥ����С�������ֵ����У��̶�a֮��a��bc��С��c��b��
//	������һ�����м�Ϊ{a, c, b}����{a, c, b}����һ�����м�Ϊ{a, b, c}��
//	ͬ������Ƴ����е���������Ϊ��{a, b, c}��{a, c, b}��{b, a, c}��{b, c, a}��{c, a, b}��{c, b, a}��
//	����{a, b, c}û����һ��Ԫ�أ�{c, b, a}û����һ��Ԫ�ء�
//	*/
//
//	auto cmpFunc = [](const int& _a, const int& _b)->bool{ return _a < _b ? true : false; };
//	std::vector<int> datas = { 1, 2, 3 };
//	printVec(datas);
//	std::next_permutation(datas.begin(), datas.end(), cmpFunc);
//	printVec(datas);
//	std::next_permutation(datas.begin(), datas.end(), cmpFunc);
//	printVec(datas);
//
//	//std::prev_permutation(datas.begin(), datas.end(), cmpFunc);
//
//}
//
//void testMismatch()
//{
//	auto cmpFunc = [](const int& _a, const int& _b)->bool{ return _a == _b ? true : false; };
//	std::vector<int> datas1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	std::vector<int> datas2 = { 0, 1, 2, 3, 4, 0, 6, 7, 8, 9 };
//
//	//��������vec�Ĳ�ͬ��ͬ��ֵ�ĵ�����
//	auto ret = std::mismatch(datas1.begin(), datas1.end(), datas2.begin(), cmpFunc);
//	if (ret.first == datas1.end() && ret.second == datas2.end())
//		printf("��ȫ��ͬ\n");
//	else
//	{
//		printf("--- ret.first:%d, ret.second:%d \n", *ret.first, *ret.second);
//	}
//}
//
//void testCopy()
//{
//	std::vector<int> datas1 = { 0, 1, 2, 3, 4, 0, 2, 7, 8, 2 };
//	std::vector<int> datas2(datas1.size());
//	std::copy(datas1.begin(), datas1.end(), datas2.begin());
//	printVec(datas2);
//
//	int dstNum = 2;
//	auto cmpFunc = [&](const int& val)->bool{return val == dstNum ? true : false; };
//	std::vector<int> datas3(datas1.size());
//	std::copy_if(datas1.begin(), datas1.end(), datas3.begin(), cmpFunc); // ��ȵĲſ���ȥ
//	printVec(datas3);
//}
//
//void testUnorderMap()
//{
//	auto printMap = [](const std::unordered_map<int, std::string>& datas)
//	{
//		for (auto iter = datas.begin(); iter != datas.end(); iter++)
//			printf("--- key:%d, value:%s\n", iter->first, iter->second.c_str());
//		printf("\n");
//	};
//
//	std::unordered_map<int, std::string> datas;
//	datas.insert(std::pair<int, std::string>(1, "aaa"));
//	datas.insert(std::pair<int, std::string>(9, "bbb"));
//	datas.insert(std::pair<int, std::string>(5, "ccc"));
//	datas.insert(std::pair<int, std::string>(2, "ddd"));
//	datas.insert(std::pair<int, std::string>(7, "eee"));
//	datas.insert(std::pair<int, std::string>(9, "fff"));
//	datas.insert(std::pair<int, std::string>(6, "ggg"));
//	datas.insert(std::pair<int, std::string>(3, "hhh"));
//	datas.insert(std::pair<int, std::string>(4, "iii"));
//	datas.insert(std::pair<int, std::string>(0, "jjj"));
//	printMap(datas);
//
//
//
//	std::map<int, int> datas2;
//}
//
//void testMapWithCmpFunc1()
//{
//	//-------------��keyֵ���� ------------------
//	//�Զ���key�Ƚ��࣬��д()��������map����ʱ��ᰴ˳����뵽���ʵ�λ��
//	struct CmpByKey {
//		bool operator()(const int& k1, const int& k2) {
//			return k1 < k2 ? true : false;
//		}
//	};
//
//	// ����map
//	printf("--------- ����map ��keyֵ����\n");
//	std::map<int, std::string, CmpByKey> datas;
//	datas.insert(std::pair<int, std::string>(1, "aaa"));
//	datas.insert(std::pair<int, std::string>(9, "bbb"));
//	datas.insert(std::pair<int, std::string>(5, "ccc"));
//	datas.insert(std::pair<int, std::string>(2, "ddd"));
//	datas.insert(std::pair<int, std::string>(7, "eee"));
//	datas.insert(std::pair<int, std::string>(9, "fff"));
//	datas.insert(std::pair<int, std::string>(6, "ggg"));
//	datas.insert(std::pair<int, std::string>(3, "hhh"));
//	datas.insert(std::pair<int, std::string>(4, "iii"));
//	datas.insert(std::pair<int, std::string>(0, "jjj"));
//
//	for (auto iter = datas.begin(); iter != datas.end(); iter++)
//		printf("--- key:%d, value:%s\n", iter->first, iter->second.c_str());
//	printf("\n");
//
//	//-------------��valueֵ���� ------------------
//	printf("--------- ����map ��valueֵ����\n");
//	typedef std::pair<int, std::string> PAIR;
//	std::map<int, std::string> datas2;
//	datas2.insert(std::pair<int, std::string>(1, "a"));
//	datas2.insert(std::pair<int, std::string>(9, "bb"));
//	datas2.insert(std::pair<int, std::string>(5, "ccc"));
//	datas2.insert(std::pair<int, std::string>(5, "zzzzzzzzzzz")); //�Ѿ��и�5��key�����Բ��ᱻ����
//	datas2.insert(std::pair<int, std::string>(2, "ddd"));
//	datas2[2] = "yyyyyyyyyyy"; //�����滻���������
//	datas2.insert(std::pair<int, std::string>(7, "eeee"));
//	datas2.insert(std::pair<int, std::string>(9, "fff"));
//	datas2.insert(std::pair<int, std::string>(6, "g"));
//	datas2.insert(std::pair<int, std::string>(3, "hh"));
//	datas2.insert(std::pair<int, std::string>(4, "iiiiii"));
//	datas2.insert(std::pair<int, std::string>(0, "j"));
//
//	auto cmpFunc = [](const PAIR& _a, PAIR& _b){return _a.second.length() < _b.second.length() ? true : false; };
//	struct CmpByValue { //Ҳ�����������ʽ
//		bool operator()(const PAIR& _a, const PAIR& _b) {
//			return _a.second.length() < _b.second.length() ? true : false;
//		}
//	};
//
//	std::vector<PAIR> vecData(datas2.begin(), datas2.end()); //�����е�pair����洢��vec�У�
//	std::sort(vecData.begin(), vecData.end(), cmpFunc); //Ȼ��ָ�����򷽷�����
//	//std::sort(vecData.begin(), vecData.end(), CmpByValue()); //Ȼ��ָ�����򷽷�����
//	for (int i = 0; i != vecData.size(); ++i)
//		printf("--- key:%d, value:%s\n", vecData[i].first, vecData[i].second.c_str());
//	printf("\n");
//
//	//���������¶���Ҫ��valueֵ����������map
//	printf("--------- ����unorder_map ��valueֵ����\n");
//	std::unordered_map<int, std::string> data5;
//	data5.insert(std::pair<int, std::string>(1, "a"));
//	data5.insert(std::pair<int, std::string>(9, "bb"));
//	data5.insert(std::pair<int, std::string>(5, "ccc"));
//	data5.insert(std::pair<int, std::string>(5, "zzzzzzzzzzz")); //�Ѿ��и�5��key�����Բ��ᱻ����
//	data5.insert(std::pair<int, std::string>(2, "ddd"));
//	data5[2] = "yyyyyyyyyyy"; //�����滻���������
//	data5.insert(std::pair<int, std::string>(7, "eeee"));
//	data5.insert(std::pair<int, std::string>(9, "fff"));
//	data5.insert(std::pair<int, std::string>(6, "g"));
//	data5.insert(std::pair<int, std::string>(3, "hh"));
//	data5.insert(std::pair<int, std::string>(4, "iiiiii"));
//	data5.insert(std::pair<int, std::string>(0, "j"));
//
//	std::for_each(data5.begin(), data5.end(), 
//		[](const PAIR& iter)
//	{ printf("--- key:%d, value:%s\n", iter.first, iter.second.c_str()); });
//	printf("\n");
//
//	std::vector<PAIR> vecData2(data5.begin(), data5.end()); //�����е�pair����洢��vec�У�
//	std::sort(vecData2.begin(), vecData2.end(), cmpFunc); //Ȼ��ָ�����򷽷�����
//	for (int i = 0; i != vecData2.size(); ++i)
//		printf("--- key:%d, value:%s\n", vecData2[i].first, vecData2[i].second.c_str());
//	printf("\n");
//
//	auto iter5 = data5.find(9);
//	if (iter5 != data5.end())
//		printf("--- key:%d, value:%s\n", iter5->first, iter5->second.c_str());
//	else
//		printf("--- not find\n");
//	 
//}
//
//struct person
//{
//	std::string name;
//	int age;
//
//	person(std::string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//
//	//bool operator== (const person& p) const
//	//{
//	//	return name == p.name && age == p.age;
//	//}
//
//	bool operator < (const person& p) const
//	{
//		return age < p.age ? true : false;
//	}
//};
//
//void testMapWithCmpFunc2()
//{
//	/*
//	�÷���������ǣ�stl::map ��key��Ҫ����operator< ��
//	��boost::unordered_map��Ҫ����hash_value��equal������
//	�����������ͣ���string����Щ�����ò��ġ�
//	�����Զ����������key������Ҫ�Լ�����operator< ����hash_value()�ˡ�
//	*/
//	typedef std::pair<person, int> PAIR;
//	std::map<person, int> m;
//	person p1("Tom1", 20);
//	person p2("Tom2", 22);
//	person p3("Tom3", 22);
//	person p4("Tom4", 23);
//	person p5("Tom5", 24);
//	m.insert(std::make_pair(p3, 100));
//	m.insert(std::make_pair(p4, 100));
//	m.insert(std::make_pair(p5, 100));
//	m.insert(std::make_pair(p1, 100));
//	m.insert(std::make_pair(p2, 100));
//
//	//map����һ�ֱ�����ʽ1 (c++11)
//	printf("--- std::for_each(m.begin(), m.end(), \n");
//	std::for_each(m.begin(), m.end(),
//		[](const PAIR& iter)
//	{
//			std::cout << iter.first.name << "\t" << iter.first.age << std::endl;
//	});
//	printf("\n");
//
//	//map����һ�ֱ�����ʽ2 (c++11)
//	printf("--- for (auto iter : m) \n");
//	for (auto iter : m)
//		std::cout << iter.first.name << "\t" << iter.first.age << std::endl;
//	printf("\n");
//
//	//map����һ�ֱ�����ʽ3
//	printf("--- for (auto iter = m.begin(); iter != m.end(); iter++) \n");
//	for (auto iter = m.begin(); iter != m.end(); iter++)
//		std::cout << iter->first.name << "\t" << iter->first.age << std::endl;
//}
//
//
////--------------------------- unorder_map ��дhash��equal���� begin ----------
////���Ƕ�keyֵ����
////�����ϣ������ϵͳ������ַ���hash���������������д��
//struct str_hash{
//	size_t operator()(const std::string& str) const
//	{
//		return std::hash_value(str.c_str());
//	}
//};
//
////struct str_hash{      //��дhash����
////	size_t operator()(const std::string& str) const
////	{
////		unsigned long __h = 0;
////		for (size_t i = 0; i < str.size(); i++)
////		{
////			__h = 51 * __h + str[i];
////		}
////		return size_t(__h);
////	}
////};
//
//struct str_equal{      //string �ж���Ⱥ���
//	bool operator()(const std::string& s1, const std::string& s2) const
//	{
//		return strcmp(s1.c_str(), s2.c_str()) == 0;
//	}
//};
//
//class Plane
//{
//public:
//	Plane(int _speed) { mSpeed = _speed; }
//	bool operator==(const Plane& p) const
//	{
//		return mSpeed == p.mSpeed ? true : false;
//	}
//
//public:
//	int mSpeed;
//};
//
//struct plane_hash{
//	size_t operator()(const Plane& p) const
//	{
//		return p.mSpeed >> 1;
//	}
//};
//
//void testUnorderHashKey()
//{
//	std::unordered_map<std::string, int, str_hash, str_equal> myMap;
//	myMap.insert(std::make_pair("hello", 123));
//	myMap.insert(std::make_pair("world", 456));
//	myMap.insert(std::make_pair("I", 555));
//	myMap.insert(std::make_pair("am", 333));
//	myMap.insert(std::make_pair("Test", 888));
//
//	std::for_each(myMap.begin(), myMap.end(),
//		[](const std::pair<std::string, int>& iter)
//	{ printf("--- key:%s, value:%d\n", iter.first.c_str(), iter.second); });
//	printf("\n");
//
//	printf("--- �����Զ���key��������д==���������str_equal��\n");
//	//�����Զ���key��������д==���������str_equal��
//	//ּ��������keyֵ��hashֵ��ͬʱ����һ���ж��Ƿ���ͬ�������ͬ�򲻲����ȥ
//	//���в���ʱ��ͬ��hashֵʱ����һ���ж��Ƿ���ͬ�������ͬ�򷵻ظĵ�������
//	std::unordered_map<Plane, int, plane_hash> myPlane;
//	myPlane.insert(std::make_pair(Plane(123), 123));
//	myPlane.insert(std::make_pair(Plane(456), 456));
//	myPlane.insert(std::make_pair(Plane(789), 789));
//	std::for_each(myPlane.begin(), myPlane.end(),
//		[](const std::pair<Plane, int>& iter)
//	{ printf("--- speed:%d, value:%d\n", iter.first.mSpeed, iter.second); });
//
//	auto iter = myPlane.find(Plane(123));
//	if (iter != myPlane.end())
//		printf("--- find\n");
//	else
//		printf("--- not find\n");
//}
////--------------------------- unorder_map ��дhash���� end ----------
//
//int main()
//{
//	//testSTLVec();
//	//testSTLMap();
//	//testVecDel();
//	//testMapDel();
//	//testInsertVector();
//	//testList();
//	//testVecInsert();
//	//testPartialSort();
//	//testNth_element();
//	testPartition();
//	//testRemoveAndErase();
//	//testSearch();
//	//testSearchForMap();
//	//testMerge();
//	//testMemFun();
//	//testbind1stAndBind2nd();
//	//testTransform();
//	//testFindIfRemoveIfReplaceIf();
//	//testBinarysearch();
//	//testShinkToFit();
//	//testArr();
//
//	//---- #include <numeric> begin ---
//	//testAccumulate();
//	//testInnerProduct();
//	//testPartialSum();
//	//testAdjacentDifference();
//	//---- #include <numeric> end ---
//
//	//testMinMaxElement();
//	//testShuffle();
//	//testHeap();
//	//testNextPermutation();
//	//testMismatch();
//	//testCopy();
//	//testUnorderMap();
//	//testMapWithCmpFunc1();
//	//testMapWithCmpFunc2();
//	//testUnorderHashKey();
//
//	system("pause");
//	return 0;
//}
//
///*
//������ԴԽ�ٵ�����ǰ�棺
//1. partition
//2. stable_partition
//3. nth_element
//4. partial_sort
//5. sort
//6. stable_sort
//*/