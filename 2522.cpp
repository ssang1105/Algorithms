#include <iostream>
using namespace std;

int main(void){

	int N;
	cin >> N;

	// ex ) N == 3
	for (int i = 1; i <= (2*N) - 1; i++){
		if (i <= N){
			for (int j = i; j < N; j++) cout << " ";
			for (int j = 0; j < i; j++) cout << "*";
			cout << endl;
		}
		else{
			for (int j = 0; j < i - N; j++) cout << " ";
			for (int j = i-N; j < N; j++) cout << "*";	
			cout << endl;
		}
	}


	return 0;
}
