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
        if(size < 3) return results;
        std::sort(nums.begin(),nums.end());
        for(size_t i = 0; i < size; ++i){
            if(nums.at(i) > 0) break;
            if(i == 0 || (i > 0 && nums.at(i) != nums.at(i - 1))){
                size_t lower_bound = i + 1;
                size_t upper_bound = size - 1;
                int sum = 0 - nums.at(i);
                while(lower_bound < upper_bound){
                    if(nums[lower_bound] + nums[upper_bound] == sum){
                        results.push_back({nums.at(i),nums.at(lower_bound),nums.at(upper_bound)});
                        while(lower_bound < upper_bound && nums[lower_bound] == nums[lower_bound + 1]){
                            lower_bound++;
                        }
                        while(lower_bound < upper_bound && nums[upper_bound - 1] == nums[upper_bound]){
                            upper_bound--;
                        }
                        lower_bound++;
                        upper_bound--;
                    }
                    else if(nums[lower_bound] + nums[upper_bound] < sum){
                        lower_bound++;
                    }
                    else{
                        upper_bound--;
                    }
                }
            }
        }
        return results;
    }

};
// @lc code=end

