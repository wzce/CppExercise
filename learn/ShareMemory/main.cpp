#include<string>
#include<iostream>

#include <chrono>
#include <thread>

#include"share.h"
using namespace std;



int main(){

	SharedMemory share;

	int flag = false;

	while (true){
		if (!flag){
			share.Init("demo");
			share.IntPutData("demo", string("this is a shered memory string."));
			flag = true;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10000));//睡眠10s
		cout << " -" << endl;
		cout << "获取的共享内存 的值 demo : " << share.OutPutData("demo") << endl;
	}

	return 1;
}