"""
64. Minimum Path Sum    Medium

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
"""

class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        n = len(grid)
        m = len(grid[0])
        result = [[0] * m for _ in range(n)]

        if m == 0 and n == 0:
            return 0

        result[0][0] = grid[0][0]
        for i in range(1, n):
            result[i][0] = grid[i][0] + result[i - 1][0]

        for j in range(1, m):
            result[0][j] = grid[0][j] + result[0][j - 1]

        for i in range(1, n):
            for j in range(1, m):
                result[i][j] = grid[i][j] + min(result[i - 1][j], result[i][j - 1])
        return result[n - 1][m - 1]