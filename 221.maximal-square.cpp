/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;


// Brutal solution
// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int max = 0;
//         unsigned height = matrix.size();
//         unsigned width = matrix[0].size();
//         vector<vector<bool>> degenrateMatrix(height,std::vector<bool>(width));
//         for(size_t i = 0; i < height; ++i){
//             for(size_t j = 0; j < width; ++j){
//                 if(matrix[i][j] != '0'){
//                     degenrateMatrix[i][j] = 1;
//                     max = 1;
//                 }
//                 else
//                     degenrateMatrix[i][j] = 0;
//             }
//         }
//         recrusive(degenrateMatrix,max,2);
//         return max;
//     }
//
//     void recrusive(vector<vector<bool>> &matrix,int &max,int depth){
//         unsigned height = matrix.size();
//         unsigned width = matrix[0].size();
//         if(width < 2 || height < 2) return;
//         bool validFlag = false;
//         vector<vector<bool>> degenrateMatrix(height - 1,std::vector<bool>(width - 1));
//         for(size_t i = 0; i < height - 1; ++i){
//             for(size_t j = 0; j < width - 1; ++j){
//                 if(matrix[i][j]   &&
//                 matrix[i][j + 1]  &&
//                 matrix[i + 1][j]  &&
//                 matrix[i + 1][j + 1]){
//                     degenrateMatrix[i][j] = true;
//                     max = pow(depth,2);
//                     if(!validFlag)
//                         validFlag = true;
//                 }
//                 else
//                     degenrateMatrix[i][j] = false;
//             }
//         }
//         if(!validFlag) return;
//         recrusive(degenrateMatrix,max,depth + 1);
//         return;
//     }
// };

/*

| 1 | 1 | 1 |
| 1 | 1 | 1 |
| 1 | 1 | 1 |
左下角最大边长为3的条件: 
    dp[i][j] != 1,
    dp[i-1][j] == 2,
    dp[i][j-1] == 2,
    dp[i-1][j-1] ==2

| 1 | 1 | 1 |
| 0 | 1 | 1 |
| 1 | 1 | 1 |
当坐下角最大边长为2时，
则 dp[i-1][j]，dp[i][j-1]，dp[i-1][j-1]最大边长至少有一个为1


则dp方程为
若matrix[i][j] != 0,
dp[i][j] = min(dp[i-1][j],min(dp[i],[j-1],dp[i-1][j-1])) + 1

若matrix[i][k] == 0, dp[i][j] = 0

边界条件：
若i或j有一个为0，则dp[i][j] = matrix[i][j] - '0',


*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int height = matrix.size();
        int width = matrix[0].size();
        int mz = 0;
        // vector<vector<int>> dp(height,std::vector<int>(width));
        vector<int> prev(width,0);
        vector<int> curr(width,0);
        for(unsigned i = 0; i < height; ++i){
            for(unsigned j = 0; j < width; ++j){
                if(i == 0 || j == 0 || matrix[i][j] == '0')
                    curr[j] = matrix[i][j] - '0';
                else
                    curr[j] = min(prev[j-1],min(prev[j],curr[j-1])) + 1;
                mz = max(curr[j],mz);
            }
            fill(prev.begin(),prev.end(),0);
            swap(prev,curr);
        }
        return mz * mz;
    }
};
// @lc code=end