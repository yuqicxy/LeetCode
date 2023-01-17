/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());
    //     return s == t;
    // }


    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int N = s.length();
        unordered_map<char,int> hash;
        for(int i = 0; i < N; ++i){
            hash[s[i]]++;
            hash[t[i]]--;
        }
        for(auto p : hash){
            if(p.second != 0)
                return false;
        }
        return true;
    }

};
// @lc code=end

