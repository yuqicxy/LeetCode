/*
 * @lc app=leetcode id=3203 lang=cpp
 *
 * [3203] Find Minimum Diameter After Merging Two Trees
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class MySolution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = calcDiameter(edges1); 
        int d2 = calcDiameter(edges2);
        return max({d1, d2, (d1 + 1)/2 + (d2 + 1)/2 + 1});
    }

    int calcDiameter(const vector<vector<int>> &edges){
        if(edges.empty()) return 0;
        const int N = edges.size() + 1;
        unordered_map<int,vector<int>> graphs;
        for(auto &edge: edges){
            graphs[edge[0]].push_back(edge[1]);
            graphs[edge[1]].push_back(edge[0]);
        }
        queue<int> nodes;
        vector<int> degrees(N, 0);
        //start from the leaf node
        for(auto p : graphs){
            degrees[p.first] = p.second.size();
            if(p.second.size() == 1)
                nodes.push(p.first);
        }
        int maxDiameter = 0;
        vector<int> depth(N, 0);
        vector<bool> visited(N, false);
        while(!nodes.empty()){
            int n = nodes.front();
            nodes.pop();
            visited[n] = true;
            for(auto dest : graphs[n]){
                if(--degrees[dest] == 1){
                    nodes.push(dest);
                }
                if(!visited[dest]){
                    maxDiameter = max(maxDiameter, depth[dest] + depth[n] + 1);
                    depth[dest] = max(depth[dest], depth[n] + 1);
                }
            }
        }
        return maxDiameter;
    }
};

// @lc code=start
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = calcDiameter(edges1); 
        int d2 = calcDiameter(edges2);
        return max({d1, d2, (d1 + 1)/2 + (d2 + 1)/2 + 1});
    }

    int calcDiameter(const vector<vector<int>> &edges){
        if(edges.empty()) return 0;
        unordered_map<int,vector<int>> graphs;
        for(auto &edge: edges){
            graphs[edge[0]].push_back(edge[1]);
            graphs[edge[1]].push_back(edge[0]);
        }
        int v1, v2, d;
        tie(v1,d) = farest(graphs, 0);
        tie(v2,d) = farest(graphs, v1);
        return d;
    }

    tuple<int,int> farest(const unordered_map<int,vector<int>> &graph, int i){
        const int N = graph.size();
        queue<int> nodes;
        nodes.push(i);
        int maxDiameter = -1;
        int dest = -1;
        vector<int> visited(N, 0);
        visited[i] = 1;
        while(!nodes.empty()){
            int i = nodes.front(); nodes.pop();
            for(auto j : graph.at(i)){
                if(visited[j] == 0){
                    visited[j] = visited[i] + 1;
                    nodes.push(j);
                    if(maxDiameter < visited[j]){
                        maxDiameter = visited[j];
                        dest = j;
                    }
                }
            }
        }
        return {dest, maxDiameter - 1};
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3}}, edges2 = {{0,1}};
    cout << s.minimumDiameterAfterMerge(edges1, edges2) << endl;
    edges1 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    edges2 = {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}};
    cout << s.minimumDiameterAfterMerge(edges1, edges2) << endl;
}