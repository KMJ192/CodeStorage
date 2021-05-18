#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

//bool solution(vector<string> phone_book) {
//    bool answer = true;
//
//    for (int i = 0; i < phone_book.size(); i++) {
//        for (int j = i+1; j < phone_book.size(); j++) {
//            if (i != j && i < j) {
//                if(phone_book[i].length() <= phone_book[j].length()){
//                    if (phone_book[j].find(phone_book[i]) != string::npos && phone_book[j].find(phone_book[i]) == 0)
//                        return false;
//                }
//                else {
//                    if (phone_book[i].find(phone_book[j]) != string::npos && phone_book[i].find(phone_book[j]) == 0)
//                        return false;
//                }
//            }
//        }
//    }
//
//    return answer;
//}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size(); i++) {
        if (i == phone_book.size() - 1) break;
        if (phone_book[i + 1].find(phone_book[i]) != string::npos && phone_book[i + 1].find(phone_book[i]) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> phone_book = { "123","456","789" };

    cout << solution(phone_book) << "\n";

	return 0;
}