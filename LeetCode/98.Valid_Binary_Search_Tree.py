"""
98. Validate Binary Search Tree     Medium

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        sortedList = []
        self.inOrder(root, sortedList)
        print(sortedList)
        return self.isSorted(sortedList)
        
    def inOrder(self, root, result):
        if not root:
            return
        self.inOrder(root.left, result)
        result.append(root.val)
        self.inOrder(root.right, result)

    def isSorted(self, sortedList):
        i = 1
        while i < len(sortedList):
            if sortedList[i - 1] >= sortedList[i]:
                return False
        return True
        
