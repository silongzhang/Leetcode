// #15 三数之和

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		if (nums.size() < 3) return ans;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int left = i + 1, right = nums.size() - 1; left < right;) {
				int sum = nums[i] + nums[left] + nums[right];
				if (sum == 0) {
					ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
					while (left < right && nums[left] == nums[left + 1]) ++left;
					while (left < right && nums[right] == nums[right - 1]) --right;
					++left; --right;
				}
				else sum > 0 ? --right : ++left;
			}
		}
		return ans;
	}
};

