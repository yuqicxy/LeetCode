/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int M = matrix.size();
    //     int N = M ? matrix[0].size() : 0;
    //     int row = 0;
    //     if(target < matrix[0][0] || target > matrix[M-1][N-1]) return false;
    //     for(row = 0; row < M - 1; ++row){
    //         if(target == matrix[row][0])
    //             return true;
    //         if(target > matrix[row][0] && target < matrix[row + 1][0])
    //             break;
    //     }
    //     for(int col = 0; col < N; ++col){
    //         if(matrix[row][col] == target)
    //             return true;
    //     }
    //     return false;
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        int N = M ? matrix[0].size() : 0;
        int left = 0;
        int right = M * N - 1;
        if(right < 0) return false;
        while(left != right){
            int mid = (left + right) / 2;
            if(matrix[mid / N][mid % N] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return matrix[left / N][left % N] == target;
    }
};
// @lc code=end