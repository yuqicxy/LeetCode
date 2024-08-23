/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */
#include <vector>
#include <numeric>
using namespace std;
//sliding window
// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size() < k)
            return accumulate(nums.begin(),nums.end(),0)/double(nums.size());

        int t = (int)nums.size() - k;
        int max = accumulate(nums.begin(),nums.begin() + k,0);
        int lastTmp = max;
        for(int i = 0; i < t; i++){
            lastTmp += nums[k + i] - nums[i];
            max = lastTmp > max ? lastTmp : max;
        }
        return max / double(k);
    }
};
// @lc code=end
int main(){
    vector<int> nums{0,4,0,3,2};
    const int &k = 1;
    Solution s;
    double&& res = s.findMaxAverage(nums,k);
    return 0;
}

