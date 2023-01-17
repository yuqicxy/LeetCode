/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int start = 0;
        for(;(k = k % size) != 0; size -= k, start += k){
            for(unsigned i = 0;i < k; ++i){
                swap(nums[start + i],nums[size - k + i + start]);
            }
        }
    }
};
// @lc code=end

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int k = 38;
    Solution s;
    s.rotate(nums,k);
}