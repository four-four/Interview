/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (48.26%)
 * Total Accepted:    265.4K
 * Total Submissions: 549.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<string> result;
    void traverse(TreeNode* node, string path) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            path += to_string(node->val);
            result.push_back(path);
        }

        if (node->left) {
            traverse(node->left, path + to_string(node->val) + "->");
        }

        if (node->right) {
            traverse(node->right, path + to_string(node->val) + "->");
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        traverse(root, path);
        return result;
    }
};

