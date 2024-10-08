#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return helper(nums,0,nums.size() - 1);
    }

    TreeNode *helper(vector<int>& nums, int low, int high){
        if(low > high)
            return nullptr;

        int mid = (low + high)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = helper(nums,low,mid - 1);
        node->right = helper(nums,mid + 1,high);
        return node;
    }
};

int main(){
    vector<int> nums = {-10,-3,0,5,9};
    Solution s;
    TreeNode* node = s.sortedArrayToBST(nums);
    return 1;
}