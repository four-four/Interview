"""
169. Majority Element   Easy

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
"""

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        midIndex = int(length / 2)
        self.buildHeap(nums, length)
        
        for i in midIndex:
            nums[0], nums[length - i - 1] = nums[length - i - 1], nums[0]
            self.heapify(nums, 0, length - i - 1)
        return nums[0]
        
    def heapify(self, nums, index, length):
        if index >= length: 
            return

        left = 2 * index + 1
        right = 2 * index + 2
        maxIndex = index

        if left < length and nums[left] > nums[maxIndex]:
            maxIndex = left
        if right < length and nums[right] > nums[maxIndex]:
            maxIndex = right
        if index != maxIndex:
            nums[index], nums[maxIndex] = nums[maxIndex], nums[index]
            self.heapify(nums, maxIndex, length)
    
    def buildHeap(self, nums, length):
        lastNode = length - 1
        start = int((lastNode - 1) / 2)

        while start >= 0:
            self.heapify(nums, start, length)
            start -= 1