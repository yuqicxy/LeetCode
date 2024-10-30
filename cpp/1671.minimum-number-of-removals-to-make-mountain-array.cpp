/*
 * @lc app=leetcode id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <ranges>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int N = static_cast<int>(nums.size());
        int maxFound = 0;
        for(int i = 1; i < N - 1; i++){
            vector<int> left;
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i])
                    left.push_back(nums[j]);
            }
            left.push_back(nums[i]);
            vector<int> right;
            right.push_back(nums[i]);
            for(int j = i + 1; j < N; ++j){
                if(nums[i] > nums[j])
                    right.push_back(nums[j]);
            }
            int ls = lengthofLIS(left.begin(),  left.end(), less<int>{});
            int rs = lengthofLIS(right.begin(), right.end(), greater<int>{});
            if(ls > 1 && rs > 1){
                int count = ls + rs - 1;
                maxFound = max(maxFound, count);
            }
        }
        return N - maxFound;
    }

    template<typename _RanIt, typename _Pr>
    int lengthofLIS(_RanIt first, _RanIt last, _Pr pred){
        vector<int> res;
        for(auto itr = first; itr != last; ++itr){
            auto index = lower_bound(res.begin(), res.end(), *itr, pred);
            if(index == res.end())
                res.push_back(*itr);
            else
                *index = *itr;
        }
        return static_cast<int>(res.size());
    }
};
// @lc code=end
int main(){
    Solution s;
    vector nums{1,3,1};
    cout << s.minimumMountainRemovals(nums) << endl; //0
    nums = {2,1,1,5,6,2,3,1};
    cout << s.minimumMountainRemovals(nums) << endl; //3
    nums = {4,3,2,1,1,2,3,1};
    cout << s.minimumMountainRemovals(nums) << endl;  //4
    nums = {1,2,3,4,4,3,2,1};
    cout << s.minimumMountainRemovals(nums) << endl;  //1
    nums = {9,8,1,7,6,5,4,3,2,1};
    cout << s.minimumMountainRemovals(nums) << endl;  //2
    nums = {100,92,89,77,74,66,64,66,64};
    cout << s.minimumMountainRemovals(nums) << endl;  //6
    return 0;
}