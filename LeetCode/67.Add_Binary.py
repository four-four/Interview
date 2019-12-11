"""
67. Add Binary  Easy

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
"""

class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        i = len(a) - 1
        j = len(b) - 1
        carry = 0
        resultList = []

        while i >= 0 or j >= 0 or carry == 1:
            if i >= 0 and a[i] == '1':
                carry += 1
            i -= 1
            if j >= 0 and b[j] == '1':
                carry += 1
            j -= 1
            resultList.append(str(carry % 2))
            carry = int(carry / 2)
            print(carry)
            print(resultList)
        return ("").join(resultList[::-1])

if __name__ == "__main__":
    a = "1011"
    b = "111"
    so = Solution()
    so.addBinary(a, b)