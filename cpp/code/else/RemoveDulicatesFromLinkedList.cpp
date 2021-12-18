#pragma once
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

void _print(ListNode* node) {
	if (node == nullptr) return;
	cout << node->val << endl;
	_print(node->next);
}

void dfs(ListNode* node) {
	if (node == nullptr) return;
	if (node->next == nullptr) return;

	if (node->val == node->next->val) {
			node->next = node->next->next;
			dfs(node);
	}
	else {
			dfs(node->next);
	}
}

int run() {
	string line;
	ListNode* node = new ListNode(1);
	ListNode* tmp = new ListNode(1);
	ListNode* tmp1 = new ListNode(3);
	ListNode* tmp2 = new ListNode(4);
	ListNode* tmp3 = new ListNode(4);
	ListNode* tmp4 = new ListNode(4);
	ListNode* tmp5 = new ListNode(5);
	ListNode* tmp6 = new ListNode(6);
	ListNode* tmp7 = new ListNode(6);

	tmp6->next = tmp7;
	tmp5->next = tmp6;
	tmp4->next = tmp5;
	tmp3->next = tmp4;
	tmp2->next = tmp3;
	tmp1->next = tmp2;
	tmp->next = tmp1;
	node->next = tmp;

	dfs(node);
	_print(node);
	return 0;
}