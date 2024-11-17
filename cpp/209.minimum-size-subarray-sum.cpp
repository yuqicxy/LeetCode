/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, ans = INT_MAX;
        for(;right < nums.size(); ++right){
            target -= nums[right];
            while(target <= 0){
                ans = min(ans, right - left + 1);
                target += nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{2,3,1,2,4,3};
    cout << s.minSubArrayLen(7,nums) << endl;
    nums = {1,4,4};
    cout << s.minSubArrayLen(4,nums) << endl;
    nums = {1,1,1,1,1,1,1,1};
    cout << s.minSubArrayLen(11,nums) << endl;
}