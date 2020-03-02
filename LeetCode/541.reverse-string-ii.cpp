/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (46.78%)
 * Total Accepted:    74.6K
 * Total Submissions: 158.9K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */
#include <string>
using namespace std;
class Solution {
private:
    string reverseSubStr(string s, int start, int end) {
        string output = "";
        for (int i = end; i >= start; i--) {
            output.push_back(s[i]);
        }
        return output;
    }
public:
    string reverseStr(string s, int k) {
        int len = s.length();

        string result = "";
        for (int i = 0; i < len; i += 2 * k) {
            int endPos = i + k - 1;
            if (endPos > len - 1) {
                endPos = len - 1;
            }
            string sub = reverseSubStr(s, i, endPos);
            result += sub;
            result += s.substr(endPos + 1, k);
        }

        return result;
    }
};
