#include <stdio.h>
#include "stdlib.h"
#include <iostream>

//extern "C"
//{
//
//	int i = 100;
//
//	void func()
//	{
//		printf("--- %d\n", i++);
//	}
//}

//��Ϊ��ں�����.c�ļ��У����õ�c�������������У��������c��ʹ���ⲿʵ�ֵķ�ʽ������cpp��
//��ôcpp�е����б�c�ļ�������extern�ı����򷽷�������Ҫ����Ϊ extern "C"������cpp�еı����򷽷���c������ȥ����
//��ʱ, ������Ҫʹ��extern "C"���������ʱ�����C��ʽ�����⣬
//.cpp�ļ��еĴ�����԰���C++��ʽ��д������
//
//devVar.cpp�������淽ʽд��Ҳ����ȷ�ġ�
//hello world



extern "C" int i = 100;
extern "C" void func()
{
		printf("--- %d\n", i++);
}
