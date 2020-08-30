//문제 : https://www.acmicpc.net/problem/11720

//문제
//N개의 숫자가 공백 없이 쓰여있다.이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 숫자의 개수 N(1 ≤ N ≤ 100)이 주어진다.둘째 줄에 숫자 N개가 공백없이 주어진다.

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