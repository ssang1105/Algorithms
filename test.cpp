#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*
과제 명 : 식 계산하기
작성자 : 전상우 (200921312)
날짜 : 2015-10-08
*/
int main()
{
	int n = 0; // 입력받을 n
	int i = 0; // for문을 위한 변수 1
	int j = 0; // for문을 위한 변수 2
	float tmp = 1;
	float sum = 0.0; // 식 계산의 결과를 위한 변수
	printf("식을 계산할 n을 입력하세요 : ");
	scanf("%d", &n);
	for (i = 1; i<=n; i++){
		for (j = 1; j <= i; j++){
			tmp *= (1.0 / (float)(i));
		}
		sum += tmp;
		tmp = 1;
	}

	printf("식의 결과 값 : %f", sum);
	return 0;
}
