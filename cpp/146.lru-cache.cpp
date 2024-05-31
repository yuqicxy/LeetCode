/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <unordered_map>
#include <deque>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity):mCapacity(capacity) {
    }
    
    int get(int key) {
        auto itr = mCache.find(key);
        if(itr == mCache.end()) return -1;
        memo(itr);
        return itr->second.first;
    }
    
    void put(int key, int value) {
        auto itr = mCache.find(key);
        if(itr != mCache.end()){
            memo(itr);
        }else{
            if(mCache.size() == mCapacity){
                auto leastRecentlyUsedKey = mUsed.back();
                mUsed.pop_back();
                mCache.erase(leastRecentlyUsedKey);
            }
            mUsed.push_front(key);
        }
        mCache[key] = {value,mUsed.begin()};
    }

private:
    typedef list<int> List;
    typedef pair<int,List::iterator> VI;
    typedef unordered_map<int,VI> CacheType;
    List mUsed;
    CacheType mCache;
    int mCapacity;
private:
    void memo(CacheType::iterator itr){
        mUsed.erase(itr->second.second);
        mUsed.push_front(itr->first);
        itr->second.second = mUsed.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(){
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
}

