/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (52.86%)
 * Total Accepted:    252.4K
 * Total Submissions: 477.2K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * 
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "A"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "AB"
 * Output: 28
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "ZY"
 * Output: 701
 * 
 */
class Solution {
private:
    int calculate(char a, int times) {
        int num = int(a - 'A' + 1);
        while(times > 0) {
            num *= 26;
            times--;
        }
        return num;
    }
public:
    int titleToNumber(string s) {
        int len = s.length();
        int result = 0;
        for (int i = len - 1; i >= 0; i--) {
            result += calculate(s[i], len - 1 - i);
        }
        return result;
    }
};

