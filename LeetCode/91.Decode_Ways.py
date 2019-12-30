"""
91. Decode Ways     Medium

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
"""

class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)

        if n == 0:
            return 0
        
        if n == 1:
            if s == '0':
                return 0
            else:
                return 1
        
        pre2 = 1
        pre1 = 0
        maxDec = 0
        if s[0] != '0':
            pre1 = 1
        for i in range(2, n + 1):
            num = s[i - 2] + s[i - 1]
            if s[i - 1] == '0':
                if self.isValid(num):
                    maxDec = pre2
                else:
                    return 0
            else:
                if self.isValid(num):
                    maxDec = pre1 + pre2
                else:
                    maxDec = pre1
            pre2 = pre1
            pre1 = maxDec
        return maxDec
    
    def isValid(self, s):
        if int(s) <= 26 and int(s) >= 10:
            return True
        else:
            return False

if __name__ == "__main__":
    so = Solution()
    result = so.numDecodings("1070")
    print(result)