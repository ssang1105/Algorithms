#include<iostream>
using namespace std;

bool isHansu(int num){
	int n_1, n_2, n_3;

	n_1 = num / 100; 
	n_2 = (num / 10) % 10;
	n_3 = num % 10;

	if (n_2 == 0) return false;
	else if ((n_1 + n_3) / 2 == n_2 && (n_1 + n_3) % 2 == 0)
		return true;
	else
		return false;
	
}

int main(void){
	int N;
	int cnt = 0;
	cin >> N;

	for (int i = N; i >= 1; i--){
		if (i < 100)
			cnt++;
		else if (isHansu(i)){
			cnt++;
		}
	}

	cout << cnt << endl;
	
}