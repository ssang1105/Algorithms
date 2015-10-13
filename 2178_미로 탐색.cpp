#include <iostream>
#include <queue>
using namespace std;

char map[101][101] = { 0 };
int visited[101][101] = { 0 };
int result = 0;
int M, N;
typedef struct {
	int A;
	int B;
	int visitNum;
} DATA;

queue<DATA> q;

void bfs(){
	
	DATA tmp;

	// ╩С
	if (map[q.front().A-1][q.front().B] == '1' && visited[q.front().A-1][q.front().B] == 0){
		tmp.A = q.front().A-1;
		tmp.B = q.front().B;
		tmp.visitNum = q.front().visitNum+1;
		visited[tmp.A][tmp.B] = 1;
		q.push(tmp);
	}
	// ©Л
	if (map[q.front().A][q.front().B+1] == '1' && visited[q.front().A][q.front().B+1] == 0){
		tmp.A = q.front().A;
		tmp.B = q.front().B+1;
		tmp.visitNum = q.front().visitNum + 1;
		visited[tmp.A][tmp.B] = 1;
		q.push(tmp);
	}
	// го
	if (map[q.front().A+1][q.front().B] == '1' && visited[q.front().A+1][q.front().B] == 0){
		tmp.A = q.front().A+1;
		tmp.B = q.front().B;
		tmp.visitNum = q.front().visitNum + 1;
		visited[tmp.A][tmp.B] = 1;
		q.push(tmp);
	}
	// аб
	if (map[q.front().A][q.front().B-1] == '1' && visited[q.front().A][q.front().B-1] == 0){
		tmp.A = q.front().A;
		tmp.B = q.front().B-1;
		tmp.visitNum = q.front().visitNum + 1;
		visited[tmp.A][tmp.B] = 1;
		q.push(tmp);
	}

	if (q.front().A == N && q.front().B == M){
		result = q.front().visitNum;
		return;
	}

	if (q.empty())
		return;
	else{
		q.pop();
		bfs();
	}
}

int main(void){
	

	cin >> N >> M;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}

	DATA data;
	data.A = 1;
	data.B = 1;
	data.visitNum = 1;
	q.push(data);
	visited[1][1] = 1;

	bfs();
	cout << result << endl;
}