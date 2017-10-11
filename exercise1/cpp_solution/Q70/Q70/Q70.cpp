#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

struct student{
	string name;
	int grade;
	int courseNum;
public:
	student(){}
	student(string name, int grade, int courseNum){
		this->name = name;
		this->grade = grade;
		this->courseNum = courseNum;

	}
}s;

struct course{
	string name;
	int grade;
	int courseNum;
public:
	course(){}
	course(string name, int grade, int courseNum){
		this->name = name;
		this->grade = grade;
		this->courseNum = courseNum;

	}
}c;


void exercise11(){
	int n;
	cin >> n;
	student stu[100];
	course cse[100];//默认不会超过100，题中已经说了;
	int stuNum = 0;
	int courseNum = 0;

	string stuName, courseName, stuNo;
	int grade;

	for (int i = 0; i < n; i++){
		cin >> stuName >> stuNo >> courseName >> grade;
		bool isExistStu = false;
		for (int j = 0; j < stuNum; j++){
			if (stuName.compare(stu[j].name) == 0){
				stu[j].courseNum++;
				stu[j].grade = stu[j].grade + grade;
				isExistStu = true;
				break;
			}
		}
		if (!isExistStu){
			student s;
			s.courseNum = courseNum;
			s.grade = grade;
			s.name = stuName;
			s.courseNum = 1;
			stu[stuNum] = s;
			stuNum++;
		}

		bool isExistCourse = false;
		for (int j = 0; j < courseNum; j++){
			if (courseName.compare(cse[j].name) == 0){
				cse[j].courseNum++;
				cse[j].grade = cse[j].grade + grade;
				isExistCourse = true;
				break;
			}
		}
		if (!isExistCourse){
			course cs;
			cs.courseNum = 1;
			cs.grade = grade;
			cs.name = courseName;
			cse[courseNum] = cs;
			courseNum++;
		}
	}

	string str[100];
	double g[100];

	int commandNum;
	cin >> commandNum;
	for (int i = 0; i < commandNum; i++){
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.compare("student") == 0){
			for (int k = 0; k < stuNum; k++){
				if (s2.compare(stu[k].name) == 0){
					str[i] = s2;
					g[i] = (double)stu[k].grade / stu[k].courseNum;
					break;
				}
			}
		}
		else{
			for (int k = 0; k < courseNum; k++){
				if (s2.compare(cse[k].name) == 0){
					str[i] = s2;
					g[i] = (double)cse[k].grade / cse[k].courseNum;
					break;
				}
			}
		}
	}

	for (int i = 0; i < commandNum; i++){
		cout.setf(ios::fixed);
		cout << str[i] << " " << setprecision(2) << g[i] << endl;
	}


}

int main(){
	exercise11();
	return 1;
}