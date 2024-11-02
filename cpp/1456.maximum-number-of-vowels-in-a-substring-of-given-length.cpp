/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
        int maxAns = 0;
        for(auto i = 0, ans = 0; i < s.size(); ++i){
            if(i >= k)
                ans -= vowels[s[i-k] - 'a'];
            ans += vowels[s[i] - 'a'];
            maxAns = max(ans,maxAns);
        }
        return maxAns;
    }
};
// @lc code=end
#include <iostream>

int main(){
    Solution s;
    cout <<s.maxVowels("abciiidef", 3)<< endl;
    cout <<s.maxVowels("aeiou" , 2)<< endl;
    cout <<s.maxVowels("leetcode", 3)<< endl;
}