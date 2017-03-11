//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <memory>
//
//class Human
//{
//public:
//	Human() : mNum(nullptr)
//	{
//		mNum = new int(123);
//		printf("Human ����\n"); 
//	}
//	Human(const Human& _h)
//	{
//		mNum = new int(*_h.mNum);
//		printf("Human ��������\n");
//	}
//	Human(Human && _h)
//	{
//		mNum = _h.mNum; //
//		_h.mNum = nullptr; //���뽫��͵�ߵ�ָ���ÿգ���Ȼ��ʱ��������ʱ���ͷ��ڴ�
//		printf("Human �ƶ�����\n");
//	}
//	virtual ~Human() 
//	{
//		printf("Human ����\n");
//		if (mNum) delete mNum;
//	}
//	void show(){ if(mNum) printf("--- num:%d\n", *mNum); }
//private:
//	int* mNum;
//};
//
//void testSmartPoint1()
//{
//	std::unique_ptr<Human> up1(new Human);
//	//std::unique_ptr<Human> h2 = h1; //����ʧ�ܣ�
//	up1->show();
//
//	std::unique_ptr<Human> up3 = std::move(up1); //��h1��new Human������Ȩ����h3��h1�ÿ�empty
//	up3->show(); //������������ӵ�ж����Ψһָ����������ڵĽ���������
//
//	//h1->show();//����ʱ������h1�ѽ�����������Ȩ������Ϊempty״̬
//
//	up3.reset();//����ʽ�ͷŶ����ڴ�
//	//h3->show();//����ʱ����������ʽ�ͷŶ����ڴ棬����Ϊempty״̬
//	system("pause");
//}
//
//void testSmartPoint2()
//{
//	//���std::shared_ptr<Human> sp1Ϊempty״̬���򲻻�����������ж�if(sp1)
//	//void reset() _NOEXCEPT 
//	//{	// release resource and convert to empty shared_ptr object
//	//	shared_ptr().swap(*this);
//	//}
//	//use_count() {return (_Rep ? _Rep->_Use_count() : 0);}
//	/*
//	reset����
//	���ó�ʼ��һ��shared_ptr()���������_Rep��_Ptr��ʼ������nullptr����
//	Ȼ�����swap(T&a),ʵ�ֽ�a��_Rep��_Ptr����Ϊnullptr
//	���ù�һ�κ�֮���������۵����ٴ�reset�����������ù�
//
//	use_count����
//	�ж�_Rep�Ƿ�nullptr����Ϊnullptr�򷵻ض�������ô���
//	*/
//	std::shared_ptr<Human> sp1(new Human());
//	std::shared_ptr<Human> sp2 = sp1;
//	std::shared_ptr<Human> sp3 = sp1;
//	printf("--- ref count:%ld\n", sp2.use_count());//3
//
//	sp1.reset(); //��ʽ�������ã�_Rep��_Ptr����Ϊnullptr��sp1Ϊempty״̬
//	sp1.reset(); //�����ù�
//	sp1.reset(); //�����ù�
//	printf("--- sp1 ref count:%ld\n", sp1.use_count()); //0 
//	//sp1->show(); //��ʱsp1Ϊempty״̬����������ʹ��sp1->show()
//
//	printf("--- sp2 ref count:%ld\n", sp2.use_count()); //2 //��Ϊ��ʱsp3��sp2��������Զ�������ã����Զ���δ���ͷ�
//	printf("--- sp3 ref count:%ld\n", sp3.use_count()); //2 
//
//	sp2.reset();//�������ú�_Rep��_Ptr����Ϊnullptr��sp2Ϊempty״̬
//	printf("--- sp2 ref count:%ld\n", sp2.use_count()); //0
//	printf("--- sp3 ref count:%ld\n", sp3.use_count()); //1 //��Ϊ��ʱsp3��������Զ�������ã����Զ���δ���ͷ�
//
//	sp3.reset();//�������ú�_Rep��_Ptr����Ϊnullptr��sp3Ϊempty״̬ //��ʱ����shared_ptr��sp3�������ã������ͷ�
//	printf("--- sp3 ref count:%ld\n", sp3.use_count()); //0 
//	system("pause");
//}
///*
//Human ����
//--- ref count:3
//--- sp1 ref count:0
//--- sp2 ref count:2
//--- sp3 ref count:2
//--- sp2 ref count:0
//--- sp3 ref count:1
//Human ����
//--- sp3 ref count:0
//�밴���������. . .
//*/
//
//void testSmartPoint3()
//{
//	std::shared_ptr<Human> sp1(new Human());
//	std::shared_ptr<Human> sp2 = sp1;
//	std::weak_ptr<Human> wp = sp1; //����Ӱ�����ü���
//
//	printf("--- ref count:%ld\n", sp2.use_count());//2
//
//	sp2.reset();
//
//	printf("--- sp1 count:%ld\n", sp1.use_count());//1
//	std::shared_ptr<Human> sp4 = wp.lock(); //�����ʱ���жԶ��󱣳����ã����д��������sp4Ҳ���ᱣ�����ã����ü���+1
//	if (sp4)
//		printf("--- sp4 ref count:%ld\n", sp4.use_count());//2
//
//
//	sp1.reset();
//	printf("--- wp ref count:%ld\n", wp.use_count());//1
//	if (sp4)
//		sp4.reset(); //���д���󣬽���std::shared_ptr�Զ��󱣳����ã���������
//	printf("--- wp ref count:%ld\n", wp.use_count());//0
//
//	std::shared_ptr<Human> sp5 = wp.lock(); //�����ʱû�жԶ��󱣳����ã���sp5��empty״̬
//	if (sp5)
//		printf("--- sp5 ref count:%ld\n", sp4.use_count());
//
//}
//
//int main()
//{
//	//testSmartPoint1();
//	//testSmartPoint2();
//	testSmartPoint3();
//
//	system("pause");
//	return 0;
//}