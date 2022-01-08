#include <iostream>
#include <set>

using namespace std;

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
      string next = s.substr(0, i) + s.substr(i + 1);
      recursion(next, prefix + s[i]);
    }
  }
public:
  void makeAnagram(string s) {
    if (s.length() == 0) return;
    recursion (s, "");
  }
  set<string> anagramTable() {
    return dictionary;
  }
};

int main() {
  string object = "abcdefgh";
  Anagram a;
  a.makeAnagram(object);
  set<string> dictionary = a.anagramTable();

  for (
    set<string>::iterator it = dictionary.begin(); 
    it != dictionary.end(); 
    it++
  ) {
    cout << *it << endl;
  }
  

  return 0;
}