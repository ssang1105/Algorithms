#include <iostream>
using namespace std;

int main(void){
	int N;
	cin >> N;
	for (int i = 1; i <= (2 * N) - 1; i++){
		if (i <= N){
			for (int j = 0; j < i; j++) cout << "*";
			for (int k = i; k < N; k++) cout << ' ';
		}
		else{
			for (int m = i - N; m < N; m++) cout << "*";
			for (int l = 0; l < i - N; l++) cout << " ";
		}
		cout << endl;
	}
	return 0;
}
