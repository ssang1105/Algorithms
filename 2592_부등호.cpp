#include<iostream>
#include<string>
using namespace std;

int used[10] = { 0 };

int main(void){

	int N;
	
	char input_st[300];
	int min_val[11];
	int max_val[11];
	char tmp;
	int m = 0;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		input_st[m++] = tmp;
	}
	

	
	// 최대값일 때 초기값 설정
	max_val[0] = 9;
	used[9] = 1;

	// 최대값 구하기
	for (int i = 1; i <= N+1; i++){
		if (input_st[i-1] == '<'){
			for (int j = 9; j >= 0; j--){
				// 아직 사용지 않은 숫자이고, 이전숫자보다 클 경우
				if (used[j] == 0){
					if (j > max_val[i - 1]){
						max_val[i] = j;
						used[j] = 1;
						break;
					}
					else{
						int k = 1;
						max_val[i] = j;
						used[j] = 1;
						// (Insertion Sort랑 비슷한 원리)
						while (k != i+1){
							if (input_st[i - k] == '<'){
								int tmp = max_val[i - k + 1];
								max_val[i - k + 1] = max_val[i - k];
								max_val[i - k] = tmp;
								k++;
							}
							else if (input_st[i - k] == '>'){
								break;
							}
							
						}
						break;
					}
				}
			}
		}
		else if (input_st[i-1] == '>'){
			for (int j = 9; j >= 0; j--){
				// 아직 사용지 않은 숫자이고, 이전숫자보다 작을 경우
				if (used[j] == 0 && j < max_val[i-1]){
					max_val[i] = j;
					used[j] = 1;
					break;
				}
			}
		}
	}

	for (int i = 0; i <= N; i++){
		used[i] = 0;
	}

	// 최소값일 때 초기값 설정
	min_val[0] = 0;
	used[0] = 1;

	// 최소값 구하기
	for (int i = 1; i <= N + 1; i++){
		if (input_st[i - 1] == '<'){
			for (int j = 0; j <= 9; j++){
				// 아직 사용지 않은 숫자이고, 이전숫자보다 클 경우
				if (used[j] == 0 && j > min_val[i - 1]){
					min_val[i] = j;
					used[j] = 1;
					break;
				}
			}
		}
		else if (input_st[i - 1] == '>'){
			for (int j = 0; j <= 9; j++){
				// 아직 사용지 않은 숫자이고, 이전숫자보다 작을 경우
				if (used[j] == 0){
					if (j < min_val[i - 1]){
						min_val[i] = j;
						used[j] = 1;
						break;
					}
					else{
						int k = 1;
						min_val[i] = j;
						used[j] = 1;
						// (Insertion Sort랑 비슷한 원리)
						while (k != i + 1){
							if (input_st[i - k] == '<'){
								break;
							}
							else if(input_st[i - k] == '>'){
								int tmp = min_val[i - k + 1];
								min_val[i - k + 1] = min_val[i - k];
								min_val[i - k] = tmp;
								k++;
							}
						}
						break;
					}
				}
			}
		}
	}

	

	for (int i = 0; i < N + 1; i++)
		cout << max_val[i];

	cout << endl;

	for (int i = 0; i < N + 1; i++)
		cout << min_val[i];

	cout << endl;
		

	return 0;
}