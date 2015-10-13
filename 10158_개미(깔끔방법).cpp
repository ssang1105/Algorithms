#include <iostream>
using namespace std;

int main(void){
	unsigned int w, h;
	unsigned int x, y;
	unsigned int dx = 1;
	unsigned int dy = 1;
	unsigned long tt;

	cin >> w >> h;
	cin >> x >> y;
	cin >> tt;

	
	while (tt--){
		
		// 좌, 우 벽에 부딪히는 경우
		if (x == w || x == 0)
			dx = -dx;
		// 상, 하 벽에 부딪히는 경우
		if (y == h || y == 0)
			dy = -dy;
		// 핵심은 if ~ else if 가 아니라
		// if ~ if로 함으로써 
		// 꼭지점에 부딪힌 경우도 해당이 됨.
		

		x += dx;
		y += dy;
	

	}
	cout << x  << " " << y << endl;



}

