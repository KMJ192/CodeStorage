#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    //1. �迭 A�� ��� string�� �ϳ��� string�� �Է�,
    //2. string�� �ߺ� ����(�ߺ��� ���� )
    //3. ���� string�� ���� param�迭�� ���ҿ� �����ϴ��� Ȯ��
    vector<string> commonChars(vector<string>& A) {
        vector<string> answer;
        string tmp;
        string tmp2;
        bool _switch;
        for (int i = 0; i < A.size(); i++) {
            tmp = tmp + A[i];
        }

        tmp = delDuplication(tmp);

        for (int i = 0; i < tmp.size(); i++) {
            _switch = false;
            tmp2 = "";
            for (int j = 0; j < A.size(); j++) {
                if (A[j].find(tmp[i]) != string::npos) {
                    _switch = true;
                }
                else {
                    _switch = false;
                    break;
                }
            }
            tmp2 += tmp[i];
            if (_switch) {
                answer.push_back(tmp2);
            }
        }

        map<string, int> re;
        for (int i = 0; i < answer.size(); i++) {
            re.insert(pair<string, int>(answer[i], 0));
        }

        int result = 0;
        for (map<string, int>::iterator it = re.begin(); it != re.end(); it++) {
            _switch = false;
            //cout << it->first << endl;
            for (int i = 0; i < A.size(); i++) {
                int count = 0;
                for (int j = 0; j < A[i].size(); j++) {
                    //cout << A[i][j];
                    tmp2 = "";
                    tmp2 += A[i][j];
                    if (it->first == tmp2) {
                        count++;
                    }
                }
                if (i == 0) {
                    result = count;
                }
                else {
                    if (result > count) {
                        result = count;
                    }
                }
                //cout << count << endl;
            }
            it->second = result;
        }

        answer.clear();
        for (map<string, int>::iterator it = re.begin(); it != re.end(); it++) {
            for (int i = 0; i < it->second; i++) {
                answer.push_back(it->first);
            }
        }
        //for (int i = 0; i < answer.size(); i++) {
        //    cout << answer[i] << endl;
        //}

        return answer;
    }

    string delDuplication(string &object) {
        vector<char> tmp;
        string re;
        for (int i = 0; i < object.size(); i++) {
            tmp.push_back(object[i]);
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for(int i = 0; i < tmp.size(); i++) {
            re = re + tmp[i];
        }
        return re;
    }
};

int main() {
    vector<string> A = { "bella","label","roller" };
    Solution a;
    a.commonChars(A);
	return 0;
}