#include <iostream>
#include <string>
using namespace std;

int L, C;
char str[20];
bool checkPassword(string result){
	for (int i = 0; i < L; i++)
		if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u')
			return true;
	return false;
}

void makePassword(int length, int start_index, string result){
	if (length == L){
		if (checkPassword(result)){
			cout << result << endl;
		}
		return;
	}
	for (int i = start_index; i < C; i++){
		makePassword(length + 1, i + 1, result + str[i]);
	}
}

int main(void){
	
	int num= 0;
	cin >> L >> C;
	for (int i = 0; i < C ; i++){
		char tmp;
		cin >> tmp;
		if (tmp != NULL)
			str[num++] = tmp;
	}

	// 버블 소트
	for (int i = 0; i < num-1; i++){
		for (int j = 0; j < num-1; j++){
			if (str[j] > str[j + 1]){
				char tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
			}
		}
	}

	makePassword(0, 0, "");
	

}