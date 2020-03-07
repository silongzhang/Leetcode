// #11 盛最多水的容器

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxValue = 0;
		int left = 0, right = height.size() - 1;
		while (left < right) {
			int temp = (right - left) * std::min(height[right], height[left]);
			if (maxValue < temp) maxValue = temp;
			height[left] < height[right] ? ++left : --right;
		}
		return maxValue;
	}
};

