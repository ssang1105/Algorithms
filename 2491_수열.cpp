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
 * ������ ���� ���ڵ��� ��� �־����� count �ؾ� ��.
 * ex) 2 3 4 5 5 5 4 3 2
 * ���� Ž�� �� �ʿ�� ���� ��
 * ������ �����ų� (�����ϴٰ� ���� �� or ���� �� ������ ���)
 * ���Ұ� ���������� count ��(�����ϴٰ� ���� �� or ���� �� ������ ���)
 * ó���� ������?
 * -> �����ϴ� ������ �����ϴ� ������ �Ǵ��ϴ� �ڵ�¥? x
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