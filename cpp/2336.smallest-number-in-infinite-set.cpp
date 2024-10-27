/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */
#include <set>
using namespace std;

// @lc code=start
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet():mMax(1) {
    }
    
    int popSmallest() {
        if(!mSet.empty())
        {
            int val = *mSet.begin();
            mSet.erase(mSet.begin());
            return val;
        }
        return mMax++;
    }
    
    void addBack(int num) {
        if(num < mMax)
            mSet.insert(num);
    }
private:
    int mMax;
    set<int> mSet;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

