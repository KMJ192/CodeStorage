#include<iostream>
#include <algorithm>

using namespace std;

//int answer = 9;
//
//void dfs(int N, int number, int count, int currentNumber) {
//    cout << count << ", " << currentNumber << endl;
//    //����Ƚ�� �̻󰬴ٸ� ����
//    if (count >= 9)        return;
//    //������� number�� ���ٸ� ����Ƚ���� answer�� ������ ����
//    if (currentNumber == number) {
//        answer = min(answer, count);
//        return;
//    }
//    int tempNumber = 0;
//    //�ִ� N�� ���Ƚ���� 9�������̹Ƿ� �̶����� �ݺ�
//    for (int i = 0; i + count < 9; i++) {
//        //N���� NN,NNN,NNNN .....
//        tempNumber = tempNumber * 10 + N;
//        //���ϱ� ���� ���ϱ� ������ dfs ���
//        dfs(N, number, count + 1 + i, currentNumber + tempNumber);
//        dfs(N, number, count + 1 + i, currentNumber - tempNumber);
//        dfs(N, number, count + 1 + i, currentNumber * tempNumber);
//        dfs(N, number, count + 1 + i, currentNumber / tempNumber);
//    }
//}
//
//int solution(int N, int number) {
//    dfs(N, number, 0, 0);
//    //answer�� 9��� ���� number�� �´� ��찡 ������ ���̹Ƿ� -1 ����
//    if (answer == 9)    return -1;
//    return answer;
//}

int answer = 9;
void Dfs(int N, int number, int count, int goal) {
    if (count >= 9) return;
    if (goal == number) {
        answer = min(answer, count);
    }
    int tmp = 0;
    for (int i = 0; i + count < 9; i++) {
        tmp = tmp * 10 + N;
        Dfs(N, number, count + 1 + i, goal + tmp);
        Dfs(N, number, count + 1+ i, goal - tmp);
        Dfs(N, number, count + 1 + i, goal * tmp);
        Dfs(N, number, count + 1 + i, goal / tmp);
    }
}

int solution(int N, int number) {

    Dfs(N, number, 0, 0);

    return answer;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(5, 12) << endl;

    return 0;
}