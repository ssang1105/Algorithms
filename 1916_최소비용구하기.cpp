#include <iostream>
using namespace std;

long long map[1002][1002] = { 0 };

void floyd(int n){
	for (int k = 0; k <= n; k++){
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				if (map[i][j] > map[i][k] + map[k][j] && map[i][k] != 0 && map[k][j] != 0 && map[i][j] != 0)
					map[i][j] = map[i][k] + map[k][j];
	}
}

int main(void){

	int cityNum;
	int A, B;
	int busInfo;
	int input_a, input_b, input_c;

	cin >> cityNum;
	cin >> busInfo;

	while (busInfo--){
		cin >> input_a >> input_b >> input_c;
		map[input_a][input_b] = input_c;
	}

	cin >> A >> B;

	floyd(cityNum);
	cout << map[A][B] << endl;

}

