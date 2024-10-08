/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSwaps(string s){
        if(s.empty()) return 0;
        int openBracketCount = 0;
        int closedBracketCount = 0;
        int ans = 0;
        size_t j = s.size();
        for(size_t i = 0; i < j; ++i){
            s[i] == '[' ? openBracketCount++ : closedBracketCount++;
            if(closedBracketCount > openBracketCount){
                for(size_t idx = j - 1; idx > i; --idx){
                    if(s[idx] == '['){
                        swap(s[i], s[idx]);
                        closedBracketCount--;
                        openBracketCount++;
                        ans++;
                        j = idx;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end


int main(){
    Solution s;
    cout << s.minSwaps("][][") << endl;
    cout << s.minSwaps("]]][[[") << endl;
    cout << s.minSwaps("[]") << endl;
    return 0;
}