/*
 * @lc app=leetcode id=2406 lang=cpp
 *
 * [2406] Divide Intervals Into Minimum Number of Groups
 */

#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

class StupidSolution {
    using Interval = pair<int,int>; /** {end, start} */
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<set<Interval> > groups;
        for (auto &&item : intervals)
        {
            Interval i{item.back(), item.front()};
       
            bool insert = false;
            for(auto itr = groups.begin(); itr != groups.end(); ++itr){
                insert = tryInsertInterval(*itr, i);
                if(insert) break;
            }
            if(!insert)
                groups.push_back(set<Interval>{i});
        }
        return (int)groups.size();        
    }

    bool tryInsertInterval(set<Interval> &intervalSet, const Interval &i){
        auto itr = intervalSet.lower_bound({i.second, i.first});
        // if(itr != intervalSet.end() && itr->second > i.first){
        //     intervalSet.insert(i);
        //     return true;
        // }else if(itr == intervalSet.end()){
        //     intervalSet.insert(i);
        //     return true;
        // }
        
        if(itr != intervalSet.end() && !(itr->second > i.first))
            return false;
        else{
            intervalSet.insert(i);
            return true;
        }
    }
};

// @lc code=start
class Solution {
    using Interval = pair<int,int>; /** {end, start} */
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, std::greater<int>> heap;
        for (auto &&i : intervals)
        {
            if(!heap.empty() && heap.top() < i[0])
                heap.pop();
            heap.push(i[1]);
        }
        return (int)heap.size();
    }
};
// @lc code=end
#include <iostream>
int main(){
    Solution s;
    vector<vector<int>> intervals{{5,10},{6,8},{1,5},{2,3},{1,10}};
    cout << s.minGroups(intervals) << endl;
    intervals = {{1,3},{5,6},{8,10},{11,13}};
    cout << s.minGroups(intervals) << endl;
    intervals = {
        {229966,812955},{308778,948377},{893612,952735},
        {395781,574123},{478514,875165},{766513,953839},
        {460683,491583},{133951,212694},{376149,838265},
        {541380,686845},{461394,568742},{804546,904032},
        {422466,467909},{557048,758709},{680460,899053},
        {110928,267321},{470258,650065},{534607,921875},
        {292993,994721},{645020,692560},{898840,947977},
        {33584,330630},{903142,970252},{17375,626775},
        {804313,972796},{582079,757160},{785002,987823},
        {599263,997719},{486500,527956},{566481,813653},
        {211239,863969},{808577,883125},{21880,516436},
        {264747,412144},{327175,772333},{984807,988224},
        {758172,916673},{23583,406006},{954674,956043},
        {379202,544291},{688869,785368},{841735,983869},
        {99836,916620},{332504,740696},{740840,793924},
        {896607,920924},{868540,922727},{125849,550941},
        {433284,685766}
    };
    cout << s.minGroups(intervals) << endl; //19
    return 0;
}