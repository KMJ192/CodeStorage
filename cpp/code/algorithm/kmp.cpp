#include<iostream>
#include<vector>

using namespace std;

void makeTable(string str, vector<int>& table) {
    for (int i = 1; i < str.length(); i++) {
        int j = table[i - 1];
        while (j > 0 && str[j] != str[i]) {
            j = table[j - 1];
        }

        if (str[j] == str[i]) j++;

        table[i] = j;
    }
}

void kmp(string str, string pattern, vector<int>& table) {
    int strLen = str.size(), patLen = pattern.size();
    int j = 0;
    for (int i = 0; i < strLen; i++) {
        while (j > 0 && str[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (str[i] == pattern[j]) {
            if (j == patLen - 1) {
                cout << "[" << i - patLen + 1 << "]번째에서 발견" << endl;
                j = table[j];
            }
            else j++;
        }
    }
}

void run(string s, string pattern) {
    vector<int> table(s.size(), 0);
    makeTable(s, table);
    kmp(s, pattern, table);
}

int main() {

    run("abcdefgh", "efg");
    return 0;
}