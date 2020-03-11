// #22 À¨ºÅÉú³É

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
private:
	void generateParenthesis(vector<string> &ans, int n, string curr, int open, int close) {
		if (curr.size() == 2 * n) {
			ans.push_back(curr);
			return;
		}
		if (open < n) generateParenthesis(ans, n, curr + "(", open + 1, close);
		if (close < open) generateParenthesis(ans, n, curr + ")", open, close + 1);
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		generateParenthesis(ans, n, "", 0, 0);
		return ans;
	}
	vector<string> generateParenthesis_2(int n) {
		vector<string> ans;
		if (n == 0) ans.push_back("");
		else {
			for (int i = 0; i < n; ++i) {
				for (const auto &pre : generateParenthesis_2(i)) {
					for (const auto &suc : generateParenthesis_2(n - 1 - i)) {
						ans.push_back("(" + pre + ")" + suc);
					}
				}
			}
		}
		return ans;
	}
};

