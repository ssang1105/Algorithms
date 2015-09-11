#include <iostream>
using namespace std;

int yaksu(int num, int order){
	int k = 0;
	for (int i = 1; i <= num; i++)
		if (num%i == 0){
			k++;
			if (k == order) return i;
		}

	return 0;
}

int main(void){
	int A, B;
	cin >> A >> B;
	cout << yaksu(A, B) << endl;
	

}