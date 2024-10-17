/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        if(n < 2)
            return n;
        int ans = 0;
        while(n-- > 2){
            ans = a + b + c;
            a = b;
            b = c;
            c = ans; 
        }
        return c;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.tribonacci(4) << endl;
    cout << s.tribonacci(25) << endl;
}
