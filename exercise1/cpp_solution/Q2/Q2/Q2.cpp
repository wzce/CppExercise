#include<iostream>
using namespace std;


long long exercise2(){
	int num, x;
	cin >> num;
	cin >> x;

	if (num == 0){
		return 0;
	}
	if (x == 0){
		return 1;
	}

	long long res = 1;

	for (int i = 0; i < x; i++){
		res = res * num;
	}

	return res;
}

int main(){
	cout << exercise2();
	double c = 0.2323;
	//int a = c1;
	return 1;
}