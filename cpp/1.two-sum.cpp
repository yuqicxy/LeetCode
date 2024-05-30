/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_multimap<int,int> hashmap;
        for(unsigned int i =0; i < nums.size(); ++i)
            hashmap.emplace(nums.at(i),i);
        for(auto &&i : hashmap){
            int val = target - i.first;
            auto &&range = hashmap.equal_range(val);
            for(auto findItr = range.first; findItr != range.second; ++findItr){
                if(findItr->second != i.second){
                    result.push_back(i.second);
                    result.push_back(findItr->second);
                    return result;
                }
            }
        }
        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    auto nums = std::vector<int>({2,7,11,15});
    s.twoSum(nums,9);
}