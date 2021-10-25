/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
private:
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        int size = nums.size();
        unordered_multimap<int,size_t> hashmap;
        for(size_t i = 0; i < size ; ++i)
            hashmap.emplace(nums.at(i),i);
        for(size_t i = 0; i < size - 2; ++i){
            int sum2target = 0 - nums.at(i);
            for(size_t j = i + 1 ; j < size - 1; ++j){
                int finalTarget = sum2target - nums.at(j);
                auto range = hashmap.equal_range(finalTarget);
                for_each(range.first,range.second,[&](const pair<int,size_t> &pair){
                    if(pair.second > j)
                        results.push_back({nums.at(i), nums.at(j), pair.first});
                });
            }
        }
        return results;
    }

};
// @lc code=end

