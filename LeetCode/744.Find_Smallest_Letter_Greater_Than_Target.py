"""
744. Find Smallest Letter Greater Than Target   Easy

Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
"""

class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        low = 0
        length = len(letters)
        high = length


        while low < high:
            mid = int(low + (high - low) / 2)
            value = letters[mid]
            if value <= target:
                low = mid + 1
            else:
                high = mid - 1
        if low >= length:
            return letters[0]
        else:
            return letters[low]

if __name__ == "__main__":
    solution = Solution()
    letters = ['a', 'c', 'e', 'm']
    solution.nextGreatestLetter(letters, 'a')
    solution.nextGreatestLetter(letters, 'z')