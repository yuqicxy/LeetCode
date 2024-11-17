/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> mq;
        long* B = new long[nums.size()];
        B[0] = nums[0];
        int ans = INT_MAX;
        for(int right = 0; right < nums.size(); ++right){
            if(right > 0)
                B[right] = B[right - 1] + nums[right];
            
            if(B[right] >= k)
                ans = min(ans, right + 1);
            
            while(!mq.empty() && B[right] - B[mq.front()] >= k){
                ans = min(ans, right - mq.front());
                mq.pop_front();
            }

            while(!mq.empty() && B[right] <= B[mq.back()]){
                mq.pop_back();
            }

            mq.push_back(right);
        }
        delete []B;
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    
    vector nums{1};
    cout << s.shortestSubarray(nums, 1)<< endl;

    nums = {1,2};
    cout << s.shortestSubarray(nums, 4)<< endl;

    nums={2,-1,2};
    cout << s.shortestSubarray(nums, 3) << endl;

    return 0;
}
