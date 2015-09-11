#include <iostream>
using namespace std;

int main(void){

	int n;
	int arr[11];
	
	
	cin >> n;

	for (int i = 0; i < n; i++){
		int tmp_arr[1001] = { 0 };
		for (int j = 0; j < 10; j++){
			cin >> arr[j];
			tmp_arr[arr[j]] = arr[j];
		}
		
		for (int m = 0, n = 0; m < 1001; m++){
			if (tmp_arr[m] > 0){
				if (++n == 8) {
					cout << tmp_arr[m] << endl;
					break;
				}
			}

		}
	}


}