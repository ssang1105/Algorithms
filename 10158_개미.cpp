#include <iostream>
using namespace std;

unsigned int w, h;
unsigned int x, y;
unsigned int current_x, current_y, current_dir;
unsigned long tt;


void gogo(int x, int y){

	// ������ ���� ��� ���� ��� (x-1, y+1)
	if (current_dir == 1){
		current_x -= 1;
		current_y += 1;
		if (current_y == w && current_x == 1){
			// ���� �Ʒ���
			current_dir = 3;
		}
		// ������ ���� �ε��� ��� ���� ����
		else if (current_y == w)
			current_dir = 4;
		// ���� ���� �ε��� ��� ������ �Ʒ���
		else if (current_x == 1)
			current_dir = 2;
	}
	// ������ �Ʒ��� ��� ���� ��� (x+1, y+1)
	else if (current_dir == 2){
		current_x += 1;
		current_y += 1;
		if (current_y == w  && current_x == h + 1){
			// ���� ����
			current_dir = 4;
		}
		// ������ ���� �ε��� ��� ���� �Ʒ��� 
		else if (current_y == w)
			current_dir = 3;
		// �Ʒ��� ���� �ε��� ��� ������ ����
		else if (current_x == h+1)
			current_dir = 1;
	}
	// ���� �Ʒ��� ��� ���� ��� (x+1, y-1)
	else if (current_dir == 3){
		current_x += 1;
		current_y -= 1;
		if (current_y == 0 && current_x == h + 1){
			// ������ ����
			current_dir = 1;
		}
		// ���� ���� �ε��� ��� ������ �Ʒ�
		else if (current_y == 0)
			current_dir = 2;
		// �Ʒ��� ���� �ε��� ��� ���� ����
		else if (current_x == h+1)
			current_dir = 4;

	}
	// ���� ���� ��� ���� ��� (x-1, y-1)
	else if (current_dir == 4){
		current_x -= 1;
		current_y -= 1;
		if (current_y == 0 && current_x == 1){
			// ������ �Ʒ���
			current_dir = 2;
		}
		// ���� ���� �ε��� ��� ������ ���� 
		else if (current_y == 0)
			current_dir = 1;
		// ���� ���� �ε��� ��� ���� �Ʒ�
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
		// w = 6, h = 4 �϶�
		// (x = 4, y = 1)--> ( 4 , 4 ) 
		gogo(current_x, current_y);
		
	}
	cout << current_y << " " << h + 1 - current_x << endl;
	
	

}