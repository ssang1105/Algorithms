#include <iostream>
using namespace std;

int main(void){
	int a, b;
	int arr[21];
	for (int i = 1; i <= 20; i++)
		arr[i] = i;

	for (int i = 0; i < 10; i++){
		cin >> a >> b;

		int k = 0;
		for (int i = a; k <= (b-a)/2;   i++, k++){
			int tmp = arr[i];
			arr[i] = arr[b - k];
			arr[b - k] = tmp;
		}
	}

	for (int i = 1; i <= 20; i++)
		cout << arr[i] << " ";
	return 0;
}