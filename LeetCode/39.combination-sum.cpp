/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (52.17%)
 * Total Accepted:    434.8K
 * Total Submissions: 832.8K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, vector<int>& list, int target) {
        if (0 == target) {
            vector<int> item(list);
            result.push_back(item);
            return;
        }

        if (0 > target) {
            return;
        }

        for (int i : candidates) {
            if (i < list.back()) {
                continue;
            }

            list.push_back(i);
            backtracking(candidates, list, target - i);
            list.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        if (candidates.empty()) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> list;

        backtracking(candidates, list, target);
        return result;
    }
};

