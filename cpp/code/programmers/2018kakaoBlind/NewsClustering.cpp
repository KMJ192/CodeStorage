#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <cmath>
#include <iomanip>

#define OBJ 65536

using namespace std;

string convert(string s) {
  string retS = "";
  for (int i = 0; i < s.size(); i++) {
    retS.push_back((char) tolower(s[i]));
  }
  return retS;
}

vector<string> tokenization(string s) {
  // regular expression
  regex match("[a-z][a-z]");
  
  vector<string> token;
  for (int i = 0; i < s.size(); i++) {
    if(i + 1 != s.size()) {
      string c = { s[i], s[i+1] };
      if (regex_match(c, match)) token.push_back(c);
    }
  }
  return token;
}

int solution(string str1, string str2) {
  unsigned int answer = 0;

  // lower case convert
  str1 = convert(str1);
  str2 = convert(str2);

  // string tokenization
  vector<string> token1 = tokenization(str1);
  vector<string> token2 = tokenization(str2);

  map<string, int> map1;
  map<string, int> map2;

  int intersectionCnt = 0; // ⋂
  int unionCnt = 0; // ⋃

  for(int i = 0; i < token1.size(); i++) map1[token1[i]]++;
  for(int i = 0; i < token2.size(); i++) map2[token2[i]]++;

  for(map<string, int>::iterator it = map1.begin(); it != map1.end(); it++){
    unionCnt += max(map2[it->first], it->second);
    if(map2[it->first]) {
      intersectionCnt += min(map2[it->first], it->second);
      map2[it->first] = 0;
    }
  }

  for(map<string, int>::iterator it = map2.begin(); it != map2.end(); it++){
    if(it->second > 0) unionCnt += it->second;
  }

  setprecision(10);

  if (unionCnt == 0) return OBJ;
  if (intersectionCnt == 0) return 0;

  double a = (double)intersectionCnt / (double)unionCnt;

  answer = floor(a * OBJ);
  
  return answer;
}

int main() {
  cout << solution("E=M*C^2", "e=m*c^2") << endl;
  return 0;
}