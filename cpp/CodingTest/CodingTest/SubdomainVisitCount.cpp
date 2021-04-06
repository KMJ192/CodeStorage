#include<iostream>
#include<vector>
#include<map>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> subDomain;
        string tmp;
        for (int i = 0; i < cpdomains.size(); i++) {
            vector<string> streamArr;
            streamArr.clear();
            streamArr = splitString(cpdomains[i], ' ');

            vector<string> piece;
            piece.clear();
            piece = splitString(streamArr[1], '.');
            reverse(piece.begin(), piece.end());
            tmp = "";
            for (int j = 0; j < piece.size(); j++) {
                if (j == 0) tmp = piece[j];
                else tmp = piece[j] + '.' + tmp;
                if (subDomain.find(tmp) == subDomain.end()) {
                    //키값이 없음
                    subDomain.insert(pair<string, int>(tmp, stoi(streamArr[0])));
                }
                else {
                    //키값이 있음
                    subDomain.find(tmp)->second = subDomain.find(tmp)->second + stoi(streamArr[0]);
                }
            }
        }
        vector<string> answer;
        for (map<string, int>::iterator it = subDomain.begin(); it != subDomain.end(); it++) {
            answer.push_back(to_string(it->second) + " " + it->first);
        }

        return answer;
    }
    vector<string> splitString(string object, char delimeter) {
        vector<string> re;
        re.clear();
        string buffer;
        istringstream ss(object);
        while (getline(ss, buffer, delimeter)) {
            re.push_back(buffer);
        }
        return re;
    }
};

int main() {

    vector<string> cpdomains = { "9001 discuss.leetcode.com" };

    Solution a;
    a.subdomainVisits(cpdomains);

	return 0;
}