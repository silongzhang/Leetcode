// 102. ¶þ²æÊ÷µÄ²ãÐò±éÀú

#include<iostream>
#include<vector>
#include<queue>
#include"Tree.h"

using namespace std;

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL) return res;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			const auto num = que.size();
			vector<int> vec(num);
			for (int i = 0; i < num; ++i) {
				const auto fr = que.front();
				vec[i] = fr->val;
				if (fr->left != NULL) que.push(fr->left);
				if (fr->right != NULL) que.push(fr->right);
				que.pop();
			}
			res.push_back(vec);
		}
		return res;
	}
};

