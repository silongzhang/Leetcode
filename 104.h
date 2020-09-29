// 104. 二叉树的最大深度

#include<iostream>
#include<algorithm>
#include"Tree.h"

using namespace std;

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		else return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};

