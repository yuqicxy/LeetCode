/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start

#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mSet.find(val) != mSet.end())
            return false;
        mNum.push_back(val);
        mSet[val] = mNum.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mSet.find(val) == mSet.end())
            return false;
        int index =  mSet[val];
        int lastVal = mNum.back();
        mSet[lastVal] = index;
        mNum[index] = lastVal; 
        mNum.pop_back();
        mSet.erase(val);
        return true;
    }
    
    int getRandom() {
        return mNum[rand() % mNum.size()];
    }
private:
    unordered_map<int,int> mSet;
    vector<int> mNum;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

