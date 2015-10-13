#include <iostream>

using namespace std;

unsigned long long pig[7];
unsigned long long result[7];
int main(void){
	int T;
	unsigned long long max_saryo;
	unsigned long long day = 0;
	unsigned long long sum = 0;
	cin >> T;

	while (T--){
		cin >> max_saryo;
		for (int i = 0; i <= 5; i++)
			cin >> pig[i];
			


		while (true){
			day++;
			if (day == 1){
				for (int i = 0; i <= 5; i++){
					result[i] = pig[i];
					sum += result[i];
				}
			}
			else{
				for (int i = 0; i <= 5; i++){
					result[i] = pig[i] + pig[(i + 1) % 6] + pig[(i + 5) % 6] + pig[(i + 3) % 6];
					sum += result[i];
				}		
			}
			if (sum > max_saryo)
				break;
			sum = 0;
			for (int i = 0; i <= 5; i++){
				pig[i] = result[i];
			}
		}


		cout << day << endl;

		day = 0;
		max_saryo = 0;
		sum = 0;
		for (int i = 0; i <= 5; i++)
			result[i] = 0;
	}


	return 0;
}