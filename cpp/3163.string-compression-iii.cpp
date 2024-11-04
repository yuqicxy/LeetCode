/*
 * @lc app=leetcode id=3163 lang=cpp
 *
 * [3163] String Compression III
 */

#include <string>
#include <iostream>

using namespace std;

class StupidSolution {
public:
    string compressedString(string word) {
        char tmp = word.front();
        int count = 1;
        string ans;
        for(int i = 1; i < word.size(); ++i){
            if(tmp == word[i]){
                count++;
            }else{
                while(count > 9){
                    ans += to_string(9) + tmp;
                    count -= 9;
                }
                ans += to_string(count) + tmp;
                tmp = word[i];
                count = 1;
            }
        }
        while(count > 9){
            ans += to_string(9) + tmp;
            count -= 9;
        }
        ans += to_string(count) + tmp;
        return ans;
    }
};


// @lc code=start
class Solution {
public:
    string compressedString(string word) {
        int i = 0, j = 0;
        int count = 0;
        string ans;
        while(i < word.size()){
            while(count < 9 && word[i] == word[j]){
                i++;
                count++;
            }
            ans += to_string(count) + word[j];
            count = 0;
            j = i;
        }
        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << s.compressedString("abcde") << endl;
    cout << s.compressedString("aaaaaaaaaaaaaabb") << endl;
}