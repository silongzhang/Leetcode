// #32 最长有效括号

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int maxLen = 0;
		int left = 0, right = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') ++left;
			else if (s[i] == ')') ++right;
			if (left == right) maxLen = max(maxLen, left + right);
			else if (right > left) left = right = 0;
		}
		left = right = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == '(') ++left;
			else if (s[i] == ')') ++right;
			if (left == right) maxLen = max(maxLen, left + right);
			else if (left > right) left = right = 0;
		}
		return maxLen;
	}
};

