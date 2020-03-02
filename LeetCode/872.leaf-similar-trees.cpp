/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (64.41%)
 * Total Accepted:    65.6K
 * Total Submissions: 101.6K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree.  From left to right order, the
 * values of those leaves form a leaf value sequence.
 * 
 * 
 * 
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 * 
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 * 
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Both of the given trees will have between 1 and 100 nodes.
 * 
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
    void postOrder(TreeNode* root, vector<int>& leafs) {

        if (!root) {
            return;
        }
        postOrder(root->left, leafs);
        postOrder(root->right, leafs);
        if (!root->left && !root->right) {
            leafs.push_back(root->val);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leafs1;
        vector<int>leafs2;

        postOrder(root1, leafs1);
        postOrder(root2, leafs2);

        int N = leafs1.size();
        if (N != leafs2.size()) {
            return false;
        }

        for (int i = 0; i < N; i++) {
            if (leafs1[i] != leafs2[i]) {
                return false;
            }
        }
        return true;
    }
};

