#include <iostream>
#include <string>
using namespace std;

string input;
bool isGwalHo; // 첫번째 '('인지
int sum = 0;


// ()()()))( 80
// )))() 40
// (()) 30
// ((())) 40
// )( 20

void gwalhoTest(int i){
	if (input[i + 1] != input[i])
		sum += 10;
	else
		sum += 5;
	if (i + 1 < input.length())
		gwalhoTest(i + 1);
}


int main(void){
	cin >> input;
	
	sum = 0;
	gwalhoTest(0);

	cout << sum << endl;
	
}


