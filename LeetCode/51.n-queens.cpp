/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (42.75%)
 * Total Accepted:    170.9K
 * Total Submissions: 399.3K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
#include <vector>
#include <string>

using namespace std;
class Solution {
private:
    vector<vector<string>> result;
    vector<vector<bool>> board;
    vector<bool> rowUsed;
    void addResult(int LEN) {
        vector<string> solution;
        for (int i = 0; i < LEN; i++) {
            string line = "";
            for (int j = 0; j < LEN; j++) {
                if (board[i][j]) {
                    line += "Q";
                } else {
                    line += ".";
                }
            }
            solution.push_back(line);
        }
        result.push_back(solution);
    }

    void backtracking(int row, int LEN) {
        if (row == LEN) {
            addResult(LEN);
            return;
        }

        for (int i = 0; i < LEN; i++) {
            if (isInvalid(row, i, LEN)) {
                continue;
            }

            board[row][i] = true;
            rowUsed[i] = true;
            backtracking(row + 1, LEN);
            board[row][i] = false;
            rowUsed[i] = false;
        }
    }

    bool isInvalid(int row, int col, int LEN) {
        if (row < 0 || col < 0 || row >= LEN || col >= LEN) {
            return true;
        }

        if (rowUsed[col]) {
            return true;
        }
        
        int i = row, j = col;
        while (i > 0 && j > 0) {
            if (board[i - 1][j - 1]) {
                return true;
            }
            i--;
            j--;
        }
        
        i = row, j = col;
        while (i > 0 && j < LEN - 1) {
            if (board[i - 1][j + 1]) {
                return true;
            }
            i--;
            j++;
        }

        return false;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        rowUsed.assign(n, false);
        vector<bool> list(n, false);
        board.assign(n, list);

        backtracking(0, n);
        return result;
    }

};

