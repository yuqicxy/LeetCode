/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

#include <string>
#include <iostream>

using namespace std;

class BrutalForceSolution {
public:
    int maximumLength(string s) {
        int ans = -1;
        int len = 1;
        for(int len = 1; len < s.size() - 1; ++len){
            for(int i = 0; i < s.size() - len; ++i){
                string subString = s.substr(i, len);
                int occurancy = 1;
                if(isSpecial(subString))
                {
                    //check occurancy
                    int start = i;
                    while(occurancy < 3 && start + 1 < s.size()){
                        int pos = s.find(subString, start + 1);
                        if(pos == string::npos)
                            break;
                        occurancy++;
                        start = pos;
                    }
                }
                if(occurancy > 2){
                    ans = len;
                    break;
                }
            }
        }
        return ans;
    }

    /**
     * @brief check whether the string is made up of a single character
     * 
     * @param s input
     * @return true 
     * @return false 
     */
    bool isSpecial(const string &s){
        if(s.size() == 1)
            return true;
        for(int i = 1; i < s.size(); ++i){
            if(s[i-1] != s[i])
                return false;           
        }
        return true;
    }
};


// @lc code=start
class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        int len = 1;
        for(int len = 1; len < s.size() - 1; ++len){
            for(int i = 0; i < s.size() - len; ++i){
                string subString = s.substr(i, len);
                int occurancy = 1;
                if(isSpecial(subString))
                {
                    //check occurancy
                    int start = i;
                    while(occurancy < 3 && start + 1 < s.size()){
                        int pos = s.find(subString, start + 1);
                        if(pos == string::npos)
                            break;
                        occurancy++;
                        start = pos;
                    }
                }
                if(occurancy > 2){
                    ans = len;
                    i = s.size();
                    break;
                }
            }
        }
        return ans;
    }

    /**
     * @brief check whether the string is made up of a single character
     * 
     * @param s input
     * @return true 
     * @return false 
     */
    bool isSpecial(const string &s){
        if(s.size() == 1)
            return true;
        for(int i = 1; i < s.size(); ++i){
            if(s[i-1] != s[i])
                return false;           
        }
        return true;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.maximumLength("aaaa") << endl; //2
    cout << s.maximumLength("abcdef") << endl; //-1
    cout << s.maximumLength("abcaba") << endl; //1
    cout << s.maximumLength("aaabbbbccccc") << endl; //3
}