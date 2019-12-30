/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (51.12%)
 * Total Accepted:    245K
 * Total Submissions: 478.9K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
private:
    vector<vector<int>> result;
    void backtracking(vector<int>& list, int k, int n) {
        if (k == list.size()) {
            vector<int> item(list);
            result.push_back(item);
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!list.empty() && i <= list.back()) {
                continue;
            }
            list.push_back(i);
            backtracking(list, k, n);
            list.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if (k == 0) {
            return result;
        }

        vector<int> list;
        backtracking(list, k, n);
        return result;
    }
};

