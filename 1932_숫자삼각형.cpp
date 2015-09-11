#include <iostream>
using namespace std;



// f(m,n) = f(m,n) + MAX ( f(m+1 , n) , f(m+1, n+1) ) --> O
/* Ä³½ÌÀ» ÇÒ ¶§´Â return °ªÀ» Ä³½Ì*/
int triangle[505][505] = { 0 };
int cache[505][505] = { 0 };
int maxSum = 0;
int sum = 0;

int returnMAX(int a, int b){
	if (a >= b) return a;
	else return b;
}

int recur(int a, int b){
	if (triangle[a + 1][b] != 0 || triangle[a + 1][b + 1] != 0){
		if (cache[a][b] != 0)
			return cache[a][b];
		else{
			cache[a][b] = triangle[a][b] + returnMAX(recur(a + 1, b + 1), recur(a + 1, b));
			return triangle[a][b] + returnMAX(recur(a + 1, b + 1), recur(a + 1, b));
		}
	}
	else{
		return triangle[a][b];
	}
}

int main(void){
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= i; j++){
			cin >> triangle[i][j];
		}
	}

	

	cout << recur(1,1) << endl;

}