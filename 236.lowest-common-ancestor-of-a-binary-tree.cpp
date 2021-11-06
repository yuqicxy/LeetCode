/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return ancestor(root,p,q);
    }

    TreeNode* ancestor(TreeNode* root,TreeNode *p,TreeNode*q){
        if(root == p || root == q || root == nullptr)
            return root;
        TreeNode *parentP = ancestor(root->left,p,q);
        TreeNode *parentQ = ancestor(root->right,p,q);
        if(parentP && parentQ)
            return root;
        else
            return parentP ? parentP : parentQ;
    }
};
// @lc code=end

