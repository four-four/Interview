"""
75. Sort Colors     Medium

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
"""

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        pZero = 0
        curr = 0
        pTwo = len(nums) - 1

        while curr <= pTwo:
            if nums[curr] == 0:
                nums[pZero], nums[curr] = nums[curr], nums[pZero]
                pZero += 1
                curr += 1
            elif nums[curr] == 2:
                nums[pTwo], nums[curr] = nums[curr], nums[pTwo]
                pTwo -= 1
            else:
                curr += 1
