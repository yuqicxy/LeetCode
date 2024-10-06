/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        istringstream ss(sentence1);
        vector<string> str1;
        string word;
        while(ss >> word)
            str1.push_back(word);
        vector<string> str2;
        ss = istringstream(sentence2);
        while(ss >> word)
            str2.push_back(word);
        
        int N = min(str1.size(), str2.size());
        int maxPrefix = 0;
        for(int i = 0; i < N; ++i){
            if(str1[i] != str2[i])
                break;
            maxPrefix++;
        }

        int maxSuffix = 0;
        for(int i = 0; i < N; ++i){
            if( *(str1.rbegin() + i) != *(str2.rbegin() + i))
                break;
            maxSuffix++;
        }

        
        return maxPrefix + maxSuffix < N ? false : true;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << boolalpha;
    cout << s.areSentencesSimilar("My name is Haley", "My Haley") << endl;
    cout << s.areSentencesSimilar("of", "A lot of words") << endl;
    cout << s.areSentencesSimilar("Eating right now", "Eating") << endl;
    cout << s.areSentencesSimilar( "A A", "A aA") << endl;
}