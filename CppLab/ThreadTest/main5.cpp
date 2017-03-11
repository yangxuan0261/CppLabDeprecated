//#include <iostream>       // std::cout
//#include <functional>     // std::ref
//#include <thread>         // std::thread
//#include <future>         // std::promise, std::future
//
//void print_int(std::future<int>& fut) {
//	int x = fut.get(); // ��ȡ����״̬��ֵ.
//	std::cout << "value: " << x << '\n'; // ��ӡ value: 10.
//}
//
//int main()
//{
//	std::promise<int> prom; // ����һ�� std::promise<int> ����.
//	std::future<int> fut = prom.get_future(); // �� future ����.
//	std::thread t(print_int, std::ref(fut)); // �� future ��������һ���߳�t.
//	prom.set_value(10); // ���ù���״̬��ֵ, �˴����߳�t����ͬ��.
//	t.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <future>         // std::promise, std::future
//
//std::promise<int> prom;
//
//void print_global_promise() {
//	std::future<int> fut = prom.get_future();
//	int x = fut.get();
//	std::cout << "value: " << x << '\n';
//}
//
//int main()
//{
//	std::thread th1(print_global_promise);
//	prom.set_value(10);
//	th1.join();
//
//	prom = std::promise<int>();    // prom ��move��ֵΪһ���µ� promise ����.
//
//	std::thread th2(print_global_promise);
//	prom.set_value(20);
//
//	std::cout << "come here\n";
//	th2.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>       // std::cin, std::cout, std::ios
//#include <functional>     // std::ref
//#include <thread>         // std::thread
//#include <future>         // std::promise, std::future
//#include <exception>      // std::exception, std::current_exception
//
//void get_int(std::promise<int>& prom) {
//	int x;
//	std::cout << "Please, enter an integer value: ";
//	std::cin.exceptions(std::ios::failbit);   // throw on failbit
//	try {
//		std::cin >> x;                         // sets failbit if input is not int
//		prom.set_value(x);
//	}
//	catch (std::exception&) {
//		prom.set_exception(std::current_exception());
//	}
//}
//
//void print_int(std::future<int>& fut) {
//	try {
//		int x = fut.get();
//		std::cout << "value: " << x << '\n';
//	}
//	catch (std::exception& e) {
//		std::cout << "[exception caught: " << e.what() << "]\n";
//	}
//}
//
//int main()
//{
//	std::promise<int> prom;
//	std::future<int> fut = prom.get_future();
//
//	std::thread th1(get_int, std::ref(prom));
//	std::thread th2(print_int, std::ref(fut));
//
//	th1.join();
//	th2.join();
//
//	system("pause");
//	return 0;
//}