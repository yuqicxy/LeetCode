/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // BFS method
    // int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    //     unordered_set<string> dict(wordList.begin(),wordList.end());
    //     if(dict.find(endWord) == dict.end()) return 0;
    //     queue<string> queue;
    //     queue.push(beginWord);
    //     int step = 0;
    //     while(!queue.empty()){
    //         step++;
    //         int size = queue.size();
    //         for(int i = 0; i < size; ++i){
    //             string str = queue.front();
    //             queue.pop();
    //             dict.erase(str);
    //             if(str == endWord)
    //                 return step;
    //             string word = str;
    //             for (int j = 0; j < word.length(); j++) {
    //                 char c = word[j];
    //                 for (int k = 0; k < 26; k++) {
    //                     word[j] = 'a' + k;
    //                     if (dict.find(word) != dict.end()) {
    //                         queue.push(word);
    //                     }
    //                 }
    //                 word = str;
    //             }
    //         }
    //     }
    //     return 0;
    // }
    /**
     * @brief BFS and two end search method
     * 
     * @param beginWord 
     * @param endWord 
     * @param wordList 
     * @return int 
     */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        unordered_set<string> head;
        head.insert(beginWord);
        unordered_set<string> tail;
        tail.insert(endWord);
        if(dict.erase(endWord) == 0) return 0;
        unordered_set<string> *headPtr = nullptr,*tailPtr = nullptr;
        int step = 2;
        while(!head.empty() && !tail.empty()){
            if(head.size() > tail.size()){
                headPtr = &head;
                tailPtr = &tail;
            }else{
                headPtr = &tail;
                tailPtr = &head;
            }
            unordered_set<string> cache;
            for(auto itr = headPtr->begin(); itr != headPtr->end(); ++itr){
                string word = (*itr);
                for (int j = 0; j < word.length(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if(tailPtr->find(word) != tailPtr->end())
                            return step;
                        if (dict.find(word) != dict.end()) {
                            cache.insert(word);
                            dict.erase(word);
                        }
                    }
                    word = (*itr);
                }
            }
            swap(tail,cache);
            step++;
        }
        return 0;
    }
};
// @lc code=end

