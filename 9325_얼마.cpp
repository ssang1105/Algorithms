#include <iostream>
using namespace std;

int main(void){

	int T;
	cin >> T;
	while (T--){
		int sum = 0;
		int carCost;
		int boopNum;
		int boopCnt;
		int boopCost;
		cin >> carCost;
		sum += carCost;
		cin >> boopNum;
		while (boopNum--){
			cin >> boopCnt >> boopCost;
			sum += (boopCnt * boopCost);
		}
		cout << sum << endl;
	}

	return 0;
}