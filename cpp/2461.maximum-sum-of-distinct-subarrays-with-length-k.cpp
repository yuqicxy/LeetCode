/*
 * @lc app=leetcode id=2461 lang=cpp
 *
 * [2461] Maximum Sum of Distinct Subarrays With Length K
 */
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        const size_t N = nums.size();
        long long ans = 0;
        long long subarraySum = 0;
        unordered_map<int, int> set;
        for(int i = 0; i < N; ++i){
            set[nums[i]]++;
            subarraySum += nums[i];
            if(i >= k){
                subarraySum -= nums[i - k];
                set[nums[i - k]]--;
                if(set[nums[i - k]] <= 0)
                    set.erase(nums[i - k]);
            }
            if(set.size() == k)
                ans = max(ans, subarraySum);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{1,5,4,2,9,9,9};
    cout << s.maximumSubarraySum(nums, 3) << endl; //15

    nums={4,4,4};
    cout << s.maximumSubarraySum(nums, 3) << endl; //0

    nums = {1,1,1,7,8,9};
    cout << s.maximumSubarraySum(nums, 3) << endl; //24

    nums = {9,9,9,1,2,3};
    cout << s.maximumSubarraySum(nums, 3) << endl; //12

    nums = {5,3,3,1,1};
    cout << s.maximumSubarraySum(nums, 3) << endl; //0

    return 0;
}