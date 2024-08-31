/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 */

#include "common/TreeNode.h"
#include <deque>

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
    TreeNode* searchBST(TreeNode* root, int val) {
        std::deque<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty()){
            auto currNode = queue.front();
            if(currNode->val == val)
                break;
            if(currNode->left)
                queue.push_back(currNode->left);
            if(currNode->right)
                queue.push_back(currNode->right);
            queue.pop_front();
        }
        return !queue.empty() ? queue.front() : nullptr;
    }
};
// @lc code=end


int main(){
    TreeNode* node = new TreeNode{4,2,7,1,3};
    Solution s;
    auto result = s.searchBST(node, 5);
    return 0;
}

