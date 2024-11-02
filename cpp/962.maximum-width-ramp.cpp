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
        sort(indexes.begin(),indexes.end(), [&](int left, int right){
            if(nums[left] < nums[right]) return true;
            //Add additional rule for the duplicate number, make sure the lower index appear firstly.
            else if(nums[left] == nums[right]) return left < right; 
            return false;
        });

        int ans = 0;
        int mn = nums.size();
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
    // auto nums = vector<int>{6,0,8,2,2,1,5,1};
    // cout << s.maxWidthRamp(nums) << endl;
    // nums = vector<int>{9,8,1,0,1,9,4,0,4,1};
    // cout << s.maxWidthRamp(nums) << endl;
    
    auto nums = vector<int>{
        3 ,28,15,1 ,4 ,
        12,6 ,19,8 ,15,
        3 ,9 ,6 ,4 ,13,
        12,6 ,12,10,1 ,
        2 ,1 ,4 ,1 ,4 ,
        0 ,0 ,1 ,1 ,0 };

    nums = vector<int>{3,28,15,1,4,12,6,19,8,15,3,9,6,4,13,12,6,12,10,1,2,1,4,1,4,0,0,1,1,0};

    cout << s.maxWidthRamp(nums) << endl; //25
}