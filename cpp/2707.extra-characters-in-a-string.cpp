/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [2707] Extra Characters In A String
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dpArray(s.size(), -1);
        return calMinExtraChar(s,dictionary,dpArray,0);
    }

    int calMinExtraChar(const string &s, const vector<string>& dictionary, vector<int> &dpArray, int i){
        if(i == s.size()) return 0;

        if(dpArray[i] == -1){
            dpArray[i] = 1 + calMinExtraChar(s,dictionary,dpArray,i + 1);

            for (auto &&word : dictionary)
            {
                if(s.compare(i,word.size(), word) == 0){
                    dpArray[i] = min(dpArray[i], calMinExtraChar(s,dictionary,dpArray,i + word.size()));
                }
            }
            
        }

        return dpArray[i];
    }
};
// @lc code=end

int main(){
    Solution s;
    auto tmp = vector<string>{"leet","sc","code","leetcode"};
    cout<< s.minExtraChar("leetscodescode", tmp) <<endl;
}