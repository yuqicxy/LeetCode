/*
 * @lc app=leetcode id=3254 lang=cpp
 *
 * [3254] Find the Power of K-Size Subarrays I
 */

#include<vector>
#include<iostream>
#include<queue>

using namespace std;

class StupidSolution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 1){
            ans.push_back(nums.front());
            return ans;
        }else if(k == 1){
            return nums;
        }
        queue<int> noneOrderEle;
        for(int i = 1, j = 0; i < nums.size(); ++i){
            if(nums[i] - nums[i - 1] != 1 )
                noneOrderEle.push(i - 1);
            if(i - j + 1 == k){
                if(!noneOrderEle.empty() && noneOrderEle.front() >= j)
                    ans.push_back(-1);
                else
                    ans.push_back(nums[i]);
                j++;
                if(!noneOrderEle.empty() && j > noneOrderEle.front())
                    noneOrderEle.pop();
            }
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1)
            return nums;
        vector<int> ans;
        int l = 0, r = 1;
        while(r < nums.size()){
            bool isConsective = true;
            if(nums[r] != nums[r-1] + 1){
                while(l < r && l + k - 1 < nums.size()){
                    ans.push_back(-1);
                    ++l;
                }
            }
            if(r - l + 1 == k){
                ans.push_back(nums[r]);
                ++l;
            }
            ++r;
        }
        return ans;
    }
};
// @lc code=end

ostream& operator<<(ostream& ss, vector<int> nums){
    ss << "[";
    for(auto num:nums){
        ss << num <<',';
    }
    ss<<"\b]";
    return ss;
}

int main(){
    Solution s;
    vector nums{1,2,3,4,3,2,5};
    // [3,4,-1,-1,-1]
    cout << s.resultsArray(nums, 3)<< endl;

    nums = {2,2,2,2,2};
    // [-1,-1]
    cout << s.resultsArray(nums, 4) << endl;

    nums = {3,2,3,2,3,2};
    // [-1,3,-1,3,-1]
    cout << s.resultsArray(nums, 2)<< endl;

    nums = {1};
    // [1]
    cout << s.resultsArray(nums, 1)<< endl;

    nums = {1,4};
    // [1,4]
    cout << s.resultsArray(nums, 1)<< endl;

    nums = {1,3,4};
    // [-1,4]
    cout << s.resultsArray(nums, 2)<< endl;

    return 0;
}
