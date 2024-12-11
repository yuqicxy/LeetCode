/*
 * @lc app=leetcode id=2779 lang=cpp
 *
 * [2779] Maximum Beauty of an Array After Applying Operation
 */


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        for(; j < N; ++j){
            if(nums[j] - nums[i] > 2*k){
                i++;
            }
        }
        return j - i;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{48,93,96,19};
    cout << s.maximumBeauty(nums, 24) << endl; //3
    nums={4,6,1,2};
    cout << s.maximumBeauty(nums, 2) << endl; //3
    nums = {1,1,1,1};
    cout << s.maximumBeauty(nums, 10) << endl; //4
    nums = {100000};
    cout << s.maximumBeauty(nums, 0) << endl; //1
}