#include <iostream>
using namespace std;

long long cache[102] = { 0 };

long long padovan(int num){
	if (num == 1 || num == 2 || num == 3){
		cache[num] = 1;
		return 1;
	}
	else if (num == 4){
		cache[num] = 2;
		return 2;
	}
	else{
		if (cache[num - 2] == 0 && cache[num - 3] == 0){
			cache[num] = padovan(num - 2) + padovan(num - 3);
			return cache[num];
		}
		else if (cache[num - 2] == 0 && cache[num - 3] != 0){
			cache[num] = cache[num - 3] + padovan(num - 2);
			return cache[num];
		}
		else if (cache[num - 2] != 0 && cache[num - 3] == 0){
			cache[num] = padovan(num - 3) + cache[num - 2];
			return cache[num];
		}
		else
			return cache[num - 2] + cache[num - 3];
	}
}

int main(void){

	int T;
	int N;
	cin >> T;
	
	while (T--){
		cin >> N;
		cout << padovan(N) << endl;
	}
	

	return 0;
}