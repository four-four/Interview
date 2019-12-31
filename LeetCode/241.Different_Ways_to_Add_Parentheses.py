"""
241. Different Ways to Add Parentheses  Medium

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
"""


class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        result = []
        if input.isdigit():
            return [int(input)]
        print(input)
        
        length = len(input)
        for i in range(length):
            if self.isOperater(input[i]):
                leftList = self.diffWaysToCompute(input[:i])
                rightList = self.diffWaysToCompute(input[i+1:])
                for left in leftList:
                    for right in rightList:
                        result.append(self.calculate(input[i], left, right))
        return result
            
    def isOperater(self, char):
        return char == '+' or char == '-' or char == '*'
    
    def calculate(self, operater, left, right):
        if operater == '+':
            return left + right
        elif operater == '-':
            return left - right
        elif operater == '*':
            return left * right
        

if __name__ == "__main__":
    input = "2*3-4*5"
    solution = Solution()
    result = solution.diffWaysToCompute(input)
    print(result)