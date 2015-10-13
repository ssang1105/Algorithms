#include <iostream>
#include <string>
using namespace std;
unsigned long long result = 0;
void baksuTest(string s){
	
	
}

int main(void){
	unsigned long long A, B;
	
	cin >> A >> B;

	for (unsigned long long i = A; i <= B; i++){
		string s = to_string(i);
		baksuTest(s);
	}
	cout << (result) % 20150523<< endl;
}