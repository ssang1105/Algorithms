// 플로이드 알고리즘
#include <iostream>
#include <queue>
using namespace std;


int map[105][105] = { 0 };
int visited[105] = { 0 };
int isGroup[105] = { 0 };
int result[105] = { 0 };

int num = 0;
int max_num = 0;
int minNodeNum = 9999;
int minNode = 0;
int A = 0;
int K = 0;
pair <int, int> pa;
queue < pair <int, int> > q;
int N;
int M;

void initVisited(){
	for (int i = 1; i <= N; i++)
		visited[i] = 0;
}
void bfs(){

	isGroup[q.front().first] = 1;
	visited[q.front().first] = 1;
	
	for (int i = 1; i <= N; i++){
		if (( map[q.front().first][i] == 1 || map[i][q.front().first] == 1 ) && visited[i] == 0){
			pa.first = i;
			pa.second = q.front().second + 1;
			q.push(pa);
		}
	}
	
	if (q.front().second > max_num)
		max_num = q.front().second;
	
	q.pop();
	
	if (!q.empty())
		bfs();

}

int main(void){
	int a, b;

	cin >> N;
	cin >> M;
	while (M--){
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int i = 1; i <= N; i++){
		pa.first = i;
		pa.second = 0;
		q.push(pa);
		// 한번도 거치지 않는 노드이면 (그룹이면) 
		if (isGroup[i] == 0){			
			result[K++] = minNode;
			max_num = 0;
			minNodeNum = 9999;
		}
		
		bfs();
		
		// 대표 구하기
		if (minNodeNum > max_num){
			minNodeNum = max_num;
			minNode = i;
			max_num = 0;
			if (result[K] == 0)
				result[K] = minNode;
		}
		
		initVisited();
	}

	cout << K << endl;
	for (int i = 1; i <= K; i++)
		cout << result[i] << endl;


}

