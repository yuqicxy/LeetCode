/*
 * @lc app=leetcode id=1942 lang=cpp
 *
 * [1942] The Number of the Smallest Unoccupied Chair
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class stupidSolution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival = times[targetFriend].front();
        auto newItr = remove_if(times.begin(),times.end(), [&targetArrival](auto &&item){
            return item.front() > targetArrival;
        });
        sort(times.begin(), newItr, [](auto left, auto right){
            return left[0] < right[0];
        });
        vector<int> chairs;
        int ans = 0;
        for(auto itr = times.begin(); itr != newItr; ++itr){
            bool newChair = true;
            for(auto chairItr = chairs.begin(); chairItr < chairs.end(); ++chairItr){
                if(!(*chairItr > (*itr)[0])){
                    *chairItr = (*itr)[1];
                    newChair = false;
                    ans = distance(chairs.begin(), chairItr);
                    break;
                }
            }
            if(newChair){
                chairs.push_back((*itr)[1]);
                ans = chairs.size() - 1;
            }
        }
        return ans;
    }
};


#include <queue>
#include <tuple>
#include <set>

// @lc code=start
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        using OccupiedChair = tuple<int,int>;
        using ChairQueue = priority_queue<OccupiedChair,vector<OccupiedChair>, greater<OccupiedChair>>;
        ChairQueue chairQueue;
        int targetArrival = times[targetFriend].front();
        // cout<<"targetArrival:"<< "\t" << targetArrival <<endl;

        // auto newItr = remove_if(times.begin(),times.end(), [&targetArrival](auto &&item){
        //     return item.front() > targetArrival;
        // });
        auto newItr = times.end();
        sort(times.begin(), newItr);
        // ,[](auto left, auto right){
        //     return left[0] < right[0];
        // });
        // for(auto itr = times.begin(); itr != newItr; ++itr){
        //     cout<<itr->front() << "\t" << itr->back() <<endl;
        // }
        int ans = 0;
        int seatID = 0;
        set<int> seats;
        for(auto itr = times.begin(); itr != newItr; ++itr){
            int arrival = itr->front();
            int leave = itr->back();
            while(!chairQueue.empty()){
                auto [freeTime, chairId] = chairQueue.top();
                if(freeTime <= arrival){
                    seats.insert(chairId);
                    chairQueue.pop();
                }else
                    break;
            }

            if(!seats.empty()){
                ans = (*seats.begin());
                seats.erase(seats.begin());
            }else{
                ans = seatID;
                seatID++;
            }

            chairQueue.push({leave,ans});
            if(arrival == targetArrival)
                return ans;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;

    vector<vector<int>> times{{1,4},{2,3},{4,6}};
    cout << s.smallestChair(times, 1) << endl; //1
    times = {{3,10},{1,5},{2,6}};
    cout << s.smallestChair(times, 0) << endl; //2
    times = {
        {33889,98676},{80071,89737},{44118,52565},
        {52992,84310},{78492,88209},{21695,67063},
        {84622,95452},
        {98048,98856},{98411,99433},{55333,56548},
        {65375,88566},{55011,62821},{48548,48656},
        {87396,94825},{55273,81868},{75629,91467}
    };
    cout << s.smallestChair(times, 6) << endl; //2
}
