/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */
#include <vector>
#include <stack>
#include <tuple>
#include <iostream>
#include <map>

using namespace std;

class TwoPointerSolution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> maxList(nums.size(), 0);
        maxList.back() = nums.back();
        for(int i = maxList.size() - 2; i >= 0; --i){
            maxList[i] = max(maxList[i + 1], nums[i]);
        }

        int left = 0, right = 0;
        int ans = 0;
        while(right < nums.size()){
            while(left < right && nums[left] > maxList[right])
                left++;
            ans = max(ans, right-left);
            right++;
        }
        return ans;
    }
};

#include <algorithm>

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> indexes;
        for(int i = 0; i < nums.size(); ++i){
            indexes.push_back(i);
        }
        sort(indexes.begin(),indexes.end(), [&nums](int left, int right){
            return nums[left] < nums[right];
        });

        int ans = 0, mn=INT_MAX;
        for(int i = 0; i < nums.size(); ++i){
            ans = max(ans, indexes[i] - mn);
            mn = min(mn, indexes[i]);
        }

        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    auto nums = vector<int>{6,0,8,2,1,5};
    cout << s.maxWidthRamp(nums) << endl;
    nums = vector<int>{9,8,1,0,1,9,4,0,4,1};
    cout << s.maxWidthRamp(nums) << endl;
}