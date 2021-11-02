/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> map;
        for(string str : strs){
            string tmp = str;
            sort(str.begin(),str.end());
            map[str].push_back(tmp);
        }

        vector<vector<string>> result;
        for(auto pair : map){
            result.push_back(pair.second);
        }
        return result;
    }
};
// @lc code=end

