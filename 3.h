// #3 无重复字符的最长子串

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLength = 0, currLength = 0;
		unordered_map<char, int> lastLocation;
		for (int i = 0; i < s.size(); ++i) {
			auto pos = lastLocation.find(s[i]);
			if (pos == lastLocation.end()) {
				lastLocation.insert(make_pair(s[i], i));
				++currLength;
			}
			else {
				int lastIndex = pos->second;
				currLength = i - lastIndex > currLength ? currLength + 1 : i - lastIndex;
				pos->second = i;
			}
			if (maxLength < currLength)
				maxLength = currLength;
		}
		return maxLength;
	}
};

