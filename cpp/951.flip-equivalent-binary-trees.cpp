/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
 */

#include "common/TreeNode.h"

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == root2)
            return true;
        if(root1 == nullptr || root2 == nullptr)
            return false;
        if(root1->val == root2->val){
            bool ans = true;
            if(root1->left != nullptr){
                if(root2->left == nullptr || root1->left->val != root2->left->val){
                    //exchange
                    swap(root1->left, root1->right);
                }
            }else if(root1->right != nullptr){
                if(root2->right == nullptr || root1->right->val != root2->right->val){
                    swap(root1->left, root1->right);
                }
            }
            ans = ans && flipEquiv(root1->left, root2->left);
            ans = ans && flipEquiv(root1->right, root2->right);
            return ans;
        }
        return false;
    }
};
// @lc code=end

int main(){
    TreeNode *tree1 = new TreeNode({1,2,3,4,5,6,7});
    TreeNode *tree2 = new TreeNode({1,3,2,7,6,4,5});
    Solution s;
    s.flipEquiv(tree1, tree2);
}

