#include <iostream>
#include <queue>
using namespace std;

int visited[100010];
int cnt = 0;
int result = 0;
int A, B;
bool EXIT =false;

typedef struct{
	int data;
	int count;
} DATA;

queue<DATA> q;

void bfs(){
	
	while (!q.empty()){

		DATA a, b, c;
		if (q.front().data * 2 <= 100000 && visited[q.front().data * 2] == 0){
			a.count = q.front().count + 1;
			a.data = q.front().data * 2;
			q.push(a);
			visited[a.data] = 1;
			if (a.data == B) break;
		}
		
		if (q.front().data - 1> 0 && visited[q.front().data-1] == 0){
			a.count = q.front().count + 1;
			a.data = q.front().data - 1;
			q.push(a);
			visited[a.data] = 1;
			if (a.data == B) break;
		}

		
		if (q.front().data + 1 <= 100000 && visited[q.front().data+1] == 0){
			a.count = q.front().count + 1;
			a.data = q.front().data + 1;
			q.push(a);
			visited[a.data] = 1;
			if (a.data == B) break;
		}
	
		q.pop();
	}

	result = q.front().count+1;
	cout << result << endl;
}

int main(void){
	
	cin >> A >> B;
	if (A == B){
		cout << 0 << endl;
		return 0;
	}
	else if (A > B){
		cout << A -B << endl;
		return 0;
	}	
		
	DATA data;
	data.data = A;
	data.count = 0;
	visited[data.data] = 1;
	q.push(data);
	
	bfs();
		
}