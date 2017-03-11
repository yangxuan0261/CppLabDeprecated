//// by MoreWindows( http://blog.csdn.net/MoreWindows )
//#include <cstdio>
//#include <algorithm>
//#include <ctime>
//using namespace std;
////------------------------��������----------------------------
//void quick_sort(int s[], int l, int r)
//{
//	if (l < r)
//	{
//		int i = l, j = r, x = s[l];
//		while (i < j)
//		{
//			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����
//				j--;
//			if (i < j)
//				s[i++] = s[j];
//
//			while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
//				i++;
//			if (i < j)
//				s[j--] = s[i];
//		}
//		s[i] = x;
//		quick_sort(s, l, i - 1); // �ݹ���� 
//		quick_sort(s, i + 1, r);
//	}
//}
////------------------------�鲢����----------------------------
////���ж�����������a[first...mid]��a[mid...last]�ϲ���
//void mergearray(int a[], int first, int mid, int last, int temp[])
//{
//	int i = first, j = mid + 1;
//	int m = mid, n = last;
//	int k = 0;
//
//	while (i <= m && j <= n)
//	{
//		if (a[i] < a[j])
//			temp[k++] = a[i++];
//		else
//			temp[k++] = a[j++];
//	}
//
//	while (i <= m)
//		temp[k++] = a[i++];
//
//	while (j <= n)
//		temp[k++] = a[j++];
//
//	for (i = 0; i < k; i++)
//		a[first + i] = temp[i];
//}
//void mergesort(int a[], int first, int last, int temp[])
//{
//	if (first < last)
//	{
//		int mid = (first + last) / 2;
//		mergesort(a, first, mid, temp);    //�������
//		mergesort(a, mid + 1, last, temp); //�ұ�����
//		mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�
//	}
//}
//bool MergeSort(int a[], int n)
//{
//	int *p = new int[n];
//	if (p == NULL)
//		return false;
//	mergesort(a, 0, n - 1, p);
//	return true;
//}
////------------------------������---------------------------
//inline void Swap(int &a, int &b)
//{
//	int c = a;
//	a = b;
//	b = c;
//}
////������С��
////  ��i�ڵ㿪ʼ����,nΪ�ڵ����� ��0��ʼ���� i�ڵ���ӽڵ�Ϊ 2*i+1, 2*i+2
//void MinHeapFixdown(int a[], int i, int n)
//{
//	int j, temp;
//
//	temp = a[i];
//	j = 2 * i + 1;
//	while (j < n)
//	{
//		if (j + 1 < n && a[j + 1] < a[j]) //�����Һ���������С��
//			j++;
//
//		if (a[j] >= temp)
//			break;
//
//		a[i] = a[j];     //�ѽ�С���ӽ�������ƶ�,�滻���ĸ����
//		i = j;
//		j = 2 * i + 1;
//	}
//	a[i] = temp;
//}
////������С��
//void MakeMinHeap(int a[], int n)
//{
//	for (int i = n / 2 - 1; i >= 0; i--)
//		MinHeapFixdown(a, i, n);
//}
//void MinheapsortTodescendarray(int a[], int n)
//{
//	for (int i = n - 1; i >= 1; i--)
//	{
//		Swap(a[i], a[0]);
//		MinHeapFixdown(a, 0, i);
//	}
//}
//const int MAXN = 5000000;
//int a[MAXN];
//int b[MAXN], c[MAXN], d[MAXN];
//int main()
//{
//	int i;
//	srand(time(NULL));
//	for (i = 0; i < MAXN; ++i)
//		a[i] = rand() * rand(); //עrand()����������0��0x7FFF֮��
//
//	for (i = 0; i < MAXN; ++i)
//		d[i] = c[i] = b[i] = a[i];
//
//	clock_t ibegin, iend;
//
//	printf("--��ǰ������Ϊ%d--By MoreWindows(http://blog.csdn.net/MoreWindows)--\n", MAXN);
//	//��������
//	printf("��������:  ");
//	ibegin = clock();
//	quick_sort(a, 0, MAXN - 1);
//	iend = clock();
//	printf("%d����\n", iend - ibegin);
//
//
//	//�鲢����
//	printf("�鲢����:  ");
//	ibegin = clock();
//	MergeSort(b, MAXN);
//	iend = clock();
//	printf("%d����\n", iend - ibegin);
//
//	//������
//	printf("������:  ");
//	ibegin = clock();
//	MakeMinHeap(c, MAXN);
//	MinheapsortTodescendarray(c, MAXN);
//	iend = clock();
//	printf("%d����\n", iend - ibegin);
//
//	//STL�еĶ�����
//	printf("STL�еĶ�����: ");
//	ibegin = clock();
//	make_heap(d, d + MAXN);
//	sort_heap(d, d + MAXN);
//	iend = clock();
//	printf("%d����\n", iend - ibegin);
//
//	system("pause");
//	return 0;
//}