/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (44.58%)
 * Total Accepted:    239K
 * Total Submissions: 535.7K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
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
    void backtracking(vector<int>& nums, vector<int>& list, int length) {
        if (length == 0) {
            vector<int> item(list);
            result.push_back(item);
            return;
        }

        for (int i = 0; i < LEN; i++) {
            if (visited[i]) {
                continue;
            }

            if (!list.empty() && list.back() > nums[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            list.push_back(nums[i]);
            backtracking(nums, list, length - 1);
            list.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) {
            return result;
        }

        LEN = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < LEN; i++) {
            visited.push_back(false);
        }

        for (int i = 0; i <= LEN; i++) {
            vector<int> list;
            backtracking(nums, list, i);
        }
        return result;
    }
};

