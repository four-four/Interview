"""
378. Kth Smallest Element in a Sorted Matrix    Medium

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
"""

#TODO: Time limited

class Solution(object):
    M = 1
    N = 1
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        self.N = len(matrix)
        self.M = len(matrix[0])
        self.matrix = matrix

        length = self.M * self.N
        self.buildHeap(length)
        print(self.matrix)

        for i in range(k - 1):
            self.swap(0, length - 1 - i)
            self.heapify(0, length - 1 - i)
            print(self.matrix)
        return matrix[0][0]

    def indexToXY(self, index):
        y = int(index / self.M)
        x = int(index % self.M)
        return (x, y)
    
    def XYToindex(self, x, y):
        index = x + y * self.M
        return index

    def getValue(self, index):
        x, y = self.indexToXY(index)
        return self.matrix[y][x]

    def swap(self, a, b):
        a_x, a_y = self.indexToXY(a)
        b_x, b_y = self.indexToXY(b)
        self.matrix[a_y][a_x], self.matrix[b_y][b_x] = self.matrix[b_y][b_x], self.matrix[a_y][a_x]

    def heapify(self, index, length):
        if index >= length:
            return
        left = 2 * index + 1
        right = 2 * index + 2
        minIndex = index
        if left < length and self.getValue(left) < self.getValue(minIndex):
            minIndex = left
        if right < length and self.getValue(right) < self.getValue(minIndex):
            minIndex = right
        
        if index != minIndex:
            self.swap(index, minIndex)
            self.heapify(minIndex, length)
    
    def buildHeap(self, length):
        lastNode = length - 1
        start = int((lastNode - 1) / 2)

        while start > 0:
            self.heapify(start, length)
            start -= 1

if __name__ == "__main__":
    k = 2
    l1 = [1, 2, 10]
    l2 = [3, 4, 15]
    l3 = [6, 7, 19]
    matrix = []
    matrix.append(l1)
    matrix.append(l2)
    matrix.append(l3)
    print(matrix)

    so = Solution()
    so.kthSmallest(matrix, k)
    for i in range(9):
        print(so.getValue(i))