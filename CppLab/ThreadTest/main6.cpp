//#include <iostream>     // std::cout
//#include <future>       // std::packaged_task, std::future
//#include <chrono>       // std::chrono::seconds
//#include <thread>       // std::thread, std::this_thread::sleep_for
//
//// count down taking a second for each value:
//int countdown(int from, int to) {
//	for (int i = from; i != to; --i) {
//		std::cout << i << '\n';
//		std::this_thread::sleep_for(std::chrono::seconds(1));
//	}
//	std::cout << "Finished!\n";
//	return from - to;
//}
//
//int main()
//{
//	std::packaged_task<int(int, int)> task(countdown); // ���� packaged_task
//	std::future<int> ret = task.get_future(); // ����� packaged_task ����״̬������� future ����.
//
//	std::thread th(std::move(task), 10, 0);   //����һ�����߳���ɼ�������.
//
//	int value = ret.get();                    // �ȴ�������ɲ���ȡ���.
//
//	std::cout << "The countdown lasted for " << value << " seconds.\n";
//
//	th.join();
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>     // std::cout
//#include <utility>      // std::move
//#include <future>       // std::packaged_task, std::future
//#include <thread>       // std::thread
//
//int main()
//{
//	std::packaged_task<int(int)> foo; // Ĭ�Ϲ��캯��.
//
//	// ʹ�� lambda ���ʽ��ʼ��һ�� packaged_task ����.
//	std::packaged_task<int(int)> bar([](int x){return x * 2; });
//
//	foo = std::move(bar); // move-��ֵ������Ҳ�� C++11 �е�������.
//
//	// ��ȡ�� packaged_task ����״̬������� future ����.
//	std::future<int> ret = foo.get_future();
//
//	std::thread(std::move(foo), 10).detach(); // �����̣߳����ñ���װ������.
//
//	int value = ret.get(); // �ȴ�������ɲ���ȡ���.
//	std::cout << "The double of 10 is " << value << ".\n";
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>     // std::cout
//#include <utility>      // std::move
//#include <future>       // std::packaged_task, std::future
//#include <thread>       // std::thread
//
//// �����߳�������һ�� int(int) packaged_task.
//std::future<int> launcher(std::packaged_task<int(int)>& tsk, int arg)
//{
//	if (tsk.valid()) {
//		std::future<int> ret = tsk.get_future();
//		std::thread(std::move(tsk), arg).detach();
//		return ret;
//	}
//	else return std::future<int>();
//}
//
//int main()
//{
//	std::packaged_task<int(int)> tsk([](int x){return x * 2; });
//
//	std::future<int> fut = launcher(tsk, 25);
//
//	std::cout << "The double of 25 is " << fut.get() << ".\n";
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>     // std::cout
//#include <utility>      // std::move
//#include <future>       // std::packaged_task, std::future
//#include <thread>       // std::thread
//
//int main()
//{
//	std::packaged_task<int(int)> tsk([](int x) { return x * 3; }); // package task
//
//	std::future<int> fut = tsk.get_future();   // ��ȡ future ����.
//
//	std::thread(std::move(tsk), 100).detach();   // �������̲߳�����packaged_task.
//
//	int value = fut.get();                     // �ȴ��������, ����ȡ���.
//
//	std::cout << "The triple of 100 is " << value << ".\n";
//
//	system("pause");
//	return 0;
//}

//#########################################################

//#include <iostream>     // std::cout
//#include <utility>      // std::move
//#include <future>       // std::packaged_task, std::future
//#include <thread>       // std::thread
//
//// a simple task:
//int triple(int x) { return x * 3; }
//
//int main()
//{
//	std::packaged_task<int(int)> tsk(triple); // package task
//
//
//	std::future<int> fut = tsk.get_future();
//	std::thread(std::move(tsk), 100).detach();
//	std::cout << "The triple of 100 is " << fut.get() << ".\n";
//
//
//	// re-use same task object:
//	//tsk.reset();
//	//fut = tsk.get_future();
//	//std::thread(std::move(tsk), 200).detach();
//	//std::cout << "Thre triple of 200 is " << fut.get() << ".\n";
//
//	system("pause");
//	return 0;
//}