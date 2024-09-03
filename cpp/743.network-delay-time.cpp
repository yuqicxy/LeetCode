/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <limits>
#include <iostream>
using namespace std;
class FailedTryAndNaiveBreadthFirstSearchSolution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int minCost = -1;
        queue<tuple<int,int>> startList;
        startList.push({k,0});
        while(!startList.empty()){
            int curr,cost;
            tie(curr,cost) = startList.front();
            startList.pop();
            for(unsigned i = 0; i < times.size(); ++i){
                if(curr == times[i][0]){
                    int dest = times[i][1];
                    int destCost = cost + times[i][2];
                    if(dest != n)
                        startList.push({dest,destCost});
                    else{
                        minCost = minCost > 0 ? min(minCost, destCost) : destCost;
                        break;
                    }
                }
            }
        }
        return minCost;
    }

};

// @lc code=start
class Solution {
public:
    //bellman-ford algorithm
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //initialize single source
        const int& maxNum = numeric_limits<int>::max();
        vector<int> costs(n, maxNum);
        costs[k-1] = 0;
        for(int i = 0; i < (n - 1); i++){
            for(auto edge : times){
                const int &u = edge[0] - 1;
                const int &v = edge[1] - 1;
                const int &cost = edge[2];
                if(costs[u] != maxNum && costs[v] > costs[u] + cost){
                    costs[v] = costs[u] + cost;
                }
            }
        }

        int totalCost = *max_element(costs.begin(),costs.end());
        return totalCost == maxNum ? -1 : totalCost;
    }
};
// @lc code=end
int main() {
    Solution s;
    vector<vector<int>> times ={{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout<<"test 1:"<<s.networkDelayTime(times,n,k)<<endl;
    times = {{1,2,1},{2,1,3}};
    n = 2, k = 2;
    cout<<"test 2:"<<s.networkDelayTime(times,n,k)<<endl;
    times = {{1,2,1}};
    n = 2, k = 2;
    cout<<"test 3:"<<s.networkDelayTime(times,n,k)<<endl;
    return 0;
}