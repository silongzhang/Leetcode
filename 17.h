
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
private:
	const vector<vector<string>> letters =
	{ { "a","b","c" },{ "d","e","f" },
	{ "g","h","i" },{ "j","k","l" },{ "m","n","o" },
	{ "p","q","r","s" },{ "t","u","v" },{ "w","x","y","z" } };
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		if (!digits.empty()) {
			vector<string> tails = letterCombinations(digits.substr(1));
			if (tails.empty()) tails = { "" };
			int firstIndex = digits[0] - '2';
			for (const auto head : letters[firstIndex]) {
				for (const auto elem : tails) {
					ans.push_back(head + elem);
				}
			}
		}

		return ans;
	}
};

