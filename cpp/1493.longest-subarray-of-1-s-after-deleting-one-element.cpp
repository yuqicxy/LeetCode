/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int j = 0 , i = 0;
        for(; i < nums.size(); ++i){
            if(nums[i] == 0)
                k--;
            if(k < 0 && nums[j++] == 0)
                k++;
        }
        return i - j - 1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{1,1,0,1};
    cout << s.longestSubarray(nums) << endl; //3
    nums = {0,1,1,1,0,1,1,0,1};
    cout << s.longestSubarray(nums) << endl; //5
    return 0;
}

