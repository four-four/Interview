"""
405. Convert a Number to Hexadecimal    Easy

Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
"""
import ctypes

class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "0"
        items = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f']
        resultList = []
        while num != 0:
            resultList.append(items[0b1111 & num])
            num = self.unsignedRigthShift(num, 4)
        return ("").join(resultList[::-1])

    def intOverflow(self, val):
        MAX_INT = 0x7FFFFFFF
        if val < -MAX_INT - 1 or val > MAX_INT:
            val = (val + (MAX_INT + 1)) % (2 * (MAX_INT + 1)) - MAX_INT - 1
        return val

    def unsignedRigthShift(self, val, shift):
        if val < 0:
            val = ctypes.c_uint32(val).value
        return self.intOverflow(val >> shift)