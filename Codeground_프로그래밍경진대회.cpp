#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int cnt = 0;


void promisingTest(vector <int> data, int num, int width){

	int tmp = width;
	num += tmp--;
	vector <int> tmpV;
	bool test = true;
	tmpV = data;
	sort(tmpV.begin(), tmpV.end());
	for (int i = 0; i < width; i++){
		if (tmpV[i] == num - tmp) 
			continue;
		else{	
			tmpV[i] += width--;
			if (num >= tmpV[i]) 
				test = true;
			else{
				test =false;
				break;
			}
		}
	}
	
	if (test) 
		cnt++;
}

int main(int argc, char** argv) {
	int T;
	int test_case;
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� cin �� ����Ͽ� ǥ�� �Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	���� ������ PC ���� �׽�Ʈ �� ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �˴ϴ�.
	��, �� �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	scanf("%d", &T);	//Codeground �ý��ۿ����� C++ ������ scanf ����� �����մϴ�.
	for (test_case = 1; test_case <= T; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		int N;
		int tmp;
		cin >> N;
		vector <int> data;
		for (int i = 0; i < N; i++){
			cin >> tmp;
			data.push_back(tmp);
		}

		for (int i = 0; i < N; i++){
			promisingTest(data,data[i],N);
		}

		//	�� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++ ������ printf ����� �����մϴ�. 
		printf("Case #%d\n", test_case);
		cout << cnt << endl;
		

	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}