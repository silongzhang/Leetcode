// #5 最长回文子串

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
private:
	int expandAroundCenter(string s, int left, int right) {
		for (; left >= 0 && right < s.size() && s[left] == s[right]; --left, ++right) {}
		return right - left - 1;
	}
public:
	string longestPalindrome(string s) {
		if (s.size() < 1) return "";
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); ++i) {
			int lenOdd = expandAroundCenter(s, i, i);
			int lenEven = expandAroundCenter(s, i, i + 1);
			int len = std::max(lenOdd, lenEven);
			if (len > end - start + 1) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}
};

