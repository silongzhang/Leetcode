// 76. ×îÐ¡¸²¸Ç×Ó´®

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	unordered_map<char, int> unMapWin, unMapSub;
	bool check() {
		for (const auto &elem : unMapSub) {
			if (unMapWin[elem.first] < elem.second)
				return false;
		}
		return true;
	}
	string minWindow(string s, string t) {
		unMapWin.clear(); unMapSub.clear();
		for (const auto &ch : t)
			++unMapSub[ch];
		int beginPos = -1, len = INT_MAX;
		int left = 0, right = 0;
		for (; right < s.size(); ++right) {
			if (unMapSub.find(s[right]) != unMapSub.end())
				++unMapWin[s[right]];
			for (; check() && left <= right; ++left) {
				if (len > right - left + 1) {
					beginPos = left;
					len = right - left + 1;
				}
				if (unMapSub.find(s[left]) != unMapSub.end()) {
					--unMapWin[s[left]];
				}
			}
		}
		return beginPos == -1 ? "" : s.substr(beginPos, len);
	}
};

