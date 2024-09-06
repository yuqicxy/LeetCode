/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */
#include <vector>
#include <iostream>
#include <queue>
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
using namespace std;
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int maxSum = INT_MIN;
        int maxLevel = 0;
        queue<vector<TreeNode*>> nodeQueue;
        nodeQueue.push({root});
        while(!nodeQueue.empty()){
            auto nodesSameLevel = nodeQueue.front();
            nodeQueue.pop();
            int sumLevel = 0;
            vector<TreeNode*> nodesNextLevel;
            for (auto node : nodesSameLevel){
                sumLevel += node->val;
                if(node->left != nullptr)
                    nodesNextLevel.push_back(node->left);
                if(node->right != nullptr)
                    nodesNextLevel.push_back(node->right);
            }
            if(!nodesNextLevel.empty()){
                nodeQueue.push(nodesNextLevel);
            }
            if(sumLevel > maxSum){
                maxSum = sumLevel;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};
// @lc code=end

int main(){
    Solution s;
    TreeNode root{1,7,0,7,-8};
    cout << s.maxLevelSum(&root) << endl;
    TreeNode root{1,7,0,7,-8};
    cout << s.maxLevelSum(&root) << endl;
    
}