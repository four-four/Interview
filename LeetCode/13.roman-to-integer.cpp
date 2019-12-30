/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (53.97%)
 * Total Accepted:    549.4K
 * Total Submissions: 1M
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
private:
    unordered_map<char, int> mappingTable;
    int convert(stack<char>& S) {
        int num = 0;
        if (S.empty()) {
            return num;
        }

        int max = mappingTable[S.top()];
        S.pop();
        while(!S.empty()){
            num += mappingTable[S.top()];
            S.pop();
        }
        if (max > num) {
            return max - num;
        } else {
            return max + num;
        }
    }
public:
    int romanToInt(string s) {
        mappingTable['I'] = 1;
        mappingTable['V'] = 5;
        mappingTable['X'] = 10;
        mappingTable['L'] = 50;
        mappingTable['C'] = 100;
        mappingTable['D'] = 500;
        mappingTable['M'] = 1000;

        stack<char> S;
        S.push(s[0]);
        int num = 0;
        for (int i = 1; i < s.length(); i++) {
            if (mappingTable[s[i]] < mappingTable[S.top()]) {
                num += convert(S);
            }
            S.push(s[i]);
        }
        num += convert(S);
        return num;
    }
};

