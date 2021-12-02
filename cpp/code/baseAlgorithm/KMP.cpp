#include <iostream>
#include <vector>

using namespace std;

class KMPAlgorithm {
private:
  void makeTable(string s, vector<int>& table) {
    int sLen = (int)s.size();
    for (int i = 1; i < sLen; i++) {
      int j = table[i - 1];
      
      while (j > 0 && s[i] != s[j]) {
        j = table[j - 1];
      }
      if(s[i] == s[j]) j++;

      table[i] = j;
    }
  }

  void kmp(string &s, string &pattern, vector<int>& table) {
    int sLen = (int)s.size(), patternLen = (int)pattern.size();
    int j = 0;
    for (int i = 0; i < sLen; i++) {
      while (j > 0 && s[i] != pattern[j]) {
        j = table[j - 1];
      }
      if (s[i] == pattern[j]) {
        if (j == patternLen - 1){
          cout << i - patternLen + 1 << endl;
          j = table[j];
        } else j++;
      }
    }
  }
  
public:
  void run(string &s, string &pattern) {
    vector<int> table((int)s.size(), 0);
    makeTable(s, table);
    kmp(s, pattern, table);
  }
};

int main() {
  using ss = pair<string, string>;
  ss input = ss("abcabcdabcde", "abcde");
  KMPAlgorithm s;
  s.run(input.first, input.second);

  return 0;
}