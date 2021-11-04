/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief 
     *  
     *  1 2 3 4 5 6 7   size = 7   k = 3  start = 0
     *  5 6 7 4 1 2 3   size = 4   k = 3  start = 3
     *  因此问题简化为 [4 1 2 3] k = 3 =>> [1 2 3 4]
     *  
     *  当k > nums.size() 时,问题等价于 k = k % nums.size()
     * 
     * 
     * @param nums 
     * @param k 
     */
    // void rotate(vector<int>& nums, int k) {
    //     int size = nums.size();
    //     int start = 0;
    //     k = k % size;
    //     for(;(k = k % size) != 0; size -= k, start += k){
    //         for(unsigned i = 0;i < k; ++i){
    //             swap(nums[start + i],nums[size - k + i + start]);
    //         }
    //     }
    // }

    /**
     * @brief 
     *                1 2 3 4 5 6 7
     *  1st reverse   4 3 2 1 5 6 7
     *  2nd reverse   4 3 2 1 7 6 5
     *  3rd reverse   5 6 7 1 2 3 4
     * 
     * @param nums 
     * @param k 
     */
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(),nums.end());
    }
};
// @lc code=end