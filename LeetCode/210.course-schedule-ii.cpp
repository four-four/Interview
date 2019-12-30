/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (37.34%)
 * Total Accepted:    196.2K
 * Total Submissions: 525.1K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished   
 * course 0. So the correct course order is [0,1] .
 * 
 * Example 2:
 * 
 * 
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both     
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0. 
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
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
class Solution {
private:
    vector<vector<bool>> graph;
    vector<int> result;
    void findOrder(int length) {
        vector<int> inDegrees(length, 0);
        queue<int> Q;
        int numCourses = length;

        for (vector<bool>& node : graph) {
            for (int i = 0; i < length; i++) {
                if (node[i]) {
                    inDegrees[i]++;
                }
            }
        }

        for (int i = 0; i < length; i++) {
            if (0 == inDegrees[i]) {
                Q.push(i);
            }
        }

        while(!Q.empty()) {
            int node = Q.front();
            result.push_back(node);
            Q.pop();
            numCourses--;
            for (int i = 0; i < length; i++) {
                if (graph[node][i]) {
                    inDegrees[i]--;
                    if (0 == inDegrees[i]) {
                        Q.push(i);
                    }
                }
            }
        }

        if (0 != numCourses) {
            result.clear();
        } else{
            reverse(result.begin(), result.end());
        }
    }

    void createGraph(vector<vector<int>>& lines) {
        for (vector<int>& line : lines) {
            graph[line[0]][line[1]] = true;
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> line(numCourses, false);
        graph.assign(numCourses, line);
        createGraph(prerequisites);
        findOrder(numCourses);

        return result;
    }
};

