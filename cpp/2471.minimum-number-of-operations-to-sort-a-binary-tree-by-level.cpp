/*
 * @lc app=leetcode id=2471 lang=cpp
 *
 * [2471] Minimum Number of Operations to Sort a Binary Tree by Level
 */

#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
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
    int minimumOperations(TreeNode* root) {
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        int ans = 0;
        while(!nodes.empty()){
            vector<TreeNode*> nodesAtNextLevel;
            vector<int> nums;
            for(auto node : nodes){
                nums.push_back(node->val);
                if(node->left){
                    nodesAtNextLevel.push_back(node->left);
                }
                if(node->right){
                    nodesAtNextLevel.push_back(node->right);
                }
            }
            ans += countMinimumOper(nums);
            swap(nodes, nodesAtNextLevel);
        }
        return ans;
    }

    int countMinimumOper(const vector<int>& nums){
        const int N = nums.size();
        vector<int> ids(N);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&nums](int left, int right){
            return nums[left] < nums[right];
        });
        int count = 0;
        for(int i = 0; i < N; ++i){
            while(ids[i] != i){
                count++;
                swap(ids[i], ids[ids[i]]);
            }
        }
        return count;
    }
};
// @lc code=end

int main(){
    Solution s;
    TreeNode *tree1 = new TreeNode({1,3,2,7,6,5,4});
    cout << s.minimumOperations(tree1) << endl; //3
    TreeNode *tree2 = new TreeNode({1,4,3,7,6,8,5});
    cout << s.minimumOperations(tree2) << endl; //3
    TreeNode *tree3 = new TreeNode({1,2,3,4,5,6});
    cout << s.minimumOperations(tree3) << endl; //0
}

