/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (40.18%)
 * Total Accepted:    297K
 * Total Submissions: 738.5K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
#include <vector>
#include <queue>

using namespace std;
class Solution {
private:
    vector<vector<bool>> graph;
    void createGraph(vector<vector<int>>& lines) {
        for (vector<int>& line : lines) {
            graph[line[0]][line[1]] = true;
        }
    }

    bool hasCycle(int LEN) {
        int numCourses = LEN;
        vector<int> inDegrees(LEN, 0);
        for (vector<bool> &node : graph) {
            for (int i = 0; i < LEN; i++) {
                if (node[i]) {
                    inDegrees[i]++;
                }
            }
        }

        queue<int> Q;
        for (int i = 0; i < LEN; i++) {
            if (inDegrees[i] == 0) {
                Q.push(i);
            }
        }

        while (!Q.empty()) {
            int node = Q.back();
            Q.pop();
            numCourses--;
            for (int i = 0; i < LEN; i++) {
                if (graph[node][i]) {
                    inDegrees[i]--;
                    if (inDegrees[i] == 0) {
                        Q.push(i);
                    }
                }
            }
        }
        return numCourses == 0;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> line(numCourses, false);
        graph.assign(numCourses, line);

        createGraph(prerequisites);

    }
};

