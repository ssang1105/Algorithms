#include <iostream>
using namespace std;

bool isSosu(unsigned int n){

	if (n == 1) return false;
	// 짝수 중에 2만 소수이므로 2의 배수는 미리 거르자.
	if (n == 2)return true;
	if (n % 2 == 0) return false;
	for (unsigned int i = 3; i*i <= n; i += 2)
		if (n%i == 0) return false;
	return true;
}


int main(void){
	unsigned int M, N;
	cin >> M >> N;

	for (unsigned int i = M; i <= N; i++)
		if (isSosu(i)) cout << i << endl;

	return 0;
}

