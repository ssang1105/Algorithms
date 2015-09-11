#include <iostream>
using namespace std;

int arr[100005];
int max_num = 0;
int cnt = 0;
int k = 0;
int N;
bool isUp = false;
int i = 0;
/*
 * 이전에 같은 숫자들이 몇번 있었는지 count 해야 해.
 * ex) 2 3 4 5 5 5 4 3 2
 * 완전 탐색 할 필요는 없을 듯
 * 증가가 끝나거나 (증가하다가 낮은 수 or 같은 수 나오는 경우)
 * 감소가 끝날때까지 count 해(감소하다가 높은 수 or 같은 수 나오는 경우)
 * 처음에 시작은?
 * -> 증가하는 수인지 감소하는 수인지 판단하는 코드짜? x
 */
int CountPrevSame(int num){
	int cntSame = 0;
	for (int q = num-1 ; num>0; q--){
		if (arr[num] == arr[q])
			cntSame++;
		else
			break;
	}
	return cntSame;
}

int sameNumbers(int num){
	cnt++;
	for (; i < N-1; i++){
		if (arr[i] == arr[i + 1]){
			cnt++;
		}
		else
			break;
	}

	return i;

}
int increasing(int num){
	cnt++;
	for (; i < N-1; i++){
		if (arr[i] <= arr[i + 1]){
			cnt++;
		}
		else
			break;
	}

	return i;
}

int decreasing(int num){
	cnt++;
	for (; i < N-1; i++){
		if (arr[i] >= arr[i + 1]){
			 cnt++;
		}
		else
			break;
	}

	return i;
}
int main(void){
	cin >> N;

	// input
	for (int q = 0; q < N; q++){
		cin >> arr[q];
	}

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}

	for ( i = 0; i < N-1; i++){		
		cnt = CountPrevSame(i);
		if (arr[i] == arr[i + 1])
			i = sameNumbers(i) - 1;
		else if (arr[i] < arr[i + 1])
			i = increasing(i)-1;
		else if (arr[i] > arr[i + 1])
			i = decreasing(i)-1;
			
		if (cnt > max_num)
			max_num = cnt;
		cnt = 0;
	}

	cout << max_num << endl;
	return 0;
}