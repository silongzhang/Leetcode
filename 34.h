// #34 在排序数组中查找元素的第一个和最后一个位置

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int searchRangeBound(vector<int>& nums, int target, bool left) {
		int low = 0, high = nums.size();
		int mid;
		while (low < high) {
			mid = (low + high) / 2;
			if (nums[mid] > target || (left && nums[mid] == target)) {
				high = mid;
			}
			else low = mid + 1;
		}
		return low;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty()) return vector<int>{-1, -1};
		int first = searchRangeBound(nums, target, true);
		if (first == nums.size() || nums[first] != target) return vector<int>{-1, -1};
		int afterLast = searchRangeBound(nums, target, false);
		return vector<int>{first, afterLast - 1};
	}
};

