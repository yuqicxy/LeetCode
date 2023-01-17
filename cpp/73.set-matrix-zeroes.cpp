/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0Is0 = false;
        for(unsigned i = 0; i < matrix.size(); ++i){
            if(matrix[i][0] == 0) col0Is0 = true;
            for(unsigned j = 1; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                } 
            }
        }
        for(unsigned i = 1; i < matrix.size(); ++i){
            for(unsigned j = 1; j < matrix[0].size(); ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if(col0Is0) matrix[i][0] = 0;
        }

        if(matrix[0][0] == 0){
            for(unsigned j = 1; j < matrix[0].size(); ++j){
                matrix[0][j] = 0;
            }
        }

        if(col0Is0) matrix[0][0] = 0;
    }
};
// @lc code=end

