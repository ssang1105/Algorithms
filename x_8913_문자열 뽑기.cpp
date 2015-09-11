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

	// input�� ù��° ���ڴ� tmp_arr�� �־� (���� ���ڵ�� ��� ���ؾ� ��)
	tmp_arr[0] = input[0];
	for (int i = 1; i <= arr_num; i++){

		// ���� ���ĺ� �� ��� tmp_arr�� input ���� �ϳ��� ������
		if (tmp_arr[x] == input[i]){
			tmp_arr[++x] = input[i];
		}
		// �ٸ� �� �� ��� ������� tmp_arr�� �� ���̸� ���ÿ� push
		else{
			// ������ top�̶� ���� push�ϴ°Ŷ� ���ڰ� ����, ���� length�� 2�̻��̸� pop
			if (top_value(&st) == tmp_arr[x] && ((x + 1) + top_length(&st)) >= 2){
				pop(&st);	
			}
			// ���̰� 2���� ���� ���ڿ��� push ( ���̰� 2�̻� ���ڿ��� pass )
			else if (!(x + 1 >= 2)){
				push(&st, tmp_arr[x], x + 1); // x�� 0���� ���������� +1	
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

		// array �ʱ�ȭ 
		*input = NULL;
		for (int i = 0; i < 26; i++){
			group_length[i] = 0;
		}
	}
}