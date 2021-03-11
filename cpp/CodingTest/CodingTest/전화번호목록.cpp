#include<iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 1; j < phone_book.size(); j++) {
            if (i != j && i < j) {
                //cout << phone_book[i]<< ", " << phone_book[j] << endl;
                if(phone_book[i].length() <= phone_book[j].length()){
                    if (phone_book[j].find(phone_book[i]) != string::npos && phone_book[j].find(phone_book[i]) == 0)
                        return false;
                }
                else {
                    if (phone_book[i].find(phone_book[j]) != string::npos && phone_book[i].find(phone_book[j]) == 0)
                        return false;
                }
            }
        }
    }

    return answer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> phone_book = { "12","123","1235","567","88" };

    //접두어 특정 문자 앞에 붙은거
    //phone_book에서 접두어가 있을 경우 false, 없을 경우 true return
    cout << solution(phone_book) << "\n";


	return 0;
}