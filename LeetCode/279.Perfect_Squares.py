"""
279. Perfect Squares    Medium

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
"""

class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """

        squares = self.getSquareList(n)
        result = [0] * (n + 1)

        result[1] = 1
        for i in range(2, n + 1):
            result[i] = i
            for j in squares:
                if j == i:
                    result[i] = 1
                elif j > i:
                    break
                else:
                    result[i] = min(result[i], result[i - j] + 1)
        return result[n]

    def getSquareList(self, n):
        result = []
        diff = 3
        curr = 1
        while curr <= n:
            result.append(curr)
            curr += diff
            diff += 2
            
        return result

if __name__ == "__main__":
    so = Solution()
    result = so.numSquares(26)
    print(result)