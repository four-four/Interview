/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (51.30%)
 * Total Accepted:    457.7K
 * Total Submissions: 888.1K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
#include <unordered_map>
#include <string>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>hashMap;

        for (string str : strs) {
            vector<int> nums(26, 0);
            string key = "";
            for (char a : str) {
                nums[(a - 'a')]++;
            }

            for (int i : nums) {
                key += to_string(i) + "#";
            }
            
            if (hashMap.count(key) == 0) {
                vector<string> strList;
                strList.push_back(str);
                hashMap.insert(pair<string, vector<string>>(key, strList));
            } else {
                hashMap[key].push_back(str);
            }
        }

        vector<vector<string>> result;
        for (const auto& item : hashMap) {
            result.push_back(item.second);
        }
        return result;
    }
};

