"""
95. Unique Binary Search Trees II   Medium

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        dataList = []
        i = 1
        while i <= n:
            dataList.append(i)
            i += 1
        result = self.generateTreeList(dataList)
        return result
        
    def generateTreeList(self, dataList):
        if len(dataList) == 0:
            return [None]
        if len(dataList) == 1:
            return [TreeNode(dataList[0])]
        result = []
        
        for i in range(len(dataList)):
            leftList = self.generateTreeList(dataList[:i])
            rightList = self.generateTreeList(dataList[i+1:])
            for left in leftList:
                for right in rightList:
                    node = TreeNode(dataList[i])
                    node.left = left
                    node.right = right
                    result.append(node)
        return result