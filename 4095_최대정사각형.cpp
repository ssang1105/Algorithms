#include <iostream>
using namespace std;

int graph[1005][1005] = { 0 };

int minValue(int a, int b, int c){
	int min = 0;
	if (a >= b)
		min = b;
	else
		min = a;

	if (min >= c)
		min = c;
	
	return min;
}

int main(void){
	int N, M;
	int max_square = 0;
	while (true){
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= M; j++){
				cin >> graph[i][j];
			}
		}

		// 困率 捻记
		for (int i = 0; i <= M; i++){
			graph[0][i] = 0;
		}
		// 哭率 捻记
		for (int i = 0; i <= N; i++){
			graph[i][0] = 0;
		}


		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= M; j++){
				if (graph[i][j] == 1){
					int min = minValue(graph[i - 1][j], graph[i][j - 1], graph[i - 1][j - 1]);
					graph[i][j] = min + 1;
					if (graph[i][j] > max_square)
						max_square = graph[i][j];
				}
			}
		}

		cout << max_square << endl;

		// 檬扁拳
		max_square = 0;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= M; j++){
				graph[i][j] = 0;
			}
		}

	}

}