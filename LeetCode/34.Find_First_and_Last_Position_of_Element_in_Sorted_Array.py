"""
34. Find First and Last Position of Element in Sorted Array     Medium

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

"""

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        first = self.findFirst(nums, target)
        print("first: %d" % first)
        if target != nums[first]:
            return [-1, -1]
        last = self.findLast(nums, first, target)
        print("last: %d" % last)
        return [first, last]
        
    def findFirst(self, nums, target):
        low = 0
        high = len(nums) - 1

        while low < high:
            mid = low + int((high - low) / 2)
            if nums[mid] >= target:
                high = mid
            else:
                low = mid + 1
        return low
    
    def findLast(self, nums, start, target):
        low = start
        length = len(nums)
        high = length - 1

        while low < high:
            mid = low + int((high - low) / 2)
            print(low, mid, high)
            if nums[mid] < target:
                low = mid + 1
            elif nums[mid] == target:
                if mid >= length - 1:
                    return mid
                else:
                    if nums[mid + 1] != target:
                        return mid
                    else:
                        low = mid + 1
            else:
                high = mid - 1
        return low

if __name__ == "__main__":
    nums = [1,2,3,3,3,3,4,5,9]
    solution = Solution()
    solution.searchRange(nums, 3)