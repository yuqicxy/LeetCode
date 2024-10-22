/*
 * @lc app=leetcode id=2583 lang=cpp
 *
 * [2583] Kth Largest Sum in a Binary Tree
 */
#include "common/TreeNode.h"
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
#include <queue>
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> ans;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            size_t sz = nodeQueue.size();
            long long sum = 0;
            while(sz--){
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if(node->left != nullptr)
                    nodeQueue.push(node->left);
                if(node->right != nullptr)
                    nodeQueue.push(node->right);
                sum += node->val;
            }
            ans.push(sum);
            if(ans.size() > k)
                ans.pop();
        }
        if(ans.size() < k)
            return -1;
        return ans.top();
    }
};
// @lc code=end

int main(){
    TreeNode* root = new TreeNode({5,8,9,2,1,3,7,4,6});
    Solution s;
    cout << s.kthLargestLevelSum(root,2) << endl;
    delete root;
}

