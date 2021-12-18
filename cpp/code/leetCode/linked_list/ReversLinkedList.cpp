#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n)

class Solution {
  stack<int> vals;
public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr) return nullptr;
      if (head->next == nullptr) return head;
      recursion(head);
      ListNode* answer = new ListNode();
      ListNode* tmp = new ListNode();
      answer = tmp;

      while (!vals.empty()) {
        tmp->next = new ListNode(vals.top());
        tmp = tmp->next;
        vals.pop();
      }

      answer = answer->next;
      return answer;
    }

    void recursion(ListNode* node) {
      vals.push(node->val);
      if (node->next == nullptr) return;
      recursion(node->next);
    }

    void display(ListNode* node) {
      cout << node->val << endl;
      if (node->next == nullptr) return;
      display(node->next);
    }
};

int main() {

  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

  Solution s;
  s.display(s.reverseList(head));

  return 0;
}