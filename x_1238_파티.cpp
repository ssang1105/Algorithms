#include <iostream>
using namespace std;

int arr[1001][1001] = { 0 };
int done[1001] = { 0 };
int my_time = 0;
int max_time = 0;
int go_time[1001] = { 0 };
int back_time[1001] = { 0 };
int N, M, X;



void go(int num){
	for (int i = 1; i <= N; i++){
		if (arr[i][num] > 0 && done[i] == 0){
			done[i] = 1;
			if (go_time[i] == 0)
				go_time[i] = arr[i][num] + go_time[num];
			else if (go_time[i]>0 && go_time[i] > arr[i][num] + go_time[num])
				go_time[i] = arr[i][num] + go_time[num];
			
			go(i);
		}
	}
}

void back(int num){
	for (int i = 1; i <= N; i++){
		if (arr[num][i] > 0 && done[i] == 0){
			done[i] = 1;

			if (back_time[i] == 0)
				back_time[i] = arr[num][i] + back_time[num];
			else if (back_time[i]>0 && back_time[i] > arr[num][i] + back_time[num])
				back_time[i] = arr[num][i] + back_time[num];

			back(i);
		}
	}

}
int main(void){
	
	int a, b, value;

	cin >> N >> M >> X;

	while (M--){
		cin >> a >> b >> value;
		arr[a][b] = value;
	}

	done[X] = 1;
	//go
	for (int i = 1; i <= N; i++){
		if (arr[i][X] > 0){
			done[i] = 1;
			if (go_time[i] == 0)
				go_time[i] = arr[i][X];
			else if (go_time[i]>0 && go_time[i] > arr[i][X])
				go_time[i] = arr[i][X];
			
			go(i);
			
		}
		
	}
	
	for (int i = 1; i <= N; i++) done[i] = 0;

	done[X] = 1;
	//back
	for (int i = 1; i <= N; i++){
		if (arr[X][i] > 0){
			done[i] = 1;
			if (back_time[i] == 0)
				back_time[i] = arr[X][i];
			else if (back_time[i]>0 && back_time[i] > arr[X][i])
				back_time[i] = arr[X][i];
			
			back(i);
		}
		
	}
	
	for (int i = 1; i <= N; i++){
		my_time = go_time[i] + back_time[i];
		if (my_time > max_time) max_time = my_time;

	}

	cout << max_time << endl;
}