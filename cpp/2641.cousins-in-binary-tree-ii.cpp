/*
 * @lc app=leetcode id=2641 lang=cpp
 *
 * [2641] Cousins in Binary Tree II
 */
#include "common/TreeNode.h"
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int sz = queue.size();
            long long sum = 0;
            vector<TreeNode*> subNodes;
            while(sz--){
                TreeNode* nd = queue.front();
                queue.pop();
                if(nd->left != nullptr){
                    queue.push(nd->left);
                    sum += nd->left->val;
                }
                if(nd->right != nullptr){
                    queue.push(nd->right);
                    sum += nd->right->val;
                }
                subNodes.push_back(nd);
            }

            for_each(subNodes.begin(), subNodes.end(), [sum](TreeNode* nd){
                long long tmp = sum;
                if(nd->left != nullptr)
                    tmp -= nd->left->val;
                if(nd->right != nullptr)
                    tmp -= nd->right->val;
                if(nd->left != nullptr)
                    nd->left->val = tmp;
                if(nd->right != nullptr)
                    nd->right->val = tmp;
            });
        }
        return root;
    }
};
// @lc code=end

int main(){
    Solution s;
    TreeNode *node = new TreeNode({
        5, 4, 9, 1, 10, 0, 7
    });
    s.replaceValueInTree(node);
}

