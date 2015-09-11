#include <iostream>
using namespace std;

int graph[52][52];
int num = 0;

void dfs(int a, int b){

	if (graph[a - 1][b] == 1){
		graph[a - 1][b] = 0;
		dfs(a - 1, b);
	}
	if (graph[a + 1][b] == 1){
		graph[a + 1][b] = 0;
		dfs(a + 1, b);
	}
	if (graph[a][b + 1] == 1){
		graph[a][b + 1] = 0;
		dfs(a, b + 1);
	}
	if (graph[a][b - 1] == 1){
		graph[a][b - 1] = 0;
		dfs(a, b - 1);
	}
	if (graph[a - 1][b - 1] == 1){
		graph[a - 1][b - 1] = 0;
		dfs(a - 1, b - 1);
	}
	if (graph[a - 1][b + 1] == 1){
		graph[a - 1][b + 1] = 0;
		dfs(a - 1, b + 1);
	}
	if (graph[a + 1][b - 1] == 1){
		graph[a + 1][b - 1] = 0;
		dfs(a + 1, b - 1);
	}
	if (graph[a + 1][b + 1] == 1){
		graph[a + 1][b + 1] = 0;
		dfs(a + 1, b + 1);
	}



}

int main(void){
	int A, B;
	for (;;){
		cin >> A >> B;
		if (A == 0 && B == 0) break;


		// 3 x 2
		for (int i = 1; i <= B; i++){
			for (int j = 1; j <= A; j++){
				cin >> graph[i][j];
			}
		}

		// dfs
		for (int i = 1; i <= B; i++){
			for (int j = 1; j <= A; j++){
				if (graph[i][j] == 1){
					dfs(i, j);
					num++;
				}
			}
		}

		cout << num << endl;



		// ÃÊ±âÈ­
		for (int i = 1; i <= B; i++){
			for (int j = 1; j <= A; j++){
				graph[i][j] = 0;
			}
		}

		num = 0;

	}
}