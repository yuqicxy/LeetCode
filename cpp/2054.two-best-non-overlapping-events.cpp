/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//Dont read [problem] carefully, problem require to select two events.
// the solution here support any non-overlapping events to achieve max value
class MySolution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const auto &left, const auto &right)
            {
                return left[1] < right[1];
            }
        );
        vector<pair<int,int>> cache; //(endTime, cost)
        int maxCost = 0;
        for(int i = 0; i < events.size(); ++i){
            auto itr = lower_bound(cache.begin(), cache.end(), events[i][0], [](const pair<int,int>& p, int val){
                return p.first < val;
            });
            if(itr == cache.begin()){
                cache.push_back({events[i][1], events[i][2]});
                maxCost = max(maxCost, events[i][2]);
            }
            else{
                for(auto j = cache.begin(); j < itr; ++j){
                    j->second += events[i][2];
                    maxCost = max(maxCost, j->second);
                }
            }
        }
        return maxCost;
    }
};


// @lc code=start
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<tuple<int, bool, int>> infos;
        infos.reserve(events.size() * 2);
        for(vector<int>& e : events){
            infos.push_back({e[0], false, e[2]});
            infos.push_back({e[1], true, e[2]});
        }
        sort(infos.begin(), infos.end());
        int ans = 0;
        int maxValue = 0;
        for(auto &info : infos){
            if(get<1>(info)){
                maxValue = max(maxValue, get<2>(info));
            }else{
                ans = max(ans, maxValue + get<2>(info));
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> events{{1,3,2},{4,5,2},{2,4,3}};
    cout << s.maxTwoEvents(events) << endl; //4
    events = {{1,3,2},{4,5,2},{1,5,5}};
    cout << s.maxTwoEvents(events) << endl; //5
    events = {{1,5,3},{1,5,1},{6,6,5}};
    cout << s.maxTwoEvents(events) << endl; //8
    events = {{10,83,53},{63,87,45},{97,100,32},{51,61,16}};
    cout << s.maxTwoEvents(events) << endl; //85

    return 0;
}