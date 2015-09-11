#include <iostream>
using namespace std;

char *isRprime(int a, int b){

	int a_arr[1001] = { 0 };
	int k = 0;

	for (int i = 2; i <= a; i++){
		if (a%i == 0) a_arr[i]++;
		if (b%i == 0) a_arr[i]++;
	}

	if (a >= b){
		for (int i = 2; i <= a; i++){
			if (a_arr[i] == 2) return "no";
		}
	}
	else{
		for (int i = 2; i <= b; i++){
			if (a_arr[i] == 2) return "no";
		}
	}

	return "yes";
	
}

int main(void){
	int A, B;

	cin >> A >> B;

	cout << isRprime(A, B) << endl;

}