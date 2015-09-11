#include <iostream>
#include <algorithm>
using namespace std;

char map[27][27] = { 0 };
int visited[27][27] = { 0 };
int danji[27];
int k = 0;
int danjiNum = 0;

void dfs(int a, int b){
	visited[a][b] = 1;
	danjiNum++;
	if (map[a + 1][b] == '1' && visited[a + 1][b] == 0){
		dfs(a + 1, b);
	}
	if (map[a - 1][b] == '1' && visited[a - 1][b] == 0){
		dfs(a - 1, b);
	}
	if (map[a][b + 1] == '1' && visited[a][b + 1] == 0){
		dfs(a, b + 1);
	}
	if (map[a][b - 1] == '1' && visited[a][b - 1] == 0){
		dfs(a, b - 1);
	}
	
}
int main(void){

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> map[i][j];
		}
	}


	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (map[i][j] == '1' && visited[i][j] == 0){
				dfs(i, j);
				danji[k++] = danjiNum;
				danjiNum = 0;
			}
		}
	}
	

	sort(danji, danji + k);
	cout << k << endl;
	for (int i = 0; i < k; i++){
		if (danji[i] != 0)
			cout << danji[i] << endl;
	}

}