/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (37.43%)
 * Total Accepted:    475K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
bool compare(vector<int>a, vector<int>b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }

    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.empty()) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> curr(intervals[0]);
        for (auto &item : intervals) {
            if (item[0] > curr[1]) {
                vector<int> tmp(curr);
                result.push_back(tmp);
                curr[0] = item[0];
                curr[1] = item[1];
                continue;
            }

            if (item[1] > curr[1]) {
                curr[1] = item[1];
            }
        }
        result.push_back(curr);
        return result;
    }
};

