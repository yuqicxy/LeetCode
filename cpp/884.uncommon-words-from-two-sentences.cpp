/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <ranges>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> dict;
        getWords(s1,dict);
        getWords(s2,dict);
        vector<string> ans;
        for (auto &&itr : dict)
            if(itr.second == 1)
                ans.push_back(itr.first);
        return ans;
    }

    void getWords(string s, unordered_map<string,int> &dict){
        stringstream ss(s);
        string word;
        while(getline(ss,word,' ')){
            dict[word]++;
        }
    }
};
// @lc code=end

int main(){
    Solution s;
    //  ["sweet","sour"]
    auto v = s.uncommonFromSentences("this apple is sweet", "this apple is sour");
    cout<<"[";
    for (auto &&i : v)
    {
        cout<<","<< i;
    }
    cout<<"]"<<endl;
}