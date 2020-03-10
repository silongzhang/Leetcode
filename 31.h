// #31 下一个排列

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		auto suc = nums.end();
		auto pre = prev(suc);
		for (; pre != nums.begin() && *prev(pre) >= *prev(suc); --pre, --suc) {}
		if (pre == nums.begin()) reverse(nums.begin(), nums.end());
		else {
			--pre;
			suc = nums.end();
			for (--suc; suc != pre && *suc <= *pre; --suc) {}
			swap(*pre, *suc);
			reverse(next(pre), nums.end());
		}
	}
};

