#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<string, string>> v = {
    {"0", "zero"},
    {"1", "one"},
    {"2", "two"},
    {"3", "three"},
    {"4", "four"},
    {"5", "five"},
    {"6", "six"},
    {"7", "seven"},
    {"8", "eight"},
    {"9", "nine"}
};

int solution(string s) {
    int answer = 0;
    bool foundFlag = false;
    while (1) {
        for (int i = 0; i < v.size(); i++) {
            if (s.find(v[i].second) != string::npos) {
                s.replace(s.find(v[i].second), v[i].second.size(), v[i].first);
                foundFlag = true;
                break;
            }
        }
        if (foundFlag == true) {
            foundFlag = false;
        }
        else {
            break;
        }
    }
    answer = stoi(s);

    return answer;
}

int main() {
    cout << solution("2three45sixseven");
    return 0;
}