#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec;
bool used[200 + 1];
bool m[200 + 1][200 + 1][200 + 1];
int A, B, C;

void solve(int cur_a, int cur_b, int cur_c) {
	if (!m[cur_a][cur_b][cur_c]) {
		m[cur_a][cur_b][cur_c] = true;
		if (cur_a == 0) {
			vec.push_back(cur_c);
		}

		if (cur_c > 0) {
			if (cur_b < B) {
				if ((B - cur_b) >= cur_c) {
					solve(cur_a, cur_b + cur_c, 0);
				}
				else {
					solve(cur_a, B, cur_c - (B - cur_b));
				}
			}
			if (cur_a < A) {
				if ((A - cur_a) >= cur_c) {
					solve(cur_a + cur_c, cur_b, 0);
				}
				else {
					solve(A, cur_b, cur_c - (A - cur_a));
				}
			}
		}
		if (cur_b > 0) {
			if (cur_a < A) {
				if ((A - cur_a) >= cur_b) {
					solve(cur_a + cur_b, 0, cur_c);
				}
				else {
					solve(A, cur_b - (A - cur_a), cur_c);
				}
			}
			if (cur_c < C) {
				if ((C - cur_c) >= cur_b) {
					solve(cur_a, 0, cur_c + cur_b);
				}
				else {
					solve(cur_a, cur_b - (C - cur_c), C);
				}
			}
		}
		if (cur_a > 0) {
			if (cur_b < B) {
				if ((B - cur_b) >= cur_a) {
					solve(0, cur_b + cur_a, cur_c);
				}
				else {
					solve(cur_a - (B - cur_b), B, cur_c);
				}
			}
			if (cur_c < C) {
				if ((C - cur_c) >= cur_a) {
					solve(0, cur_b, cur_c + cur_a);
				}
				else {
					solve(cur_a - (C - cur_c), cur_b, C);
				}
			}
		}
	}

}
int main() {
	cin >> A >> B >> C;
	int a = 0;
	int b = 0;
	int c = C;
	vec.push_back(C);
	m[0][0][c] = true;
	if (C >= A)
		solve(A, 0, C - A);
	else
		solve(c, 0, 0);
	if (C >= B) 
		solve(0, B, C - B);
	else
		solve(0, c, 0);

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		if (!used[vec[i]]) {
			used[vec[i]] = true;
			cout << vec[i] << " ";
		}
	}
	return 0;
}