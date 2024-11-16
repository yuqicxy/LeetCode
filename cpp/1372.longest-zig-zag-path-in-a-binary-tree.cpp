/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 */
#include <stack>
#include <tuple>
#include"common/TreeNode.h"
using namespace std;


class IterativeSolution {
public:
    int longestZigZag(TreeNode* root) {
       int ans = 0;
        stack<TreeNode*> stk;
        stack<tuple<int,int>> countStk;
        stk.push(root);
        countStk.push({0,0});
        while(!stk.empty()){
            TreeNode* curr = stk.top();
            int left, right;
            tie(left,right) = countStk.top();
            stk.pop();
            countStk.pop();
            if(curr->left){
                stk.push(curr->left);
                countStk.push({0, left + 1});
                ans = max(ans, left + 1);
            }
            if(curr->right){
                stk.push(curr->right);
                countStk.push({right + 1, 0});
                ans = max(ans, right + 1);
            }
        }
        return ans;
    }
};

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
    int longestZigZag(TreeNode* root) {
        return dfs(root)[2];
    }

    vector<int> dfs(TreeNode* node){
        if(!node) return {-1,-1,-1};
        vector l = dfs(node->left);
        vector r = dfs(node->right);
        int ans = max(max(l[1], r[0]) + 1, max(l[2],r[2]));
        return {l[1] + 1, r[0] + 1, ans};
    }
};
// @lc code=end

