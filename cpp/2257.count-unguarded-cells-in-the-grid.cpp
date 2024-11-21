/*
 * @lc app=leetcode id=2257 lang=cpp
 *
 * [2257] Count Unguarded Cells in the Grid
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n,0));
        
        for(const auto &wall : walls)
            grid[wall[0]][wall[1]] = 15;
        
        int ans = m * n - walls.size();

        vector<int> direction{0,1,0,-1,0};
        for(const auto &guard : guards){
            for(int d = 0; d < 4; ++d){
                int row = guard[0];
                int col = guard[1];
                while(row >= 0 && col >=0 && row < m && col < n && ((grid[row][col] & (1 << d)) == 0))
                {
                    if(grid[row][col] == 0) ans--;
                    grid[row][col] += 1 << d;
                    row += direction[d];
                    col += direction[d + 1];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> guards{{0,0},{1,1},{2,3}};
    vector<vector<int>> walls{{0,1},{2,2},{1,4}};
    cout << s.countUnguarded(4, 6, guards, walls) << endl;
    return 0;
}
