/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */
#include <string>
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

class StupidSolution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int count = 0;
        while(ss >> word){
            count++;
            if(word.substr(0,searchWord.size()) == searchWord)
                return count;
        }
        return -1;
    }
};

// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto sent = " " + sentence, word = " " + searchWord;
        auto pos = sent.find(word);
        if (pos != string::npos)
            return count(begin(sent), begin(sent) + pos + 1, ' ');
        return -1;
    }
};
// @lc code=end

int main(){
    StupidSolution s;
    cout << s.isPrefixOfWord("i love eating burger", "burg") << endl; //4
    cout << s.isPrefixOfWord("this problem is an easy problem", "pro") << endl; //2
    cout << s.isPrefixOfWord("i am tired", "you") << endl; //-1
    cout << s.isPrefixOfWord("hello from the other side", "they") << endl; //-1

}

