/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class StupidSolution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<size_t> zerosPos;
        int lastZeroIndex = -1;
        int maxLen = 0;
        for(auto i = 0, curLen = 0; i < nums.size(); ++i){
            if(!nums[i])
                zerosPos.push(i);
            if(zerosPos.size() > k){
                lastZeroIndex = zerosPos.front();
                zerosPos.pop();
            }
            curLen = i - lastZeroIndex;
            maxLen = max(curLen, maxLen);
        }
        return maxLen;
    }
};

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        for(; i < nums.size(); ++i){
            if(!nums[i])
                k--;
            if(k < 0 && !nums[j++])
                k++;
        }
        return i - j;   
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{1,1,1,0,0,0,1,1,1,1,0};
    cout << s.longestOnes(nums, 2) <<endl;
    nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << s.longestOnes(nums, 3) <<endl;
}