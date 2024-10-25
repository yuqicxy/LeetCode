/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */
#include <Array>

using namespace std;

// @lc code=start
class Solution {
public:
    int numTilings(int n) {
        //dp[n] = 2*dp[n-1] + dp[n-3]
        int md = 1e9 + 7;
        array<long long ,1001> dp{0};
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;
        if(n <= 3)
            return dp[n-1];
        for(int i = 3; i < n; ++i){
            dp[i] = (dp[i-1] * 2 + dp[i-3]) % md;
        }
        return dp[n - 1];
    }
};
// @lc code=end
#include <iostream>
int main(){
    Solution s;
    //312342182
    cout << s.numTilings(30) << endl;
}
