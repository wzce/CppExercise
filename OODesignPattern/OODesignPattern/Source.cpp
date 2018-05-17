#include<iostream>
#include"single.h"
using namespace std;


int main(){
	SingleTon *s1 = SingleTon::getInstance();
	SingleTon *s2 = SingleTon::getInstance();

	cout << "s1的地址: " << s1 << "  s2的地址: "<< s2<< "  是否相等: "<< (s1==s2)<<endl;
	//delete s1;
	//cout << "11 s1的地址: " << s1 << "  s2的地址: " << s2 << "  是否相等: " << (s1 == s2) << endl;
	HungrySingleTon* hs1 = HungrySingleTon::getInstance();
	HungrySingleTon* hs2 = HungrySingleTon::getInstance();
	cout << "hs1的地址: " << hs1 << "  hs2的地址: " << hs2 << "  是否相等: " << (hs1 == hs2) << endl;

	return 1;
}