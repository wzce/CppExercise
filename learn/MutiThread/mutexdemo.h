#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>

using namespace std;

mutex mu;  //线程互斥对象

int totalNum = 50;


volatile int counter(0); // non-atomic counter  
 

void attempt_10k_increases() {
	for (int i = 0; i<10000; ++i) {
		if (mu.try_lock()) {   // only increase if currently not locked:  
			++counter;
			mu.unlock();
			break;
		}
	}
}

void tryLockDemo(){
	std::thread threads[10];
	// spawn 10 threads:  
	for (int i = 0; i<10; ++i)
		threads[i] = std::thread(attempt_10k_increases);

	for (auto& th : threads) th.join();
	std::cout << counter << " successful increases of the counter.\n";
}

void thread01()
{
	while (totalNum > 0)
	{
		mu.lock(); //同步数据锁
		cout << this_thread::get_id()  << " | thread01 ,totalNum: " << totalNum << endl;
		totalNum--;
		mu.unlock();  //解除锁定
		Sleep(100);
	}
}
void thread02()
{
	while (totalNum > 0)
	{
		mu.lock();
		cout << this_thread::get_id() << " | thread02 ,totalNum: " << totalNum << endl;
		totalNum--;
		Sleep(100);
		mu.unlock();
	}
}

int mutexDemo()
{
	thread task01(thread01);
	thread task02(thread02);
	thread task03(thread01);
	task01.join();
	task02.join();
	task03.join();
	//system("pause");

	return 1;
}