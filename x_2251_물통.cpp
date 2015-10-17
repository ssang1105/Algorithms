#include <iostream>
#include <algorithm>

using namespace std;
int A, B, C;
int visited[201] = { 0 };
int a = 0;
int b = 0;
int c = 0;
void solve(int num){

	// c--> a, a --> b 
	// c--> a, c --> b
	if (num - A > 0 && visited[num - A] == 0){
		// a --> b
		if (a != 0 && b + a <= B){
			int tmp = b;
			b += a;
			a = 0;
			c = c;
			visited[c] = 1;
			solve(c);
		}
		if (a == A && b == B)
			return;
		// c-->a
		if (c - A > 0){
			a = A;
			b = b;
			c = num - A;
			visited[c] = 1;
			solve(c);
		}
		
	}
}
int main(void){


	cin >> A >> B >> C;
	visited[C] = 1;
	solve(C);
	for (int i = 1; i <= C; i++){
		if (visited[i] == 1)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}