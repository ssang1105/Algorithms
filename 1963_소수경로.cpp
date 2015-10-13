#include <iostream>
#include <queue>
using namespace std;

int A, B, T;
int prime[10000] = { 0 };
int visited[10000] = { 0 };
int result = 0;
typedef struct {
	int num;
	int cnt;
} stct;

stct st;
queue<stct> q;

void makePrimeArray(){
	for (int i = 1000; i <= 9999; i++){
		bool flag = false;
		for (int j = 2; j < i; j++){
			if (i%j == 0) {
				flag = false;
				break;
			}
			flag = true;
		}

		if (flag){
			prime[i] = 1;
		}
	}
}

void bfs(){
	
	while (!q.empty()){
		
		// 1�� �ڸ��� ��ȭ���� �� ������ ������ ��� push
		for (int i = 1; i <= 10; i++){
			// 1043�϶� 1���ڸ��� 3�� tmp
			int tmp = q.front().num % 1000 % 100 % 10;
			if (tmp + i < 10){
				if (prime[q.front().num + i] == 1 && visited[q.front().num + i] != 1){
					st.num = q.front().num + i;
					st.cnt = q.front().cnt + 1;
					if (st.num>1000){
						visited[st.num] = 1;
						q.push(st);
						if (st.num == B) {
							result = st.cnt;
							return;
						}
					}
					
				}
			}
			else{
				if (prime[q.front().num - ((tmp + i) % 10)] == 1 && visited[q.front().num - ((tmp + i) % 10)] != 1){
					st.num = q.front().num - ((tmp + i) % 10);
					st.cnt = q.front().cnt + 1;
					if (st.num > 1000){
						visited[st.num] = 1;
						q.push(st);
						if (st.num == B) {
							result = st.cnt;
							return;
						}
					}
				}
			}

			
		}
		// 10�� �ڸ��� ��ȭ���� �� ������ ������ ��� push
		for (int i = 1; i <= 10; i++){
			// 1043�϶� 10���ڸ��� 4�� tmp
			int tmp = q.front().num % 1000 % 100 / 10;
			if (tmp + i < 10){
				if (prime[q.front().num + (i * 10)] == 1 && visited[q.front().num + (i * 10)] != 1){
					st.num = q.front().num + (i * 10);
					st.cnt = q.front().cnt + 1;
					if (st.num > 1000){
						visited[st.num] = 1;
						q.push(st);
						if (st.num == B) {
							result = st.cnt;
							return;
						}
					}
				}
			}
			else{
				if (prime[q.front().num - (((tmp + i) % 10)) * 10] == 1 && visited[q.front().num - (((tmp + i) % 10)) * 10] != 1){
					st.num = q.front().num - (((tmp + i) % 10)) * 10;
					st.cnt = q.front().cnt + 1;
					if (st.num > 1000){
						visited[st.num] = 1;
						q.push(st);
						if (st.num == B) {
							result = st.cnt;
							return;
						}
					}
				}
			}

		}

		// 100�� �ڸ��� ��ȭ���� �� ������ ������ ��� push
		for (int i = 1; i <= 10; i++){
			// 1043�϶� 100���ڸ��� 0�� tmp
			int tmp = q.front().num % 1000 / 100;
			if (tmp + i < 10){
				if (prime[q.front().num + (i * 100)] == 1 && visited[q.front().num + (i * 100)] != 1){
					st.num = q.front().num + (i * 100);
					st.cnt = q.front().cnt + 1;
					if (st.num > 1000){
						visited[st.num] = 1;
						q.push(st);
						if (st.num == B) {
							result = st.cnt;
							return;
						}
					}
				}
			}
			else{
				if (prime[q.front().num - (((tmp + i) % 10)) * 100] == 1 && visited[q.front().num - (((tmp + i) % 10)) * 100] != 1){
					st.num = q.front().num - (((tmp + i) % 10)) * 100;
					st.cnt = q.front().cnt + 1;
					if (st.num > 1000){
						visited[st.num] = 1;
						q.push(st);
						if (st.num == B) {
							result = st.cnt;
							return;
						}
					}
				}
			}
		}
		// 1000�� �ڸ��� ��ȭ���� �� ������ ������ ��� push
		for (int i = 1; i <= 10; i++){
			// 1043�϶� 1000���ڸ��� 1�� tmp
			int tmp = q.front().num / 1000;
			if (tmp + i < 10){
				if (prime[q.front().num + (i * 1000)] == 1 && visited[q.front().num + (i * 1000)] != 1){
					st.num = q.front().num + (i * 1000);
					st.cnt = q.front().cnt + 1;
					if (st.num > 1000){
						visited[st.num] = 1;
						q.push(st);
						if (st.num == B) {
							result = st.cnt;
							return;
						}
					}
				}
			}
			else{
				if (prime[q.front().num - (((tmp + i) % 10)) * 1000] == 1 && visited[q.front().num - (((tmp + i) % 10)) * 1000] != 1){
					st.num = q.front().num - (((tmp + i) % 10)) * 1000;
					st.cnt = q.front().cnt + 1;
					if (st.num > 1000){
						visited[st.num] = 1;
						q.push(st);
						if (st.num == B) {
							result = st.cnt;
							return;
						}
					}
				}
			}
		}

		q.pop();
	}
}
int main(void){
	makePrimeArray();
	cin >> T;
	while (T--){
		cin >> A >> B;
		if (A - B == 0){
			cout << 0 << endl;
			continue;
		}
		
		st.num = A;
		st.cnt = 0;
		q.push(st);
		visited[st.num] = 1;
		bfs();
		if (result == 0)
			cout << "Impossible" << endl;
		else
			cout << result << endl;

		
		for (int i = 1000; i <= 10000; i++){
			visited[i] = 0;
			if (!q.empty()) q.pop();
		}
		result = 0;
	}

	return 0;
}