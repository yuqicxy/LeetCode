/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 * Algorithm: A Linear Time Majority Vote Algorithm(https://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html)
 * Leetcode:https://leetcode.com/problems/majority-element/
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        size_t size = nums.size();
        int value;
        size_t times = 0;
        for_each(nums.begin(),nums.end(),[&](int num){
            if(times < 1){
                times = 1;
                value = num;
            }
            else if(value != num)
                times--;
            else
                times++;
        });
        return value;
    }
};
// @lc code=end