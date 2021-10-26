/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int ans = 0;
        std::unordered_map<char,int> hashmap;
        for(int i=0,j=0; j<s.length(); ++j){
            auto itr = hashmap.find(s.at(j));
            if(itr != hashmap.end()){
                i = std::max(hashmap.at(s.at(j)),i);
                hashmap.at(s.at(j)) = j+1;
            }
            else{
                hashmap.emplace(s.at(j),j+1);
            }
            ans = std::max(ans,j-i+1);
        }
        return ans;
    }
};
// @lc code=end

