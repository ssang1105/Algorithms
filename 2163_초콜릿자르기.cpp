#include <iostream>
using namespace std;


int main(void){

	int A, B;
	int cnt;

	cin >> A >> B;
	
	if (A == 1 && B != 1)
		cout << B - 1 << endl;
	else if (A != 1 && B == 1)
		cout << A - 1 << endl;
	else
		cout << (B - 1) * A + A-1 << endl;
	
	return 0;
}