//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//#include <vector>
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
//Human GetHuman()
//{
//	Human h1;//����һ������
//	return h1; //����ʱ���������ʵ�����ƶ�����(Ĭ��ûʵ��)������ƶ������ⲿֵ
//}				//���û���ƶ����죨Ĭ��ʵ�ֿ������� - λ�����������������ⲿֵ
//				//λ����ֻ�ǽ������ָ�븴�ƹ���������ָ��ͬ���ڴ棬������ʱ������������
//				//�ⲿֵ�ĳ�Ա��ָ���˱��ͷŹ����ڴ��ַ���������ڽ������ٴ�������ɱ���
//
//Human GetHuman2()
//{
//	return Human(); //ֱ�ӹ�����ⲿֵ�����������ʱ������Ҳ��������Զ��忽����������ƶ����죬ֻ�����λ����������
//}
//
//void testMoveConstruct()
//{
//	Human h2 = GetHuman();//���û���ƶ����죬������ÿ������죬���漰��������������ͷ���ʱ�����в������ڴ�
//	h2.show();			//���ƶ�����ֱ��ʹ����ʱ�����в������ڴ棬������һ��new��delete�Ĳ���
//	system("pause");	
//}
///*
//Human ����
//Human �ƶ�����
//Human ����
//--- num:123
//�밴���������. . .
//Human ����
//*/
//
//void testRValueRef1()
//{
//	Human h2 = GetHuman2(); //��Ϊֱ�ӹ�����ⲿֵ��Ϊ��ʱ����������������ֵ���ã���������������h2����������
//	h2.show();
//	system("pause");
//	//h2 = GetHuman2(); //GetHuman2��λ������h2��������ʱ������������h2.num��ָ�����������ڴ棬h2�������ڽ����ٴ�delete num����
//	system("pause");
//}
///*
//Human ����
//--- num:123
//�밴���������. . .
//�밴���������. . .
//Human ����
//*/
//
//
////�β�����ֵ���ã����Ա���Ϊ��ʱ�������֣�
//void AcceptRValueRef(Human&& _h)
//{
//	system("pause"); //1
//	Human h2 = std::move(_h); //���ｫ�ٴ��ƶ�����һ������h2����_h(��ʱ����)��h2������������ڽ���(�����������)�󶼻�����
//	system("pause");//2
//}
//
//void testRValueRef2()
//{
//	AcceptRValueRef(GetHuman()); //GetHuman��ṹ��һ������Ȼ���ƶ�����һ����ʱ������Ϊ�βδ���
//	system("pause");//3
//}
///*
//Human ����
//Human �ƶ�����
//Human ����
//�밴���������. . . //1
//Human �ƶ�����
//�밴���������. . . //2
//Human ����
//Human ����
//�밴���������. . . //3
//*/
//
//void testRValueRef3()
//{
//	//int&& num = 1 + 1; //��ֵ���� 123 �� 1+1�Ľ��2 ����ʱ��������Ϊ����ʱ���������д��������ͻ�����
//	int&& num = 123; //ͨ����ֵ��������������������������num�Ľ���������
//	num += 123;
//
//	printf("--- num:%d\n", num); 
//}
//
//int main()
//{
//	//testMoveConstruct();
//	//testRValueRef1();
//	//testRValueRef2();
//	//testRValueRef3();
//
//
//	system("pause");
//	return 0;
//}