// #10 正则表达式匹配

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	bool isMatchCore(string s, string p) {
		bool flag = false;
		if (p.empty()) {
			return s.empty() ? true : false;
		}
		else if (p.size() == 1) {
			flag |= (p == s) || (p[0] == '.' && s.size() == 1);
		}
		else if (p[1] == '*') {
			flag |= isMatchCore(s, p.substr(2));
			if (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
				flag |= isMatchCore(s.substr(1), p);
				flag |= isMatchCore(s.substr(1), p.substr(2));
			}
		}
		else if (!s.empty() && (s[0] == p[0] || p[0] == '.'))
			flag |= isMatchCore(s.substr(1), p.substr(1));
		return flag;
	}
	bool isMatch(string s, string p) {
		if (s.empty() || p.empty()) return isMatchCore(s, p);
		const int m = s.size(), n = p.size();
		vector<vector<bool>> regularSP(m);
		for (int i = m - 1; i >= 0; --i) {
			regularSP[i].resize(n);
			for (int j = n - 1; j >= 0; --j) {
				if (i == m - 1 || j >= n - 2) {
					regularSP[i][j] = isMatchCore(s.substr(i), p.substr(j));
				}
				else {
					bool flag = false;
					if (p[j + 1] == '*') {
						flag |= regularSP[i][j + 2];
						if (s[i] == p[j] || p[j] == '.') {
							flag |= regularSP[i + 1][j];
							flag |= regularSP[i + 1][j + 2];
						}
					}
					else if (s[i] == p[j] || p[j] == '.')
						flag |= regularSP[i + 1][j + 1];
					regularSP[i][j] = flag;
				}
			}
		}
		return regularSP[0][0];
	}
};

