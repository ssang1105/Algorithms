#include <iostream>
using namespace std;

int main(void){


	int A, B, C;
	cin >> A >> B >> C;

	if (A*B - C >= 0)
		cout << A*B - C << endl;
	else
		cout << 0 << endl;

	return 0;
}