/*
 * @lc app=leetcode id=2593 lang=cpp
 *
 * [2593] Find Score of an Array After Marking All Elements
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class MySolution {
public:
    long long findScore(vector<int>& nums) {
        vector<bool> marked(nums.size(), false);
        vector<vector<int>> numsWithIndex(nums.size());
        for(int i = 0; i < nums.size(); ++i)
            numsWithIndex[i] = {nums[i], i};
        sort(numsWithIndex.begin(), numsWithIndex.end());
        long long ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            int index = numsWithIndex[i].back();
            if(!marked[index]){
                marked[index] = true;
                ans += numsWithIndex[i].front();
                if(index > 0)
                    marked[index - 1] = true;
                if(index < nums.size() - 1)
                    marked[index + 1] = true;
            }
        }
        return ans;
    }
};

class SetSolution {
public:
    long long findScore(vector<int>& nums) {
        const int N = nums.size();
        set<pair<int,int>> os;
        for(int i = 0; i < N; ++i)
            os.insert({nums[i], i});
        long long ans = 0;
        for(const auto &p : os){
            if(nums[p.second] == 0) continue;
            ans += p.first;
            if(p.second > 0) nums[p.second - 1] = 0;
            if(p.second < N - 1) nums[p.second + 1] = 0;
        }
        return ans; 
    }
};


// @lc code=start
class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<vector<int>> numsWithIndex(nums.size());
        for(int i = 0; i < nums.size(); ++i)
            numsWithIndex[i] = {nums[i], i};
        sort(numsWithIndex.begin(), numsWithIndex.end());
        long long ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            int index = numsWithIndex[i].back();
            if(nums[index] != 0){
                nums[index] = 0;
                ans += numsWithIndex[i].front();
                if(index > 0)
                    nums[index - 1] = 0;
                if(index < nums.size() - 1)
                    nums[index + 1] = 0;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector nums{2,1,3,4,5,2};
    cout << s.findScore(nums) << endl;
    nums = {2,3,5,1,3,2};
    cout << s.findScore(nums) << endl;
    return 0;
}