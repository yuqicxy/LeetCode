/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

#include <vector>
#include <functional>
#include <tuple>
#include <iostream>
using namespace std;
// @lc code=start

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;
        auto vertexEdgeList = vector<vector<tuple<int,bool>>>(n);

        for(auto edge : connections){
            vertexEdgeList[edge[0]].emplace_back(edge[1],true);
            vertexEdgeList[edge[1]].emplace_back(edge[0],false);
        }

        vector<bool> vColor(n,false);
        function<void(int)> dfs = [&](int start){
            vColor[start] = true;
            auto edgeList = vertexEdgeList[start];
            for(auto edge : edgeList){
                int end = get<0>(edge);
                bool isForward = get<1>(edge);
                if(!vColor[end]){
                    if(isForward) count++;
                    dfs(end);
                }
            }
        }; 
        dfs(0);
        return count;
    }
};
// @lc code=end

void main(){
    Solution s;
    vector<vector<int>> connection = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << s.minReorder(6, connection) << endl;
    connection = {{1,0},{1,2},{3,2},{3,4}};
    cout << s.minReorder(5, connection) << endl;
    connection = {{1,0},{2,0}};
    cout << s.minReorder(3, connection) << endl;
}
