// 75. ÑÕÉ«·ÖÀà

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0, current = 0, right = nums.size() - 1;
		while (current <= right) {
			if (nums[current] == 0)
				swap(nums[left++], nums[current++]);
			else if (nums[current] == 1)
				++current;
			else
				swap(nums[current], nums[right--]);
		}
	}
};

