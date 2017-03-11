//��̫�ֲ�
#include <iostream>
#include <time.h>
#include <random>
#include <functional>

void randNumTest()
{
	std::minstd_rand0 generator0(time(NULL)); // linear_congruential_engine ����ͬ�෨
	std::default_random_engine generator1(time(NULL)); // mersenne_twister_engine ÷ɭ��ת��
	std::uniform_int_distribution<int> distInt(100, 200); // uniform_int_distribution �������ȷֲ�
	std::uniform_real_distribution<float> distFloat(0.f, 100.f); // uniform_real_distribution ���������ȷֲ�

	auto dice = std::bind(distInt, generator1);
	for (int i = 0; i < 5; i++)
		std::cout << dice() << std::endl;
}

//int main()
//{
//	randNumTest();
//	system("pause");
//}