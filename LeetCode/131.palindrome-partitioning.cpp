/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (43.86%)
 * Total Accepted:    193.4K
 * Total Submissions: 440.6K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<vector<string>> result;
    void backtracking(string s, vector<string>& list, int length) {
        if (length == 0) {
            vector<string> item(list);
            result.push_back(item);
            return;
        }

        for (int i = 1; i <= s.length(); i++) {
            if (!isPalindrome(s, 0, i - 1)) {
                continue;
            }

            list.push_back(s.substr(0, i));
            backtracking(s.substr(i), list, length - i);
            list.pop_back();
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> list;
        backtracking(s, list, s.length());
        return result;
    }
};

