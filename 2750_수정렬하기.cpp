#include <iostream>
using namespace std;

int tmp[3][1005];
int main(void){

	
	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < 2; j++)
			tmp[j][i] = 0;
	}
	int T;
	int A;
	
	int n = 0;
	cin >> T;
	for(int i =0 ; i <T; i++){
		cin >> A;
		if (A >= 0)
			tmp[1][A] = 1;
		else{
			A *= -1;
			tmp[0][A] = 1;
		}
		
	}

	for (int i = 1000; i >= 0; i--){
		if (tmp[0][i] == 1)
			cout << i*-1 << endl;
	}

	for (int i = 0; i <=1000; i++){
		if (tmp[1][i] == 1){
			cout << i << endl;
		}
	}

	return 0;
}