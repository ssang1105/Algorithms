#include <iostream>
using namespace std;

int main(void){

	int arrX[4];
	int arrY[4];
	int tmp_arrX[1001] = { 0 };
	int tmp_arrY[1001] = { 0 };

	for (int i = 0; i < 3; i++){
		cin >> arrX[i] >> arrY[i];
		tmp_arrX[arrX[i]]++;
		tmp_arrY[arrY[i]]++;
	}

	for (int i = 0; i < 1001; i++){
		if (tmp_arrX[i] == 1) {
			cout << i << " ";
			break;
		}
	}

	for (int i = 0; i < 1001; i++){
		if (tmp_arrY[i] == 1) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}