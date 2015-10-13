#include <iostream>
using namespace std;

int arr[100001];
int result[100001];
int max_num = 0;
int num = 0;
int main(void){

	int N, K;

	cin >> N >> K;
	for (int i = 1; i <= N; i++){
		cin >> arr[i];
	}

	
	for (int i = 1; i < 1+K; i++){
		result[1] += arr[i];
	}
	max_num = result[1];
	// 중요한 종료 조건!!!!
	// 입력값에 따른 종료조건 잘 명시해
	if (K >= N){
		cout << max_num << endl;
		return 0;
	}
	
	for (int i = 2; i <= N; i++){
		result[i] = result[i - 1] - arr[i - 1] + arr[i+K-1];
		if (result[i] >= max_num)
			max_num = result[i];
		if (i + K> N)
			break;
	}


	cout << max_num << endl;

	return 0;
}