#include <iostream>
using namespace std;



int recur(int first, int number, int cnt){
	int tmp;
	cnt++;
	tmp = ((number / 10 + number % 10)%10) + (10 * (number%10));
	if (tmp == first) return cnt;
	else recur(first, tmp, cnt);


}

int main(void){
	int N;
	cin >> N;

	
	cout << recur(N,N,0) << endl;
}