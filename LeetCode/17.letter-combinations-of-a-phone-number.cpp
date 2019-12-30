/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (44.05%)
 * Total Accepted:    491.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
private:
    const string mappings[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void combineLetters(queue<string>& Q, int number) {
        string letters = mappings[number];
        if (Q.empty()) {
            for (int i = 0; i < letters.length(); i++) {
                string prefix = "";
                prefix += letters[i];
                Q.push(prefix);
            }
        } else {
            int length = Q.size();
            while (length > 0) {
                string prefix = Q.front();
                Q.pop();
                length--;
                for (int i = 0; i < letters.length(); i++) {
                    string newWord = prefix + letters[i];
                    Q.push(newWord);
                }
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        queue<string> Q;
        for (int i = 0; i < digits.length(); i++) {
            int num = digits[i] - '0';
            combineLetters(Q, num);
        }

        while (!Q.empty()) {
            result.push_back(Q.front());
            Q.pop();
        }
        return result;
    }

};

