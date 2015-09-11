#include <iostream>
using namespace std;

bool isYaksu(int a, int b){
	
	int i;
	for (i = 1; i*i < b; i++){
		if (b % i == 0 && i == a) return true;
		else if (b % i == 0 && (b / i) == a) return true;
	}
	if (i*i == b) return true;

	return false;
}

int main(void){

	int A, B;

	for (;;){
		cin >> A >> B;
		if (A == 0 && B == 0) break;
		if (B>A && isYaksu(A, B)){
			cout << "factor" << endl;
			continue;
		}
		else if (B<A && isYaksu(B,A)){
			cout << "multiple" << endl;
			continue;
		}
		else cout << "neither" << endl;




	}


	return 0;
}