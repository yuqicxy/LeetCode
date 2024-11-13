/*
 * @lc app=leetcode id=2563 lang=cpp
 *
 * [2563] Count the Number of Fair Pairs
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        long long ans = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            auto lowerItr = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto upperItr = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            ans += distance(lowerItr, upperItr);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{0,1,7,4,4,5};
    cout << s.countFairPairs(nums, 3, 6) << endl;

    nums = {1,7,9,2,5};
    cout << s.countFairPairs(nums, 11, 11) << endl;
    return 0;
}