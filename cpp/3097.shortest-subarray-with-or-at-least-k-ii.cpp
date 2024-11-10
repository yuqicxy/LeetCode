/*
 * @lc app=leetcode id=3097 lang=cpp
 *
 * [3097] Shortest Subarray With OR at Least K II
 */
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int bits[32]{};
        int cur = 0;
        int j = 0;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            cur |= nums[i];
            for(int b = 0; b < 32; ++b){
                if(nums[i] & (1 << b))
                    bits[b] = i;
            }
            while(cur >= k and j <= i){
                ans = min(ans, i - j + 1);
                for(int b = 0; b < 32; ++b){
                    if((nums[j] & (1 << b))  && bits[b] == j){
                        bits[b] = -1;
                        cur ^= 1 << b;
                    }
                }
                j++;
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{1,2,3};
    cout << s.minimumSubarrayLength(nums, 2) << endl; 
    nums = {2,1,8};
    cout << s.minimumSubarrayLength(nums, 10) << endl;
    nums = {1,2};
    cout << s.minimumSubarrayLength(nums, 0) << endl;
    return 0;
}
