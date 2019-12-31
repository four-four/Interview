"""
303. Range Sum Query - Immutable    Easy

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
"""

class NumArray(object):

    sums = []
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        length = len(nums)
        if length > 0:
            self.initSums(nums, length + 1)    

    def initSums(self, nums, length):
        self.sums = [0] * length
        for i in range(1, length):
            self.sums[i] = self.sums[i - 1] + nums[i - 1]

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j + 1] - self.sums[i]
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)