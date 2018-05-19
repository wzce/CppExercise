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
		if ( !(nextX>=0 && nextX<m)){//x轴数组越界
			continue;
		}
		if (!(nextY >= 0 && nextY<p)){//y轴数组越界
			continue;
		}
		if (Maze[nextX][nextY] == 0 && mark[nextX][nextY] == 0){
			mark[nextX][nextY] = 1;
			if (seekPath(nextX,nextY)){
				cout << "( " << nextX << " , " << nextY << " , " << dir << " ) " << endl;//输出路径
				return 1;
			}
		}
	}//当前路径不通，进行回溯，换一个候选路径

	if (x==1 && y==0){
		cout << " no path in Maze" << endl;
	}
	return 0;
}

//非递归访问的方式
void findPath(int x,int y){
	//x,y表示开始的入口坐标
	stack<pair<int,int>> path;
	path.push({x,y});
	int nextX, nextY;
	bool hasNext;
	while (!path.empty()){
		hasNext = 0;
		for (int i = 0; i < 8;i++){
			nextX = step[i].x + x;
			nextY = step[i].y + y;
			if (!(nextX >= 0 && nextX<m)){//x轴数组越界
				continue;
			}
			if (!(nextY >= 0 && nextY<p)){//y轴数组越界
				continue;
			}
			
			if (Maze[nextX][nextY] == 0 && mark[nextX][nextY] == 0){
				mark[nextX][nextY] = 1;
				path.push({nextX,nextY});
				x = nextX;
				y = nextY;
				cout << "访问（" << x << "，" << y << ") --->" << endl;;
				hasNext = 1;
				break;//试探到一个可行路径，跳出方向试探的循环
			}
		}

		if (nextX == xx && nextY== yy){
			//说明找到出口
			cout << "找到出口了" << endl;
			break;
		}

		if (!hasNext){
			//当前试探没有下一步，回退
			x = path.top().first;
			y = path.top().second;
			cout << "回退（" << x << "，" << y << ") <---" << endl;;
			path.pop();
		}
		//cout << "---seek---" << endl;
	}//end while

	if (nextX == xx && nextY == yy){
		//找到出口
		while (!path.empty()){
			cout << "( " << path.top().first << " , " << path.top().second << " )" << endl;
			path.pop();
		}
	}
	else{
		cout << "No path in the Maze" << endl;
	}
}
