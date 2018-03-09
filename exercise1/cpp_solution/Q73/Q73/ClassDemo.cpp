#include<iostream>
#include<string>
using namespace std;

class Parent{
public:
	string name;
	int age;
	Parent();
	void setAge(int a){
		this->age = a;
	}
	void setName(string name){
		this->name = name;
	}
	virtual void show(){
		cout << "name: " << name << "  age:" << age;
	}
};

class P1 :public Parent{
public:
	int weight;
	void setWeight(int a){
		this->weight= a;
	}
	void show(){
		cout << "name: " << name << "  age:" << age;
	}
};

int main(){

	cout << "demo" << endl;
	P1 p1;
	p1.setAge(22);
	p1.setName("wei zuce");
	p1.setWeight(120);
	p1.show();
	return 1;
}