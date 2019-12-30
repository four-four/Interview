/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (59.03%)
 * Total Accepted:    481.1K
 * Total Submissions: 814.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> result;
    int N;
    void backtracking(vector<int>& nums, vector<int>& permuteList) {
        if (permuteList.size() == N) {
            vector<int> item(permuteList);
            result.push_back(item);
            return;
        }

        for (int i = 0; i < N; i++) {
            if (visited[i]) {
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
    vector<vector<int>> permute(vector<int>& nums) {
        N = nums.size();
        if (N == 0) {
            return result;
        }
        
        for (int i = 0; i < N; i++) {
            visited.push_back(false);
        }
        vector<int> permuteList;
        backtracking(nums, permuteList);
        return result;
    }
};

