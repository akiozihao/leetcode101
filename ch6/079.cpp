//
// Created by akio on 2020/10/25.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (word.empty()) return true;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (helper(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }


private:
    bool helper(vector<vector<char>> &board, const string &word, int idx, int i, int j,
                vector<vector<bool>> &visited) {
        if (idx == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
        visited[i][j] = true;
        bool res = helper(board, word, idx + 1, i - 1, j, visited) ||
                   helper(board, word, idx + 1, i + 1, j, visited) ||
                   helper(board, word, idx + 1, i, j - 1, visited) ||
                   helper(board, word, idx + 1, i, j + 1, visited);
        visited[i][j] = false;
        return res;
    }
};