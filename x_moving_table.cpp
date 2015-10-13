#include <iostream>
using namespace std;

int arr[401] = { 0 };
int moving[201] = { 0 };
int a[201] = { 0 };
int b[201] = { 0 };
int visited[201] = { 0 };
int main(void){

	int N;
	int time = 0;
	int visit_num = 0;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a[i] >> b[i];
		if (b[i] >= a[i]){
			// 작은수가 짝수인 경우
			if (a[i] % 2 == 0) a[i] -= 1;
			// 큰수가 홀수인 경우
			if (b[i] % 2 == 1) b[i] += 1;
			
			moving[i] = b[i] - a[i];
			
		}
		else{
			// 작은수가 짝수인 경우
			if (b[i] % 2 == 0) b[i] -= 1;
			// 큰수가 홀수인 경우
			if (a[i] % 2 == 1) a[i] += 1;

			int tmp = b[i];
			b[i] = a[i];
			a[i] = tmp;

			moving[i] = b[i] - a[i];
		}
	}

	// Sort
	for (int i = 0; i <= N-1; i++){
		for (int j = 0; j <= N - 1; j++){
			if (moving[j] < moving[j + 1]){
				int tmp = moving[j];
				moving[j] = moving[j + 1];
				moving[j + 1] = tmp;

				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;

				tmp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = tmp;

			}
		}
	}

	while (visit_num < N){
		time++;
		for (int i = 0; i < N; i++){
			if (visited[i] == 0){
					bool flag = false;
					for (int j = a[i]; j <= b[i]; j++){
						if (arr[j] == 0){
							arr[j] = 1;
							flag = true;
						}
						else{
							for (int k = j; j >= a[i]; j--)
								arr[j] = 0;
							flag = false;
							break;
						}
					}
					if (flag) {
						visited[i] = 1;
						visit_num++;
					}
				
			}
		}
		
		// arr 초기화
		for (int i = 1; i <= 400; i++)
			arr[i] = 0;
	}
	
	cout << time * 10 << endl;

	

	return 0;
}