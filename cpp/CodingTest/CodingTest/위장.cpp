#include<iostream>
#include<vector>
#include<map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> ssang;

    for (int i = 0; i < clothes.size(); i++) {
        bool sw = false;
        if (i == 0) ssang.insert(pair<string, int>(clothes[i][1], 1));
        else {
            for (map<string, int>::iterator it = ssang.begin(); it != ssang.end(); it++) {
                if (it->first == clothes[i][1]) {
                    sw = true;
                    it->second += 1;
                    break;
                }
            }
            if(sw !=true) {
                ssang.insert(pair<string, int>(clothes[i][1], 1));
            }
        }
    }

    int zohap = 0;
    int answer = 0;
    for (map<string, int>::iterator it = ssang.begin(); it != ssang.end(); it++) {
        //cout << it->first << ", " << it->second << endl;
        answer++;
        if (answer == 1) {
            zohap = it->second;
        }
        else {
            zohap *= it->second;
        }
    }

    answer = clothes.size();
    if(answer != zohap) answer += zohap;
    return answer;
}

int main() {

    vector<vector<string>> clothes = {
        {"yellowhat", "headgear"},
        {"bluesunglasses", "headgear"},
        {"green_turban", "headgear"}
    };
    cout << solution(clothes);

	return 0;
}