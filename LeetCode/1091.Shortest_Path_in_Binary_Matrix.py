"""
1091. Shortest Path in Binary Matrix    Medium

In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4

 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1
"""

class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        n, m = len(grid), len(grid[0])

        if grid[0][0] == 1 or grid[n - 1][m - 1] == 1:
            return -1
        if n == 1 and m == 1:
            return 1
        
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        queue = [(0, 0)]
        grid[0][0] = 1
        steps = 1

        while queue:
            size = len(queue)
            while size > 0:
                curr = queue.pop(0)
                size -= 1
                for direction in directions:
                    x, y = (direction[0] + curr[0]), (direction[1] + curr[1])
                    if (x, y) == (n - 1, m - 1):
                        return steps + 1
                    if x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 0:
                        print(x, y)
                        queue.append((x, y))
                        grid[x][y] = 1
                
            steps += 1
        return -1

                    
