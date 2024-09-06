/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertexCount = isConnected.size();
        vector<bool> colors(vertexCount,0);
        int provinces = 0;
        for(int i = 0; i < vertexCount; ++i){
            if(!colors[i])
            {
                colors[i] = true;
                DFS(isConnected,colors, i);
                provinces++;
            }
        }
        return provinces;
    }

private:
    void DFS(vector<vector<int>>& isConnected,vector<bool>& colors, int u){
        for(int v = 0; v < isConnected.size(); ++v){
            if(isConnected[u][v] == 1 && !colors[v]){
                colors[v] = true;
                DFS(isConnected,colors, v);
            }
        }
    }
};
// @lc code=end

int main()
{
    typedef vector<vector<int>> Grid;
    Grid network{{1,1,0},{1,1,0},{0,0,1}};
    Solution s;
    cout<<s.findCircleNum(network)<<endl;
    Grid network2{{1,0,0},{0,1,0},{0,0,1}};
    cout<<s.findCircleNum(network2)<<endl;
}
