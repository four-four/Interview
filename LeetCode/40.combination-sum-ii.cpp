/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (44.66%)
 * Total Accepted:    271.2K
 * Total Submissions: 606.6K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<bool> visited;
    int LEN;
    void backtracking(vector<int>& candidates, vector<int>& list, int target) {
        if (0 == target) {
            vector<int> item(list);
            result.push_back(item);
            return;
        }

        if (0 > target) {
            return;
        }

        for (int i = 0; i < LEN; i++) {
            if (visited[i]) {
                continue;
            }

            if (!list.empty() && candidates[i] < list.back()) {
                continue;
            }

            if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            list.push_back(candidates[i]);
            backtracking(candidates, list, target - candidates[i]);
            list.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) {
            return result;
        }

        LEN = candidates.size();

        for (int i = 0; i < LEN; i++) {
            visited.push_back(false);
        }

        sort(candidates.begin(), candidates.end());
        vector<int> list;

        backtracking(candidates, list, target);
        return result;
    }
};

