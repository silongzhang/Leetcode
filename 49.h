// #49 ×ÖÄ¸ÒìÎ»´Ê·Ö×é

#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution {
private:
	string hash(const string &str) {
		vector<int> count(26, 0);
		for (int i = 0; i < str.size(); ++i) ++count[str[i] - 'a'];
		string ans;
		for (int i = 0; i < 26; ++i) {
			ans.push_back('#');
			ans.push_back(count[i]);
		}
		return ans;
	}
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> ans;
		if (!strs.empty()) {
			for (const auto &elem : strs) {
				auto hashValue = hash(elem);
				auto pos = ans.find(hashValue);
				if (pos == ans.end()) ans.insert(make_pair(hashValue, vector<string>{elem}));
				else pos->second.push_back(elem);
			}
		}
		vector<vector<string>> ret;
		for (const auto &elem : ans) ret.push_back(elem.second);
		return ret;
	}
};

