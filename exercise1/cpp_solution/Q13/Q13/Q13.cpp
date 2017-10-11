#include<iostream>
#include<string>
#include <iomanip>
using namespace std;


int f(int n)
{
	if (n == 1)
		return 1;
	else
		return f(n - 1) + n;
}

void exercise12(){
	int m;
	cin >> m;
	int c = 0;
	int b = 0;
	for (int i = 1;; i++)
		if (f(i) >= m)
		{
		c = f(i) - m;
		b = i;
		break;
		}
	if (b % 2 != 0)
		cout << (c + 1) << "/" << (b - c);
	else
		cout << (b - c) << "/" << (c + 1);
}


int main(){
	exercise12();
	return 1;
}