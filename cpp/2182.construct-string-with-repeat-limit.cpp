/*
 * @lc app=leetcode id=2182 lang=cpp
 *
 * [2182] Construct String With Repeat Limit
 */

#include <string>
#include <iostream>
#include <array>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        array<int, 26> characters = {};
        for(auto charac : s)
            characters[charac - 'a']++;
        string ans = "";
        queue<int> q;
        int i = 26;
        while(i--){
            while(!q.empty() && characters[i] > 0){
                ans.push_back('a' + i);
                --characters[i];
                int count = min(characters[q.front()] , repeatLimit);
                ans += string(count, static_cast<char>('a' + q.front())); 
                characters[q.front()] -= count;
                if(!characters[q.front()])q.pop();

            }
            int count = min(characters[i] , repeatLimit);
            ans += string(count,static_cast<char>('a' + i));
            characters[i] -= count;
            if(characters[i] > 0) q.push(i);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.repeatLimitedString("cczazcc", 3) << endl;
    cout << s.repeatLimitedString("aababab", 2) << endl;
}