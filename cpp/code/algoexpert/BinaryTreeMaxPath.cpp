#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
	Binary tree�� ���� ū max path sum ��ȯ

	��δ� Ʈ������ ����� ����� ��������,
	��尡 �� �� �̻��� �ٸ� ��忡 ������� �ʰ� ��� �հ�� Ư�� ��ο� �ִ� ��� ���� �հ��Դϴ�.

	�� BinaryTree ��忡�� ���� ��, ���� ���� ��� �� ������ ���� ��尡 �ֽ��ϴ�.
	���� ���� BinaryTree ��� ��ü�̰ų� null�� �� �ֽ��ϴ�.

	input : Binary Tree
		   1
		��   ��
	   2        3
	 �ע�     �ע�
	4   5    6   7

	output
	 - �ִ� ��� �հ�
	 - 5 + 2 + 1 + 3 + 7 => 18
*/
int lMax = 0, rMax = 0;
vector<int> path;

//���� ����� �ִ밪
void left(TreeNode* head, int hap) {
	hap = hap + head->val;
	lMax = max(lMax, hap);
	if (head->left != nullptr) {
		left(head->left, hap);
	}
	if (head->right != nullptr) {
		left(head->right, hap);
	}
}
//������ ����� �ִ밪
void right(TreeNode* head, int hap) {
	hap = hap + head->val;
	rMax = max(rMax, hap);

	if (head->left != nullptr) {
		right(head->left, hap);
	}
	if (head->right != nullptr) {
		right(head->right, hap);
	}
}

int solution(TreeNode* root) {
	left(root->left, 0);
	right(root->right, 0);

	cout << rMax << endl;
	cout << lMax << endl;
	int answer = root->val + rMax + lMax;
	cout << answer << endl;
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	TreeNode* root = new TreeNode(1);

	TreeNode* l = new TreeNode(2);
	TreeNode* r = new TreeNode(3);

	TreeNode* ll = new TreeNode(4);
	TreeNode* lr = new TreeNode(5);

	TreeNode* rl = new TreeNode(6);
	TreeNode* rr = new TreeNode(7);

	l->left = ll;
	l->right = lr;

	r->left = rl;
	r->right = rr;

	root->left = l;
	root->right = r;

	solution(root);

	delete rr;
	delete rl;
	delete ll;
	delete lr;

	delete r;
	delete l;

	delete root;

	return 0;
}