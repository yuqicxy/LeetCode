/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(unsigned i = 0;i < grid.size(); ++i){
            for(unsigned j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1')
                {
                    DFS(grid,i,j);
                    ++islands;
                }
            }
        }
        return islands;
    }

    void DFS(vector<vector<char>> &grid,
        unsigned row,unsigned col){
        if(grid[row][col] != '1')
            return;
        grid[row][col] = '0';
        if(row > 0)
            DFS(grid,row-1,col);
        if(col > 0)
            DFS(grid,row,col - 1);
        if(row < grid.size() - 1)
            DFS(grid,row + 1,col);
        if(col < grid[0].size() - 1)
            DFS(grid,row,col + 1);
    }

};
// @lc code=end

