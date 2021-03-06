"""
504. Base 7     Easy

Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
"""

class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "0"
        result = []
        isNegative = False

        if num < 0:
            isNegative = True
            num = -num
        
        while num > 0:
            result.append(str(num % 7))
            num = int(num / 7)
        
        return ("").join(result)


        
        