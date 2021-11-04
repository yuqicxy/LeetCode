/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto itr = nums.begin() + k - 1;
        nth_element(nums.begin(),itr,nums.end(),std::greater<int>());
        return *(itr);
    }
};
// @lc code=end