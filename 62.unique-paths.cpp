/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <vector>

class Solution {
public:
    /**
     * @brief recursive method
     *  high time complexity
     * @param m 
     * @param n 
     * @return int 
     */
    // int uniquePaths(int m, int n) {
    //     if(m == 1 || n == 1)
    //         return 1;
    //     return uniquePaths(m,n-1) + uniquePaths(m-1,n);        
    // }

    /**
     * @brief dynamic programming solution
     * 
     * @param m 
     * @param n 
     * @return int 
     */
    int uniquePaths(int m, int n) {
        if(m > n) return uniquePaths(n,m);
        std::vector<int> dp(n * m, 0);
        for(size_t i = 0; i < m; ++i){
            for(size_t j = i; j < n; ++j){
                if(i == 0 || j == 0){
                    dp[i * n + j] = 1;
                    continue;
                }
                if(j == i){
                    dp[i * n + j - 1] = dp[(j-1) * n + i];
                }
                dp[i * n + j] = dp[i * n + j - 1] + dp[(i - 1) * n + j];
            }
        }
        return dp[(m - 1) * n + n - 1];
    }
};
// @lc code=end

