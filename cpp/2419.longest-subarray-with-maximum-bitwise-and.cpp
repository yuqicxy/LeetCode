/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto max = *(max_element(nums.cbegin(),nums.cend()));

        int count = 0;
        int maxCount = 0;
        for(auto num : nums){
            if(num == max){
                count++;
                maxCount = count > maxCount ? count : maxCount;
            }else{
                count = 0;
            }
        }
        return maxCount;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.longestSubarray(vector{1,2,3,3,2,2}) << endl;
    cout << s.longestSubarray(vector{1,2,3,4}) << endl;
    cout << s.longestSubarray(vector{1,3,3,3}) << endl;

}

