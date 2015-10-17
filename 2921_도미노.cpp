#include <iostream>
using namespace std;

int N;
int solve(int num){
	if (num == 1) return 3;
	else if (num == 2) return 12;
	else{
		int sum = solve(num - 1);
		for (int i = num; i <= num + num; i++)
			sum += i;
		
		return sum;
	}
}
int main(void){

	
	cin >> N;
	cout << solve(N) << endl;
	

	return 0;
}