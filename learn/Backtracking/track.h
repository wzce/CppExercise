#include<string>
#include<iostream>
#include<stack>
using namespace std;

struct offsets{
	int x;
	int y;
	string dir;
};


offsets step[8] = { { -1, 0, "N" }, { -1, 1, "NE" }, { 0, 1, "E" }, { 1, 1, "SE" },
{ 1, 0, "S" }, { 1, -1, "SW" }, { 0, -1, "W" }, { -1, -1, "NW" } };
const int m = 9, p = 9;
int mark[m][m] = { 0 };
int Maze[m][m] = {  {1,1,1,1,1,1,1,1,1},
					{0,1,1,1,1,1,0,0,1},
					{1,0,0,0,0,1,1,0,1},
					{1,0,1,1,1,0,0,1,1},
					{1,1,0,0,0,1,0,0,1},
					{1,0,1,1,1,1,1,1,1}, 
					{1,1,0,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1},
					{1,0,1,1,1,1,1,1,1} 
				};
int xx = 8, yy = 1;
int seekPath(int x,int y){
	int nextX, nextY;
	string dir;
	if (x == xx && y == yy){
		return 1;
	}

	for (int i = 0; i < 8;i++){
		nextX = step[i].x + x;
		nextY = step[i].y + y;
		dir = step[i].dir;
		if ( !(nextX>=0 && nextX<m)){//x������Խ��
			continue;
		}
		if (!(nextY >= 0 && nextY<p)){//y������Խ��
			continue;
		}
		if (Maze[nextX][nextY] == 0 && mark[nextX][nextY] == 0){
			mark[nextX][nextY] = 1;
			if (seekPath(nextX,nextY)){
				cout << "( " << nextX << " , " << nextY << " , " << dir << " ) " << endl;//���·��
				return 1;
			}
		}
	}//��ǰ·����ͨ�����л��ݣ���һ����ѡ·��

	if (x==1 && y==0){
		cout << " no path in Maze" << endl;
	}
	return 0;
}

//�ǵݹ���ʵķ�ʽ
void findPath(int x,int y){
	//x,y��ʾ��ʼ���������
	stack<pair<int,int>> path;
	path.push({x,y});
	int nextX, nextY;
	bool hasNext;
	while (!path.empty()){
		hasNext = 0;
		for (int i = 0; i < 8;i++){
			nextX = step[i].x + x;
			nextY = step[i].y + y;
			if (!(nextX >= 0 && nextX<m)){//x������Խ��
				continue;
			}
			if (!(nextY >= 0 && nextY<p)){//y������Խ��
				continue;
			}
			
			if (Maze[nextX][nextY] == 0 && mark[nextX][nextY] == 0){
				mark[nextX][nextY] = 1;
				path.push({nextX,nextY});
				x = nextX;
				y = nextY;
				cout << "���ʣ�" << x << "��" << y << ") --->" << endl;;
				hasNext = 1;
				break;//��̽��һ������·��������������̽��ѭ��
			}
		}

		if (nextX == xx && nextY== yy){
			//˵���ҵ�����
			cout << "�ҵ�������" << endl;
			break;
		}

		if (!hasNext){
			//��ǰ��̽û����һ��������
			x = path.top().first;
			y = path.top().second;
			cout << "���ˣ�" << x << "��" << y << ") <---" << endl;;
			path.pop();
		}
		//cout << "---seek---" << endl;
	}//end while

	if (nextX == xx && nextY == yy){
		//�ҵ�����
		while (!path.empty()){
			cout << "( " << path.top().first << " , " << path.top().second << " )" << endl;
			path.pop();
		}
	}
	else{
		cout << "No path in the Maze" << endl;
	}
}
