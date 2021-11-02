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
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(--k == 0)
                break;
            root = root->right;
        } 
        return root->val;
    }

    TreeNode* buildTree(vector<string> list){
        queue<TreeNode*> queue;
        TreeNode* root = new TreeNode(stoi(list.front()));
        queue.push(root);
        for(unsigned i = 1; i < list.size();){
            TreeNode* curr = queue.front();
            queue.pop();
            if(curr == nullptr){
                i = i + 2;
                continue;
            }
            if(list[i] != "null"){
                curr->left = new TreeNode(stoi(list[i]));
            }else
                curr->left = nullptr;
            queue.push(curr->left);
            ++i;

            if(i < list.size()){
                if(list[i] != "null"){
                    curr->right = new TreeNode(stoi(list[i]));
                }
                else
                    curr->right = nullptr;
                queue.push(curr->right);
                ++i;
            }
        }
        return root;
    }
};

int main(){
    Solution s;
    TreeNode* root = s.buildTree({"5","3","6","2","4","null","null","1"});
    cout<<s.kthSmallest(root,3);
    return 1;
}