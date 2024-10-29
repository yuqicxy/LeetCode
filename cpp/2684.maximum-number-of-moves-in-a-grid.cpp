/*
 * @lc app=leetcode id=2684 lang=cpp
 *
 * [2684] Maximum Number of Moves in a Grid
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int M = static_cast<int>(grid.size());
        int N = static_cast<int>(grid.front().size());
        vector<int> ans(M,0);
        vector<int> tmp;
        for(int colId = N - 2; colId >= 0; --colId){
            tmp.assign(M,0);
            for(int rowId = 0; rowId < M; ++rowId){
                for(int z = -1; z <= 1; ++z){
                    if(rowId + z >= 0 && rowId + z < M && grid[rowId + z][colId + 1] > grid[rowId][colId]){
                        tmp[rowId] = max(tmp[rowId], 1 + ans[rowId + z]);
                    }
                }
            }
            ans = tmp;
        }
        return *max_element(ans.begin(), ans.end());
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> grid{{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
    cout << s.maxMoves(grid) << endl;
    grid = {{3,2,4},{2,1,9},{1,1,7}};
    cout << s.maxMoves(grid) << endl;
}