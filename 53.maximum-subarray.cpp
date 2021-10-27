/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @brief brute force algorithm
     * 
     * @param nums 
     * @return int 
     */
    // int maxSubArray(vector<int>& nums) {
    //     size_t numsSize = nums.size();
    //     vector<int> dp(numsSize);
    //     int max = numeric_limits<int>::min();
    //     for(size_t i = 0; i < numsSize; ++i){
    //         dp[i] = nums.at(i);
    //         max = (dp[i] > max) ? dp[i] : max;
    //         for(size_t j = i + 1; j < numsSize; ++j){
    //             dp[j] = dp[j-1] + nums.at(j);
    //             max = (dp[j] > max) ? dp[j] : max;
    //         }
    //         dp.clear();
    //     }
    //     return max;
    // }

    /**
     * @brief Kadane's Algorithm
     * 
     * https://leetcode.com/problems/maximum-subarray/discuss/118509/C++-Kadane's-Algorithm
     * 
     * @param nums 
     * @return int 
     */
    int maxSubArray(vector<int>& nums) {
        int totalSum = 0; //local sum
        int globalSum = numeric_limits<int>::min(); //max total sum
        for(int val : nums){
            // compare current val with curr + totalsum
            totalSum = max(totalSum + val,val);
            // max total sum
            globalSum =  max(totalSum,globalSum);
        }
        return globalSum;
    }
};
// @lc code=end