#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
bool ok;
void go(string now) {
	if (ok) return;
	if (now.empty()) {
		ok = true;
		return;
	}
	for (int i = 0, j; i < now.length() && !ok; i++) {
		for (j = i; j < now.length() && now[i] == now[j]; j++);
		if (j - i >= 2)
			go(now.substr(0, i) + now.substr(j));
		i = j - 1;
	}
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		char in[1111];
		cin >> in;
		string s = in;
		ok = false;
		go(s);
		cout << ok << endl;
	}
	return 0;
}