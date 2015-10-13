#include <iostream>
using namespace std;

int arr[200][200] = { 0 };
int N, M;
int main(void){

	cin >> N;
	cin >> M;
	int a, b;
	while (M--){
		cin >> a >> b;
		arr[a][b] = 1;
	}

	/*
		Index Áß¿ä!
	*/
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (arr[j][i] == 1){
				for (int k = 1; k <= N; k++){
					if (arr[i][k] == 1){
						arr[j][k] = 1;					
					}
				}
			}
		}
	}
	
	
	for (int i = 1; i <= N; i++){
		int cnt = 0;
		for (int j = 1; j <= N; j++){
			if (i == j) continue;
			else if (arr[i][j]==0 && arr[j][i] == 0) cnt++;
		}	
		cout << cnt<< endl;
	}

	return 0;
}