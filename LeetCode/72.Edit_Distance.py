"""
72. Edit Distance   Hard

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
"""

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """

        m = len(word1)
        n = len(word2)

        result = [[0] * (m + 1) for _ in range(n + 1)]

        for i in range(1, n + 1):
            result[i][0] = result[i - 1][0] + 1

        for j in range(1, m + 1):
            result[0][j] = result[0][j - 1] + 1

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if word1[j - 1] == word2[i - 1]:
                    result[i][j] = result[i - 1][j - 1]
                else:
                    result[i][j] = 1 + min(result[i - 1][j - 1], result[i - 1][j], result[i][j - 1])
        return result[-1][-1]
