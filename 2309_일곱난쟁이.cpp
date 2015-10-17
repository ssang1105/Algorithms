#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int sum = 0;
int main(void){

	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9 && i != j; j++)	{
			sum = 0;
			for (int k = 0; k < 9; k++) {
				if (k != i && k != j)
					sum += arr[k];
			}
			if (sum == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j)
						cout << arr[k] << endl;
				}
			}
		}
	}
}