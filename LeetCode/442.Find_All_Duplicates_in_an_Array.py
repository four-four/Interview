"""
442. Find All Duplicates in an Array    Medium

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
"""

class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        length = len(nums)
        result = []
        for i in range(length):
            while nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]:
                j = nums[i] - 1
                nums[i], nums[j] = nums[j], nums[i]

        for i in range(length):
            if nums[i] != i + 1:
                result.append(nums[i])

        return result