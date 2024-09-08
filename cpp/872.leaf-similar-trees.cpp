/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 */
#include <vector>
#include <stack>
#include "common/TreeNode.h"
using namespace std;
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
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> leaf1;
        getLeafNodeDFS(leaf1,root1);
        vector<TreeNode*> leaf2;
        getLeafNodeDFS(leaf2,root2);
        return leaf1 == leaf2;
    }

    void getLeafNodeDFS(vector<TreeNode*> &leafs, TreeNode* root){
        if(root->left != nullptr)
            getLeafNodeDFS(leafs, root->left);
        if(root->right != nullptr)
            getLeafNodeDFS(leafs, root->right);
        if(isLeaf(root))
            leafs.push_back(root);
    }

    bool isLeaf(TreeNode* node){
        if(node->left == nullptr && node->right == nullptr)
            return true;
        return false;
    }
};
// @lc code=end
