// #1 两数之和

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		if (nums.size() < 2) { exit(1); }
		vector<int> vec;
		unordered_map<int, int> unMap;
		for (int i = 0; i < nums.size(); ++i) {
			auto pos = unMap.find(target - nums[i]);
			if (pos == unMap.end()) {
				unMap.insert(make_pair(nums[i], i));
			}
			else {
				vec = vector<int>{ pos->second,i };
				break;
			}
		}
		return vec;
	}
};

