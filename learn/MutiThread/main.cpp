#include<string>
#include<iostream>
#include"demo.h"
#include"mutexdemo.h"
#include"timedMutexDemo.h"
using namespace std;

int main(){
	cout << "��ʼ" << endl;
	//demo();
	//mutexDemo();
	//timeMutexDemo();
	tryLockDemo();
	cout << "����" << endl;
	return 1;
}
