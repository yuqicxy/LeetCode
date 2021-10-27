/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t numsSize = nums.size();
        vector<int> dp(numsSize,0);
        int max = numeric_limits<int>::min();
        for(size_t i = 0; i < numsSize; ++i){
            dp[i] = nums.at(i);
            max = (dp[i] > max) ? dp[i] : max;
            for(size_t j = i + 1; j < numsSize; ++j){
                dp[j] = dp[j-1] + nums.at(j);
                max = (dp[j] > max) ? dp[j] : max;
            }
        }
        return max;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> input= {1,-12,3,-4,5,-21};
    cout<<s.maxSubArray(input);
    return 1;
}