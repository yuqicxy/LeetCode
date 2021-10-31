/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TrieNode{
    public:
        TrieNode():mWord(""){
            mNext.resize(26,nullptr);
        }

        vector<TrieNode*> mNext;
        string mWord;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrieTree(words);
        vector<string> results;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                depthFirstSearch(board,root,i,j,results);
            }
        }
        return results;
    }

    void depthFirstSearch(vector<vector<char>> &board,TrieNode *root,
            int i,int j,vector<string> &results){
        char c = board[i][j];
        if(c == '#' || root->mNext[c - 'a'] == nullptr) return;
        root = root->mNext[c-'a'];
        board[i][j] = '#';
        if(!root->mWord.empty()){
            results.push_back(root->mWord);
            root->mWord = "";
        }
        if(i > 0) depthFirstSearch(board,root, i - 1, j,results);
        if(i < board.size() - 1) depthFirstSearch(board,root, i + 1, j,results);
        if(j < board[0].size() - 1) depthFirstSearch(board,root, i, j + 1,results);
        if(j > 0) depthFirstSearch(board,root, i, j - 1,results);
        board[i][j] = c;
        return;
    }

    TrieNode *buildTrieTree(vector<string>& words){
        TrieNode *root = new TrieNode;
        for(auto &&word : words){
            TrieNode *p = root;
            for(auto &&c : word){
                if(p->mNext[c-'a'] == nullptr)
                    p->mNext[c - 'a'] = new TrieNode;
                p = p->mNext[c-'a'];
            }
            p->mWord = word;
        }
        return root;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> results = s.findWords(board,words);
    for(auto &&str : results){
        cout<<str<<endl;
    }
}
// @lc code=end