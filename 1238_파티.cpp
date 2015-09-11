#include <iostream>
using namespace std;


int arr[1001][1001] = { 0 };
int done[1001] = { 0 };
int go_time[1001] = { 0 };
int back_time[1001] = { 0 };
int my_time = 0;
int max_time = 0;

void dijk(int num, int N, int destination){
	
	int dist = 0;
	int min_dist = 10000;
	
	for (int i = 1; i <= N; i++){
		// 길이 있으면
		if (arr[num][i] > 0){
			dist = arr[num][i];
			if (dist < min_dist) min_dist = dist;
		}
		if (i == destination){
			break;
		}
	}
}

int main(void){
	int a, b, value;
	int N, M, X;
	

	cin >> N >> M >> X;

	while (M--){
		cin >> a >> b >> value;
		arr[a][b] = value;
	}

	for (int i = 1; i <= N; i++){
		if (i == N) continue;
		dijk(i, N, X);

	}

}