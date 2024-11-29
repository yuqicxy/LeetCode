/*
 * @lc app=leetcode id=2577 lang=cpp
 *
 * [2577] Minimum Time to Visit a Cell In a Grid
 */
#include<vector>
#include<iostream>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        int M = grid.size();
        int N = grid.front().size();
        vector<int> directions{1,0,-1,0,1};
        vector<vector<bool>> founded(M, vector<bool>(N, false));
        founded[0][0]=false;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            int time = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            if (x == M - 1 && y == N - 1) return time;
            if(founded[x][y]) continue;
            founded[x][y] = true;
            for(int i = 0; i < directions.size() - 1; ++i){
                int newx = x + directions[i];
                int newy = y + directions[i + 1];
                if(min(newx,newy) >= 0 && newx < M && newy< N && !founded[newx][newy]){
                    int wait = (grid[newx][newy] - time) % 2 == 0;
                    int newtime = max(grid[newx][newy] + wait, time + 1);
                    pq.push({newtime, newx, newy});
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,3,2},{5,1,2,5},{4,3,8,6}};
    cout << s.minimumTime(grid) << endl; //7
    grid = {{0,2,4},{3,2,1},{1,0,4}};
    cout << s.minimumTime(grid) << endl; //-1
    grid = {{0,1,99},{3,99,99},{4,5,6}};
    cout << s.minimumTime(grid) << endl; //6
}