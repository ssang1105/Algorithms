#include <iostream>
using namespace std;

int main(void){
	int A, B, C;
	int gop;
	int map[10] = { 0 };
	cin >> A >> B >> C;
	gop = A * B * C;

	while ( gop > 10){
		map[gop % 10]++;
		gop = gop / 10;
	}
	map[gop]++;
	

	for (int i = 0; i <= 9; i++)
		cout << map[i] << endl;

}