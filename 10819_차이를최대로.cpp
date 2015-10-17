#include<iostream>

using namespace std;

int data[9];
int perm[8];
bool include[9];
int N;
int m;
void solve(int num) {

	if (num > N) {
		int sum = 0;
		for (int i = 1; i < N; i++) {
			int temp = data[perm[i]] - data[perm[i + 1]];
			if (temp < 0) temp *= -1;
			sum += temp;
		}
		if (m < sum) m = sum;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!include[i]) {
			include[i] = true;
			perm[num] = i;
			solve(num + 1);
			include[i] = false;
		}
	}
}
int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> data[i];
	

	solve(1);

	cout << m;
	return 0;
}