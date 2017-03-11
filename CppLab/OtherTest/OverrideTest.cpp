#include <iostream>
#include <sstream>
#include <string>

class CBase
{
public:
	CBase() { printf("--- CBase ����\n"); }
	virtual ~CBase(){ printf("--- CBase ����\n"); }

	//������ָ�����ຯ�����ǻ��ຯ������������������һ��
	virtual void test1(int _a, std::string _b) { printf("--- CBase test1\n"); }

	//���أ�������һ�¡�������һ�£�����ָ��ľ������͵��ö�Ӧ�ķ�����
	virtual void test2(int _a, std::string _b) { printf("--- CBase test2\n"); }

	//û��virtual�ؼ��֣���������������һ�£���Ȼ�Ǹ���ָ��ľ������͵��ö�Ӧ�ķ�����
	void test3(int _a, std::string _b) { printf("--- CBase test3\n"); }

private:

};

class CDev : public CBase
{
public:
	CDev() { printf("--- CDev ����\n"); }
	virtual ~CDev(){ printf("--- CDev ����\n"); }

	virtual void test1(int _a, std::string _b) { printf("--- CDev test1\n"); }

	virtual void test2(int _a) { printf("--- CDev test2\n"); }

	void test3(int _a, std::string _b) { printf("--- CDev test3\n"); }

private:

};

void testOverride()
{
	CBase* d1 = new CDev;

	d1->test1(1, "asd");
	d1->test2(1, "asd");
	d1->test3(1, "asd");

	printf("\n");

	CDev* d2 = (CDev*)d1;
	d2->test2(2);
	d2->test3(2, "asd");
	delete d1;

}

//int main()
//{
//
//	testOverride();
//	system("pause");
//	return 0;
//}