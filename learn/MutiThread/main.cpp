#include<string>
#include<iostream>
#include"demo.h"
#include"mutexdemo.h"
#include"timedMutexDemo.h"
using namespace std;

int main(){
	cout << "¿ªÊ¼" << endl;
	//demo();
	//mutexDemo();
	//timeMutexDemo();
	tryLockDemo();
	cout << "½áÊø" << endl;
	return 1;
}
