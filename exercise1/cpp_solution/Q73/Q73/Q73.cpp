#include<iostream>
#include<string>
using namespace std;

char ch[10][4] = {
		{},//0
		{},//1
		{ 'a', 'b', 'c' },//2
		{ 'd', 'e', 'f' },//3
		{ 'g', 'h', 'i' },//4
		{ 'j', 'k', 'l' },//5
		{ 'm', 'n', 'o' },//6
		{ 'p', 'q', 'r', 's' },//7
		{ 't', 'u', 'v' },//8
		{ 'w', 'x', 'y', 'z' }//9
};

void exercise15(){
	int num;
	cin >> num;
	int *number = new int[10000000];
	int length = 0;
	int rem;


	//��������
	while (num != 0){
		rem = num % 10;
		number[length] = rem;
		num = num / 10;
		length++;
	}

	//������������������
	string *pre = new string[1000000];
	string *result = new string[1000000];
	int index = 0, preIndex = 0;
	int preLength = 0;
	int charLength;
	for (int i = length - 1; i >= 0; i--){
		index = 0;
		charLength = 3;
		if (number[i] == 9 || number[i] == 7){
			charLength = 4;
		}

		//��һ�ε�ʱ��pre����Ϊ�յ����
		if (preLength == 0){
			for (int k = 0; k < charLength; k++){
				string* s1 = new string("");
				s1->append(1, ch[number[i]][k]);
				result[index] = *s1;
				index++;

			}

			preLength = index;
			//�ѽ����ֵ����һ�������е�pre������ȥ
			for (int m = 0; m < index; m++){
				string *str = new string();
				str->append(result[m]);
				pre[m] = *str;
				//cout << " pre[m]" << pre[m] << endl;;
			}
			//cout << "�������ķָ���================================================================================" << endl;
			continue;
		}


		for (int j = 0; j < preLength; j++){
			for (int k = 0; k < charLength; k++){
				string* s = new string();
				s->append(pre[j]);
				s->append(1, ch[number[i]][k]);
				result[index] = *s;
				index++;
			}
		}

		//�ѽ����ֵ����һ�������е�pre������ȥ
		for (int m = 0; m < index; m++){
			string *str = new string(result[m]);
			pre[m] = *str;
		}

		preLength = index;

	}


	//������
	for (int i = 0; i < index-1; i++){
		cout << result[i] << endl;
	}

	cout << result[index-1];

}


int main(){
	exercise15();
	return 1;
}