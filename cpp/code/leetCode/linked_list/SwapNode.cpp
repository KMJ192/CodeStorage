#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) return nullptr;
    swap(true, head);

    return head;
  }
  void swap(bool first, ListNode* node) {
    if (first == true) {
      if (node->next == nullptr) return;
      int tmp = node->val;
      node->val = node->next->val;
      node->next->val = tmp;
      swap(false, node->next);
    } else {
      if (node->next == nullptr) return;
      swap(true, node->next);
    }
  }
};

void display(ListNode* head) {
  cout << head->val << endl;
  if (head->next == nullptr) return;
  display(head->next);
}

int main() {
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  Solution s;
  s.swapPairs(new ListNode(1));
  display(head);
  return 0;
}