#include<iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

//N의 값을 이용한 사칙연산만을 이용하여 number를 표현하는데 N을 가장 적게 사용하는 방법 return
//사칙연산 + - * /만 사용가능하며 / 연산에서 나머지는 무시함
//최솟값이 8보다 클 경우 -1 return
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