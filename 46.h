// #46 È«ÅÅÁĞ

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
	void permuteCore(vector<int> &nums, vector<vector<int>> &ans, int first) {
		if (first == nums.size() - 1) ans.push_back(nums);
		else {
			for (int i = first; i < nums.size(); ++i) {
				swap(nums[i], nums[first]);
				permuteCore(nums, ans, first + 1);
				swap(nums[i], nums[first]);
			}
		}
	}
public:
	vector<vector<int>> permute(vector<int> &nums) {
		vector<vector<int>> ans;
		if (!nums.empty()) permuteCore(nums, ans, 0);
		return ans;
	}
};

