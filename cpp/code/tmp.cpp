#include <iostream>
#include <vector>

using namespace std;

void makeTable(string s, vector<int>& table) {
  int sLen = s.size();
  for (int i = 1; i < sLen; i++) {
    int j = table[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = table[j - 1];
    }

    if (s[i] == s[j]) j++;
    table[i] = j;
  }
}

void kmp(string s, string pattern, vector<int>& table) {
  int sLen = s.size(), pLen = pattern.size();
  int j = 0;
  for (int i = 0; i < sLen; i++) {
    while (j > 0 && s[i] != pattern[j]) {
      j = table[j - 1];
    }
    if (s[i] == pattern[j]) {
      if (j == pLen - 1) {
        cout << i - pLen + 1 << endl;
        j = table[j];
      } else {
        j++;
      }
    }
  }
}

int main(){
  using ss = pair<string, string>;
  ss input = ss("sabcdeabcdabcdeabcde", "abcde");
  vector<int> table(input.first.size(), 0);
  makeTable(input.first, table);
  kmp(input.first, input.second, table);
  
  return 0;
}
 