/*
 * @lc app=leetcode id=2501 lang=cpp
 *
 * [2501] Longest Square Streak in an Array
 */
#include <unordered_map>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

class StupidSolution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> dp;
        transform(nums.begin(), nums.end(), 
            std::inserter(dp,dp.begin()), 
            [](int i){
                return pair<int,int>{i, 0};
            }
        );
        
        int ans = 1;
        for(auto num : nums)
            ans = max(ans, updateDP(dp, num));

        return ans == 1 ? -1 : ans;
    }


    int updateDP(unordered_map<int,int> &dp, int num){
        auto itr = dp.find(num);
        if(itr != dp.end()){
            if(itr->second == 0){
                int _sqrt = static_cast<int>(sqrt(num));
                if(_sqrt * _sqrt == num){
                    itr->second = 1 + updateDP(dp, _sqrt);
                }
                else{
                    itr->second = 1;
                }
            }
            return itr->second;
        }
        return 0;
    }
};

// @lc code=start
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        unordered_map<int,int> mp;
        for(auto num : nums){
            int sqrtNum = static_cast<int>(sqrt(num));
            if(sqrtNum * sqrtNum == num && mp.contains(sqrtNum)){
                mp[num] = mp[sqrtNum] + 1;
                ans = max(ans, mp[num]);
            }else{
                mp[num] = 1;
            }
        }
        return ans;
    }
};
// @lc code=end
#include <iostream>

int main(){
    Solution s;
    vector nums{4,3,6,16,8,2};
    cout << s.longestSquareStreak(nums) << endl;
    nums = {2,3,5,6,7};
    cout << s.longestSquareStreak(nums) << endl;
}