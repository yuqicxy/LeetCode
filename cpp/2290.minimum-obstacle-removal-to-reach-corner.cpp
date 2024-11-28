/*
 * @lc app=leetcode id=2290 lang=cpp
 *
 * [2290] Minimum Obstacle Removal to Reach Corner
 */

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class InitialSolution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<int> direction{1,0,-1,0,1};
        int M = grid.size();
        int N = grid.front().size();
        //initialize single source
        vector<vector<int>> nodes(M, vector<int>(N, INT_MAX)); 
        vector<vector<int>> founded(M, vector<int>(N, 0));
        nodes[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        while(!pq.empty()){
            int step, x, y;
            tie(step, x, y) = pq.top();
            founded[x][y] = 1;
            pq.pop();
            for(int i = 0; i < direction.size() - 1; ++i){
                int mx = direction[i] + x;
                int my = direction[i + 1] + y;
                if(mx > -1 && mx < M && my > -1 && my < N){
                    nodes[mx][my] = min(nodes[mx][my], step + grid[mx][my]);
                    if(!founded[mx][my])
                        pq.push({nodes[mx][my], mx, my});
                }
            }
        }
        return nodes.back().back();
    }
};

// @lc code=start
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<int> direction{1,0,-1,0,1};
        int M = grid.size();
        int N = grid.front().size();
        vector<vector<int>> nodes(M, vector<int>(N, INT_MAX)); 
        nodes[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        while(!pq.empty()){
            int step, x, y;
            tie(step, x, y) = pq.top();
            pq.pop();
            for(int i = 0; i < direction.size() - 1; ++i){
                int mx = direction[i] + x;
                int my = direction[i + 1] + y;
                if(mx > -1 && mx < M && my > -1 && my < N){
                    if(step + grid[mx][my] < nodes[mx][my])
                    {
                        nodes[mx][my] = step + grid[mx][my];
                        pq.push({nodes[mx][my], mx, my});
                    }
                }
            }
        }
        return nodes.back().back();
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> grid{{0,1,1},{1,1,0},{1,1,0}};
    cout << s.minimumObstacles(grid) << endl;
    grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout << s.minimumObstacles(grid) << endl;
    return 0;
}