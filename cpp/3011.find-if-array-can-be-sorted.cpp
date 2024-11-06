/*
 * @lc app=leetcode id=3011 lang=cpp
 *
 * [3011] Find if Array Can Be Sorted
 */

#include <bit>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int lastSegmentMax = INT_MIN;
        int segmentMax = INT_MIN, segmentMin = INT_MAX;
        int setBitNumber = 0;
        for(int i = 0; i < nums.size(); ++i){
            int tmp = popcount<unsigned int>(nums[i]);
            if(tmp != setBitNumber){
                setBitNumber = tmp;
                lastSegmentMax = segmentMax;
                segmentMax = nums[i];
                segmentMin = nums[i];
            }else{
                segmentMax = max(nums[i], segmentMax);
                segmentMin = min(nums[i], segmentMin);
            }
            if(segmentMin < lastSegmentMax)
                return false;
        }
        return true;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{8,4,2,30,15};
    cout << boolalpha;
    cout << s.canSortArray(nums) << endl; //t
    nums = {1,2,3,4,5};
    cout << s.canSortArray(nums) << endl; //t
    nums = {3,16,8,4,2};
    cout << s.canSortArray(nums) << endl; //t
    nums = {20,16}; 
    cout << s.canSortArray(nums) << endl; //t
    return 0;
}
