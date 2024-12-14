/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

#include <map>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> s;
        int  i = 0, j = 0;
        long long ans = 0;
        while(j < nums.size()){
            s[nums[j]]++;
            while(i < j && abs(s.cbegin()->first - s.crbegin()->first) > 2){
                s[nums[i]]--;
                if(s[nums[i]] == 0)
                    s.erase(nums[i]);
                ++i;
            }
            ans += (j - i + 1);
            ++j;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{5,4,2,4};
    cout << s.continuousSubarrays(nums) << endl;
    nums = {1,2,3};
    cout << s.continuousSubarrays(nums) << endl;
}