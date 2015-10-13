#include <iostream>
#include <string>
using namespace std;

string result = "";
int N;
bool isReturn;

void dfs(int num){
	
	if (isReturn)	return;
	// int���� ���ڷ� �ֱ����� �������� 0 �߰�
	result += (num + '0'); 

	// ���̰� 2�ΰͺ��� ���̰� result�� ���� / 2 �ΰͱ��� �ݺ������� �ִ��� üũ (result�� ���̰� 3�����ΰ�� pass)
	int checkLength = result.length() / 2;
	for (int i = 2; i <= checkLength; ++i){
		string a = result.substr(result.length() - i, i); 
		string b = result.substr(result.length() - i * 2, i);
		// ���� ������ �߰��� ���
		if (a == b){
			result.erase(result.length() - 1);
			return;
		}
	}

	// N���� ���� ���� �ϼ�
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
