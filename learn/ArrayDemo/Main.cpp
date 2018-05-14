#include<iostream>
#include<memory>
using namespace std;

class A 	//»ùÀà
{
protected:
	int x, y;
public:
	void virtual f(){
		cout << " A ::f()" << endl;
	}

	void g(){
		cout << " A ::g()" << endl;
	};
};

class B : public A
{

public:
	void h() {
		x = 1;
		f(1);
		A::f();
	}

	void f(int){
		cout << " B ::f()" << endl;
	};
};


int main(){
	int a1[] = {0,1,2,3,4,5,6,7,8,9};
	cout << "size of a1:" <<sizeof(a1)<< endl;

	shared_ptr<int> p2(new int(42));


	B b;
	b.f(1);        //Ok
	b.A::f(); 	   //Ok   BAD

	plus<int> intAdd;


	return 1;
}