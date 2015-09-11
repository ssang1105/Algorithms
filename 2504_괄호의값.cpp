#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(void){
	string S;
	stack <int> st;
	int tmp = 0;
	int result = 0;
	cin >> S;

	for (int i = 0; i < S.length(); i++){
		if (S[i] == '(' || S[i] == '[')
			st.push(S[i]);
		else if (st.top() == '(' && S[i] == ')'){
			st.pop();
			st.push(2);
		}	
		else if (st.top() == '[' && S[i] == ']'){
			st.pop();
			st.push(3);
		}
		else if (st.top() != '['  && S[i] == ']'){
			while (true){
				if (st.top() == '['){
					st.pop();
					st.push(tmp);
					tmp = 0;
					break;
				}
				tmp += st.top()*3;
				st.pop();
				if (st.empty()){
					cout << 0 << endl;
					return 0;
				}
			}
		}
		else if (st.top() != '(' && S[i] == ')'){
			while (true){
				if (st.top() == '('){
					st.pop();
					st.push(tmp);
					tmp = 0;
					break;
				}
				tmp += st.top() * 2;
				st.pop();
				if (st.empty()){
					cout << 0 << endl;
					return 0;
				}
			}
		}		
	}

	while (!st.empty()){
		if (st.top() == '(' || st.top() == '['){
			result = 0;
			break;
		}	

		result += st.top();
		st.pop();
	}
	
	cout << result << endl;
}