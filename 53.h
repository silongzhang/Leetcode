// #53 最大子序和

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		int currSum = nums[0], maxSum = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			currSum = currSum > 0 ? currSum + nums[i] : nums[i];
			if (maxSum < currSum) maxSum = currSum;
		}
		return maxSum;
	}
};

