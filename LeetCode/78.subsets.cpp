/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (56.73%)
 * Total Accepted:    456.4K
 * Total Submissions: 803.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    int LEN;
    void backtracking(vector<int>& nums, vector<int>& list, int length) {
        if (0 == length) {
            vector<int> item(list);
            result.push_back(item);
            return;
        }

        for (int i = 0; i < LEN; i++) {
            if (!list.empty() && nums[i] <= list.back()) {
                continue;
            }
            list.push_back(nums[i]);
            backtracking(nums, list, length - 1);
            list.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        LEN = nums.size();
        for (int i = 0; i < LEN; i++) {
            vector<int> list;
            backtracking(nums, list, i);
        }
        return result;
    }
};

