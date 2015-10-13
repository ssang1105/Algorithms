#include <iostream>
using namespace std;

int stair[302] = { 0 };
int cache[302] = { 0 };
int isContinue[302] = { 0 };

int retMax(int a, int b, int num){

	// �������� ���
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

		// num-1, num-2 �� �� ĳ�ÿ� �ִ� ���
		if (cache[num - 1] != 0 && cache[num - 2] != 0)
			cache[num] = retMax(cache[num - 1], cache[num - 2], num) + stair[num];
			
		// num-1�� ĳ�ÿ� �ִ°��
		else if (cache[num - 1] != 0)
			cache[num] = retMax(cache[num - 1], recur(num - 2), num) + stair[num];

		// num-2�� ĳ�ÿ� �ִ°��
		else if (cache[num - 2] != 0){
			cache[num] = retMax(recur(num - 1), cache[num - 2], num) + stair[num];
		}
		// num-1, num-2 �� �� ĳ�ÿ� ���� ���
		else{
			cache[num] = retMax(recur(num - 1), recur(num - 2), num) + stair[num];
		}
		
	}		

	// �������� ���
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