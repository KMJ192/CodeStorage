#include <iostream>
#include <map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  map<int, int> s;
  void recursion(ListNode* node) {
    s[node->val]++;
    if(node->next == nullptr) return;
    recursion(node->next);
  }

public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr && list2 == nullptr) return nullptr;
    
    ListNode* answer = new ListNode();
    ListNode* tmp = new ListNode();
    answer = tmp;

    if(list1 != nullptr) recursion(list1);
    if(list2 != nullptr) recursion(list2);
    
    for(auto i : s){
      int node = i.first, cnt = i.second;
      for(int n = 0; n < cnt; n++){
        tmp->next = new ListNode(node);
        tmp = tmp->next;
      }
    }

    answer = answer->next;
    display(answer);

    return answer;
  }

  void display(ListNode* node) {
    cout << node->val << endl;
    if (node->next == nullptr) return;
    display(node->next);
  }
};

int main() {
  ListNode* list1 = new ListNode(-9, new ListNode(2, new ListNode(4)));
  ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
  Solution s;
  s.mergeTwoLists(list1, list2);
  return 0;
}