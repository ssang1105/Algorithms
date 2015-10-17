#include<iostream>
#include<math.h>

using namespace std;

int pump[100000];
int sobangcha[100000];
int visited[100000];
int P, F;
int result = 100000;

void connect(int pump_num, int cha_num, int leng){

	if (cha_num == F){
		if (result > leng)
			result = leng;
		return;
	}

	for (int i = 0; i < P; i++){
		if (visited[i] == 0){
			visited[i] = 1;
			if (pump[i] - sobangcha[cha_num] > 0){
				leng += pump[i] - sobangcha[cha_num];
				connect(i, cha_num + 1, leng);
				leng -= pump[i] - sobangcha[cha_num];
			}
			else{
				leng += sobangcha[cha_num] - pump[i];
				connect(i, cha_num + 1, leng);
				leng -= sobangcha[cha_num] - pump[i];
			}
			visited[i] = 0;
		}
	}

}
int main(void){
	
	cin >> P >> F;
	for (int i = 0; i < P; i++)
		cin >> pump[i];
	for (int i = 0; i < F; i++)
		cin >> sobangcha[i];


	connect(0,0,0);

	cout << result << endl;

	return 0;
}