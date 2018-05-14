#include <iostream>
#include <thread>

using namespace std;

int sum = 0;

struct Node{
	int x=0;
	int y=0;
	void show(){
		cout << "x: " << x << "  ,y: " << y << endl;
	}
};

void update(Node &node){
	node.x = 10;
	node.y = 10;
}

void output(int i)
{
	sum++;
	//cout << "--------------------��ǰ���߳�id:" << this_thread::get_id() <<"-------------"<< endl;
	cout <<" thread ��������ֵ: " << i << "     sum:  "<<sum<<endl;
}

int demo()
{
	cout << "����4���߳�" << endl;
	thread t[4];
	for (uint8_t i = 0; i < 4; i++)
	{
		t[i]=thread(output, i);
	}

	cout << "--------1---" << endl;

	for (int i = 0; i < 4;i++){
		t[i].join();
	
	}
	cout << "--------end-----sum: " <<sum<< endl;

	Node n;
	n.show();
	cout << "-----------------------" << endl;
	thread tt(update,n);
	tt.join();
	n.show();
	cout << "-----------------------" << endl;

	thread ttt(update, ref(n));
	ttt.join();
	n.show();
	return 0;
}