//���� : https://www.acmicpc.net/problem/11720

//����
//N���� ���ڰ� ���� ���� �����ִ�.�� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� ������ ���� N(1 �� N �� 100)�� �־�����.��° �ٿ� ���� N���� ������� �־�����.
#define _CRT_SECURE_NO_WARNINGS // scanf ���� ���� ���� ������ ���� ����
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