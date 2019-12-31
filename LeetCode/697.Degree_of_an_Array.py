"""
697. Degree of an Array     Easy

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

"""
from collections import Counter

class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counts = Counter(nums)
        maxDegree = 0
        minDistance = len(nums)

        for tup in counts.most_common():
            item, degree = tup
            if degree < maxDegree:
                break
            maxDegree = degree
            minDistance = min(minDistance, self.getRange(nums, item, maxDegree))
        return minDistance
            
    def getRange(self, nums, item, degree):
        minIndex = 0
        maxIndex = 0
        times = 0
        for i in range(len(nums)):
            if nums[i] == item:
                times += 1
                if times == 1:
                    minIndex = i
                if times == degree:
                    maxIndex = i
                    break
        
        return maxIndex - minIndex + 1
        
if __name__ == "__main__":
    nums = [1,2,2,3,1]
    so = Solution()
    result = so.findShortestSubArray(nums)
    print(result)