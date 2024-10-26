/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
            pathSumTraverse(root, targetSum);
        }
        return ans;
    }

    void pathSumTraverse(TreeNode* root, long long targetSum) {
        if(root == nullptr) return;
        if(root->val == targetSum)
            ans++;
        pathSumTraverse(root->left, targetSum - root->val);
        pathSumTraverse(root->right, targetSum - root->val);
    }
private:
    int ans = 0;
};
// @lc code=end

