// 98. ÑéÖ¤¶þ²æËÑË÷Ê÷

#include<iostream>
#include"Tree.h"

class Solution {
public:
	bool helper(TreeNode* root, long LB, long UB) {
		if (root == NULL) return true;
		if (root->val <= LB || root->val >= UB) return false;
		else
			return helper(root->left, LB, root->val) && helper(root->right, root->val, UB);
	}
	bool isValidBST(TreeNode* root) {
		return helper(root, LONG_MIN, LONG_MAX);
	}
};

