#include <iostream>
using namespace std;

int arr[1001][1001];
int main(void){

	int N,W;
	int a, b;
	cin >> N;
	for (int i = 0; i < W; i++){
		cin >> a >> b;
		arr[a][b] = 1;
	}

	return 0;
}