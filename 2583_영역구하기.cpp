#include <iostream>
#define MAX_SIZE_Q 101
using namespace std;



typedef struct {
	int queue[101];
	int front;
	int rear;
} MyQueue;

int result_num = 0;
int result_area = 0;
int k = 0;
int result_area_list[101];
int graph[101][101] = { 0 };
MyQueue q_x;
MyQueue q_y;
int M, N, num;

void init(MyQueue *Q){
	Q->front = 0;
	Q->rear = 0;
}

bool is_full(MyQueue *Q){
	return Q->front == (Q->rear + 1) % MAX_SIZE_Q;
}
bool is_emptyy(MyQueue *Q){
	return Q->front == Q->rear;
}

void push(MyQueue *Q, int data){
	if (!is_full(Q)){
		Q->rear = (Q->rear + 1) % MAX_SIZE_Q;
		Q->queue[Q->rear] = data;
	}
}

void pop(MyQueue *Q){
	if (!is_emptyy(Q)){
		Q->front = (Q->front + 1) % MAX_SIZE_Q;
	}
}
int top(MyQueue *Q){
	return Q->queue[ (Q->front + 1) % MAX_SIZE_Q ];
}

void bfs(){
	result_area++;
	graph[top(&q_x)][top(&q_y)] = 1;
	

		if ((top(&q_x) >= 0) && (top(&q_y)+1 >=0) && 
			(top(&q_x) <= M) && (top(&q_y)+1 < N) &&
			graph[top(&q_x)][top(&q_y) + 1] == 0)	{

				push(&q_x, top(&q_x));
				push(&q_y, top(&q_y) + 1);
				graph[top(&q_x)][top(&q_y)+1] = 1;
		}
	if ((top(&q_x)+1 >= 0) && (top(&q_y) >= 0) && 
		(top(&q_x)+1 < M) && (top(&q_y) <= N) && 
		graph[top(&q_x) + 1][top(&q_y)] == 0){

				push(&q_x, top(&q_x)+1);
				push(&q_y, top(&q_y));
				graph[top(&q_x)+1][top(&q_y)] = 1;

		}
	if ((top(&q_x) >= 0) && (top(&q_y)-1 >= 0) &&
		(top(&q_x) <= M) && (top(&q_y)-1 < N) && 
		graph[top(&q_x)][top(&q_y) - 1] == 0){

				push(&q_x, top(&q_x));
				push(&q_y, top(&q_y)-1);
				graph[top(&q_x)][top(&q_y)-1] = 1;
		}
	if ((top(&q_x)-1 >= 0) && (top(&q_y) >= 0) && 
		(top(&q_x)-1 < M) && (top(&q_y) <= N) && 
		graph[top(&q_x) - 1][top(&q_y)] == 0){

				push(&q_x, top(&q_x)-1);
				push(&q_y, top(&q_y));
				graph[top(&q_x)-1][top(&q_y)] = 1;
	}

	pop(&q_x);
	pop(&q_y);

	if (!is_emptyy(&q_x) && !is_emptyy(&q_y)){
		bfs();
	}
		

}

int main(void){

	
	int x_1, y_1, x_2, y_2;
	
	
	cin >> N>> M >> num;

	// 그래프 만들기
	for (int i = 0; i < num; i++){
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int j = x_1; j < x_2; j++){
			for (int k = y_1; k < y_2; k++){
				if (graph[j][k] != 1)	{
					graph[j][k] = 1;
				}
			}
		}
	}

		
	// (0,0)부터 (N,M)까지 BFS
	// ex ) M == 7 / N == 5
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if (graph[i][j] == 0) {
				result_num++;
				push(&q_x, i);
				push(&q_y, j);
				bfs();
				init(&q_x);
				init(&q_y);
				result_area_list[k++] = result_area;
				result_area = 0;
			}
		}
	}

	// 출력
	cout << result_num << endl;

	// 버블소트
	for (int i = 0; i<k - 1; i++){
		for (int j = 0; j<k- 1; j++){
			if (result_area_list[j] > result_area_list[j + 1]){
				int temp = result_area_list[j];
				result_area_list[j] = result_area_list[j + 1];
				result_area_list[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < k; i++){
		cout << result_area_list[i] << " ";
	}

	return 0;
}