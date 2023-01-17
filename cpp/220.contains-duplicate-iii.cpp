/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unsigned int size = nums.size();
        set<int64_t> set;
        int j = 0;
        for(int i = 0; i < size; ++i){
            if(std::abs(i - j) > k) {
                set.erase(nums[j]);
                j++;
            }
            int64_t diff = static_cast<int64_t>(nums[i]) - static_cast<int64_t>(t);
            auto pos = set.lower_bound(diff);
            int64_t compare = (static_cast<int64_t>(*pos) - static_cast<int64_t>(nums[i]));
            if(pos != set.end() && compare <= t)
                return true;
            set.emplace(nums[i]);
        }
        return false;
    }
};
// @lc code=end

