/*
 * @lc app=leetcode id=2463 lang=cpp
 *
 * [2463] Minimum Total Distance Traveled
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot),end(robot));
        sort(begin(factory),end(factory),[](auto left, auto right){
            return less<int>{}(left.front(), right.front());
        });
        vector<vector<vector<long long>>> DPArray(robot.size(), vector<vector<long long>>(factory.size(), vector<long long>(robot.size(), -1)));
        return dp(DPArray, robot, factory, 0, 0, 0);
    }

    long long dp(vector<vector<vector<long long>>>& DParray, vector<int>& robot, vector<vector<int>>& factory, int i, int j, int k){
        if(i == robot.size()) return 0;
        if(j == factory.size()) return numeric_limits<long long>::max();
        if(DParray[i][j][k] != -1) return DParray[i][j][k];
        long long option1 = dp(DParray, robot, factory, i ,    j + 1, 0);
        long long option2 = numeric_limits<long long>::max();
        if(factory[j][1] > k){
            option2 = dp(DParray, robot, factory, i + 1, j,     k + 1);
            if(option2 < numeric_limits<long long>::max())
                option2 += abs(factory[j][0] - robot[i]);
        }
        DParray[i][j][k] = min(option1, option2);
        return DParray[i][j][k];
    }
};
// @lc code=end

int main(){
    Solution s;
    vector robots{0,4,6};
    vector<vector<int>> factory{{6,2},{2,2}};
    cout << s.minimumTotalDistance(robots, factory) << endl;
    return 0;
}