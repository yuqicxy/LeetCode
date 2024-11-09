/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */
#include <vector>
#include <iostream>

using namespace std;

ostream& operator<<(ostream &ss, const vector<int> &nums){
    ss << "[";
    for(auto num : nums)
        ss << num << ", ";
    ss << "]";
    return ss;
}

// @lc code=start
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorNums = 0;
        for(auto num : nums)
            xorNums ^= num;

        vector<int> ans(nums.size(), 0);
        int maximum = (1 << maximumBit) - 1;
        for(int i = 0; i < nums.size(); ++i){
            ans[i] = xorNums ^ maximum;
            xorNums ^= nums[nums.size() - i - 1];
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution s;
    vector nums{0,1,1,3};
    cout << s.getMaximumXor(nums, 2) << endl;
    nums = {2,3,4,7};
    cout << s.getMaximumXor(nums, 3) << endl;
    return 0;
}