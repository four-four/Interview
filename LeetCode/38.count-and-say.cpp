/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (42.44%)
 * Total Accepted:    338.7K
 * Total Submissions: 797.1K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence. You can do so recursively, in other words from the
 * previous member read off the digits, counting the number of digits in groups
 * of the same digit.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * Explanation: For n = 3 the term was "21" in which we have two groups "2" and
 * "1", "2" can be read as "12" which means frequency = 1 and value = 2, the
 * same way "1" is read as "11", so the answer is the concatenation of "12" and
 * "11" which is "1211".
 * 
 * 
 */
class Solution {
private:
    string calculateNext(string curr) {
        int length = curr.length();
        int counter = 1;
        string result = "";
        for (int i = 0; i < length; i++) {
            if (i < length - 1 && curr[i + 1] == curr[i]) {
                counter++;
            } else {
                result += to_string(counter);
                result += to_string(curr[i] - '0');
                counter = 1;
            }
        }
        return result;
    }
public:
    string countAndSay(int n) {
        int i = 1;
        string current = "1";
        while (i < n) {
            current = calculateNext(current);
            i++;
        }
        return current;
    }
};

