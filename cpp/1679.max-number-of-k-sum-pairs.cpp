/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        size_t i = 0, j = nums.size() - 1;
        int ans = 0;
        while(i < j){
            int val = nums[i] + nums[j];
            if(val > k){
                j--;
            }else if(val < k){
                i++;
            }else{
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end
#include <iostream>
int main(){
    Solution s;
    vector nums{1,2,3,4};
    cout << s.maxOperations(nums, 5) << endl;
    nums = {3,1,3,4,3};
    cout << s.maxOperations(nums, 6) << endl;
}