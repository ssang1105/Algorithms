#include <iostream>
#include <string.h>
using namespace std;

char input[26];
int alpha_index[26];
int group_length[26];
int k = 0;

void makeGroup(char* input){
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
		// �ٸ� �� �� ��� ������� tmp_arr�� �� ���̸� ����
		else{	
			group_length[k] = x+1;
			alpha_index[k] = i -group_length[k];
			k++;
			
			*tmp_arr = NULL;
			x = 0;
			tmp_arr[x] = input[i];
		}
	}
}

void delLongestGroup(char *input){
	int index = 0;
	int max = 0;
	int max_index = 0;
	for (int i = 0; i < k; i++){
		index = group_length[i];
		// ���̰� ���� ū �׷� ã��
		if (index > max){
			max = index;
			max_index = i;
		}
	}

	int init_index = alpha_index[max_index];
	int dest_index = alpha_index[max_index] + group_length[max_index]-1;
	// ���̰� ���� ū �׷� �����
	// ���̰� 2 �̻�
	if (dest_index-init_index >= 1){
		if (dest_index == strlen(input)){
			for (int i = init_index; i <= dest_index; i++)
				input[i] = NULL;
		}
		else{
		
			int m = 0;
			for (int i = init_index; i <= strlen(input); i++){
				if (input[dest_index + m + 1] != NULL)
					input[i] = input[dest_index + m++ + 1];
				else
					input[i] = NULL;
			}
		}
	}
	



}
int main(void){
	int N;
	cin >> N;

	while (N--){
		cin >> input;
		makeGroup(input);
		for (int i = 0; i < k; k++){
			
			delLongestGroup(input);
			k = 0;
			for (int i = 0; i < 26; i++){
				group_length[i] = 0;
				alpha_index[i] = 0;
			}
			if (strlen(input) == 0) break;
			makeGroup(input);
			
		}
		if (strlen(input) == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		
		
		

		// array �ʱ�ȭ 
		k = 0;
		for (int i = 0; i < 26; i++){
			group_length[i] = 0;
			input[i] = 0;
			alpha_index[i] = 0;
		}
	}
}