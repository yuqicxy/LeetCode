/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <iostream>
#include <iterator>

using namespace std;

// @lc code=start
struct Node{
    unsigned                mFrequency;
    unordered_set<string>   mDict;
};

class AllOne {
public:
    AllOne() {
    }
    
    void inc(string key) {
        auto itr = mHash.find(key); 
        if(itr == mHash.end()){
            // if(mList.empty()){
            //     mHash[key] = mList.insert(mList.begin(),Node{1, {key}});
            // }
            /** Key don't exist in map, the frequency of the key is 1*/
            if(mList.empty() || mList.begin()->mFrequency > 1){
                /** the frequency of first node of list is larger then 1: 
                 *  1. construct a new node which frequency is 1 into list, 
                 *  2. add key into the dict of new node
                 *  3. insert key into hash map using begin() as value*/
                mHash[key] = mList.insert(mList.begin(),Node{1, {key}});
            }else{
                /** the frequency of first node equal to 1:
                 *  1. add key into the dict of first node
                 *  2. insert key into hash map using begin() as value*/
                mList.begin()->mDict.insert(key);
                mHash[key] = mList.begin();
            }
        }else{
            /** Key exist in map */
            auto curr = itr->second; /** List::iter*/
            auto nxt = std::next(curr); /* List::iter*/
            curr->mDict.erase(key);
            if(nxt == mList.end() || nxt->mFrequency > curr->mFrequency + 1){
                /**
                 *     1. the frequency of next node in list is larger than curr->mFrequency + 1
                 *  or 2. the curr node is the last node in list
                 *  For both of these two cases, constructing a new node 
                 *  
                 *  1. construct new Node using the key, and increment the frequency
                 *  2. update value of hash map
                 */
                itr->second = mList.insert(nxt, Node{curr->mFrequency + 1, {key}});
            }else{
                /**
                 * using the existing node 
                 * 1. add key to the dict of exising node
                 * 2. update value of hash map
                 */
                nxt->mDict.insert(key);
                itr->second = nxt;
            }
            if(curr->mDict.empty())
                mList.erase(curr);
        }
    }
    
    void dec(string key) {
        auto itr = mHash.find(key);
        auto curr = itr->second; /** list iter */
        curr->mDict.erase(key);
        if(curr->mFrequency == 1){
            mHash.erase(key);
        }else{
            if(curr == mList.begin()){
                itr->second = mList.insert(curr, Node{curr->mFrequency - 1, {key}});
            }else{
                auto previous = std::prev(curr);
                if(previous->mFrequency == curr->mFrequency - 1){
                    previous->mDict.insert(key);
                    itr->second = previous;
                }else{
                    itr->second = mList.insert(curr, Node{curr->mFrequency - 1, {key}});
                }
            }
        }
        if(curr->mDict.empty())
            mList.erase(curr);
    }
    
    string getMaxKey() {
        /** the max is the last node of list */
        return mList.empty() ? "" : *(mList.back().mDict.begin());
    }
    
    string getMinKey() {
        /** the min is the first node of list */
        return mList.empty() ? "" : *(mList.front().mDict.begin());
    }

private:
    
    /// @brief mList stored the Node by grouping string frequency, each different frequenct is a node.
    list<Node> mList;

    /// @brief mHash store key{string} value{const iter in mList stored the frequency of string}>
    unordered_map<string, list<Node>::iterator> mHash;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

int main(){
    AllOne allOne;
    allOne.inc("hello");
    allOne.inc("hello");
    allOne.dec("hello");
    allOne.inc("code");
    allOne.inc("leet");
    allOne.inc("code");
    cout << allOne.getMaxKey() << endl; // return "hello"
    cout << allOne.getMinKey() << endl; // return "hello"
    allOne.dec("code");
    allOne.inc("leet");
    cout << allOne.getMaxKey() << endl; // return "hello"
    cout << allOne.getMinKey() << endl; // return "leet"
}

