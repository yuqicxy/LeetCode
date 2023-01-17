/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max = 1;
        unsigned height = matrix.size();
        unsigned width = matrix[0].size();
        vector<vector<bool>> degenrateMatrix(height,std::vector<bool>(width));
        for(size_t i = 0; i < height; ++i){
            for(size_t j = 0; j < width; ++j){
                if(matrix[i][j] != '0')
                    degenrateMatrix[i][j] = 1;
                else
                    degenrateMatrix[i][j] = 0;
            }
        }
        recrusive(degenrateMatrix,max,2);
        return max;
    }

    void recrusive(vector<vector<bool>> &matrix,int &max,int depth){
        unsigned height = matrix.size();
        unsigned width = matrix[0].size();
        if(width < 2 || height < 2) return;
        bool validFlag = false;
        vector<vector<bool>> degenrateMatrix(height - 1,std::vector<bool>(width - 1));
        for(size_t i = 0; i < height - 1; ++i){
            for(size_t j = 0; j < width - 1; ++j){
                if(matrix[i][j]   &&
                matrix[i][j + 1]  &&
                matrix[i + 1][j]  &&
                matrix[i + 1][j + 1]){
                    degenrateMatrix[i][j] = true;
                    max = pow(depth,2);
                    if(!validFlag)
                        validFlag = true;
                }
                else
                    degenrateMatrix[i][j] = false;
            }
        }
        if(!validFlag) return;
        recrusive(degenrateMatrix,max,depth + 1);
        return;
    }
};
// @lc code=end

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution s;
    cout<<s.maximalSquare(matrix);
    return 1;
}