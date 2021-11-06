/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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

#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief use BST tree attribute:
     * 
     *  leftChild <= parent <- rightChild
     * 
     * @param root 
     * @param p 
     * @param q 
     * @return TreeNode* 
     */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            int min = std::min(p->val,q->val);
            int max = std::max(p->val,q->val);
            if(root->val <= max && root->val >= min)
                return root;
            if(root->val > max)
                root = root->left;
            else
                root = root->right;
        }
        return nullptr;
    }
};
// @lc code=end

