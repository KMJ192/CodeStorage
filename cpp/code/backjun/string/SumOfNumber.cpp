//문제 : https://www.acmicpc.net/problem/11720

//문제
//N개의 숫자가 공백 없이 쓰여있다.이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 숫자의 개수 N(1 ≤ N ≤ 100)이 주어진다.둘째 줄에 숫자 N개가 공백없이 주어진다.
#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include<iostream>

using namespace std;

int main() {

	int count = 0, hap = 0;
	char input[100];

	scanf("%d", &count);
	scanf("%s", input);

	for (int i = 0; i < count; i++) {
		hap += input[i] - '0';
	}

	printf("%d", hap);

	return 0;
}