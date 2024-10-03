/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sumReminder = accumulate(nums.begin(), nums.end(), 0, 
            [&](const int &init, const int &val){
                return (init + val) % p;
            }
        );
        unordered_map<int, int> mHash{{0,-1}};
        int curr = 0 , res = INT_MAX;
        for (auto i = 0;i < nums.size(); ++i)
        {
            curr = (curr + nums[i]) % p;
            mHash[curr] = i;
            int want = (curr - sumReminder + p) % p;
            if(mHash.count(want))
                res = min(res, i - mHash[want]);
        }
        return res < nums.size() ? res : -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums{3,1,4,2};
    cout << s.minSubarray(nums, 6) << endl;
    nums = {6,3,5,2};
    cout << s.minSubarray(nums, 9) << endl;
    nums = {1000000000,1000000000,1000000000};
    cout << s.minSubarray(nums, 3) << endl;
    return 0;
}