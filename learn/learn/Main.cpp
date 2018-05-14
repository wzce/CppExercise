#include<iostream>
#include<string>
#include<vector>
#include"student.h"
using namespace std;
 
Student addAge(Student ss){
	Student s = ss;
	s.age++;
	s.name = s.name + "_new";
	return s;
}

int main(){
	Student s;
	s.name = "s";
	s.age = 11;
	s.sex = "Å®";

	Student sss = addAge(s);
	/*
	StudentList list;
	list.add(s);
	Student ss;
	ss.name = "ss";
	ss.age = 22;
	ss.sex = "ÄĞ";
	list.add(ss);

	list.showList();
	*/

	cout << "   -----------------------------------" << endl;

	int *i = new int(1234);

	cout << "address i:" << i << "  value i: " << *i << endl;
	return 1;
}