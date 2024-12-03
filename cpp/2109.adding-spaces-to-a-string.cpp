/*
 * @lc app=leetcode id=2109 lang=cpp
 *
 * [2109] Adding Spaces to a String
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class MySolution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int place = 0;
        for(int i = 0 ; i < spaces.size(); ++i){
            ans += s.substr(place, spaces[i] - place) + " ";
            place = spaces[i];
        }
        ans += s.substr(place);
        return ans;
    }
};

// @lc code=start
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (j < spaces.size() && i == spaces[j]) {
                res += " ";
                ++j;
            }
            res += s[i];
        }
        return res;
    }
};
// @lc code=end


int main(){
    Solution s;
    vector spaces{8,13,15};
    cout << s.addSpaces("LeetcodeHelpsMeLearn", spaces) << endl;
    spaces = {1,5,7,9};
    cout << s.addSpaces("icodeinpython", spaces) << endl;
    spaces = {0,1,2,3,4,5,6};
    cout << s.addSpaces("spacing", spaces) << endl;
}
