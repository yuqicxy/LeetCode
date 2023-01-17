/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief dynamic programming solution
     * 
     * @param obstacleGrid 
     * @return int 
     */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();
        std::vector<int> dp(n * m, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i ==0 && j == 0){
                    dp[0] = obstacleGrid[0][0] != 0 ? 0 : 1;
                    continue;
                }
                else if(i == 0){
                    dp[j] = obstacleGrid[0][j] != 0 ? 0 : dp[j - 1];
                    continue;
                }
                else if(j == 0){
                    dp[i * n] = obstacleGrid[i][0] != 0 ? 0 : dp[(i - 1) * n];
                    continue;
                }
                else{
                    dp[i * n + j] = obstacleGrid[i][j] != 0 ? 0 : (dp[(i - 1) * n + j] + dp[i * n + j - 1]);
                }
            }
        }
        return dp[(m - 1) * n + n - 1];
    }
};
// @lc code=end

