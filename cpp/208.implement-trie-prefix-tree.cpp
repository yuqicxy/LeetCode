/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include <unordered_map>
#include <string>

using namespace std;

class SlowTrie {
public:
    SlowTrie():isWord(false), mTrie() {
    }
    
    void insert(string word) {
        auto itr = mTrie.find(word.front());
        if(itr == mTrie.end()){
            auto t = SlowTrie();
            if(word.length() > 1)
                t.insert(word.substr(1));
            else
                t.isWord = true;
            mTrie[word.front()] = t;
        }
        else if(itr != mTrie.end()){
            if(word.length() > 1){
                itr->second.insert(word.substr(1));
            }else{
                itr->second.isWord = true;
            }
        }

    }
    
    bool search(string word) {
        auto itr = mTrie.find(word[0]);
        if(itr == mTrie.end())
            return false;
        if(word.length() > 1)
            return itr->second.search(word.substr(1));
        else
            return itr->second.isWord;
    }
    
    bool startsWith(string prefix) {
        auto itr = mTrie.find(prefix[0]);
        if(itr == mTrie.end())
            return false;
        if(prefix.length() > 1)
            return itr->second.startsWith(prefix.substr(1));
        else
            return true;
    }
private: 
    unordered_map<char, SlowTrie> mTrie;
    bool isWord;
};

#include <array>

// @lc code=start
class Trie {
public:
    Trie():isWord(false),mTrie{nullptr} {
    }

    ~Trie(){
        for(auto ptr : mTrie){
            if(ptr != nullptr)
                delete ptr;
        }
    }
    
    void insert(string word) {
        Trie* node = this;
        for(auto a : word){
            int i = a - 'a';
            if(node->mTrie[i] == nullptr)
                node->mTrie[i] = new Trie();
            node = node->mTrie[i];
        }
        node->isWord=true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(auto a : word){
            int i = a - 'a';
            if(node->mTrie[i] != nullptr)
                node = node->mTrie[i];
            else
                return false;
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto a : prefix){
            int i = a - 'a';
            if(node->mTrie[i] != nullptr)
                node = node->mTrie[i];
            else
                return false;
        }
        return true;
    }
private:
    bool isWord;
    array<Trie*, 26> mTrie;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
#include <iostream>

int main(){
    Trie trie = Trie();
    cout << boolalpha;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // return True
    cout << trie.search("app")   << endl;     // return False
    cout << trie.startsWith("app") << endl; // return True
    trie.insert("app");
    cout << trie.search("app") << endl;     // return True
}

