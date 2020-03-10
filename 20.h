// #20 ÓÐÐ§µÄÀ¨ºÅ

#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
private:
	bool match(char lhs, char rhs) {
		if (lhs == '(' && rhs == ')') return true;
		else if (lhs == '[' && rhs == ']') return true;
		else if (lhs == '{' && rhs == '}') return true;
		else return false;
	}
public:
	bool isValid(string s) {
		stack<char> stc;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				stc.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
				if (stc.empty() || !match(stc.top(), s[i])) return false;
				else stc.pop();
			}
		}
		return stc.empty() ? true : false;
	}
};

