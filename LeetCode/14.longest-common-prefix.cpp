/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.46%)
 * Total Accepted:    604.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
private:
    string findMinStr(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        int minSize = strs[0].size();
        string minStr = strs[0];

        for (string str : strs) {
            if (str.size() < minSize) {
                minStr = str;
            }
        }
        return minStr;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string minStr = findMinStr(strs);
        int maxMatch = minStr.size();

        for (string str : strs) {
            for (int i = 0; i < maxMatch; i++) {
                if (str[i] != minStr[i]) {
                    maxMatch = i;
                    break;
                }
            }
        }
        
        return minStr.substr(0, maxMatch);
    }
};

