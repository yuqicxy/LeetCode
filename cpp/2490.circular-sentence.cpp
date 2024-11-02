/*
 * @lc app=leetcode id=2490 lang=cpp
 *
 * [2490] Circular Sentence
 */
#include <string>
#include <ranges>
#include <stack>

#include <iostream>

using namespace std;

class UnsupportedCPP20Solution {
public:
    bool isCircularSentence(string sentence) {
        stack<char> mStk;
        for(auto word : views::split(sentence, " "sv)){
            if(mStk.empty()){
                mStk.push(word.front());
                mStk.push(word.back());
            }
            else if(mStk.top() == word.front()){
                mStk.pop();
                mStk.push(word.back());
            }else{
                return false;
            }
        }
        auto last = mStk.top();
        mStk.pop();
        auto front = mStk.top();
        if(last == front)
            return true;
        return false;
    }
};

#include <sstream>
class StupidSolution {
public:
    bool isCircularSentence(string sentence) {
        stack<char> mStk;
        stringstream ss(sentence);
        string word;
        while(getline(ss,word,' ')){
            if(mStk.empty()){
                mStk.push(word.front());
                mStk.push(word.back());
            }
            else if(mStk.top() == word.front()){
                mStk.pop();
                mStk.push(word.back());
            }else{
                return false;
            }
        }
        auto last = mStk.top();
        mStk.pop();
        auto front = mStk.top();
        return last == front;
    }
};

// @lc code=start
class Solution {
public:
    bool isCircularSentence(string sentence) {
        for(auto i = 0; i < sentence.size(); ++i){
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1])
                return false;
        }
        return sentence.front() == sentence.back();
    }
};
// @lc code=end

int main(){
    Solution s;
    cout << boolalpha << s.isCircularSentence("leetcode exercises sound delightful") << endl;
    cout << boolalpha << s.isCircularSentence("eetcode") << endl;
    cout << boolalpha << s.isCircularSentence("Leetcode is cool")<< endl;
}