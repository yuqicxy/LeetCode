/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;

        int i = 0;
        int j = costs.size() - 1;
        while(k--){
            while(left.size() < candidates && i <= j)
                left.push(costs[i++]);

            while(right.size() < candidates && i <= j)
                right.push(costs[j--]);
            
            int leftMin = left.empty() ? INT_MAX : left.top();
            int rightMin = right.empty() ? INT_MAX : right.top();
            if(leftMin <= rightMin){
                ans += leftMin;
                left.pop();
            }
            else{
                ans += rightMin;
                right.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector costs = {17,12,10,2,7,2,11,20,8};
    int k = 3, candidates = 4;
    cout << s.totalCost(costs, k, candidates) <<endl;

    costs = {1,2,4,1};
    k = 3;
    candidates = 3;
    cout << s.totalCost(costs, k, candidates) <<endl;

    costs = {4866,4857,4378,4876,3594,4874,4717,4680,4813,4938,4156,4724};
    k = 9;
    candidates = 2;
    cout << s.totalCost(costs, k, candidates) <<endl; //40785

    return 0;
}