#include<iostream>
//#include <math.h>
using namespace std;

long long transfer(char*num){
	long long res = 0;
	int len = strlen(num);
	if (len == 0){
		return 0;
	}
	for (int i = 0; i <len; i++){
		if (num[i] >= '0'&&num[i] <= '9'){
			res = res * 13 + num[i] - '0';
		}
		else{
			res = res * 13 + (num[i] - 'A' + 10);
		}
	}

	return res;
}


void printF(long long num){

	if (num<0){
		cout << "-";
		num = -num;
	}

	char str[100];
	long long n = num;
	long long rem = 0;//余数
	int index = 0;
	while (n != 0){
		rem = n % 13;
		if (rem > 9){
			str[index] = rem - 10 + 'A';
		}
		else{
			str[index] = rem + '0';
		}
		//<< " index ------------------ rem: " << rem << endl;
		n = n / 13;
		//cout << " index ------------------  " << index << " str[index]:" << str[index] << endl;
		index++;
	}
	str[index] == '/0';

	int len = strlen(str);
	//逆序输出
	for (int i = index - 1; i >= 0; i--){
		cout << str[i];
	}
	//当结果为0 的时候，str是空的，需输出
	if (index == 0){
		cout << 0;
	}

}

long long exercise5(){
	char num1[100], num2[100], command[100];
	cin >> command >> num1 >> num2;
	long long n1 = transfer(num1);
	long long n2 = transfer(num2);
	long long res;
	// << "------------------ c:" << command << "  n1:"<< n1 <<"  n2:"<<n2 << endl;
	if (strcmp(command, "add") == 0){
		//cout << "------------------" << n1 << n2 << endl;
		res = n1 + n2;
	}
	else if (strcmp(command, "sub") == 0){
		res = n1 - n2;
	}
	else if (strcmp(command, "mul") == 0){
		res = n1 * n2;
	}
	else{

		if (n2 == 0){
			if (n1>0){
				cout << "+INF";
			}
			else if (n1>0){
				cout << "-INF";
			}
			else{
				cout << "NAN";
			}

			return 0;
		}
		res = n1 / n2;
	
	}

	//cout << "res:" << res<< endl;
	printF(res);
	return 0;
}

int main(){
	exercise5();
	return 1;
}