/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */
#include <tuple>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<tuple<int,int>> rottenOrange;
        size_t M = grid.size();
        size_t N = grid[0].size();
        size_t count = 0;
        for(unsigned i = 0; i < M; ++i){
            for(unsigned j = 0; j < N; ++j){
                if(grid[i][j] == 1){
                    count++;
                }
                if(grid[i][j] == 2){
                    rottenOrange.emplace_back(i,j);
                }
            }
        }

        int minutes = 0;
        while(count > 0){
            minutes++;
            vector<tuple<int,int>> rottenInNext;
            for(auto item : rottenOrange){
                int i,j;
                tie(i,j) = item;
                if(i < M - 1 && grid[i + 1][j] == 1){
                    grid[i + 1][j] = 2;
                    rottenInNext.emplace_back(i + 1,j);
                }
                if(i > 0 && grid[i - 1][j] == 1){
                    grid[i - 1][j] = 2;
                    rottenInNext.emplace_back(i - 1,j);
                }
                if(j > 0 && grid[i][j - 1] == 1){
                    grid[i][j - 1] = 2;
                    rottenInNext.emplace_back(i,j - 1);
                }
                if(j < N - 1 && grid[i][j + 1] == 1){
                    grid[i][j + 1] = 2;
                    rottenInNext.emplace_back(i,j + 1);
                }
            }
            count -= rottenInNext.size();
            if(rottenInNext.empty()) break;
            swap(rottenOrange,rottenInNext);
        }
        return count > 0 ? -1 : minutes;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> grid{{2,1,1},
                            {0,1,1},
                            {1,0,1}};
    vector<vector<int>> grid2{{2,1,1},
                            {1,1,0},
                            {0,1,1}};
    int res = s.orangesRotting(grid2);
}

