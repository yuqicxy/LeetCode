/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

#include <string>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        shared_ptr<int[]> w1Index(new int[26]{});
        set<char> s1, s2;
        for(auto character : word2){
            w1Index[character - 'a']++;
            s1.insert(character);
        }
        shared_ptr<int[]> w2Index(new int[26]{});
        for(auto character : word1){
            w2Index[character - 'a']++;
            s2.insert(character);
        }
        sort(w1Index.get(), w1Index.get() + 26);
        sort(w2Index.get(), w2Index.get() + 26);
        for(int i = 0; i < 26; ++i){
            if(*(w1Index.get() + i) != *(w2Index.get() + i))
                return false;
        }
        return s1 == s2;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << boolalpha << s.closeStrings("abc", "bca") << endl;
    cout << boolalpha << s.closeStrings("a", "aa") << endl;
    return 0;
}