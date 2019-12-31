/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (33.11%)
 * Total Accepted:    366.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int N = 0;
    int M = 0;
    
    bool find(vector<vector<char>>& board, string word, int x, int y, vector<vector<bool>>& visited) {
        if (visited[x][y] || board[x][y] != word[0]) {
            return false;
        }
        
        if (word.length() <= 1) {
            return true;
        }
        
        visited[x][y] = true;

        for (int* direction : directions) {
            int nextX = x + direction[0];
            int nextY = y + direction[1];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
                continue;
            }
            
            if (find(board, word.substr(1), nextX, nextY, visited)) {
                return true;   
            }
        }
        
        visited[x][y] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }

        N = board.size();
        M = board[0].size();

        vector<vector<bool>> visited(N, vector<bool>(M));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = false;
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (find(board, word, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

