// #64 最小路径和

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		vector<int> ans(grid[0].size(), 0);
		for (int i = grid.size() - 1; i >= 0; --i) {
			for (int j = grid[0].size() - 1; j >= 0; --j) {
				if (i == grid.size() - 1 && j == grid[0].size() - 1) ans[j] = grid[i][j];
				else if (i == grid.size() - 1 && j != grid[0].size() - 1) ans[j] = grid[i][j] + ans[j + 1];
				else if (i != grid.size() - 1 && j == grid[0].size() - 1) ans[j] += grid[i][j];
				else ans[j] = grid[i][j] + min(ans[j], ans[j + 1]);
			}
		}
		return ans[0];
	}
};

