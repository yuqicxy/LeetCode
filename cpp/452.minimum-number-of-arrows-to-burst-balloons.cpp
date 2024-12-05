/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class MySolution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto left, auto right){
            return left[1] < right[1];
        });
        int ans = 1;
        auto &prev = points.front();
        for(int i = 1; i < points.size();++i){
            if(prev.back() < points[i].front()){
                ans++;
                prev = points[i];
            }else{
                prev = {min(points[i].front(), prev.front()),prev.back()};
            }
        }
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto &left, const auto &right){
            return left[1] < right[1];
        });
        int ans = 1;
        int arrPos = points.front().back();
        for(int i = 1; i < points.size();++i){
            if(arrPos < points[i].front()){
                ans++;
                arrPos = points[i].back();
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> points{{10,16},{2,8},{1,6},{7,12}};
    cout << s.findMinArrowShots(points) << endl;
    points = {{1,2},{3,4},{5,6},{7,8}};
    cout << s.findMinArrowShots(points) << endl;
    points = {{1,2},{2,3},{3,4},{4,5}};
    cout << s.findMinArrowShots(points) << endl;
    return 0;    
}