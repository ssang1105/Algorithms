#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*
���� �� : �� ����ϱ�
�ۼ��� : ����� (200921312)
��¥ : 2015-10-08
*/
int main()
{
	int n = 0; // �Է¹��� n
	int i = 0; // for���� ���� ���� 1
	int j = 0; // for���� ���� ���� 2
	float tmp = 1;
	float sum = 0.0; // �� ����� ����� ���� ����
	printf("���� ����� n�� �Է��ϼ��� : ");
	scanf("%d", &n);
	for (i = 1; i<=n; i++){
		for (j = 1; j <= i; j++){
			tmp *= (1.0 / (float)(i));
		}
		sum += tmp;
		tmp = 1;
	}

	printf("���� ��� �� : %f", sum);
	return 0;
}
