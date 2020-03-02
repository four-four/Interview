/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 *
 * https://leetcode.com/problems/custom-sort-string/description/
 *
 * algorithms
 * Medium (63.98%)
 * Total Accepted:    48.8K
 * Total Submissions: 76.2K
 * Testcase Example:  '"cba"\n"abcd"'
 *
 * S and T are strings composed of lowercase letters. In S, no letter occurs
 * more than once.
 * 
 * S was sorted in some custom order previously. We want to permute the
 * characters of T so that they match the order that S was sorted. More
 * specifically, if x occurs before y in S, then x should occur before y in the
 * returned string.
 * 
 * Return any permutation of T (as a string) that satisfies this property.
 * 
 * 
 * Example :
 * Input: 
 * S = "cba"
 * T = "abcd"
 * Output: "cbad"
 * Explanation: 
 * "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b",
 * and "a". 
 * Since "d" does not appear in S, it can be at any position in T. "dcba",
 * "cdba", "cbda" are also valid outputs.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S has length at most 26, and no character is repeated in S.
 * T has length at most 200.
 * S and T consist of lowercase letters only.
 * 
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<char, int> hashMap;
unordered_map<char, int> hashMap;
bool compare(char a, char b) {
    return hashMap[a] < hashMap[b];
}
class Solution {
public:
    string customSortString(string S, string T) {
        int N = S.length();
        hashMap.clear();
        for (int i = 0; i < N; i++) {
            hashMap.insert(pair<char, int>(S[i], i));
        }

        vector<char> listT;
        string result = "";
        for (auto a : T) {
            if (hashMap.count(a) != 0) {
                listT.push_back(a);
            } else {
                result.push_back(a);
            }
        }
        

        sort(listT.begin(), listT.end(), compare);

        for (auto item : listT) {
            result.push_back(item);
        }
        return result;
    }
};


