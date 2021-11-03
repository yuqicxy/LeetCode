/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> results;
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.erase(endWord) == 0) return results;
        dict.erase(beginWord);
        bool meet = false;
        map<string,vector<vector<string>>> head; head[beginWord] = {{beginWord}};
        while(!head.empty()){
            map<string,vector<vector<string>>> cache;
            for(auto itr = head.begin(); itr != head.end(); ++itr){
                string word = itr->first;
                for (int j = 0; j < word.length(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if(word == endWord){
                            for(auto &&res : itr->second){
                                res.push_back(endWord);
                                results.push_back(res);
                            }
                            meet = true;
                        }
                        else if (dict.find(word) != dict.end()) {
                            for(auto &&res : itr->second){
                                vector<string> tmp(res.begin(),res.end());
                                tmp.push_back(word);
                                cache[word].push_back(tmp);
                            }
                        }
                    }
                    word = (itr->first);
                }
            }
            for(auto &&itr : cache){
                dict.erase(itr.first);
            }
            if(meet) cache.clear();
            swap(head,cache);
        }
        return results;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
    vector<vector<string>> result = s.findLadders("red","tax",wordList);
}