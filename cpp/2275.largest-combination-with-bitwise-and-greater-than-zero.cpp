/*
 * @lc app=leetcode id=2275 lang=cpp
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */

#include <vector>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int i = 1; i <= 10000000; i <<= 1){
            int count = 0;
            for(int num : candidates){
                if( (i & num) > 0)
                    count += 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector candidates{16,17,71,62,12,24,14};
    cout << s.largestCombination(candidates) << endl;
    candidates = {8,8};
    cout << s.largestCombination(candidates) << endl;
}
