/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
class SolutionStupid {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for(auto word : words){
            bool valid = true;
            unordered_set<char> s(word.begin(),word.end());
            for(auto i = s.cbegin(); i != s.cend(); i++){
                if (allowed.find(*i) == string::npos){
                    valid = false;
                    break;
                }
            }
            if(valid) count++;
        }
        return count;
    }
};
// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int s[26] = {};
        int count = 0;
        for(auto ch : allowed){
            ++s[ch - 'a'];
        }
        for(auto &w : words){
            count += (int)all_of(w.begin(),w.end(), [&s](auto character){
                return s[character - 'a'] > 0;
            });
        }
        return count;
    }
};
// @lc code=end
int main(){
    Solution s;
    //2
    cout<<s.countConsistentStrings("ab",vector<string>({"ad","bd","aaab","baa","badab"}))<<endl;   
    //7
    cout<<s.countConsistentStrings("abc",std::move<vector<string>>({"a","b","c","ab","ac","bc","abc"}))<<endl; 
}
