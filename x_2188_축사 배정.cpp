#include <iostream>
using namespace std;

int arr[201][201] = { 0 };
int visited[201];
int N, M;
int maxx = 0;

void solve(int now, int sum){

	if (sum > maxx){	
		maxx = sum;
	}

	for (int i = 1; i <= N; i++){
		if (arr[now][i] == 1 && visited[i] ==0){
			visited[i] = 1;
			solve(i, sum + 1);
			visited[i] = 0;
		}
	}

}
int main(void){

	
	int num;
	int tmp;
	cin >> N >> M;

	
	for (int i = 1; i <= M; i++){
		cin >> num;
		for (int j = 1; j <= num; j++){
			cin >> tmp;
			arr[i][tmp] = 1;
		}
	
	}
	solve(1,0);
	cout<< maxx << endl;
	return 0;
}