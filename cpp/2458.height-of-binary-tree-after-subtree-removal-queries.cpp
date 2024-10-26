/*
 * @lc app=leetcode id=2458 lang=cpp
 *
 * [2458] Height of Binary Tree After Subtree Removal Queries
 */
#include "common/TreeNode.h"
#include <queue>
#include <vector>
#include <array>

using namespace std;
class StupidSolution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); ++i){
            ans[i] = treeQuery(root, queries[i]);
        }
        return ans;
    }

    int treeQuery(TreeNode* root, int query){
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            bool flag = sz == 1;
            while(sz--){
                auto node = q.front();
                q.pop();
                if(node->val != query){
                    if(node->left != nullptr)
                        q.push(node->left);
                    if(node->right != nullptr)
                        q.push(node->right);
                }else if(flag){
                    lvl--;
                }
            }
            ++lvl;
        }
        return lvl - 1;
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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        maxDepth = 0;
        preOrder(root, 0);
        maxDepth = 0;
        postOrder(root, 0);

        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); ++i){
            ans[i] = max(preOrderArr[queries[i]], postOrderArr[queries[i]]);
        }
        return ans;
    }

    void preOrder(TreeNode* root, int depth){
        if(root == nullptr)
            return;
        preOrderArr[root->val] = maxDepth;
        maxDepth = max(maxDepth, depth);
        preOrder(root->left, depth + 1);
        preOrder(root->right, depth + 1);
    }

    void postOrder(TreeNode* root, int depth){
        if(root == nullptr)
            return;
        postOrderArr[root->val] = maxDepth;
        maxDepth = max(maxDepth, depth);
        postOrder(root->right, depth + 1);
        postOrder(root->left, depth + 1);
    }

private:
    int maxDepth = 0;
    array<int, 100001> preOrderArr;
    array<int, 100001> postOrderArr;
};
// @lc code=end
#include <iostream>
int main(){
    TreeNode *root = new TreeNode({5,8,9,2,1,3,7,4,6});
    Solution s;
    vector<int> queries{3,2,4,8};
    auto ans = s.treeQueries(root,queries);
    for (auto &&i : ans)
        cout << i << endl;
    return 0;
}
