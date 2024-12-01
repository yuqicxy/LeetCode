/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        auto &prev = intervals.front();
        int ans = 0;
        for(int i = 1; i < intervals.size(); ++i){
            const auto &curr = intervals[i];
            if(prev.back()<=curr.front()){
                prev = curr;
            }else if(prev.back() >= curr.back()){
                ans++;
                prev = curr;
            }else{
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << s.eraseOverlapIntervals(intervals) << endl; //1
    intervals = {{1,2},{1,2},{1,2}};
    cout << s.eraseOverlapIntervals(intervals) << endl; //2
    intervals = {{1,2},{2,3}};
    cout << s.eraseOverlapIntervals(intervals) << endl; //0
}

