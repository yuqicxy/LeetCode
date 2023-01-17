/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     return findMatrix(matrix,target,0,0,matrix.size() - 1,matrix[0].size() - 1);
    // }

    // bool findMatrix(vector<vector<int>>& matrix, int target, 
    //     int top, int left, int bottom, int right)
    // {
    //     if(top > bottom || left > right) return false;
    //     if(target < matrix[top][left] || target > matrix[bottom][right])
    //         return false;
    //     if(target == matrix[top][left] || target == matrix[bottom][right])
    //         return true;
    //     if(top == bottom && left == right)
    //         return false;
    //     int midRow = (top + bottom)/2;
    //     int midCol = (left + right)/2;
    //     if(target == matrix[midRow][midCol]){
    //         return true;
    //     }else if(target > matrix[midRow][midCol]){
    //         bool result1 = false, result2 = false;
    //         if(midRow + 1 < matrix.size())
    //             result1 = findMatrix(matrix, target, midRow + 1, left,       bottom, right);
    //         if(!result1 && midCol + 1 < matrix[0].size())
    //             result2 = findMatrix(matrix, target, top,        midCol + 1, midRow, right);
    //         return result1||result2;
    //     }else{
    //         bool result1 = false, result2 = false;
    //         if(midRow - 1 >= 0)
    //             result1 = findMatrix(matrix, target, top, midCol, midRow - 1, right);
    //         if(!result1 && midCol - 1 >= 0)
    //             result2 = findMatrix(matrix, target, top, left, bottom, midCol - 1);
    //         return result1||result2;
    //     }
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int row = 0, col = n - 1;
        while(row < m && col >= 0){
            if(matrix[row][col] == target)
                return true;
            matrix[row][col] > target ? col-- : row++;
        }
        return false;
    }
};
// @lc code=end