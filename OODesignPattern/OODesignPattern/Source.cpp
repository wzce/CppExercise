#include<iostream>
#include"single.h"
using namespace std;


int main(){
	SingleTon *s1 = SingleTon::getInstance();
	SingleTon *s2 = SingleTon::getInstance();

	cout << "s1�ĵ�ַ: " << s1 << "  s2�ĵ�ַ: "<< s2<< "  �Ƿ����: "<< (s1==s2)<<endl;
	//delete s1;
	//cout << "11 s1�ĵ�ַ: " << s1 << "  s2�ĵ�ַ: " << s2 << "  �Ƿ����: " << (s1 == s2) << endl;
	HungrySingleTon* hs1 = HungrySingleTon::getInstance();
	HungrySingleTon* hs2 = HungrySingleTon::getInstance();
	cout << "hs1�ĵ�ַ: " << hs1 << "  hs2�ĵ�ַ: " << hs2 << "  �Ƿ����: " << (hs1 == hs2) << endl;

	return 1;
}