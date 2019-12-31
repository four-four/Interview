"""
343. Integer Break  Medium

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
"""

class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 3:
            return n - 1
        result = 1
        last = n % 3
        three = n / 3
        if last == 1:
            three = three - 1
            last = last + 3
        elif last == 0:
            last = 1
        
        for i in range(three):
            result *= 3
        return result * last