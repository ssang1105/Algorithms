#include <iostream>
using namespace std;

long long map[1002][1002] = { 0 };
long long cnt = 1;
int N, M;
long long R;
int resultA = 0;
int resultB = 0;
bool isReturn = false;

void MapSetting(int A, int B, int cond){

	if (cnt > R) {
		resultA = 0;
		resultB = 0;
		isReturn = true;
		return;
	}
	
	for (int i = 0; i < 4; i++){
		if (isReturn) return;
		// 위
		if (cond == 1){
			if (map[A - 1][B] == -1){
				if (cnt == R) {
					resultA = A - 1;
					resultB = B;
					isReturn = true;
					return;
				}
				map[A - 1][B] = cnt++;
				MapSetting(A - 1, B, cond);
			}
			else
				cond = 2;
		}
		// 오른
		if (cond == 2){
			if (map[A][B + 1] == -1){
				if (cnt == R) {
					resultA = A;
					resultB = B + 1;
					isReturn = true;
					return;
				}
				map[A][B + 1] = cnt++;
				MapSetting(A, B + 1, cond);
			}
			else
				cond = 3;
		}
		// 아래
		if (cond == 3){
			if (map[A + 1][B] == -1){
				if (cnt == R) {
					resultA = A + 1;
					resultB = B;
					isReturn = true;
					return;
				}
				map[A + 1][B] = cnt++;
				MapSetting(A + 1, B, cond);
			}
			else
				cond = 4;
		}


		// 왼
		if (cond == 4){
			if (map[A][B - 1] == -1){
				if (cnt == R) {
					resultA = A;
					resultB = B - 1;
					isReturn = true;
					return;
				}
				map[A][B - 1] = cnt++;
				MapSetting(A, B - 1, cond);
			}
			else
				cond = 1;
		}
	}
	

	
}
int main(void){

	
	cin >> N >> M >> R;

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = -1;
	
	map[M][1] = cnt++;
	if (cnt-1 == R)
		cout << 1 << " " << 1 << endl;
	else{
		MapSetting(M, 1, 1);

		if (resultA == 0 && resultB == 0)
			cout << 0 << endl;
		else
			cout << resultB << " " << M - resultA + 1 << endl;
	}
	return 0;
}