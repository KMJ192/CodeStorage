#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// O(n)
class KMP {
private:
  int sLen = 0;
  int pLen = 0;
  vector<int> kmpTable;
  void makeTable (string s, string pattern, vector<int>& table) {
    sLen = (int)s.length(), pLen = (int)pattern.length();
    for (int i = 1; i < sLen; i++) {
      int j = table[i - 1];
      while (j > 0 && s[i] != pattern[j]) { j = table[j - 1]; }

      if (s[i] == pattern[j]) { j++; }

      table[i] = j;
    }
  }

  void search (string s, string pattern, vector<int>& table) {
    int j = 0;
    for (int i = 0; i < sLen; i++) {
      while (j > 0 && s[i] != pattern[j]) { j = table[j - 1]; }
      if (s[i] == pattern[j]) {
        if (j == pLen - 1) {
          kmpTable.push_back(i - pLen + 1);
          j = table[j];
        } else {
          j++;
        }
      }
    }
  }
public:
  vector<int> kmp (string s, string pattern) {
    vector<int> table((int)s.length(), 0);
    makeTable(s, pattern, table);
    search(s, pattern, table);
    return kmpTable;
  }
};

// O(n!)
class Anagram {
private:
  set<string> dictionary;
  void recursion (string s, string prefix) {
    int sLen = (int)s.length();
    if (sLen == 0) {
      dictionary.insert(prefix);
      return;
    }
    for (int i = 0; i < sLen; i++) {
      string tmp = s.substr(0, i) + s.substr(i + 1);
      recursion(tmp, prefix + s[i]);
    }
  }
public:
  void makeAnagram(string s) {
    if (s.length() == 0) return;
    recursion(s, "");
  }

  set<string> anagramTable() {
    return dictionary;
  }
};

void run (string str, string pattern) {
  set<string> dictionary;
  vector<int> patternMatching;

  Anagram a;
  a.makeAnagram(pattern);
  dictionary = a.anagramTable();
  KMP k;

  for (
    set<string>::iterator it = dictionary.begin(); 
    it != dictionary.end(); 
    it++
  ) {
    patternMatching = k.kmp(str, *it);
  }

  sort(patternMatching.begin(), patternMatching.end());

  for (int p : patternMatching) {
    cout << p << endl;
  }
}

int main() {
  string str = "abbcabc", pattern = "abc";
  run(str, pattern);

  return 0;
}