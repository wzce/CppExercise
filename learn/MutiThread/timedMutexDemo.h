// timed_mutex::try_lock_for example
#include <iostream>       // std::cout
#include <chrono>         // std::chrono::milliseconds
#include <thread>         // std::thread
#include <mutex>          // std::timed_mutex

using namespace std;
 timed_mutex mtx;

 int index=10;

void fireworks() {
	// waiting to get a lock: each thread prints "-" every 200ms:
	while (!mtx.try_lock_for(std::chrono::milliseconds(200))) {
		cout << "-"  ;
	}
	// got a lock! - wait for 1s, then this thread prints "*"
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "*  thread_id:" << this_thread::get_id() << endl;;

	index--;
	cout << "index: " << index << endl;
	mtx.unlock();
}

int timeMutexDemo()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i<10; ++i)
		threads[i] = std::thread(fireworks);

	for (auto& th : threads) th.join();

	return 0;
}