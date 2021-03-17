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

//첫번째 Parameter => 이어붙일 숫자최소 단위
//두번째 Parameter => 사칙연산 조합 단위
//세번째 Parameter => 사칙연산 종류
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


//1개일때 총 8조각
//
int solution(int n, int number) {
    int answer = -1;
    if (n == number) return 1;

    global_n = n;
    global_number = number;
    Bfs(1, 0, ""); // 숫자 최소단위와 사칙연산조합단위, 사칙연산 종류
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