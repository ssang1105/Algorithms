#include <iostream>
#include <string>
using namespace std;

void swapp(string a, string b){
	string tmp = a;
	a = b;
	b = tmp;
}
int main(void){

	string str[101];
	string result;

	int T;
	cin >> T;
	
	for (int i = 1; i <= T; i++){
		cin >> str[i];
	}
	int k = 1;
	
	// KBS1 찾기
	while (1){
		if (str[k++] != "KBS1"){
			result += 1 + '0';
			break;
		}
	}
	// KBS1 올리기
	while (k-- > 1){
		result += 4 + '0';
		swapp(str[k], str[k - 1]);
	}
		

	k = 1;
	// KBS2 찾기
	while (1){
		if (str[k++] != "KBS2"){
			result += 1 + '0';
			break;
		}
	}
	// KBS2 올리기
	while (k-- > 2){
		result += 4 + '0';
		swapp(str[k], str[k - 1]);
	}
	
	cout << result << endl;


	return 0;
}