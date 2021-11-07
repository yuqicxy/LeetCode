/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return findMatrix(matrix,target,0,0,matrix.size() - 1,matrix[0].size() - 1);
    }

    bool findMatrix(vector<vector<int>>& matrix, int target, 
        int top, int left, int bottom, int right)
    {
        if(top > bottom || left > right) return false;
        if(target < matrix[top][left] || target > matrix[bottom][right])
            return false;
        if(target == matrix[top][left] || target == matrix[bottom][right])
            return true;
        if(top == bottom && left == right)
            return false;
        int midRow = (top + bottom)/2;
        int midCol = (left + right)/2;
        if(target == matrix[midRow][midCol]){
            return true;
        }else if(target > matrix[midRow][midCol]){
            bool result1 = false, result2 = false;
            if(midRow + 1 < matrix.size())
                result1 = findMatrix(matrix, target, midRow + 1, left,       bottom, right);
            if(!result1 && midCol + 1 < matrix[0].size())
                result2 = findMatrix(matrix, target, top,        midCol + 1, midRow, right);
            return result1||result2;
        }else{
            bool result1 = false, result2 = false;
            if(midRow - 1 >= 0)
                result1 = findMatrix(matrix, target, top, midCol, midRow - 1, right);
            if(!result1 && midCol - 1 >= 0)
                result2 = findMatrix(matrix, target, top, left, bottom, midCol - 1);
            return result1||result2;
        }
    }
};
// @lc code=end

int main(){
    // vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // int target = 20;
    // 
    vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int target = 10;
    Solution s;
    cout<<s.searchMatrix(matrix,target);
}