"""
201. Bitwise AND of Numbers Range
Medium

538

74

Favorite

Share
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

"""

class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        
        N = 0xFFFFFFFF
        while (m & N) != (n & N):
            N <<= 1
        return m & N

