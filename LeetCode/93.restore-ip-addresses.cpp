/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (33.10%)
 * Total Accepted:    161.9K
 * Total Submissions: 489K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> result;
    /*
     * -1 valid
     * 0 - 255 number
     */
    int getValidNumber(string numbers) {
        int value = stoi(numbers);
        if (numbers.length() != to_string(value).length()) {
            return -1;
        }
        
        if (value > 255 || value < 0) {
            return -1;
        }
        
        return value;
    }
    
    void splitAndCombine(int part, string numbers, string ip) {
        if (part == 4) {
            if (numbers.length() == 0) {
                result.push_back(ip);
            }
            return;
        }
        
        for (int i = 1; i < 4; i++) {
            if (numbers.length() < i) {
                return;
            }
            
            int val = getValidNumber(numbers.substr(0, i));
            if (val == -1) {
                continue;
            }
            string dot = ".";
            if (part == 3) {
                dot = "";
            }
            splitAndCombine(part + 1, numbers.substr(i), ip + to_string(val) + dot);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        splitAndCombine(0, s, ip);
        return result;
    }
};

