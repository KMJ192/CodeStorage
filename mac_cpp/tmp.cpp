/**
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 * @file tmp.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <unistd.h>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
      
      return head;
    }
};

int main() {
  ListNode* head = new ListNode(
    1, 
    new ListNode(
      2, 
      new ListNode(
        3, 
        new ListNode(
          4, 
          new ListNode(
            5
          )
        )
      )
    )
  );

  Solution s;

  s.reverseKGroup(head, 3);

  return 0;
}