#include <iostream>
#include <algorithm>
using namespace std;


int visited[12] = { 0 };
int N;
unsigned int data[12][12];
unsigned int minn = 10000000;

void dfs(int num, int sum, int width){
	if (width == N-1){
		minn = min(minn, sum + data[num][0]);
		return;
	}
	for (int i = 1; i < N; i++){
		if (visited[i] == 0 && data[num][i]){
			visited[i] = 1;
			dfs(i, sum + data[num][i], width + 1);
			visited[i] = 0;
		}
	}
}
int main(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> data[i][j];
		}
	}
	for (int i = 0; i < N; i++){
		visited[i] = 1;
		dfs(i, 0, 0);
		visited[i] = 0;
	}

	cout << minn << endl;
	
}


/*
void solve(int now, int sum, int width){
if (width== N){
if (sum < minn)
minn = sum;
return;
}


for (int i = now; i <= N; i++){
if (include[(i + 1) % N] == 0){
if ((i + 1) % N == 0){
// 출발했던 지점으로 돌아가기
if (width == N - 1){
include[(i + 1) % N] = 1;
solve(now + 1, sum + data[i][(i + 1) % N], width + 1);
include[(i + 1) % N] = 0;
}
continue;
}
include[(i + 1) % N] = 1;
solve(now + 1, sum + data[i][(i + 1) % N], width + 1);
include[(i + 1) % N] = 0;
}
}

}
*/