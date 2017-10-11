#include <iostream>  
#include <string>  
#include <cctype>  
#include <algorithm>  
using namespace std;


string reverse(string s1){
	string *res = new string();
	int len = s1.length();
	for (int i = len - 1; i >= 0; i--){
		res->append(1, s1[i]);
	}

	return *res;
}

void exercise9(){
	int num;
	cin >> num;
	string command;
	string value = "";

	string str[10000];
	int index = 0;

	for (int i = 0; i < num; i++){
		cin >> command;
		if (command.compare("append") == 0){
			string append;
			cin >> append;

			value = value.append(append);
		}
		else if (command.compare("replace") == 0){
			string v1, v2;
			cin >> v1 >> v2;

			while (value.find(v1, 0) != 4294967295){
				int location = value.find(v1, 0);
				int length1 = v1.length();
				int length2 = v2.length();

				value.erase(location, length1);
				value.insert(location, v2);
			}
		}
		else if (command.compare("length") == 0){
			string *s = new string;

			int len = value.length();
			int rem;
			char ch;
			while (len != 0){
				rem = len % 10;
				ch = rem + '0';
				s->append(1, ch);
				len = len / 10;
			}
			*s = reverse(*s);
			str[index] = *s;

			//cout << "length: str[index];  " << str[index] <<  "  index :" << index << endl;

			index++;

		}
		else if (command.compare("reverse") == 0){
			value = reverse(value);
		}

		else if (command.compare("changecase") == 0){
			string c1;
			cin >> c1;
			if (c1.compare("up") == 0){
				transform(value.begin(), value.end(), value.begin(), ::toupper);
			}
			else{
				transform(value.begin(), value.end(), value.begin(), ::tolower);
			}

		}

		else if (command.compare("print") == 0){
			string *s = new string;
			s->append(value);
			str[index] = *s;
			//cout << "print: str[index];  " << str[index] <<  "  index :"<<index<< endl;
			index++;
		}

	}

	for (int i = 0; i < index-1; i++){
		cout << str[i] << endl;
	}

	cout << str[index - 1];
}

int main(){
	exercise9();
	return 1;
}