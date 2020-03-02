/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.38%)
 * Total Accepted:    737.4K
 * Total Submissions: 2.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        if (nums.empty()) {
            return result;
        }

        int N = nums.size();

        for (int k = 0; k < N - 2; k++) {
            if (nums[k] > 0) {
                return result;
            }

            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }

            int i = k + 1;
            int j = N - 1;

            while (i < j) {
                int val = nums[k] + nums[i] + nums[j];
                if (0 == val) {
                    vector<int> arr({nums[k], nums[i], nums[j]});
                    result.push_back(arr);
                    i++;
                    j--;
                    while (i < j && nums[i] == nums[i - 1]) {
                        i++;
                    }

                    while (i < j && nums[j] == nums[j + 1]) {
                        j--;
                    }
                } else if (val > 0) {
                    j--;
                } else {
                    i++;
                }
            }
        }
        return result;
    }
};

