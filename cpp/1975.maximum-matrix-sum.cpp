/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int N = matrix.size();
        int count = 0;
        int minimum = INT_MAX;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                count += matrix[i][j] < 0;
                ans += abs(matrix[i][j]);
                minimum = min(minimum, abs(matrix[i][j]));
            }
        }
        return count % 2 == 0 ? ans : ans - 2 * minimum;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> matrix{{1,-1},{-1,1}};
    cout << s.maxMatrixSum(matrix) << endl;
    matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};
    cout << s.maxMatrixSum(matrix) << endl;
}
