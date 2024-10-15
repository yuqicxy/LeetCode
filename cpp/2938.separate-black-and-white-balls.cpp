/*
 * @lc app=leetcode id=2938 lang=cpp
 *
 * [2938] Separate Black and White Balls
 */
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long countOfOne = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '1')
                countOfOne++;
            else
                ans += countOfOne;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.minimumSteps("101") <<endl; // 1
    cout << s.minimumSteps("100") <<endl; // 2
    cout << s.minimumSteps("0111") <<endl; // 0
}