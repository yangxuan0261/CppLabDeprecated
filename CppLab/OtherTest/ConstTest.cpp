//#include <stdlib.h>
//#include <iostream>
//#include <sstream>
//#include <string>
//
//class Car
//{
//public: 
//	void Run() const { printf("--- Car Run\n"); }
//	void Stop()  { printf("--- Car Stop\n"); }
//};
//
//void carFunc(const Car* _car)
//{
//	_car->Run();
//
//	Car* tmpCar = const_cast<Car*>(_car); //È¥³ýconstÏÞ¶¨
//	tmpCar->Stop();
//}
//
//void testConst()
//{
//	Car* car = new Car;
//	carFunc(car);
//}
//
//int main()
//{
//	testConst();
//	//testSizeof2();
//	system("pause");
//	return 0;
//}