/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0;
        for(unsigned int i = 0; i < nums.size(); ++i){
            totalSum -= nums[i];
            if(curr == totalSum)
                return i;
            else 
                curr += nums[i];
        }
        return -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums{1,7,3,6,5,6};
    cout << s.pivotIndex(nums) << endl;
    nums = {1,2,3};
    cout << s.pivotIndex(nums) << endl;
    nums = {2,1,-1};
    cout << s.pivotIndex(nums) << endl;
    return 0;
}