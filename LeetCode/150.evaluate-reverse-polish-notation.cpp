/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (34.16%)
 * Total Accepted:    196.6K
 * Total Submissions: 572.4K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Note:
 * 
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 */
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    bool isOperator(string a) {
        if (a.length() != 1) {
            return false;
        }

        if (a[0] == '+' || a[0] == '-' || a[0] == '*' || a[0] == '/') {
            return true;
        }
        return false;
    }
    int calculate(string oper, int a, int b) {
        switch(oper[0]) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return 0;
        }
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string str : tokens) {
            if (isOperator(str)) {
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
                int c = calculate(str, a, b);
                nums.push(c);
                continue;
            }

            int val = stoi(str);
            nums.push(val);
        }
        int result = nums.top();
        nums.pop();
        return result;
    }
};

