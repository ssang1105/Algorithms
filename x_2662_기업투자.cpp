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

	for (int i = 1; i <= money; i++){
		cin >> num;
		for (int j = 1; j <= companyNum; j++){
			cin >> a >> b>>
		
		 
		arr[i][0] = a;
		arr[0][i] = b;
	}

	// ȸ�� ���� ��ŭ loop
	for (int i = 1; i <= companyNum; i++){

		// ȸ�� ���� ���� ���� ��ŭ loop
		for (int j = 1; j <= money; j++){

			// ���� ������ ���� ����� �� ��ŭ loop
			for (int k = 1; k <= j; k++){
				result[i][j] = MaxNumber(result[i - 1][k], arr[i][j - k]);
			}
		}
	}

	cout << result[companyNum][money] << endl;
}