#include<iostream>
//#include <math.h>
#include<string>
using namespace std;

void exercise8(){
	char* str = new char[300000];
	cin.getline(str, 300000);

	int res = 0;
	int pres = 0;
	int len = strlen(str);

	for (int i = 0; i < len; i++){
		if (str[i] != ' '){
			res++;
			pres = res;
		}
		else{
			res = 0;
		}
	}

	if (len>0 && res == 0){
		cout << pres;
	}
	else{
		cout << res;
	}

}

int main(){
	exercise8();
	return 1;
}