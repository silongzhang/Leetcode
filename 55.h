// #55 ÌøÔ¾ÓÎÏ·

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty()) return false;
		else if (nums.size() == 1) return true;
		else {
			int lastPos = nums.size() - 1;
			for (int i = nums.size() - 2; i >= 0; --i) {
				if (i + nums[i] >= lastPos) lastPos = i;
			}
			return lastPos == 0;
		}
	}
};

