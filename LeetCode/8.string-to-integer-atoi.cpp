/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.91%)
 * Total Accepted:    459.6K
 * Total Submissions: 3.1M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31 − 1) or
 * INT_MIN (−2^31) is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical 
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * 
 * Example 5:
 * 
 * 
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−2^31) is returned.
 * 
 */
#include<bits/stdc++.h> 
#include<string>
using namespace std;
class Solution {
private:
    int getNum(int num, bool isNeg) {
        if (isNeg) {
            return -num;
        }
        return num;
    }
    bool isNumber(char a) {
        return a >= '0' && a <= '9';
    }
public:
    int myAtoi(string str) {
        int num = 0;
        bool isNeg = false;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                if (i > 0 && str[i - 1] != ' ') {
                    return getNum(num, isNeg);
                }
                continue;
            }

            if ((str[i] == '-' || str[i] == '+') && i < (str.length() - 1) && isNumber(str[i + 1])) {
                if (i > 0 && str[i - 1] != ' ') {
                    return getNum(num, isNeg);
                }
                if (str[i] == '-') {
                    isNeg = true;
                }
                continue;
            }

            if (!isNumber(str[i])) {
                return getNum(num, isNeg);
            }

            int val = str[i] - '0';
            if ((!isNeg && (num < INT_MAX / 10) || ( num == INT_MAX / 10 && val < INT_MAX % 10)) ||
                (isNeg && (-num > INT_MIN / 10) || ( -num == INT_MIN / 10 && (-1 * val) > INT_MIN % 10))) {
                    num = num * 10 + str[i] - '0';
            } else {
                if (isNeg) {
                    return INT_MIN;
                }
                return INT_MAX;
            }
        }
        return getNum(num, isNeg);
    }
};

