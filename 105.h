// 105. 从前序与中序遍历序列构造二叉树

#include<iostream>
#include<vector>
#include<unordered_map>
#include"Tree.h"

using namespace std;

class Solution {
	unordered_map<int, int> unMap;
public:
	TreeNode * subBuildTree(const vector<int>& preorder, int preL, int preR, 
		const vector<int>& inorder, int inL, int inR) {
		if (preL > preR) return NULL;
		else {
			auto rootInPos = unMap[preorder[preL]];
			auto lengthLeft = rootInPos - inL;
			auto root = new TreeNode(preorder[preL]);
			root->left = subBuildTree(preorder, preL + 1, preL + lengthLeft,
				inorder, inL, unMap[preorder[preL]] - 1);
			root->right = subBuildTree(preorder, preL + lengthLeft + 1, preR,
				inorder, unMap[preorder[preL]] + 1, inR);
			return root;
		}
	}
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() != inorder.size()) exit(1);
		for (int i = 0; i < inorder.size(); ++i)
			unMap[inorder[i]] = i;

		return subBuildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};

