#include <iostream>
#define MAX_TOP 26
using namespace std;

typedef struct{
	char st[MAX_TOP];
	int val_length[MAX_TOP];
	int top;
} MyStack;
void init(MyStack *st){
	st->top = -1;
}
bool isStackFull(MyStack *st){
	return st->top == MAX_TOP - 1;
}
bool isStackEmpty(MyStack *st){
	return st->top == -1;
}

void push(MyStack* st, char data, int leng){
	if (!isStackFull(st)){
		st->top++;
		st->st[st->top] = data;
		st->val_length[st->top] = leng;
	}
}

void pop(MyStack *st){
	if (!isStackEmpty(st)){
		st->top--;
	}
}

char top_value(MyStack *st){
	return st->st[st->top];
}
int top_length(MyStack *st){
	return st->val_length[st->top];
}
char input[26];
int group_length[26];
MyStack st;

void makeGroup(char* input){
	init(&st);
	int x = 0;
	int arr_num = 0;
	char tmp_arr[26];
	while (*(input + arr_num)) arr_num++;

	// input의 첫번째 숫자는 tmp_arr에 넣어 (다음 숫자들과 계속 비교해야 됨)
	tmp_arr[0] = input[0];
	for (int i = 1; i <= arr_num; i++){

		// 같은 알파벳 일 경우 tmp_arr에 input 값을 하나씩 복사해
		if (tmp_arr[x] == input[i]){
			tmp_arr[++x] = input[i];
		}
		// 다른 수 일 경우 현재까지 tmp_arr와 그 길이를 스택에 push
		else{
			// 스택의 top이랑 지금 push하는거랑 문자가 같고, 둘의 length가 2이상이면 pop
			if (top_value(&st) == tmp_arr[x] && ((x + 1) + top_length(&st)) >= 2){
				pop(&st);	
			}
			// 길이가 2보다 작은 문자열은 push ( 길이가 2이상 문자열은 pass )
			else if (!(x + 1 >= 2)){
				push(&st, tmp_arr[x], x + 1); // x는 0부터 시작했으니 +1	
			}
			*tmp_arr = NULL;
			x = 0;
			tmp_arr[x] = input[i];
		}
	}
}

int main(void){

	int N;
	cin >> N;

	while (N--){
		cin >> input;
		makeGroup(input);
		if (isStackEmpty(&st)) cout << 1 << endl;
		else cout << 0 << endl;

		// array 초기화 
		*input = NULL;
		for (int i = 0; i < 26; i++){
			group_length[i] = 0;
		}
	}
}