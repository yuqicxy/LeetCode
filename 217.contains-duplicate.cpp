/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums){
            if(set.count(num) > 0) return true;
            set.emplace(num);
        }
        return false;
    }
};
// @lc code=end

