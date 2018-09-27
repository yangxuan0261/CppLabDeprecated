#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

namespace VitualTableTest {


	typedef std::function<void(void)> Fun0;  //��������ʵ������

	class Base0 {
	public:
		virtual void f() { cout << "Base::f" << endl; }
		virtual void g() { cout << "Base::g" << endl; }
		virtual void h() { cout << "Base::h" << endl; }

	};

	int test0() {
		Fun0 pFun = nullptr;

		Base0 b;
		cout << "�麯�����ַ��" << (int*)(&b) << endl;
		cout << "�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&b) << endl;

		// Invoke the first virtual function 
		//pFun = (Fun0)*((int*)*(int*)(&b));
		//pFun();

		system("pause");
		return 0;
	}

	typedef void(*Fun)(void);   //void���͵ĺ���ָ�� //��������ʵ����������ȫ�ֺ�����

	// ------------------------------------------------ test1 -------------------------
	class Tmp {
	public:
		short a;
		int b;
		double c;
	};

	class Base {
	public:
		Base() :base1Num(123) { cout << "Base::Base" << endl; }
		virtual ~Base() { cout << "Base::~Base" << endl; }
		virtual void f() { cout << "Base::f" << endl; }
		virtual void g() { cout << "Base::g" << endl; }
		virtual void h() { cout << "Base::h" << endl; }
		void ooo() { cout << "Base::ooo" << endl; }
		void ppp() { cout << "Base::ppp" << endl; }

	private:
		virtual void j() { cout << "Base::j" << endl; }
		int base1Num;
	};

	class Base2 {
	public:
		Base2() :base2Num(456) { cout << "Base2::Base2" << endl; }
		virtual ~Base2() { cout << "Base2::~Base2" << endl; }
		virtual void x() { cout << "Base2::x" << endl; }
		virtual void y() { cout << "Base2::y" << endl; }
		void rrr() { cout << "Base2::rrr" << endl; }
		void sss() { cout << "Base2::sss" << endl; }

	private:
		virtual void z() { cout << "Base2::z" << endl; }
		int base2Num;
	};

	class dev : public Base, public Base2 {
	public:
		virtual void f() { cout << "dev::f" << endl; }
		virtual void k() { cout << "dev::k" << endl; }
		virtual void z() { cout << "dev::z" << endl; }

	public:
		int num;
		char* str;
		dev* child;
		Tmp tmp;
		//double price; //���˸�8���ֽڵ�double���ֽڶ���ʱ��ռ�ø����ֽڣ������С����
	};

	void testVirtualTable() {
		//Base b1;
		//b1.j();            //compile error

		dev d;
		d.num = 100;
		d.str = "hello world";
		//d.child = new dev;
		//d.child->num = 500;

		d.tmp.a = 31;
		d.tmp.b = 777;
		d.tmp.c = 888;
		//d.f();             //compile error

		cout << "�麯�����ַ��" << (int*)(&d) << endl;
		cout << "�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&d) << endl;
		printf("\n");

		//ͨ������ָ����ʵ�˽�е�j(), j()���ڶ������������ǲ��ɼ���,ָ��̫ǿ��
		Fun pFun2 = nullptr;
		//��һ���麯����ָ��ָ��
		//pFun2 = (Fun)*((int*)*(int*)(&d) + 0); //Base::~Base //�������ܵ�
		//pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 1); //dev::f //dev��дBase��f
		pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 2); //Base::g
		pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 3); //Base::h
		pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 4); //Base::j
		pFun2();
		pFun2 = (Fun)*((int*)*(int*)(&d) + 5); //dev::k
		pFun2();
		//Base base1Num�Ĵ洢ƫ�����麯����ָ�����4���ֽ�
		int base1Num = (int)*((int*)(&d) + 1);
		printf("--- base1Num:%d\n", base1Num); //123
		printf("\n");

		//�ڶ����麯����ָ��ָ��
		//pFun2 = (Fun)*((int*)*((int*)(&d) + 1) + 0);  //Base2::~Base2 //�������ܵ�
		//pFun2();
		pFun2 = (Fun)*((int*)*((int*)(&d) + 2) + 1);//Base2::y
		pFun2();
		pFun2 = (Fun)*((int*)*((int*)(&d) + 2) + 2); //Base2::y
		pFun2();
		pFun2 = (Fun)*((int*)*((int*)(&d) + 2) + 3); //dev::z //dev��дBase2��z
		pFun2();
		//Base2 base2Num�Ĵ洢ƫ�����麯����ָ�����4���ֽ�
		int base2Num = (int)*((int*)(&d) + 3);
		printf("--- base2Num:%d\n", base2Num); //456
		printf("\n");

		//ͨ����ַ��ȡ��Ա����
		int num = (int)*((int*)(&d) + 4);
		char* str = (char*)*((int*)(&d) + 5);
		printf("--- dev.num:%d\n", num);
		printf("--- dev.str:%s\n", str);
		printf("\n");

		//(base vtp + base1num + base2 vtp + base2num + dev::num + dev::str + dev::dev*) * 4 = 28
		//printf("--- dev size : %d\n", sizeof(dev)); //28
		//��� dev �Ӷ�� double �ͳ�Ա����Ϊ�ֽڶ����Ǹ������Ԫ�����Խ磬��õ�sizeofΪ40���ο�ByteAlign.cpp; 

		printf("--- Tmp size : %d\n", sizeof(Tmp));
		printf("--- dev size : %d\n", sizeof(dev));

		printf("--- str:0x%x\n", str);
		Tmp* tmp = (Tmp*)&(*((int*)(&d) + 7));
		printf("--- tmp:0x%x\n", tmp);
		printf("--- tmp.b:%d\n", tmp->b);

		short tmpA = (short)*((int*)(&d) + 7);
		printf("--- tmpA:%d\n", (int)tmpA);
		int tmpB = (int)*((int*)(&d) + 8);
		printf("--- tmpB:%d\n", tmpB);
		int tmpC = (int)*((int*)(&d) + 9);
		printf("--- tmpC:%d\n", tmp->c);

		//dev* child = (dev*)*((int*)(&d) + 4);
		//printf("--- child num:%d\n", child->num);

		//Base* b2 = new dev();
		////b2->k();           //compile error,����ָ���޷�call�������е��麯��

		////ͨ������ָ����ʵ��������е��麯��k(), ָ��̫ǿ��
		//Fun pFun3 = (Fun)*((int*)*(int*)b2 + 4);
		//pFun3();
	}

	// ------------------------------------------------ test2 -------------------------
	class base_class {
	public:
		base_class() {
		}
		virtual ~base_class() {
		}

		int normal_func() {
			cout << "This is  base_class's normal_func()" << endl;
			return 0;
		}
		virtual int virtual_fuc() {
			cout << "This is  base_class's virtual_fuc()" << endl;
			return 0;
		}

	};

	class drived_class1 : public base_class {
	public:
		drived_class1() {
		}
		virtual ~drived_class1() {
		}

		int normal_func() {
			cout << "This is  drived_class1's normal_func()" << endl;
			return 0;
		}
		virtual int virtual_fuc() {
			cout << "This is  drived_class1's virtual_fuc()" << endl;
			return 0;
		}
	};

	class drived_class2 : public base_class {
	public:
		drived_class2() {
		}
		virtual ~drived_class2() {
		}

		int normal_func() {
			cout << "This is  drived_class2's normal_func()" << endl;
			return 0;
		}
		virtual int virtual_fuc() override //ֻ����̳еĺ���������д
		{
			//base_class::virtual_fuc(); //���ø��෽��
			cout << "This is  drived_class2's virtual_fuc()" << endl;
			return 0;
		}
	};

	int test2() {
		base_class * pbc = NULL; //����ָ��
		base_class bc;
		drived_class1 dc1;
		drived_class2 dc2;

		pbc = &bc;
		pbc->normal_func();
		pbc->virtual_fuc();

		pbc = &dc1;
		pbc->normal_func(); //û��virtual�ؼ��֣�����ָ���������normal_func����
		pbc->virtual_fuc(); //��virtual�ؼ��֣�������virtual_fuc����

		pbc = &dc2;
		pbc->normal_func();//û��virtual�ؼ��֣�����ָ���������normal_func����
		pbc->virtual_fuc();//��virtual�ؼ��֣�������virtual_fuc����

		system("pause");
		return 0;
	}

	// ------------------------------------------------ test3 -------------------------
	class Dog {
	public:
		virtual void method1() { printf("--- Dog metho1\n"); } //��һ���麯��������һ���麯�����ָ�룬4���ֽ�
		virtual void method2() { printf("--- Dog metho2\n"); } //�Ժ����ӵ��麯����������麯�����У��������Ӵ�С
		void method3() {} //��ͨ�����������Ӵ�С
	};

	struct Cat {
	};

	void testEmptyClass() {
		printf("--- dog size:%d\n", sizeof(Dog)); //4
		printf("--- cat size:%d\n", sizeof(Cat)); //1���������ṹ�嶼����1���ֽڴ�С��Ŀ������new�Ƿ����ڴ棬����ͨ����ַѰ�ҵ�
		printf("\n");
	}

	// ------------------------------------------------ test4 -------------------------

	struct no_virts {
		int d1;
		int d2;
	};

	class has_virts : public no_virts {
	public:
		int d3;
		virtual void foo() { printf("--- has_virts foo \n"); }
	};

	void testMemObj() {
		has_virts hv;
		hv.d1 = 111;
		hv.d2 = 222;
		hv.d3 = 333;

		//�����麯�����ڶ�����ĸ�λ�ã������е��麯������λ�ڶ����ڴ�ֲ��Ķ���
		Fun pFunc = (Fun)*((int*)(*((int*)(&hv) + 0)) + 0); //foo���� 
		pFunc();

		int d1 = (int)*((int*)(&hv) + 1); //111
		printf("--- d1:%d\n", d1);
		int d2 = (int)*((int*)(&hv) + 2); //222
		printf("--- d2:%d\n", d2);
		int d3 = (int)*((int*)(&hv) + 3); //333
		printf("--- d3:%d\n", d3);
	}

	void main() {
		test0();
		//testVirtualTable()
		//test2();
		//testEmptyClass();
		testMemObj();
	}
}
