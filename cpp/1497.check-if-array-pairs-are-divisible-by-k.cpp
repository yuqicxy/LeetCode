/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mRemainFreq;
        for_each(arr.begin(), arr.end(),[&](int val){
            mRemainFreq[(val % k + k) % k]++;
        });

        if(mRemainFreq[0] & 1)
            return false;
        for (int i = 1; i < k; ++i)
        {
            if(mRemainFreq[i] != mRemainFreq[k-i])
                return false;
        }

        return true;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> arr{1,2,3,4,5,10,6,7,8,9};
    int k = 5;
    cout<< boolalpha << s.canArrange(arr,k)<<endl;
    arr = {1,2,3,4,5,6};
    k = 7;
    cout << s.canArrange(arr,k) <<endl;
    k = 10;
    cout << s.canArrange(arr,k)<<endl;
}