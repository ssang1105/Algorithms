#include <iostream>
using namespace std;

int N;
int map[130][130];
int whiteNum = 0;
int blackNum = 0;
bool color;
void solve(int startX, int startY, int width, bool isBlack){
	
	bool flag = false;
	
	for (int i = 0; i < width; i++){
		for (int j = 0; j < width; j++){
			if (map[startX+i][startY+j] == isBlack) continue;

			// divide
			else{
				// 왼쪽 위
				solve(startX, startY, width/2, map[startX][startY]);
				// 왼쪽 아래
				solve(startX + width / 2, startY, width / 2, map[startX + width / 2][startY]);
				// 오른쪽 위
				solve(startX, startY + width / 2, width / 2, map[startX][startY + width / 2]);
				// 오른쪽 아래
				solve(startX + width / 2, startY + width / 2, width / 2, map[startX + width / 2][startY + width / 2]);
				return;
			}
		}
		
	}
	
	if (isBlack) blackNum++;
	else whiteNum++;
	

}
int main(void){

	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	
	if (map[0][0] == 1) color = true; // black
	else color = false; // white
	solve(0, 0, N, color);

	cout << whiteNum << endl;
	cout << blackNum << endl;

	return 0;
}