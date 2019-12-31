"""
187. Repeated DNA Sequences
Medium

558

220

Favorite

Share
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

"""

class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        N = len(s)
        if N <= 10:
            return []
        
        mask = 0x7FFFFFFF
        curr = 0
        hashmap = {}
        result = []

        for i in range(9):
            curr = (curr << 3) | (s[i] & 7)
        
        for i in range(10, N):
            curr = (curr & mask) | (s[i] & 7)
            if curr not in hashmap.keys():
                hashmap[curr] = 1
            else:
                if hashmap[curr] == 1:
                    result.append(s[i - 9: i])
                hashmap[curr] += 1
        return result


