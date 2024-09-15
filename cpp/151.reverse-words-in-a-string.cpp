/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

#include <string>
#include <iostream>
#include <cassert>
using namespace std;

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        reverse(s,0,s.size());

        size_t i = 0, j = 0;
        size_t n = s.size();
        while(i < n){
            while( i < n && s[i] == ' ') ++i;
            while( i < n && s[i] != ' ') ++j, ++i;
            reverse(s, i - j, j);
            j = 0;
        }
        removeSpace(s);
        return s;
    }

    void removeSpace(string &s){
        size_t len = s.size();
        size_t i = 0,j = 0;

        while(j < len){
            while (j < len && s[j] == ' ') j++;             // skip spaces
            while (j < len && s[j] != ' ') s[i++] = s[j++]; // keep non spaces
            while (j < len && s[j] == ' ') j++;             // skip spaces
            if (j < len) s[i++] = ' ';                      // keep only one space
        }
        s = s.substr(0, i);
    }

    void reverse(string& s, size_t start, size_t count){
        for(size_t i = start, j = start + count - 1; i < j; i++, j--){
            assert(i < s.size());
            assert(j < s.size());
            swap(s.at(i),s.at(j));
        }
    }
};
// @lc code=end

int main(){
    Solution s;
    cout<<s.reverseWords("the sky is blue")<<endl;
    cout<<s.reverseWords("  hello world  ")<<endl;
}

