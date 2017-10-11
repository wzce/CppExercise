#include<iostream>
#include<string>
using namespace std;

int map(char c);

int exercise14(){
	char input[100];
	cin >> input;
	int length = strlen(input);
	int res = map(input[0]);
	for (int i = 1; i < length; i++){
		if (map(input[i]) > map(input[i - 1])){
			res = res + map(input[i]) - map(input[i - 1]) * 2;
		}
		else{
			res += map(input[i]);
		}
	}
	cout << res ;
	//system("pause");
	return 0;
}
int map(char c)
{
	switch (c){
	case 'I':return 1; break;
	case 'V':return 5; break;
	case 'X':return 10; break;
	case 'L':return 50; break;
	case 'C':return 100; break;
	case 'D':return 500; break;
	case 'M':return 1000; break;
	default:break;
	}
	return 0;
}

int main(){
	exercise14();
	//cout << 11;
	return 0;
}