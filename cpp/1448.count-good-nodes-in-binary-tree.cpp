/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */
#include <functional>
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
    int goodNodes(TreeNode* root) {
        int goodNodeCount = 0;
        function<void(TreeNode*,int)> DFSearch = [&](TreeNode* node, int maxInpath){
            if(node == nullptr) return;
            if(node->val >= maxInpath){
                goodNodeCount++;
                maxInpath = node->val;
            }
            DFSearch(node->left,maxInpath);
            DFSearch(node->right,maxInpath);
        };

        DFSearch(root,INT_MIN);
        return goodNodeCount;
    }
};
// @lc code=end

