/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (39.97%)
 * Total Accepted:    156.3K
 * Total Submissions: 390.5K
 * Testcase Example:  '[['5','3','.','.','7','.','.','.','.'],['6','.','.','1','9','5','.','.','.'],['.','9','8','.','.','.','.','6','.'],['8','.','.','.','6','.','.','.','3'],['4','.','.','8','.','3','.','.','1'],['7','.','.','.','2','.','.','.','6'],['.','6','.','.','.','.','2','8','.'],['.','.','.','4','1','9','.','.','5'],['.','.','.','.','8','.','.','7','9']]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
private:
    int rows = 9;
    int nums = 10;
    vector<vector<bool>> rowUsed(rows, vector<bool>(nums, false));
    vector<vector<bool>> colUsed(rows, vector<bool>(nums, false));
    vector<vector<bool>> subCubUsed(rows, vector<bool>(nums, false));
    bool backtracking(vector<vector<char>>& board, int row, int col) {

        while(board[row][col] != '.' && col < 9 && row < 9) {
            if (col == 8) {
                col = 0;
                row++;
            } else {
                col++;
            }
        }
        
        if (row >= 9 || row < 0 || col >= 9 || col < 0) {
            cout << row <<" " << col << endl;
        }
        
        if (row == 9) {
            return true;
        }

        for (int num = 1; num <= 9; num++) {
            if (isInvalid(row, col, num)) {
                continue;
            }
            setTag(row, col, num, true);
            board[row][col] = char('0' + num);
            if (backtracking(board, row, col)) {
                return true;
            }
            board[row][col] = '.';
            setTag(row, col, num, false);
        }

        return false;
    }

    bool isInvalid(int row, int col, int num) {
        if (row >= 9 || row < 0 || col >= 9 || col < 0 || num > 9 || num < 0) {
            return false;
        }
        int index = getSubCub(row, col);
        return rowUsed[row][num] || colUsed[col][num] || subCubUsed[index][num];
    }
    int getSubCub(int row, int col) {
        int i = row / 3;
        int j = col / 3;
        return i * 3 + j;
    }
    void setTag(int row, int col, int num, bool tag) {
        rowUsed[row][num] = tag;
        colUsed[col][num] = tag;
        int subIndex = getSubCub(row, col);
        subCubUsed[subIndex][num] = tag;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int num = board[i][j] - '0';
                setTag(i, j, num, true);
            }
        }
        backtracking(board, 0, 0);
    }
};


