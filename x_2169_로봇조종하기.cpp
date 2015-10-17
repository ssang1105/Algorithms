#include <iostream>
#include <algorithm>
using namespace std;

int A, B;
int map[1002][1002] = { 0 };
int cache[1002][1002] = { 0 };


int solve(int a, int b){

	
	if (a > 0 && b > 0){
		if (cache[a - 1][b] != 0 && cache[a][b - 1] != 0)
			return map[a][b] + max(cache[a - 1][b], cache[a][b - 1]);
		else if (cache[a - 1][b] != 0 && cache[a][b - 1] == 0)
			return map[a][b] + max(cache[a - 1][b], solve(a, b - 1));
		else if (cache[a - 1][b] == 0 && cache[a][b - 1] != 0)
			return map[a][b] + max(solve(a - 1, b), cache[a][b - 1]);
		else{
			return map[a][b] + max(solve(a - 1, b), solve(a, b - 1));
		}
	}
}

int main(void){

	cin >> A >> B;
	for (int i = 1; i <= A; i++)
		for (int j = 1; j <= B; j++)
			cin >> map[i][j];
		
	// ¼¼·Î Äí¼Ç
	for (int i = 1; i <= A; i++)
		cache[i][1] = map[i][1]+map[i-1][1];

	// °¡·Î Äí¼Ç
	for (int i = 1; i <= B; i++)
		cache[1][i] = map[1][i] + map[1][i];

	cout << solve(A, B) << endl;
	return 0;
}