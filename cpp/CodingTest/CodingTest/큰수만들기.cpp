#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

priority_queue<string> total;
vector<vector<int>> temp;

void Permutation(string object, int k) {
    if (k >= object.size()) return;
    vector<int> tmp;
    for (int i = 0; i < k; i++) {
        tmp.push_back(i);
    }

    for (int i = 0; i < object.size(); i++) {
        
    }
}

string ExtractString(string object, vector<int> position) {
    if (object.size() < position.size()) return "";
    int cnt = 0;
    string tmp;

    for (int n = 0; n < object.size(); n++) {
        if (cnt < position.size()) {
            if (n == position[cnt]) {
                cnt++;
                continue;
            }
        }
        tmp = tmp + object[n];
    }
    return tmp;
}

void Dfs(string number, int k, int last) {
    if (last == number.size() - k) return;
    


    string tmp;
}

string solution(string number, int k) {

    Dfs(number, k, 0);

    string answer = "";
    return answer;
}

int main() {

    solution("4177252841", 4);
    vector<int> test = { 1, 2, 4 };
    //ExtractString("1231234", test);

    return 0;
}