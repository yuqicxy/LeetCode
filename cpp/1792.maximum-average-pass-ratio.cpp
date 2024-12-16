/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 */

#include<vector>
#include<iostream>
#include<queue>
#include <array>

using namespace std;

// @lc code=start
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit = [](const double pass, const double total) ->double {
            return (pass + 1) / (total + 1) - (pass / total);
        };
        priority_queue<pair<double, int> > heap;
        for(int i = 0; i < classes.size(); ++i)
            heap.push({profit(classes[i][0], classes[i][1]), i});
        while(extraStudents--){
            auto p = heap.top(); heap.pop();
            heap.push({profit(++classes[p.second][0],++classes[p.second][1]), p.second});
        }
        double averg = 0;
        for(int i = 0; i < classes.size(); ++i)
            averg += (static_cast<double>(classes[i][0]) / classes[i][1]);
        return averg / classes.size();
    }
};
// @lc code=end



int main(){
    Solution s;
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    cout << s.maxAverageRatio(classes, 2) << endl;
    classes = {{2,4},{3,9},{4,5},{2,10}};
    cout << s.maxAverageRatio(classes, 4) << endl;
}