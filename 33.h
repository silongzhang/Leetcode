// #33 ËÑË÷Ğı×ªÅÅĞòÊı×é

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		else if (nums.size() == 1) return nums[0] == target ? 0 : -1;
		int left = 0, right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] >= nums[0]) left = mid + 1;
			else if (nums[mid] < nums[mid - 1]) break;
			else right = mid - 1;
		}
		if (left > right) left = 0, right = nums.size() - 1;
		else if (target >= nums[0]) left = 0, right = mid - 1;
		else left = mid, right = nums.size() - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] == target) break;
			else if (nums[mid] > target) right = mid - 1;
			else left = mid + 1;
		}
		return left <= right ? mid : -1;
	}
};

