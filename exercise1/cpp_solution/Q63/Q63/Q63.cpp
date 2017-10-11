
#include<iostream>
#include<string>
using namespace std;

long long power(int num, int  x){
	long long res = 1;

	if (num == 0){
		return 0;
	}

	if (x == 0){
		return 1;
	}

	int flag = 0;
	if (x<0){
		flag = 1;
		x = -x;
	}

	for (int i = 0; i < x; i++){
		res = res*num;
	}
	return res;
}

long long* sub(long long*list, int num, int len){
	for (int i = 0; i < len; i++){
		list[i] = list[i] - num;
	}
	return list;
}

long long * add(long long*list, int num, int len){
	for (int i = 0; i < len; i++){
		list[i] = list[i] + num;
	}
	return list;
}

long long* mul(long long*list, int num, int len){
	for (int i = 0; i < len; i++){
		list[i] = list[i] * num;
	}
	return list;
}

long long sqa(long long*list, int len){
	long long res = 0;
	for (int i = 0; i < len; i++){
		res = res + list[i] * list[i];
	}
	return res;
}

void printF(long long*list, int len){
	for (int i = 0; i < len; i++){
		cout << list[i];
		if (i == len - 1){
			cout << endl;
		}
		else{
			cout << " ";
		}
	}
}


void exercise3(){
	int len;
	cin >> len;
	long long * list = new long long[len];
	for (int i = 0; i < len; i++){
		long long c;
		cin >> c;
		list[i] = c;
	}
	//cout << "----------------------------------" << endl;
	int commandNum;
	cin >> commandNum;

	string*command = new string[commandNum];
	int *val = new int[commandNum];

	for (int j = 0; j < commandNum; j++){
		cin >> command[j];
		if (command[j].compare("sqa") == 0 || command[j].compare("print") == 0){
			val[j] == 0;
		}
		else{
			cin >> val[j];
		}
	}

	for (int j = 0; j < commandNum; j++){
		if (command[j].compare("add") == 0){
			add(list, val[j], len);
		}
		if (command[j].compare("sub") == 0){
			sub(list, val[j], len);
		}
		if (command[j].compare("mul") == 0){
			mul(list, val[j], len);
		}
		if (command[j].compare("pow") == 0){
			for (int k = 0; k < len; k++){
				list[k] = power(list[k], val[j]);
			}
		}

		if (command[j].compare("print") == 0){
			printF(list, len);
		}

		if (command[j].compare("sqa") == 0){
			//long long res = sq(list, len);
			cout << sqa(list, len) << endl;
		}

		//cout << command[j];
	}
	/*
	delete val;
	delete command;
	delete list;*/
	/*
	for (int i = 0; i < len; i++){
	cout << list[i];
	}
	*/
}


int main(){
	exercise3();
	return 1;
}