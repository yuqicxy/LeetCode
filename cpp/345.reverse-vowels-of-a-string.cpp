/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */
#include <string>
#include <set>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        const set<char> vowels{'a','A','e','E', 'i','I', 'o','O','u','U'};        

        size_t tb = s.size(); 
        for (size_t i = 0; i < tb; ++i){
            if(vowels.find(s[i]) != vowels.cend()){
                for(size_t j = tb - 1; j > i; --j){
                    if(vowels.find(s[j]) != vowels.cend()){
                        swap(s[i],s[j]);
                        tb = j;
                        break;
                    }
                }
            }
        }

        return s;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout<<s.reverseVowels("IceCreAm")<<endl;
}