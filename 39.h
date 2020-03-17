// #39 组合总和

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void combinationSumCore(const vector<int> &candidates, int target, int start, 
		vector<int> &seq, vector<vector<int>> &ans) {
		if (target == 0) ans.push_back(seq);
		else {
			for (int i = start; i < candidates.size() && target >= candidates[i]; ++i) {
				seq.push_back(candidates[i]);
				combinationSumCore(candidates, target - candidates[i], i, seq, ans);
				seq.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty()) return vector<vector<int>>();
		sort(candidates.begin(), candidates.end());
		vector<int> seq;
		vector<vector<int>> ans;
		combinationSumCore(candidates, target, 0, seq, ans);
		return ans;
	}
};

