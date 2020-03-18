// #42 Ω””ÍÀÆ

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int maxLeft = 0, maxRight = 0;
		int ans = 0;
		while (left < right) {
			if (height[left] <= height[right]) {
				maxLeft <= height[left] ? (maxLeft = height[left]) : (ans += maxLeft - height[left]);
				++left;
			}
			else {
				maxRight <= height[right] ? (maxRight = height[right]) : (ans += maxRight - height[right]);
				--right;
			}
		}
		return ans;
	}
};

