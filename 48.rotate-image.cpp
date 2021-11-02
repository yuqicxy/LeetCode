/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    /*
    * clockwise rotate
    * first reverse up to down, then swap the symmetry 
    * 1 2 3     7 8 9     7 4 1
    * 4 5 6  => 4 5 6  => 8 5 2
    * 7 8 9     1 2 3     9 6 3
    */
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for(unsigned i = 0; i < matrix.size(); ++i){
            for(unsigned j = i + 1; j < matrix[i].size(); ++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
// @lc code=end

