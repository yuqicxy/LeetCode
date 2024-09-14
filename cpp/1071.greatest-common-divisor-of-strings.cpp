/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */
#include <string>
#include <numeric>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 != str2 + str1) ? "" : str1.substr(0,gcd(str1.size(),str2.size()));
    }
};
// @lc code=end

int main(){
    Solution s;

    string str1 = "ABCABC", str2 = "ABC";
    cout<<s.gcdOfStrings(str1,str2)<<endl;
    str1 = "ABABAB", str2 = "ABAB";
    cout<<s.gcdOfStrings(str1,str2)<<endl;
}