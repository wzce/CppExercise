#include<iostream>
#include<math.h>

using namespace std;

int exercise7(){
	char input[100];
	cin >> input;
	int length = strlen(input);
	int i = 0;
	while ((pow(2, i) - length - 1 - i)<0){
		i++;
	}
	int bitLength = i;

	char *res = new char[bitLength + length];
	int index = 0;
	int oriindex = 0;
	for (int j = 0; j<bitLength + length; j++){
		if (j == pow(2, index) - 1){
			res[j] = '*';
			index++;
		}
		else{
			res[j] = input[oriindex];
			oriindex++;
		}
	}

	int len = 0;
	//假设是偶校验
	for (int j = 0; j<bitLength; j++){
		int count = 0;
		int pos = pow(2, j) - 1;
		int testindex = pos;
		while (testindex<bitLength + length){
			//读取
			for (int k = 0; k<pow(2, j); k++){
				if (testindex >= bitLength + length){
					break;
				}
				if (res[testindex] == '1'){
					count++;
				}
				else if (res[testindex] == '0'){
				}
				else{
				}
				testindex++;
			}
			for (int k = 0; k<pow(2, j); k++){
				if (testindex >= bitLength + length){
					break;
				}
				testindex++;
			}

		}
		if (count % 2 == 0){
			res[pos] = '0';
		}
		else{
			res[pos] = '1';
		}
		len = pos;
	}
	
	for (int i = 0; i < bitLength + length;i++){

		cout << res[i];
	}
	

	//cout << res;
	return 0;
}

int main(){
	exercise7();
	return 0;
}