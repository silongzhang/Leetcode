// 96. 不同的二叉搜索树

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> DP(n + 1, 0);
		DP[0] = 1;
		DP[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j <= i - 1; ++j) {
				DP[i] += DP[j] * DP[i - 1 - j];
			}
		}
		return DP[n];
	}
};

