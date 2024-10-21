/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1 , 0);
        for(int i = 1; i < n + 1 ; ++i){
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    s.countBits(2);
    s.countBits(5);
    return 0;
}