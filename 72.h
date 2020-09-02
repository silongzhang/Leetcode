// 72. ±‡º≠æ‡¿Î

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1.empty()) return word2.size();
		if (word2.empty()) return word1.size();

		vector<int> temp(word2.size() + 1);
		vector<vector<int>> distance;
		for (int i = 0; i < word1.size() + 1; ++i) distance.push_back(temp);
		for (int j = 0; j < word2.size() + 1; ++j) distance[0][j] = j;
		for (int i = 1; i < word1.size() + 1; ++i) distance[i][0] = i;

		for (int i = 1; i < word1.size() + 1; ++i) {
			for (int j = 1; j < word2.size() + 1; ++j) {
				if (word1[i - 1] == word2[j - 1]) distance[i][j] = distance[i - 1][j - 1];
				else {
					distance[i][j] =
						1 + std::min({ distance[i - 1][j - 1], distance[i - 1][j], distance[i][j - 1] });
				}
			}
		}

		return distance[word1.size()][word2.size()];
	}
};

