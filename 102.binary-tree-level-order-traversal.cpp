/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if(root == nullptr) return results;
        queue<TreeNode*> nodeInLevel;
        nodeInLevel.push(root);
        while(!nodeInLevel.empty()){
            vector<int> result;
            int queueSize = nodeInLevel.size();
            for(unsigned i = 0; i < queueSize; ++i){
                TreeNode *node = nodeInLevel.front();
                nodeInLevel.pop();
                if(node->left)
                    nodeInLevel.push(node->left);
                if(node->right)
                    nodeInLevel.push(node->right);
                result.push_back(node->val);
            }
            if(!result.empty())
                results.push_back(result);
        }
        return results;
    }
};
// @lc code=end

