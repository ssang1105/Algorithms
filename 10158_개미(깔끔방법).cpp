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
		
		// ��, �� ���� �ε����� ���
		if (x == w || x == 0)
			dx = -dx;
		// ��, �� ���� �ε����� ���
		if (y == h || y == 0)
			dy = -dy;
		// �ٽ��� if ~ else if �� �ƴ϶�
		// if ~ if�� �����ν� 
		// �������� �ε��� ��쵵 �ش��� ��.
		

		x += dx;
		y += dy;
	

	}
	cout << x  << " " << y << endl;



}

