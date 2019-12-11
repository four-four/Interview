"""
204. Count Primes   Easy

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
"""

class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        count = 0
        notPrimes = [False] * (n + 1)

        for i in range(2, n, 1):
            if notPrimes[i]:
                continue
            count += 1
            j = i * i
            while j < n:
                notPrimes[j] = True
                j += i
        return count