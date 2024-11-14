/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size() - 1;
        while(lower < upper){
            auto mid = (lower + upper)/2;
            if(nums[mid] < nums[mid + 1])
                lower = mid + 1;
            else
                upper = mid;
        }
        return lower;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{1,2,3,1};
    cout << s.findPeakElement(nums) << endl;
    nums = {1,2,1,3,5,6,4};
    cout << s.findPeakElement(nums) << endl;
    return 0;
}