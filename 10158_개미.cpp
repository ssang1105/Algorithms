#include <iostream>
using namespace std;

unsigned int w, h;
unsigned int x, y;
unsigned int current_x, current_y, current_dir;
unsigned long tt;


void gogo(int x, int y){

	// 오른쪽 위로 계속 가는 경우 (x-1, y+1)
	if (current_dir == 1){
		current_x -= 1;
		current_y += 1;
		if (current_y == w && current_x == 1){
			// 왼쪽 아래로
			current_dir = 3;
		}
		// 오른쪽 벽에 부딪힌 경우 왼쪽 위로
		else if (current_y == w)
			current_dir = 4;
		// 위쪽 벽에 부딪힌 경우 오른쪽 아래로
		else if (current_x == 1)
			current_dir = 2;
	}
	// 오른쪽 아래로 계속 가는 경우 (x+1, y+1)
	else if (current_dir == 2){
		current_x += 1;
		current_y += 1;
		if (current_y == w  && current_x == h + 1){
			// 왼쪽 위로
			current_dir = 4;
		}
		// 오른쪽 벽에 부딪힌 경우 왼쪽 아래로 
		else if (current_y == w)
			current_dir = 3;
		// 아래쪽 벽에 부딪힌 경우 오른쪽 위로
		else if (current_x == h+1)
			current_dir = 1;
	}
	// 왼쪽 아래로 계속 가는 경우 (x+1, y-1)
	else if (current_dir == 3){
		current_x += 1;
		current_y -= 1;
		if (current_y == 0 && current_x == h + 1){
			// 오른쪽 위로
			current_dir = 1;
		}
		// 왼쪽 벽에 부딪힌 경우 오른쪽 아래
		else if (current_y == 0)
			current_dir = 2;
		// 아래쪽 벽에 부딪힌 경우 왼쪽 위로
		else if (current_x == h+1)
			current_dir = 4;

	}
	// 왼쪽 위로 계속 가는 경우 (x-1, y-1)
	else if (current_dir == 4){
		current_x -= 1;
		current_y -= 1;
		if (current_y == 0 && current_x == 1){
			// 오른쪽 아래로
			current_dir = 2;
		}
		// 왼쪽 벽에 부딪힌 경우 오른쪽 위로 
		else if (current_y == 0)
			current_dir = 1;
		// 위쪽 벽에 부딪힌 경우 왼쪽 아래
		else if (current_x == 1)
			current_dir = 3;
	}

}

int main(void){

	

	cin >> w >> h;
	cin >> x >> y;
	cin >> tt;

	current_x = h + 1 - y;
	current_y = x;
	current_dir = 1; 

	while (tt--){
		// w = 6, h = 4 일때
		// (x = 4, y = 1)--> ( 4 , 4 ) 
		gogo(current_x, current_y);
		
	}
	cout << current_y << " " << h + 1 - current_x << endl;
	
	

}