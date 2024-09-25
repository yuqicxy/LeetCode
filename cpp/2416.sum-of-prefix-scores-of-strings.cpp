/*
 * @lc app=leetcode id=2416 lang=cpp
 *
 * [2416] Sum of Prefix Scores of Strings
 */

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

// @lc code=start

class Solution {
public:
    struct TrieNode
    {
        int count = 1;
        unordered_map<char,TrieNode*> children;
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        auto trie = buildTrie(words);
        vector<int> ans;
        for (auto &&word : words){
            auto tmp = trie;
            int count = 0;
            for(auto &&character : word){
                count += tmp->children[character]->count; 
                tmp = tmp->children[character];
            }
            ans.push_back(count);
        }
        delete trie;
        return ans;
    }

    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root{new TrieNode};
        for (auto &&word : words){
            auto tmp = root;
            for (auto &&character : word){
                if(tmp->children.find(character) != tmp->children.end()){
                    tmp->children[character]->count += 1;
                }else{
                    TrieNode* node(new TrieNode());
                    tmp->children[character] = node;
                }
                tmp = tmp->children[character];
            }
        }
        return root;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> words{"abc","ab","bc","b"};
    // auto node = s.buildTrie(words);
    auto v = s.sumPrefixScores(words);
    return 0;
}