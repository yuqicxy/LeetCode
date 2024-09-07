/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */
#include "common/TreeNode.h"
#include <tuple>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else{
            if(root->left == nullptr){
                return root->right;
            }else if(root->right == nullptr){
                return root->left;
            }else{
                int maxInleft = maxInSubTree(root->left);
                root->left = deleteNode(root->left,maxInleft);
                root->val = maxInleft;
            }
        }
        return root;
    }

    int maxInSubTree(TreeNode* node){
        if(node->right != nullptr)
            return maxInSubTree(node->right);
        return node->val;
    }
};
// @lc code=end

int main(){
    TreeNode node{5,3,6,2,4};
    Solution s;
    TreeNode* result = s.deleteNode(&node,5);
}

