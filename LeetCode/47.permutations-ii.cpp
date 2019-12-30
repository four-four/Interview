/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (43.37%)
 * Total Accepted:    295.9K
 * Total Submissions: 681.7K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
#include <vector>

using namespace std;
class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> result;
    int LEN;

    void backtracking(vector<int>& nums, vector<int>& permuteList) {
        if (permuteList.size() == LEN) {
            vector<int> item(permuteList);
            result.push_back(item);
        }

        for (int i = 0; i < LEN; i++) {
            if (visited[i]) {
                continue;
            }

            if (nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            permuteList.push_back(nums[i]);
            backtracking(nums, permuteList);
            permuteList.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        LEN = nums.size();

        if (0 == LEN) {
            return result;
        } 

        for (int i = 0; i < LEN; i++) {
            visited.push_back(false);
        }

        vector<int> permuteList;
        sort(nums.begin(), nums.end());
        backtracking(nums, permuteList);
        return result;
    }
};

