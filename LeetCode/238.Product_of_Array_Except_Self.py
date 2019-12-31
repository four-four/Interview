"""
238. Product of Array Except Self   Medium

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

"""

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        length = len(nums)
        products = [1] * length
        left, right = 1, 1

        for i in range(length - 1):
            left *= nums[i]
            products[i + 1] *= left

        for i in range(length - 1, 0, -1):
            right *= nums[i]
            products[i - 1] *= right
        return products

if __name__ == "__main__":
    nums = [1, 2, 3, 4]
    so = Solution()
    result = so.productExceptSelf(nums)
    print(result)
