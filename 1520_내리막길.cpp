#include <iostream>
using namespace std;

int row, column;
int map[505][505] = { 0 };
unsigned long result[505][505] = { 0 };
unsigned long tmp = 0;


void recur(int a , int b){

	if (a == row && b == column){
		result[a][b] = 1;
		return;
	}

	// 위
	if (map[a - 1][b] < map[a][b] && map[a - 1][b] != 0 ){
		if (result[a - 1][b] == 0){
			recur(a - 1, b);
			result[a][b] = result[a - 1][b];
		}
		else{
			if (a-1 == row && b == column)
				result[a][b] = result[a + 1][b] + result[a][b - 1] + result[a][b + 1];
			else
				result[a][b] = result[a + 1][b] + result[a - 1][b] + result[a][b - 1] + result[a][b + 1];
		}
	}
	// 오른쪽
	if (map[a][b + 1] < map[a][b] && map[a][b+1] != 0){
		if (result[a][b + 1] == 0){
			recur(a, b + 1);
			result[a][b] = result[a][b + 1];
		}
		else{
			if (a == row && b+1 == column)
				result[a][b] = result[a + 1][b] + result[a - 1][b] + result[a][b - 1];
			else
				result[a][b] = result[a + 1][b] + result[a - 1][b] + result[a][b - 1] + result[a][b + 1];
		}
	}
	// 아래
	if (map[a + 1][b] < map[a][b] && map[a+1][b] != 0){
		if (result[a + 1][b] == 0){
			recur(a + 1, b);
			result[a][b] = result[a + 1][b];
		}
		else{
			if (a+1 == row && b == column)
				result[a][b] = result[a - 1][b] + result[a][b - 1] + result[a][b + 1];
			else
				result[a][b] = result[a + 1][b] + result[a - 1][b] + result[a][b - 1] + result[a][b + 1];
		}
	}
	// 왼쪽
	if (map[a][b - 1] < map[a][b] && map[a][b - 1] != 0){
		if (result[a][b - 1] == 0){
			recur(a, b - 1);
			result[a][b] = result[a][b - 1];
		}
		else{
			if (a == row && b-1 == column)
				result[a][b] = result[a + 1][b] + result[a - 1][b] + result[a][b + 1];
			else
				result[a][b] = result[a + 1][b] + result[a - 1][b] + result[a][b - 1] + result[a][b + 1];
		}
	}
	

}
int main(void){

	
	cin >> row >> column;

	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= column; j++)
			cin >> map[i][j];
		
	recur(1, 1);
	result[1][1] = result[1][2] + result[2][1];
	cout << result[1][1] << endl;

	return 0;
}