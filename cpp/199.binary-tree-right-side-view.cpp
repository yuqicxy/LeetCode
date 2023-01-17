/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * @brief BFS
     * 
     * @param root 
     * @return vector<int> 
     */
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> results;
    //     typedef pair<int,TreeNode*> DepthTreeNode; 
    //     stack<DepthTreeNode> stk;
    //     if(root)
    //         stk.push({1,root});
    //     while(!stk.empty()){
    //         auto &&n = stk.top();
    //         int currDepth = n.first;
    //         TreeNode* node = n.second;
    //         stk.pop();
    //         if(results.size() < currDepth)
    //             results.push_back(node->val);
    //         if(node->left)
    //             stk.push({currDepth + 1,node->left});
    //         if(node->right)
    //             stk.push({currDepth + 1,node->right});
    //     }
    //     return results;
    // }

    /**
     * @brief DFS
     * 
     */
    vector<int> rightSideView(TreeNode* root){
        vector<int> results;
        recursive(root,0,results);
        return results;
    }

    void recursive(TreeNode *root, int level, vector<int> &results){
        if(root == nullptr) 
            return;
        if(level == results.size())
            results.push_back(root->val);
            
        recursive(root->right,level + 1,results);
        recursive(root->left,level + 1,results);
    }

};
// @lc code=end

