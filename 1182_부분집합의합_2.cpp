#include <iostream>
using namespace std;

int A, B;
int data[22];
int include[22];
int cnt = 0;

void solve(int now, int sum){

	if (now == A){
		if (sum == B){
			bool includeBool = true;
			for (int i = 0; i < A; i++)
				if (include[i] == 1) includeBool = false;
			if(!includeBool) 
				cnt++;
			return;
		}
		return;
	}
	
	include[now] = 1;
	solve(now+1, sum+ data[now]);
	include[now] = 0;
	solve(now +1, sum);

}



int main(void){

	cin >> A >> B;
	for (int i = 0; i < A; i++)
		cin >> data[i];

	solve(0, 0);
	cout << cnt << endl;

	return 0;
}