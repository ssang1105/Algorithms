#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <functional>
using namespace std;

int N;
int sum = 0;
int data[10];
int used[10] = { 0 };

int main(void){
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> data[i];
	
	
	sort(data, data + N, greater<int>());

	int selected = data[0];
	int selected_2 = data[0];
	int selected_2_index;
	used[0] = 1;
	for (int i = 0; i < N; i++){
		selected = selected_2;
		int max_num = 0;
		for (int j = 0; j < N; j++){
			if (used[j] == 1) continue;
			else if (abs(selected - data[j]) > max_num){
				max_num = abs(selected - data[j]);
				selected_2 = data[j];
				selected_2_index = j;
			}
		}
		used[selected_2_index] = 1;
		sum += abs(selected - selected_2);
	}

	
	cout << sum << endl;
	

	return 0;
}