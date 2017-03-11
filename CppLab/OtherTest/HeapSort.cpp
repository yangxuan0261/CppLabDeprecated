#include<iostream>
using namespace std;

inline void Swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

//  �¼���i���  �丸���Ϊ(i - 1) / 2
void MinHeapFixup(int a[], int i)
{
	int j, temp;

	temp = a[i];
	j = (i - 1) / 2;      //�����
	while (j >= 0 && i != 0)
	{
		if (a[j] <= temp)
			break;

		a[i] = a[j];     //�ѽϴ���ӽ�������ƶ�,�滻�����ӽ��
		i = j;
		j = (i - 1) / 2;
	}
	a[i] = temp;
}

//����С���м����µ�����nNum
void MinHeapAddNumber(int a[], int n, int nNum)
{
	a[n] = nNum;
	MinHeapFixup(a, n);
}

//  ��i�ڵ㿪ʼ����,nΪ�ڵ����� ��0��ʼ���� i�ڵ���ӽڵ�Ϊ 2*i+1, 2*i+2
void MinHeapFixdown(int a[], int i, int n)
{
	int j, temp;

	temp = a[i];
	j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1 < n && a[j + 1] < a[j]) //�����Һ���������С��
			j++;

		if (a[j] >= temp)
			break;

		a[i] = a[j];     //�ѽ�С���ӽ�������ƶ�,�滻���ĸ����
		i = j;
		j = 2 * i + 1;
	}
	a[i] = temp;
}
//����С����ɾ����
void MinHeapDeleteNumber(int a[], int n)
{
	Swap(a[0], a[n - 1]);
	MinHeapFixdown(a, 0, n - 1);
}

//������С��
void MakeMinHeap(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		MinHeapFixdown(a, i, n);
}

void PrintArr(int a[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << a[i] << " - ";
	}
	cout << endl;
}

//int main()
//{
//	
//	int a[10] = { 9, 12, 17, 30, 50, 20, 60, 65, 4, 49 };
//	int length = sizeof(a) / sizeof(int);
//	PrintArr(a, length);
//
//	MakeMinHeap(a, length);
//	PrintArr(a, length);
//
//	system("pause");
//}

/*
�㷨˼�룺�洢�ṹΪ���飬�߼��ṹΪ������
1���ѻ����飬�����0~length-1���ɶ������ṹ
2�����µ��������±�Ϊlength / 2 - 1��λ�ÿ�ʼ������ǰ���µ�������Ϊ����±������һ��ӵ�к��ӽڵ��λ��
3��ɾ����С�����ֵ�����ӶѶ�ɾ�������һ��Ԫ�ز��϶Ѷ����Ѷ������µ���
3�����ֵ���Ӷ�β��ӣ������ϵ���
*/