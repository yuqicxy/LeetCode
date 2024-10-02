/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp(arr);
        sort(tmp.begin(), tmp.end());
        unordered_map<int,int> mSortedContainer;
        for_each(tmp.begin(), tmp.end(),[&mSortedContainer](int val){
            mSortedContainer.insert({val, (int)mSortedContainer.size() + 1});
        });
        vector<int> ans;
        for_each(arr.begin(), arr.end(), [&](int val){
            ans.push_back(mSortedContainer[val]);
        });
        return ans;
    }
};
// @lc code=end

int main(){
    vector<int> arr = {40,10,20,30};
    Solution s;
    auto ans = s.arrayRankTransform(arr);
    for(auto val : ans)
        cout << val <<' ';
    cout << endl;
    arr = {100,100,100};
    ans = s.arrayRankTransform(arr);
    for(auto val : ans)
        cout << val <<' ';
    cout << endl;
    return 0;
}