/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int previousRob = 0;
        int prePreviousRob = 0;
        size_t size = nums.size();
        for(size_t i = 0; i < size; ++i){
            int currentRob = max(previousRob,prePreviousRob + nums[i]);
            prePreviousRob = previousRob;
            previousRob = currentRob;
        }
        return previousRob;
    }
};
// @lc code=end

