// #62 ²»Í¬Â·¾¶

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0) return 0;
		else if (m == 1 || n == 1) return 1;
		else {
			vector<int> routes(n, 1);
			for (int i = 1; i < m; ++i) {
				for (int j = n - 2; j >= 0; --j) {
					routes[j] += routes[j + 1];
				}
			}
			return routes[0];
		}
	}
};

