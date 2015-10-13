#include <iostream>
#include <string>
using namespace std;

string result = "";
int N;
bool isReturn;

void dfs(int num){
	
	if (isReturn)	return;
	// int형을 문자로 넣기위해 마지막에 0 추가
	result += (num + '0'); 

	// 길이가 2인것부터 길이가 result의 길이 / 2 인것까지 반복패턴이 있는지 체크 (result의 길이가 3이하인경우 pass)
	int checkLength = result.length() / 2;
	for (int i = 2; i <= checkLength; ++i){
		string a = result.substr(result.length() - i, i); 
		string b = result.substr(result.length() - i * 2, i);
		// 같은 패턴을 발견한 경우
		if (a == b){
			result.erase(result.length() - 1);
			return;
		}
	}

	// N개의 좋은 수열 완성
	if (result.length() == N){
		cout << result << endl;
		isReturn = true;
		return;
	}
	else{
		if (num == 1){
			dfs(2);
			dfs(3);
		}
		else if (num == 2){
			dfs(1);
			dfs(3);
		}
		else if (num == 3){
			dfs(1);
			dfs(2);
		}
		result.erase(result.length() - 1);
	}
	
}

int main(){
	cin >> N;
	dfs(1);
	return 0;
}
