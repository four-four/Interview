/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (30.62%)
 * Total Accepted:    92.5K
 * Total Submissions: 301.9K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums(nums);
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;

        while (start < nums.size()) {
            if (nums[start] != sortedNums[start]) {
                break;
            }
            start++;
        }

        if (start == nums.size()) {
            return 0;
        }
        while (end > 0) {
            if (nums[end] != sortedNums[end]) {
                break;
            }
            end--;
        }

        return (end - start + 1);
    }
};

