
#include<iostream>
using namespace std;

int main(){
	int num;
	cin >> num;

	if (num == 1 || num == 0){
		return num;
	}

	long long min = 0, max = 1, tmp = 0;
	for (int i = 2; i <= num; i++){
		tmp = min + max;
		min = max;
		max = tmp;
	}

	cout<< tmp;
	return 0;
}