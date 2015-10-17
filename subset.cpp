#include <iostream>
using namespace std;

int N;
int cnt = 0;
int target;
int include[41];

void solve(int now, int sum, int remaining){

	if (now > N) return;
	if (sum + remaining < N) return; //이 부분 

	if (now == N){
		if (sum == target/2){
			int tmp = 0;
			for (int i = 0; i < N; i++){
				if (include[i] == 1) tmp += (i + 1);
				else tmp -= (i + 1);
			}
			if (tmp == 0) cnt++;
			
		}
		return;
	}

	include[now] = 1;
	solve(now + 1, sum + now + 1, remaining-(now+1));
	include[now] = 0;
	solve(now + 1, sum, remaining-(now+1));

}

int main(void){

	cin >> N;
	target = N*(N + 1) / 2; // 등차수열의 합

	solve(0, 0,target*2);
	if (cnt==1)
		cout << cnt << endl;
	else{
		cout << cnt / 2 << endl;
	}
	return 0;
}

