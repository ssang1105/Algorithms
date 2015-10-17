#include <cstdio>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;



int main(int argc, char** argv) {
	int T;
	int test_case;
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,`
	�� �Ʒ����� cin �� ����Ͽ� ǥ�� �Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	���� ������ PC ���� �׽�Ʈ �� ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �˴ϴ�.
	��, �� �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	
	scanf("%d", &T);	//Codeground �ý��ۿ����� C++ ������ scanf ����� �����մϴ�.
	for (test_case = 1; test_case <= T; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.

		
		int sum = 0;
		int num = 0;

		cin >> num;

		
		int *data;
		int *tmp;
		int t;
		data = (int *)malloc(sizeof(int) * num);
		tmp = (int *)malloc(sizeof(int) * num);
		memset(tmp, 0, num * sizeof(int));
		for (int i = 0; i < num; i++){
			cin >> t;
			data[i] = t;
			tmp[i]++;
		}
		for (int i = 0; i < num; i++){
			if (tmp[i] == 0) continue;
			if (tmp[i] % 2 == 1){
				if (sum == 0) sum = data[i];
				else sum ^= data[i];
			}
		}

		//	�� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++ ������ printf ����� �����մϴ�. 
		printf("Case #%d\n", test_case);

		cout << sum << endl;
		sum = 0;
		free(tmp);
		free(data);
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}