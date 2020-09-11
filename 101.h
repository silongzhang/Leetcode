// 101. ¶Ô³Æ¶þ²æÊ÷

#include<iostream>
#include<queue>
#include"Tree.h"

using namespace std;

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> Q;
		if (!root) return true;
		Q.push(root->left); Q.push(root->right);
		while (!Q.empty()) {
			auto elem1 = Q.front(); Q.pop();
			auto elem2 = Q.front(); Q.pop();
			if (!elem1 && !elem2) continue;
			else if (!elem1 || !elem2) return false;
			else if (elem1->val != elem2->val) return false;
			else {
				Q.push(elem1->left); Q.push(elem2->right);
				Q.push(elem1->right); Q.push(elem2->left);
			}
		}
		return true;
	}
};


/*
class Solution {
public:
	bool subFunction(TreeNode* left, TreeNode* right) {
		if (!left && !right) return true;
		if (!left || !right) return false;
		return left->val == right->val && 
			subFunction(left->left, right->right) && 
			subFunction(left->right, right->left);
	}
	bool isSymmetric(TreeNode* root) {
		return !root || subFunction(root->left, root->right);
	}
};
*/

