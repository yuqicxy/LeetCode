/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unsigned int size = nums.size();
        unordered_set<int> set;
        int j = 0;
        for(int i = 0; i < size; ++i){
            if(std::abs(i - j) > k) {
                set.erase(nums[j]);
                j++;
            }
            if(set.count(nums[i]) > 0)
                return true;
            set.emplace(nums[i]);
        }
        return false;
    }
};
// @lc code=end

