//���� : https://www.acmicpc.net/problem/11720

//����
//N���� ���ڰ� ���� ���� �����ִ�.�� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� ������ ���� N(1 �� N �� 100)�� �־�����.��° �ٿ� ���� N���� ������� �־�����.

#include<iostream>

using namespace std;

int main() {

	int count, all = 0;
	int input;

	cin >> count;
	cin >> input;

	for (int i = 0; i < count; i++) {
		all += input % 10;
		input /= 10;
	}

	cout << all;

	return 0;
}