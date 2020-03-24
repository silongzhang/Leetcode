// #56 合并区间

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> merges;
		if (intervals.empty()) return merges;
		sort(intervals.begin(), intervals.end(), 
			[](const vector<int> &lhs, const vector<int> &rhs) {return lhs[0] < rhs[0]; });
		vector<int> temp = intervals[0];
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i][0] <= temp[1]) temp[1] = max(temp[1], intervals[i][1]);
			else {
				merges.push_back(temp);
				temp = intervals[i];
			}
		}
		merges.push_back(temp); 
		return merges;
	}
};

