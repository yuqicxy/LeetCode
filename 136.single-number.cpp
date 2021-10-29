/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
public:
    // XOR method
    // For [2,2,1]
    // 0 ^ 2 = 2; 2 ^ 2 = 0; 0 ^ 1 = 1
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int val : nums)
            result = result ^ val;
        return result;
    }
};
// @lc code=end

