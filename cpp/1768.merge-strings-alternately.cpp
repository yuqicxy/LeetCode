/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string::size_type i = 0,j = 0;
        string result;
        while( i < word1.size() || j < word2.size())
        {
            if(i < word1.size())
                result.append(&word1.at(i),1);
            i++;

            if(j < word2.size())
                result.append(&word2.at(j),1);
            j++;
        }
        return result;
    }
};
// @lc code=end

class StupidSolution {
public:
    string mergeAlternately(string word1, string word2) {
        string::size_type l_itr = 0;
        string::size_type r_itr = 0;
        for(;l_itr < word1.size(); ++l_itr){
            if(r_itr < word2.size()){
                ++l_itr;
                word1.insert(l_itr,&word2.at(r_itr),1);
                ++r_itr;
            }
        }
        if(r_itr < word2.size())
            word1.append(word2,r_itr,word2.size() - r_itr);
        return word1;
    }
};

int main(){
    Solution s;
    string w1 = "ab";
    string w2 = "pqrs";
    std::cout<< s.mergeAlternately(w1,w2);
}

