#include <iostream>
using namespace std;

int row, column;
int map[505][505] = { 0 };
unsigned long result[505][505] = { 0 };
unsigned long tmp = 0;

/*
	이 문제의 핵심은 
	result[a][b] += 4방향 재귀 돈 후에 최종적으로 나온 값



	USEFUL TEST CASE
	5 10
	50 49 48 47 46 45 44 43 42 41
	49 45 43 42 41 40 21 14 9  7
	50 50 42 40 39 25 20 15 7 5
	47 47 50 38 50 27 24 10 8 3
	45 50 50 35 30 29 28 27 26 1
*/
void recur(int a , int b){

	if (a == row && b == column){
		result[a][b] = 1;
		return;
	}

	// 위
	if (map[a - 1][b] < map[a][b] && map[a - 1][b] != 0 ){
		if (result[a - 1][b] == 0)
			recur(a - 1, b);
		
		result[a][b] += result[a - 1][b];
		
	}
	
	// 오른쪽
	if (map[a][b + 1] < map[a][b] && map[a][b + 1] != 0){
		if (result[a][b + 1] == 0)
			recur(a, b + 1);	
		
		result[a][b] += result[a][b + 1];
		
	}
	// 아래
	if (map[a + 1][b] < map[a][b] && map[a + 1][b] != 0){
		if (result[a + 1][b] == 0)
			recur(a + 1, b);
		
		result[a][b] += result[a + 1][b] ;
		
	}
	
	// 왼쪽
	if (map[a][b - 1] < map[a][b] && map[a][b - 1] != 0){
		if (result[a][b - 1] == 0)
			recur(a, b - 1);
		
		result[a][b] += result[a][b - 1] ;
		
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