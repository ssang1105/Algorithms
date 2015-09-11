#include <iostream>
using namespace std;

int map[101][101] = { 0 };

int main(void){
	int N;
	int A, B;
	int cnt = 0;
	cin >> N;
	while(N--){
		cin >> A >> B;
		for (int i = A; i <= A + 9; i++)
			for (int j = B; j <= B + 9; j++){
				if (A < 101 && B < 101)
					map[i][j] = 1;
			}
	}

	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			if (map[i][j] == 1) cnt++;

	cout << cnt << endl;
}