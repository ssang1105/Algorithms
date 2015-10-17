#include <iostream>
using namespace std;

int arr[21];
int a, b;
int cnt = 0;

void process(int now, int sum, bool chosen){	
	if (now == a){
		if (sum == b && chosen ) cnt++;
		return;
	}
	process(now + 1, sum + arr[now], 1);
	process(now + 1, sum, chosen);
}

int main(void){

	cin >> a >> b;
	for (int i = 0; i < a; i++){
		cin >> arr[i];
	}

	process(0, 0, 0);

	cout << cnt << endl;

	return 0;
}