"""
69. Sqrt(x)     Easy

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
"""

class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        low = 0
        high = x
        key = x
        while low <= high:
            mid = int(low + (high - low) / 2)
            value = mid * mid
            if value == key:
                return mid
            elif value > key:
                high = mid - 1
            else:
                low = mid + 1
        return high

if __name__ == "__main__":
    solution = Solution()
    x = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    result = [0, 1, 1, 1, 2, 2, 2, 2, 2, 3]
    for (item, res) in zip(x, result):
        y = solution.mySqrt(item)
        if y != res:
            print("Error, when x = %d, expected %d, got %d" %(item, res, y))
