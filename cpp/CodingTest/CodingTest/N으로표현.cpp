#include<iostream>
#include <string>
#include<vector>

using namespace std;

int global_n;
int global_number;
int tmp = 0;
string gUnit;

vector<string> Combination(int number){
    vector<string> com;
    if(number == 1){
            com.push_back("+");
            com.push_back("-");
            com.push_back("*");
            com.push_back("/");
    }
    else if (number == 2) {
        com.push_back("+-");
        com.push_back("+*");
        com.push_back("+/");
        com.push_back("-*");
        com.push_back("-/");
        com.push_back("*/");
    }
    else if (number == 3) {
        com.push_back("+-*");
        com.push_back("+-/");
        com.push_back("-*/");
    }
    else {
        com.push_back("+-*/");
    }
    return com;
}

//ù��° Parameter => �̾���� �����ּ� ����
//�ι�° Parameter => ��Ģ���� ���� ����
//����° Parameter => ��Ģ���� ����
void Bfs(int n, int number, string s) {
    cout << n << ", " << number << ", " << s << endl;
    vector<string> unit;
    for (int i = n; i <= 8; i++) {
        for (int j = 1; j <= 4; j++) {
            unit = Combination(j);
            for (int n = 0; n < unit.size(); n++) {
                Bfs(i, j, unit[n]);
            }
        }
    }
}


//1���϶� �� 8����
//
int solution(int n, int number) {
    int answer = -1;
    if (n == number) return 1;

    global_n = n;
    global_number = number;
    Bfs(1, 0, ""); // ���� �ּҴ����� ��Ģ�������մ���, ��Ģ���� ����
    return answer;
}

int main() {

    solution(5, 12);

    //string test = "1234";
    //int nTest = stoi(test);
    //nTest++;
    //cout << nTest;

    return 0;
}