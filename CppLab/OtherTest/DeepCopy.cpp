#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "AAA.h"
using namespace std;

class BBB
{
public:
	BBB() :a(nullptr), b(nullptr)
	{
		a = new int;
		*a = 10;
		b = new string;
		*b = "helloworld";
	}
	//ǳ����
	//���������û����ʽ������һ���������캯����
	//��ô�������������Զ�����һ��Ĭ�ϵĿ������캯����
	//�ù��캯����ɶ���֮���λ������λ�����ֳ�ǳ����

	//���
	BBB(const BBB& _b)
	{
		a = new int;
		*a = *_b.a;

		b = new string;
		*b = *_b.b;
	}

	virtual ~BBB()
	{
		if (a)
		{
			delete a;
			a = nullptr;
		}

		if (b)
		{
			delete b;
			b = nullptr;
		}
	}

	void Show()
	{
		printf("--- a=%d, b=%s\n", *a, b->c_str());
	}

public:
	int* a;
	std::string* b;

};

void testCopyConstruct()
{
	BBB b1;
	b1.Show();
	BBB b2 = b1;//���ø�ֵ���캯��
	b2.Show();
	system("pause");

	//�������������֮�󣬻��ͷ�ջ��b1,b2���ڴ�
	//�����ǳ�������� b1��b2 �е� a��b�ֱ�ָ����ͬ�ĵ�ַ��
	//b1�����ͷ����ab���ڴ��b2��ab�ͳ���Ұָ�룬�����е�if�жϻ��ǻ��ܽ�ȥ��deleteҰָ��ͻ���ɱ���

	//������������b2 �е�abָ���µĵ�ַ����b1�е�ab��ȫ�޹�
	//����b1 b2������������������������

	//ʲôʱ���õ�����������
	//	a.һ��������ֵ���ݵķ�ʽ���뺯���壻
	//	b.һ��������ֵ���ݵķ�ʽ�Ӻ������أ�
	//	c.һ��������Ҫͨ������һ��������г�ʼ����

}

//int main()
//{
//	testCopyConstruct();
//	system("pause");
//	return 0;
//}