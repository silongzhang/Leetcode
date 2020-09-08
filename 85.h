// 85. ×î´ó¾ØÐÎ

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		vector<int> left(matrix[0].size(), -1);
		vector<int> right(matrix[0].size(), matrix[0].size());
		vector<int> height(matrix[0].size(), 0);
		int maxArea = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			int nearestZeroOnLeft = -1;
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (matrix[i][j] == '0') {
					height[j] = 0;
					left[j] = -1;
					nearestZeroOnLeft = j;
				}
				else {
					++height[j];
					left[j] = max(left[j], nearestZeroOnLeft);
				}
			}
			int nearestZeroOnRight = matrix[i].size();
			for (int j = matrix[i].size() - 1; j >= 0; --j) {
				if (matrix[i][j] == '0') {
					right[j] = matrix[i].size();
					nearestZeroOnRight = j;
				}
				else
					right[j] = min(right[j], nearestZeroOnRight);
				maxArea = max(maxArea, height[j] * (right[j] - left[j] - 1));
			}
		}
		return maxArea;
	}
};

