"""
207. Course Schedule
Medium

2531

128

Favorite

Share
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
"""

class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        
        graphic = []
        for i in range(numCourses):
            graphic[i] = [0] * numCourses
        for pre in prerequisites:
            graphic[pre[0]][pre[1]] = 1
        globalMarked = [False] * numCourses
        localMarked = [False] * numCourses

        for i in range(numCourses):
            if self.hasCycle(globalMarked, localMarked, graphic, i):
                return False
        return True

    def hasCycle(self, globalMarked, localMarked, graphic, node):
        if localMarked[node]:
            return True
        if globalMarked[node]:
            return False

        globalMarked[node] = True
        localMarked[node] = True
        for nextNode in graphic[node]:
            if self.hasCycle(globalMarked, localMarked, graphic, nextNode):
                return True
        localMarked[node] = False
        return False

