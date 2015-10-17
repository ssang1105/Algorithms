#include <cstdio>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

int N, K;
int maxx = 0;
vector<int> v;

void solve(int now, int sum, int include[]){

	if (now == K){
		if (sum > maxx){
			bool isIncludeNull = false;
			for (int i = 0; i < N; i++)
				if (include[i] == 1)  isIncludeNull = true;
			if (isIncludeNull){
				maxx = sum;
			}
		}
		return;
	}

	include[now] = 1;
	solve(now + 1, sum + v[now + 1],include);
	include[now] = 0;
	solve(now + 1, sum,include);
}

int main(int argc, char** argv) {
	int T;
	int test_case;
	
scanf("%d", &T);	//Codeground �ý��ۿ����� C++ ������ scanf ����� �����մϴ�.
	for (test_case = 1; test_case <= T; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		
		int tmp;
		int *include;
		cin >> N >> K;

		include = (int *)malloc(sizeof(int) * N);
		memset(include, 0, N * sizeof(int));

		for (int i = 0; i < N; i++){
			cin >> tmp;
			v.push_back(tmp);
		}

		solve(0, 0, include);

		//	�� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++ ������ printf ����� �����մϴ�. 
		printf("Case #%d\n", test_case);
		cout << maxx << endl;

		free(include);
		while(!v.empty())
			v.pop_back();

		maxx = 0;

	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}