#include"94.h"


int main() {
	TreeNode node1(1);	
	TreeNode node2(2);
	TreeNode node3(3);
	node1.right = &node2;
	node2.left = &node3;
	Solution sol;
	auto ans = sol.inorderTraversal(&node1);
	return 0;
}

