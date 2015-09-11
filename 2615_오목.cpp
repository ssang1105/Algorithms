#include <iostream>
using namespace std;

int arr[21][21] = { 0 };
int visited[21][21] = { 0 };
int minA = 100;
int minB = 100;
int winner = 100;
int num = 0;
bool isBreak = false;

void initVistied(int target){
	if (num == 5){
		winner = target;
		isBreak = true;
		return;
	}
	minA = 100;
	minB = 100;
	num = 0;
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
			visited[i][j] = 0;
}

/*
ooo
*/
void checkGaro(int a, int b, int target){
	visited[a][b] = 1;

	if (minB > b){
		minB = b;
		minA = a;
	}

	else if (minB == b){
		if (minA >= a)
			minA = a;
	}

	num++;

	if (arr[a][b + 1] == target && visited[a][b + 1] == 0){
		checkGaro(a, b + 1, target);
	}
	if (arr[a][b - 1] == target && visited[a][b - 1] == 0){
		checkGaro(a, b - 1, target);
	}
}
/*
o
o
o
*/
void checkSero(int a, int b, int target){
	visited[a][b] = 1;
	if (minB > b){
		minB = b;
		minA = a;
	}
	else if (minB == b){
		if (minA >= a)
			minA = a;
	}

	num++;

	if (arr[a - 1][b] == target && visited[a - 1][b] == 0){
		checkSero(a - 1, b, target);
	}
	if (arr[a + 1][b] == target && visited[a + 1][b] == 0){
		checkSero(a + 1, b, target);
	}
}
/*
o
o
o

*/
void checkDeagak_1(int a, int b, int target){
	visited[a][b] = 1;
	if (minB > b){
		minB = b;
		minA = a;
	}
	else if (minB == b){
		if (minA >= a)
			minA = a;
	}


	num++;

	if (arr[a - 1][b - 1] == target && visited[a - 1][b - 1] == 0){
		checkDeagak_1(a - 1, b - 1, target);
	}
	if (arr[a + 1][b + 1] == target && visited[a + 1][b + 1] == 0){
		checkDeagak_1(a + 1, b + 1, target);
	}

}
/*
o
o
o
*/
void checkDeagak_2(int a, int b, int target){
	visited[a][b] = 1;
	if (minB > b){
		minB = b;
		minA = a;
	}
	else if (minB == b){
		if (minA >= a)
			minA = a;
	}


	num++;

	if (arr[a - 1][b + 1] == target && visited[a - 1][b + 1] == 0){
		checkDeagak_2(a - 1, b + 1, target);
	}
	if (arr[a + 1][b - 1] == target && visited[a + 1][b - 1] == 0){
		checkDeagak_2(a + 1, b - 1, target);
	}

}

void dfs(int a, int b, int target){

	checkGaro(a, b, target);
	initVistied(target);
	if (isBreak) return;
	checkSero(a, b, target);
	initVistied(target);
	if (isBreak) return;
	checkDeagak_1(a, b, target);
	initVistied(target);
	if (isBreak) return;
	checkDeagak_2(a, b, target);
	initVistied(target);
	if (isBreak) return;

	if (num != 5){
		winner = 0;
	}

}


int main(void){

	for (int i = 1; i <= 19; i++){
		for (int j = 1; j <= 19; j++){
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= 19; i++){
		for (int j = 1; j <= 19; j++){
			if (arr[i][j] == 1){
				dfs(i, j, 1);
				if (isBreak) break;
			}
			else if (arr[i][j] == 2){
				dfs(i, j, 2);
				if (isBreak) break;
			}
		}
		if (isBreak) break;
	}

	cout << winner << endl;
	if (winner != 0){
		cout << minA << " " << minB << endl;
	}

}