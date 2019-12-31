"""
127. Word Ladder    Medium

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
"""

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        if endWord not in wordList:
            return 0
        length = len(beginWord)
        if length != len(endWord):
            return 0
        
        N = len(wordList)
        visited = [False] * N
        queue = []
        queue.append(beginWord)
        steps = 1

        while queue:
            size = len(queue)
            while size > 0:
                curr = queue.pop(0)
                size = size - 1
                for i in range(N):
                    if visited[i]:
                        continue
                    word = wordList[i]
                    if self.connected(curr, word, length):
                        if endWord == word:
                            return steps + 1
                        visited[i] = True
                        queue.append(word)
            steps += 1
        return 0

    def generateGraphic(self, beginWord, wordList, length):
        

    def diffLettersNum(self, word1, word2, length):
        result = 0
        for i in range(length):
            if word1[i] != word2[i]:
                result += 1
        return result == 1

