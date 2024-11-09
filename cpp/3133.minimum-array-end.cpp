/*
 * @lc app=leetcode id=3133 lang=cpp
 *
 * [3133] Minimum Array End
 */
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        while(--n)
            ans = (ans + 1) | x;
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minEnd(3,4) << endl;
}