#include<iostream>
//#include <math.h>
#include<string>
using namespace std;


long long bitLength(long long num){
	long long res = 0;
	long long n = num;
	while (n != 0){
		n = n / 2;
		res++;
	}
	return res;
}


long long exercise6(){
	long long res = 0;

	int num;
	cin >> num;

	long long n;

	for (int i = 0; i < num; i++){
		cin >> n;
		long long  length = bitLength(n);
		if (length>3){
			res = res + (n >> (length - 3));
		}
		else{
			res = res + n;
		}
	}

	cout << res;

	return res;
}

int main(){
	exercise6();
	return 0;
}