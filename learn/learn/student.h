#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student{
private:

public:
	string name = "default name";
	int age;
	string sex;

	Student(){
		//name = "name";
		age = 0;
		sex = "ÄÐ";
		cout << "Student construct ,name: " << name << endl;
	}

	void setSex(string sex){
		this->sex = sex;
	}

	void show(){
		cout << "show student, name : " << name << "  ,sex: " << sex << endl;
	}

	~Student(){
		cout << "Student destroy , name : " << name << "   ,age : " << age << "  ,sex: " << sex << endl;
	}

};



class StudentList{

private:
	vector<Student> list;

public:
	void add(Student &s){
		cout << "  before----------------add " << endl;
		list.push_back(s);
		cout << "  after-----------------add " << endl;

	}

	void showList(){
		vector<Student>::iterator it = list.begin();
		while (it != list.end())
		{
			it->show();
			it++;
		}

	}
};