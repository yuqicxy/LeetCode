/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size();
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] && i && j){
                    matrix[i][j] += min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]}); 
                }
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end
#include <iostream>

int main(){
    Solution s;
    vector<vector<int>> matrix{
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    cout << s.countSquares(matrix) << endl;
    matrix = {
        {1,0,1},
        {1,1,0},
        {1,1,0}
    };
    cout << s.countSquares(matrix) << endl;
    return 0;
}