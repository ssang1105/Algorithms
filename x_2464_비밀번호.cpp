#include <iostream>
using namespace std;


// 10진수를 2진수로 변환
int BinaryToTen(int num){
	int binary[20];
	int cnt = 0;
	for (int i = 0; num>0; i++){
		binary[i] = num % 2;
		if (binary[i] == 1)
			cnt++;
		num = num / 2;
	}

	return cnt;
	
}



int main(void){

	int N;
	int targetCnt;
	int min_num=0;
	int max_num=0;
	cin >> N;
	targetCnt = (BinaryToTen(N));
	
	// 작은수 중 가까운 수 찾기
	for (int i = N-1; i >= 0; i--){
		if (BinaryToTen(i) == targetCnt){
			min_num = i;
			break;
		}
	}

	int k = N+1;
	// 큰수 중 가까운 수 찾기
	while (1){
		if (BinaryToTen(k) == targetCnt){
			max_num = k;
			break;
		}
		k++;
	}
	
	cout << min_num << " " << max_num << endl;

	return 0;
}