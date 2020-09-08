// 94. ���������������

#include<iostream>
#include<vector>
#include<stack>
#include"Tree.h"

using namespace std;

/*
// �ݹ�
class Solution {
public:
	void subFunc(TreeNode* root, vector<int> &res) {
		if (root == NULL) return;
		else {
			subFunc(root->left, res);
			res.push_back(root->val);
			subFunc(root->right, res);
		}
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		subFunc(root, res);
		return res;
	}
};
*/

// ѭ��
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> inOrderStack;
		auto curr = root;
		while (curr != NULL || !inOrderStack.empty()) {
			for (; curr != NULL; curr = curr->left) {
				inOrderStack.push(curr);
			}
			curr = inOrderStack.top();
			res.push_back(curr->val);
			inOrderStack.pop();
			curr = curr->right;
		}
		return res;
	}
};

