/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

class TrieSolution {
public:
    struct Trie{
        ~Trie(){
            for (auto &&i : subTrie)
                delete i.second;
        }
        bool isLeaf = false;
        unordered_map<string, Trie*> subTrie = {};
    };

    vector<string> removeSubfolders(vector<string>& folder) {
        Trie *root = new Trie;
        for (auto &&str : folder)
        {
            auto node = root;
            int i = 0;
            stringstream ss(str);
            string word;
            while(getline(ss,word, '/')){
                if(i++ == 0) continue;
                auto pos = node->subTrie.find(word);
                if(pos != node->subTrie.end()){
                    node = pos->second;
                }else{
                    auto tmp = new Trie();
                    node->subTrie.insert({word,tmp});
                    node = tmp;
                }
            }
            if(!word.empty())
                node->isLeaf = true;
        }
        vector<string> ans{};
        generateAns(root, "", ans);
        delete root;
        return ans;
    }

    void generateAns(Trie* node, string tmplateStr, vector<string> &ans){
        for (auto &&item : node->subTrie)
        {
            if(item.second->isLeaf){
                ans.push_back(tmplateStr + "/" + item.first);
            }
            else{
                generateAns(item.second, tmplateStr + "/" + item.first, ans);
            }
        }
    }
};

// @lc code=start
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> ans;
        ans.push_back(folder[0]);

        for(int i = 1; i < folder.size(); ++i){
            string root = ans[ans.size() - 1] + '/';
            string prefix = folder[i].substr(0,root.size());
            if(prefix != root){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
// @lc code=end
#include <iostream>

int main(){
    Solution s;
    vector<string> folders = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    auto res= s.removeSubfolders(folders);
    for (auto &&i : res)
        cout << i<<' ';
    cout << endl;

    folders = {"/a","/a/b/c","/a/b/d"};
    res= s.removeSubfolders(folders);
    for (auto &&i : res)
        cout << i<<' ';
    cout << endl;

    folders = {"/a/b/c","/a/b/ca","/a/b/d"};
    res= s.removeSubfolders(folders);
    for (auto &&i : res)
        cout << i<<' ';
    cout << endl;
    
    return 0;
}