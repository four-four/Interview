/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (53.90%)
 * Total Accepted:    143.3K
 * Total Submissions: 265.8K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;

    void backtracking(vector<int>& list, int k, int n) {
        if (k == 0 && n == 0) {
            vector<int> item(list);
            result.push_back(item);
            return;
        }

        if (k == 0 || n <= 0) {
            return;
        }

        for (int i = 1; i <= 9; i++) {
            if (!list.empty() && i <= list.back()) {
                continue;
            }
            list.push_back(i);
            backtracking(list, k - 1, n - i);
            list.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> list;
        backtracking(list, k, n);
        return result;
    }
};

