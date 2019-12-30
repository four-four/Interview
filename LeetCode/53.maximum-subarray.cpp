/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.23%)
 * Total Accepted:    719.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        int currSum = nums[0]
        int maxSum = nums[0];

        for (int i = 1; i < length; i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(nums[i], maxSum);
        }
        return maxSum;
    }
};

