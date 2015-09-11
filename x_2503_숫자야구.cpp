#include <iostream>
using namespace std;

int baseball[1000] = { 0 };

void goStrike(int num, int strike){
	
	int third = num / 100;
	int second = (num / 10) % 10;
	int first = (num % 100) % 10;



}

void goBall(int num, int ball){

}


int main(void){

	int N;
	int num;
	int strike;
	int ball;
	cin >> N;
	while (N--){
		cin >> num >> strike >> ball;

		goStrike(num, strike);
		goBall(num, ball);

	}


	return 0;
}