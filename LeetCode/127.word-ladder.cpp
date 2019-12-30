/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (26.75%)
 * Total Accepted:    334.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        visited.insert(beginWord);

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while(!q.empty()) {
            int size = q.size();
            while (size--) {
                string t = q.front();
                q.pop();
                for (int i = 0; i < t.size(); i++) {
                    string word = t;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if (!dict.count(word) || visited.count(word)) {
                            continue;
                        }
                        if (word == endWord) {
                            return steps + 1;
                        }
                        visited.insert(word);
                        q.push(word);
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};

