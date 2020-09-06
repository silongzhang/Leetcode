// 79. µ¥´ÊËÑË÷

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	void subFunc(const vector<vector<char>> &board, const string &word, bool &res, 
		vector<vector<bool>> &visited, const int &i, const int &j, const int &pos) {
		if (res) return;
		if (pos >= word.size()) {
			res = true;
			return;
		}
		if (i<0 || i>board.size() - 1 || j<0 || j>board[0].size() - 1) return;
		if (visited[i][j]) return;
		if (board[i][j] == word[pos]) {
			visited[i][j] = true;
			subFunc(board, word, res, visited, i - 1, j, pos + 1);
			subFunc(board, word, res, visited, i, j - 1, pos + 1);
			subFunc(board, word, res, visited, i + 1, j, pos + 1);
			subFunc(board, word, res, visited, i, j + 1, pos + 1);
			visited[i][j] = false;
		}
	}
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> visited(board.size());
		for (int i = 0; i < visited.size(); ++i) visited[i] = vector<bool>(board[0].size(), false);
		bool res = false;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				subFunc(board, word, res, visited, i, j, 0);
			}
		}
		return res;
	}
};

