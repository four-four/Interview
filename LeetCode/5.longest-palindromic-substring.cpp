/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.44%)
 * Total Accepted:    746.6K
 * Total Submissions: 2.6M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
#include <string>
using namespace std;
class Solution {
private:
    string expandFromCenter(string s, int left, int right) {
        string result;
        while (left >= 0 && right < s.length()) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }
        result = s.substr(left + 1, right - left - 1);
        return result;
    }
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        int length = s.length();
        string result;
        for (int i = 0; i < length; i++) {
            if ((length - i) <= maxLength / 2) {
                break;
            }
            string oneBase = expandFromCenter(s, i, i);
            string twoBase = expandFromCenter(s, i, i + 1);
            int len1 = oneBase.length();
            int len2 = twoBase.length();
            if (len1 > len2) {
                if (maxLength < len1) {
                    maxLength = len1;
                    result = oneBase;
                }
            } else {
                if (maxLength < len2) {
                    maxLength = len2;
                    result = twoBase;
                }
            }
        }
        return result;
    }
};

