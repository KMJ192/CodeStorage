#include<iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

string solution(string number, int k) {
    char maxVal;
    int count = k, index = 0;
    string answer = "";
    while (answer.size() < number.size() - k) {
        maxVal = 0;
        for (int i = index; i < number.size() - count; i++) {
            cout << number[i];
            if (maxVal < number[i]) {
                index = i + 1;
                maxVal = number[i];
            }
        }
        cout << endl;
        answer += maxVal;
        count--;
    }
    cout << answer << endl;

    return answer;
}

int main() {
    
    solution("4177252841", 4);

    return 0;
}