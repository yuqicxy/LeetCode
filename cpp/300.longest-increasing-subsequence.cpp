/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <vector>
#include <algorithm>

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            auto itr = lower_bound(begin(res), end(res), nums[i]);
            if(itr == res.end())
                res.push_back(nums[i]);
            else
                *itr = nums[i];
        }
        return res.size();
    }
};
// @lc code=end

