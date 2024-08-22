/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
#include <vector>
using namespace std;
//fast slow pointers
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        using Index = vector<int>::size_type;
        Index slow = 0;
        Index fast = 0;
        for(;fast < nums.size(); fast++){
            if(nums[slow] == 0 && nums[fast] != 0)
                swap(nums[slow],nums[fast]);
            if(nums[slow] != 0)
                slow++;
        }
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums{0,1,0,3,12};
    // vector<int> nums{1,0,1};
    s.moveZeroes(nums);
    return 0;
}
