#include <iostream>
using namespace std;

int myfibo(int num){
	if (num == 1) return 1;
	else if (num == 2) return 2;
	else if (num == 3) return 4;
	else return myfibo(num - 1) + myfibo(num - 2) + myfibo(num - 3);
}

int main(void){
	int N;
	int T;
	cin >> T;
	while (T--){
		cin >> N; 
		cout << myfibo(N) << endl;
	}
}