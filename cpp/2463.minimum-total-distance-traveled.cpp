/*
 * @lc app=leetcode id=2463 lang=cpp
 *
 * [2463] Minimum Total Distance Traveled
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <memory>
using namespace std;

// @lc code=start
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot),end(robot));
        sort(begin(factory),end(factory),[](auto left, auto right){
            return less<int>{}(left.front(), right.front());
        });
        size_t N = robot.size() * factory.size() * robot.size();
        shared_ptr<long long[]> DPArray2(new long long[N]);
        fill_n(DPArray2.get(),N,-1);
        auto ans= dp(DPArray2.get(), robot, factory, 0, 0, 0);
        return ans;
    }

    long long dp(long long* DParray, vector<int>& robot, vector<vector<int>>& factory, int i, int j, int k){
        if(i == robot.size()) return 0;
        if(j == factory.size()) return numeric_limits<long long>::max();
        size_t index = i * robot.size() * factory.size() + j * robot.size() + k;
        if(DParray[index] != -1) return DParray[index];
        long long option1 = dp(DParray, robot, factory, i, j + 1, 0);
        long long option2 = numeric_limits<long long>::max();
        if(factory[j][1] > k){
            option2 = dp(DParray, robot, factory, i + 1, j, k + 1);
            if(option2 < numeric_limits<long long>::max())
                option2 += abs(factory[j][0] - robot[i]);
        }
        DParray[index] = min(option1, option2);
        return DParray[index];
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