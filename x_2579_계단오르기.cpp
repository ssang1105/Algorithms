#include <iostream>
using namespace std;

int stair[302] = { 0 };
int cache[302] = { 0 };
int isContinue[302] = { 0 };

int retMax(int a, int b, int num){

	// 연속적인 경우
	if (isContinue[num - 1] != 0 && isContinue[num - 2] != 0){
		isContinue[num] = 100;
		return b;
	}
	else{
		if (a >= b) return a;
		else return b;
	}

}

int recur(int num){
	if (num == 1) cache[num] = stair[1];
	else if (num == 2) cache[num] = stair[1] + stair[2];
	else{

		// num-1, num-2 둘 다 캐시에 있는 경우
		if (cache[num - 1] != 0 && cache[num - 2] != 0)
			cache[num] = retMax(cache[num - 1], cache[num - 2], num) + stair[num];
			
		// num-1만 캐시에 있는경우
		else if (cache[num - 1] != 0)
			cache[num] = retMax(cache[num - 1], recur(num - 2), num) + stair[num];

		// num-2만 캐시에 있는경우
		else if (cache[num - 2] != 0){
			cache[num] = retMax(recur(num - 1), cache[num - 2], num) + stair[num];
		}
		// num-1, num-2 둘 다 캐시에 없는 경우
		else{
			cache[num] = retMax(recur(num - 1), recur(num - 2), num) + stair[num];
		}
		
	}		

	// 연속적인 경우
	if (isContinue[num] == 100)
		isContinue[num] = 0;
	else
		isContinue[num] = 1;
	return cache[num];
}

int main(void){

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> stair[i];
	}
	
	
	 cout << recur(N) << endl;



	return 0;
}