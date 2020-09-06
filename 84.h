// 84. 柱状图中最大的矩形

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int maxArea = 0;
		stack<pair<int, int>> monotonic;
		vector<int> left(heights.size(), -1);
		vector<int> rightMight(heights.size(), heights.size());
		for (int i = 0; i < heights.size(); ++i) {
			bool pushed = false;
			while (!monotonic.empty()) {
				auto topElem = monotonic.top();
				if (topElem.first < heights[i]) {
					left[i] = topElem.second;
					monotonic.push(make_pair(heights[i], i));
					pushed = true;
					break;
				}
				else {
					rightMight[topElem.second] = i;
					int height = topElem.first, width = rightMight[topElem.second] - left[topElem.second] - 1;
					maxArea = max(maxArea, height * width);
					monotonic.pop();
				}
			}
			if (!pushed) monotonic.push(make_pair(heights[i], i));
		}
		while (!monotonic.empty()) {
			auto topElem = monotonic.top();
			int height = topElem.first, width = rightMight[topElem.second] - left[topElem.second] - 1;
			maxArea = max(maxArea, height * width);
			monotonic.pop();
		}
		return maxArea;
	}
};

