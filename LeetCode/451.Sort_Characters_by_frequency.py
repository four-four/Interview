"""
451. Sort Characters By Frequency Medium

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

"""

from collections import Counter

class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = []
        sCounter = Counter(s)
        length = len(s) + 1
        bucket = [None] * (length)
        
        for value in sCounter:
            frequency = sCounter[value]
            if not bucket[frequency]:
                bucket[frequency] = []
            bucket[frequency].append(value)
        
        while bucket:
            values = bucket.pop()
            if values:
                for value in values:
                    for i in range(length - 1):
                        result.append(value)
            length -= 1
        
        return ("").join(result)
