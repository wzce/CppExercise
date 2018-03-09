#include <iostream>  
#include <string>  
#include <cctype>  
#include <algorithm>  
using namespace std;

void exercise10(){
	int num;
	string str;
	cin >> num >> str;
	if (num == 1){
		cout << 1;
		return;
	}
	int max = 0;
	int index;
	for (int i = 1; i < num; i++){
		int length = 1;
		index = 1;
		//奇数个情况
		while ((i + index) < num && (i - index) >= 0 
		&& str[i + index] == str[i - index]){
			length = length + 2;
			index++;
		}
		if (length>max){
			max = length;
		}
		//偶数个情况
		length = 0;
		int min = i;
		int m = i + 1;
		while (m < num && min >= 0 && str[min] == str[m]){
			length = length + 2;
			min--;
			m++;
		}
		if (length>max){
			max = length;
		}
	}
	cout << max;
}


int main(){
	exercise10();
	return 1;
}