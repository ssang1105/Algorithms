#include <iostream>
using namespace std;

int main(void){
	int n;
	cin >> n;

	for (int i = 0; i < (2 * n) - 1; i++){
		if (i <= n){
			for (int j = 0; j < n - 1; j++) cout << " ";
			for (int j = i; j > 0; j--) cout << "*";
			cout << "*" << endl;
			for (int j = i; j > 0; j--) cout << "*";
			for (int j = 0; j < n - 1; j++) cout << " ";
		}
		else{
			for (int j = i; j > 0; j--) cout << "";
			for (int j = 0; j < n - 1; j++) cout << "*";
			cout << "*" << endl;
			for (int j = i; j > 0; j--) cout << "";
			for (int j = 0; j < n - 1; j++) cout << "*";
		}
		cout << endl;
	}
}