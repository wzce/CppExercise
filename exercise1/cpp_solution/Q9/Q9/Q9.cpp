#include<iostream>
#include <math.h>
using namespace std;

bool isPrime(long long num)
{
	if (num == 1){
		return 0;
	}
	//������С�����⴦��  
	if (num == 2 || num == 3)
		return 1;
	//����6�ı��������һ����������  
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	//��6�ı��������Ҳ���ܲ�������  
	for (int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	//�ų����У�ʣ���������  
	return 1;
}


long long exercise4(){
	long long num1, num2;

	cin >> num1;
	cin >> num2;

	long long res = 0;

	for (long long i = num1; i <= num2; i++){
		if (isPrime(i)){
			//cout << i << endl;
			res = res + i;
		}
	}
	cout << res;
	return res;
}

int main(){
	exercise4();
	return 1;
}