/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> pq;
        if(costs.size() > 2 * candidates){
            for(int i = 0; i < candidates; ++i){
                pq.emplace(costs[i], i);
                pq.emplace(costs[costs.size() - 1 - i], costs.size() - 1 - i);
            }
        }else{
            for(int i = 0; i < costs.size(); ++i)
                pq.emplace(costs[i], i);
        }
            
        int i = candidates, j = costs.size() - candidates - 1;
        while(k--){
            auto [cost, id] = pq.top();
            pq.pop();
            ans += cost;
            if(i <= j){
                if(id < i){
                    pq.emplace(costs[i], i);
                    ++i;
                }else if(id > j){
                    pq.emplace(costs[j], j);
                    --j;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector costs = {17,12,10,2,7,2,11,20,8};
    int k = 3, candidates = 4;
    cout << s.totalCost(costs, k, candidates) <<endl;

    costs = {1,2,4,1};
    k = 3;
    candidates = 3;
    cout << s.totalCost(costs, k, candidates) <<endl;
    return 0;
}