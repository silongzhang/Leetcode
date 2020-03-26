// #70 ÅÀÂ¥Ìİ

#include<iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n < 1) return 0;
		else if (n == 1) return 1;
		int first = 1, second = 2;
		for (int i = 3; i <= n; ++i) {
			int third = first + second;
			first = second;
			second = third;
		}
		return second;
	}
};

