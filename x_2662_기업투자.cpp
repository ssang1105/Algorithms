#include <iostream>
using namespace std;

int result[22][22] = { 0 };
int arr[22][22] = { 0 };

int MaxNumber(int a, int b){
	if (a >= b) return a;
	else return b;
}
int main(void){
	int companyNum;
	int money;
	int num, a, b;

	cin >> money >> companyNum;

	for (int i = 1; i <= companyNum; i++){
		cin >> num >> a >> b;
		arr[num][0] = a;
		arr[0][num] = b;
	}

	for (int i = 1; i <= companyNum; i++){
		for (int j = 1; j <= money; j++){
			for (int k = 1; k <= j; k++){
				result[i][j] = MaxNumber(result[i - 1][k], arr[i][j - k]);
			}
		}
	}

	cout << result[companyNum][money] << endl;
}