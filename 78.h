// 78. ×Ó¼¯

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.emplace_back(vector<int>());
		for (int index = 0; index < nums.size(); ++index) {
			const size_t NumExist = res.size();
			for (int i = 0; i < NumExist; ++i) {
				vector<int> temp(res[i]);
				temp.push_back(nums[index]);
				res.emplace_back(temp);
			}
		}
		return res;
	}
};

