#include<iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

//N�� ���� �̿��� ��Ģ���길�� �̿��Ͽ� number�� ǥ���ϴµ� N�� ���� ���� ����ϴ� ��� return
//��Ģ���� + - * /�� ��밡���ϸ� / ���꿡�� �������� ������
//�ּڰ��� 8���� Ŭ ��� -1 return
int solution(int N, int number) {
    assert(1 <= N && N <= 9);
    assert(1 <= number && number <= 32000);
    int answer = 0;



    if (answer > 8) {
        return -1;
    }
    return answer;
}

int main() {

    solution(5, 12);
    return 0;
}