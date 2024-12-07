/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = 1e9;
        while(left < right){
            int mid = (left + right) / 2;
            int count = 0;
            for(int num : nums)
                count += (num - 1) / mid;
            if(count > maxOperations){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{9};
    cout << s.minimumSize(nums, 2) << endl;
    nums = {2,4,8,2};
    cout << s.minimumSize(nums, 4) << endl;
}